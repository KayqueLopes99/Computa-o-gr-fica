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

void draw_line(int x0, int y0, int x1, int y1)
{
    for (float t = 0.0; t < 1.0; t = t + 0.0001)
        set_pixel((int)x0 + (x1 - x0) * t, (int)y0 + (y1 - y0) * t, 0, 0, 0);
}

void clr()
{
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            for (int c = 0; c < 3; c++)
                image[i][j][c] = 255;
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
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {

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

int load_obj(const char *filename, Vertex **vertices, int *vcount, Face **faces, int *fcount)
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

   
    int vcapacity = 1000;
    int fcapacity = 1000;

    *vertices = malloc(vcapacity * sizeof(Vertex));
    *faces = malloc(fcapacity * sizeof(Face));
    if (!*vertices || !*faces)
    {
        perror("Erro de alocação de memória");
        fclose(file);
        return 0;
    }

   
    while (fgets(line, sizeof(line), file))
    {
        if (strncmp(line, "v ", 2) == 0) 
        {
            

            if (*vcount >= vcapacity)
            {

                
                vcapacity *= 2;
                *vertices = realloc(*vertices, vcapacity * sizeof(Vertex));
                if (!*vertices)
                {
                    perror("Erro ao realocar memória para vértices");
                    fclose(file);
                    return 0;
                }
            }
            sscanf(line + 2, "%f %f %f", &(*vertices)[*vcount].x,
                   &(*vertices)[*vcount].y,
                   &(*vertices)[*vcount].z);
            (*vcount)++;
        }
        else if (strncmp(line, "f ", 2) == 0)
        {
            if (*fcount >= fcapacity)
            {
                fcapacity *= 2;
                *faces = realloc(*faces, fcapacity * sizeof(Face));
                if (!*faces)
                {
                    perror("Erro ao realocar memória para faces");
                    fclose(file);
                    return 0;
                }
            }

            
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
            (*faces)[(*fcount)++] = face;
        }
    }

    fclose(file);
    printf("Total de vertices carregados: %d\n", *vcount);
    printf("Total de faces carregadas: %d\n", *fcount);
    return 1;
}

void resizing(Vertex v0, Vertex v1)
{
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
        }
    }
}


void render_point_cloud(Vertex *vertices, int vcount)
{
    for (int i = 0; i < vcount; i++)
    {
        int x = (int)((vertices[i].x + 1.0f) * WIDTH / 2.0f);
        int y = (int)((1.0f - vertices[i].y) * HEIGHT / 2.0f);

        // Desenha um pixel preto para o ponto
        set_pixel(x, y, 0, 0, 0);
    }
}
