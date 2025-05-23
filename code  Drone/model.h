/**
 * \file model.h
 *
 * \brief Header com protótipos de funções para manipulação de modelo 3D.
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

#ifndef MODEL_H
#define MODEL_H

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_VERTICES 14000
#define MAX_FACES 14000
#define MAX_FACE_VERTS 32

typedef struct {
  float x, y, z;
} Vertex;

typedef struct {
  int verts[MAX_FACE_VERTS];
  int n;
} Face;

extern unsigned char image[HEIGHT][WIDTH][3];
void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
void clr();
void save();
void draw_line(int x0, int y0, int x1, int y1);
int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces, int *fcount);
void resizing(Vertex v0, Vertex v1, float dx, float dy);
void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount, float dx, float dy);
void apply_transformations(Vertex *original, int vcount, Face *faces, int fcount, Vertex centro, 
                           float sx, float sy, float sz, 
                           char eixo_rotacao, int angulo, 
                           float s_x);
                           
Vertex apply_scale(Vertex p, Vertex centro, float sx, float sy, float sz);
#endif