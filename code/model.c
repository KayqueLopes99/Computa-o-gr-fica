/**
 * \file model.c
 *
 * \brief Implementação das funções de manipulação do modelo 3D.
 *
 * \author
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Engenharias e Tecnologia \n
 * petrucio at ufersa (dot) edu (dot) br
 *
 * \version 1.0
 * \date May 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265358979323846

#include "model.h"
unsigned char image[HEIGHT][WIDTH][3];

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        image[y][x][0] = r;
        image[y][x][1] = g;
        image[y][x][2] = b;
    }
}

void draw_line(int x0, int y0, int x1, int y1) {
  for (float t = 0.0; t < 1.0; t = t + 0.0001)
    set_pixel((int)x0+(x1-x0)*t, (int)y0+(y1-y0)*t, 55, 50, 255);
}

void clr()
{
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            for (int c = 0; c < 3; c++)
                image[i][j][c] = 0;
}

void save()
{
    FILE *fp = fopen("output.ppm", "w");
    if (!fp)
    {
        perror("Erro ao salvar imagem");
        return;
    }
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
            for (int c = 0; c < 3; c++)
            {
                fprintf(fp, "%d ", image[i][j][c]);
            }
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
    printf("Imagem salva em output.ppm\n");
}

int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces,
             int *fcount)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char line[512];
    *vcount = 0;
    *fcount = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (strncmp(line, "v ", 2) == 0)
        {
            if (sscanf(line + 2, "%f %f %f", &vertices[*vcount].x,
                       &vertices[*vcount].y, &vertices[*vcount].z) == 3)
            {
                (*vcount)++;
            }
        }
        else if (strncmp(line, "f ", 2) == 0)
        {
            Face face = {.n = 0};
            char *token = strtok(line + 2, " \n");
            while (token && face.n < MAX_FACE_VERTS)
            {
                int index;
                if (sscanf(token, "%d", &index) == 1)
                {
                    face.verts[face.n++] = index;
                }
                token = strtok(NULL, " \n");
            }
            faces[(*fcount)++] = face;
        }
    }

    printf("Total de vertices carregados: %d\n", *vcount);
    printf("Total de faces carregadas: %d\n", *fcount);

    fclose(file);
    return 1;
}

void resizing( Vertex v0, Vertex v1 ){
  int x0 = (int)((v0.x + 1.0f) * WIDTH / 2.0f);
  int y0 = (int)((1.0f - v0.y) * HEIGHT / 2.0f);
  int x1 = (int)((v1.x + 1.0f) * WIDTH / 2.0f);
  int y1 = (int)((1.0f - v1.y) * HEIGHT / 2.0f);

  draw_line(x0, y0, x1, y1);
}

void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount)
{
    for (int i = 0; i < fcount; i++)
    {
        Face face = faces[i];
        for (int j = 0; j < face.n; j++)
        {
            Vertex v0 = vertices[face.verts[j] - 1];
            Vertex v1 = vertices[face.verts[(j + 1) % face.n] - 1];
            resizing(v0, v1);
        }}}

Vertex apply_scale(Vertex p, Vertex centro, float sx, float sy, float sz)
{
    Vertex result;
    float x = p.x - centro.x;
    float y = p.y - centro.y;
    float z = p.z - centro.z;

    float x1 = sx * x;
    float y1 = sy * y;
    float z1 = sz * z;

    result.x = x1 + centro.x;
    result.y = y1 + centro.y;
    result.z = z1 + centro.z;

    return result;
}

Vertex apply_rotation(Vertex p, Vertex centro, int angulo, char eixo)
{
    Vertex result;
    float rad = -angulo * PI / 180.0f; // Atenção: use M_PI da math.h

    float x = p.x - centro.x;
    float y = p.y - centro.y;
    float z = p.z - centro.z;

    switch (eixo)
    {
    case 'x':
        result.x = x;
        result.y = cos(rad) * y - sin(rad) * z;
        result.z = sin(rad) * y + cos(rad) * z;
        break;

    case 'y':
        result.x = cos(rad) * x + sin(rad) * z;
        result.y = y;
        result.z = -sin(rad) * x + cos(rad) * z;
        break;

    case 'z':
        result.x = cos(rad) * x - sin(rad) * y;
        result.y = sin(rad) * x + cos(rad) * y;
        result.z = z;
        break;

    default:
        result = p;
        break;
    }

    result.x += centro.x;
    result.y += centro.y;
    result.z += centro.z;

    return result;
}

Vertex apply_reflection(Vertex p, int p1, int p2, int p3, Vertex centro)
{
    Vertex refletido;
    refletido.x = centro.x + (p.x - centro.x) * p1;
    refletido.y = centro.y + (p.y - centro.y) * p2;
    refletido.z = centro.z + (p.z - centro.z) * p3;
    return refletido;
}

Vertex shear(Vertex p, float s_x)
{
    Vertex result;

    result.x = p.x + s_x * p.y;
    result.y = p.y;
    result.z = p.z;

    return result;
}
void apply_transformations(Vertex *vertices, int vcount, Vertex centro, float sx, float sy, float sz, char eixo_rotacao, int angulo, float s_x) {
    for (int i = 0; i < vcount; i++) {
        vertices[i] = apply_scale(vertices[i], centro, sx, sy, sz);
        vertices[i] = apply_rotation(vertices[i], centro, angulo, eixo_rotacao);
        vertices[i] = apply_reflection(vertices[i], -1, 1, 1, centro);
        vertices[i] = apply_reflection(vertices[i], 1, -1, 1, centro);
        vertices[i] = apply_reflection(vertices[i], 1, 1, -1, centro);
        vertices[i] = shear(vertices[i], s_x);
    }
}