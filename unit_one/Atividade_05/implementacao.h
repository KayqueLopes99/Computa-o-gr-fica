#ifndef IMPLEMENTACAO_H
#define IMPLEMENTACAO_H

#include <stdio.h>
#include <math.h>
#define HEIGHT 1000
#define WIDTH 1000
#define PI 3.14159265358979323846

// Estrutura para representar um ponto (x, y)
typedef struct
{
    float x, y;
} Ponto;


// Funções para manipulação da imagem
void initialize_image(int r, int g, int b);
void save_image();

// Funções para desenho de figuras
void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
void draw_line(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b);
void start_drawing_lines(Ponto p1, Ponto p2);

// Funções de transformação geométrica
Ponto apply_scale(Ponto p, Ponto centro, float sx, float sy);
Ponto rotation(Ponto p, Ponto centro, int angulo);
Ponto reflection(Ponto p, int p1, int p2, Ponto centro);

// Função para desenhar a imagem com cores, escalas, rotações e reflexões
void draw_image_with_colors(Ponto origem, unsigned char r, unsigned char g, unsigned char b, Ponto centro, float sx, float sy, int angulo, int s_x);

Ponto shear(Ponto p, float s_x);
#endif // IMPLEMENTACAO_H
