#include <stdio.h>
#include <math.h>
#define HEIGHT 1000
#define WIDTH 1000
#define PI 3.14159265358979323846
#include "implementacao.h"
unsigned char image[HEIGHT][WIDTH][3];

void initialize_image(int r, int g, int b)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            image[i][j][0] = r;
            image[i][j][1] = g;
            image[i][j][2] = b;
        }
    }
}

void save_image()
{
    printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d %d %d ", image[i][j][0], image[i][j][1], image[i][j][2]);
        }
        printf("\n");
    }
}

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        image[y][x][0] = r;
        image[y][x][1] = g;
        image[y][x][2] = b;
    }
}

void draw_line(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b)
{
    for (float t = 0.0; t < 1; t = t + 0.0001)
    {
        set_pixel((int)(x2 - x1) * t + x1, (int)(y2 - y1) * t + y1, r, g, b);
    }
}

void start_drawing_lines(Ponto p1, Ponto p2)
{
    draw_line(p1.x, p1.y, p2.x, p2.y, 255, 0, 0);
}

Ponto apply_scale(Ponto p, Ponto centro, float sx, float sy)
{
    Ponto result;
    float x = p.x - centro.x;
    float y = p.y - centro.y;

    float x1 = sx * x;
    float y1 = sy * y;

    result.x = x1 + centro.x;
    result.y = y1 + centro.y;

    return result;
}

Ponto3D rotation3D(Ponto3D p, Ponto3D centro, int angulo, char eixo)
{

    Ponto3D result;
    float rad = -angulo * PI / 180.0;

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

Ponto reflection(Ponto p, int p1, int p2, Ponto centro)
{
    Ponto refletido;
    refletido.x = centro.x + (p.x - centro.x) * p1; // ponto {750,250} no eixo x -> 500 + (750 - 500) * -1 = 250;
    refletido.y = centro.y + (p.y - centro.y) * p2; // ponto {750,250} no eixo x -> 500 + (250 - 500) * 1 = 250;
    return refletido;
}

Ponto shear(Ponto p, float s_x)
{
    Ponto result;

    result.x = p.x + s_x * p.y;
    result.y = p.y;

    return result;
}

void draw_image_with_colors(Ponto origem, unsigned char r, unsigned char g, unsigned char b, Ponto centro, float sx, float sy, int angulo, int s_x)
{
    Ponto base[4] = {
        {origem.x, origem.y},
        {origem.x + 40, origem.y},
        {origem.x + 40, origem.y - 40},
        {origem.x, origem.y - 40}};

    Ponto teto[3] = {
        {origem.x, origem.y - 40},
        {origem.x + 20, origem.y - 60},
        {origem.x + 40, origem.y - 40}};

    Ponto porta[4] = {
        {origem.x + 15, origem.y},
        {origem.x + 15, origem.y - 20},
        {origem.x + 25, origem.y},
        {origem.x + 25, origem.y - 20}};

    for (int i = 0; i < 4; i++)
    {
        base[i] = apply_scale(base[i], centro, sx, sy);
        Ponto3D temp3D = {base[i].x, base[i].y, 0};
        Ponto3D centro3D = {centro.x, centro.y, 0};

        temp3D = rotation3D(temp3D, centro3D, angulo, 'z');

        base[i].x = temp3D.x;
        base[i].y = temp3D.y;

        base[i] = shear(base[i], s_x);
    }
    for (int i = 0; i < 3; i++)
    {
        teto[i] = apply_scale(teto[i], centro, sx, sy);
        Ponto3D temp3D = {teto[i].x, teto[i].y, 0};
        Ponto3D centro3D = {centro.x, centro.y, 0};

        temp3D = rotation3D(temp3D, centro3D, angulo, 'z');

        teto[i].x = temp3D.x;
        teto[i].y = temp3D.y;
        teto[i] = shear(teto[i], s_x);
    }
    for (int i = 0; i < 4; i++)
    {
        porta[i] = apply_scale(porta[i], centro, sx, sy);

        Ponto3D temp3D = {porta[i].x, porta[i].y, 0};
        Ponto3D centro3D = {centro.x, centro.y, 0};

        temp3D = rotation3D(temp3D, centro3D, angulo, 'z');

        porta[i].x = temp3D.x;
        porta[i].y = temp3D.y;

        porta[i] = shear(porta[i], s_x);
    }

    float offsetX = origem.x - base[0].x;
    float offsetY = origem.y - base[0].y;

    for (int i = 0; i < 4; i++)
    {
        base[i].x += offsetX;
        base[i].y += offsetY;
    }
    for (int i = 0; i < 3; i++)
    {
        teto[i].x += offsetX;
        teto[i].y += offsetY;
    }
    for (int i = 0; i < 4; i++)
    {
        porta[i].x += offsetX;
        porta[i].y += offsetY;
    }

    // --- REFLEXÕES ---
    // 4. Gera reflexões com base na figura transformada
    Ponto base_y[4], teto_y[3], porta_y[4];
    Ponto base_x[4], teto_x[3], porta_x[4];
    Ponto base_o[4], teto_o[3], porta_o[4];

    for (int i = 0; i < 4; i++)
    {
        base_y[i] = reflection(base[i], -1, 1, centro);
        porta_y[i] = reflection(porta[i], -1, 1, centro);
        base_x[i] = reflection(base[i], 1, -1, centro);
        porta_x[i] = reflection(porta[i], 1, -1, centro);
        base_o[i] = reflection(base[i], -1, -1, centro);
        porta_o[i] = reflection(porta[i], -1, -1, centro);
    }

    for (int i = 0; i < 3; i++)
    {
        teto_y[i] = reflection(teto[i], -1, 1, centro);
        teto_x[i] = reflection(teto[i], 1, -1, centro);
        teto_o[i] = reflection(teto[i], -1, -1, centro);
    }

    start_drawing_lines(porta[0], porta[1]);
    start_drawing_lines(porta[1], porta[3]);
    start_drawing_lines(porta[2], porta[3]);

    start_drawing_lines(base[0], base[1]);
    start_drawing_lines(base[1], base[2]);
    start_drawing_lines(base[2], base[3]);
    start_drawing_lines(base[3], base[0]);

    start_drawing_lines(teto[0], teto[1]);
    start_drawing_lines(teto[1], teto[2]);
    start_drawing_lines(teto[2], teto[0]);

    // 6. Desenha reflexões

    // Reflexão no eixo Y
    for (int i = 0; i < 4; i++)
        start_drawing_lines(base_y[i], base_y[(i + 1) % 4]);
    start_drawing_lines(teto_y[0], teto_y[1]);
    start_drawing_lines(teto_y[1], teto_y[2]);
    start_drawing_lines(teto_y[2], teto_y[0]);
    start_drawing_lines(porta_y[0], porta_y[1]);
    start_drawing_lines(porta_y[1], porta_y[3]);
    start_drawing_lines(porta_y[2], porta_y[3]);

    // Reflexão no eixo X
    for (int i = 0; i < 4; i++)
        start_drawing_lines(base_x[i], base_x[(i + 1) % 4]);
    start_drawing_lines(teto_x[0], teto_x[1]);
    start_drawing_lines(teto_x[1], teto_x[2]);
    start_drawing_lines(teto_x[2], teto_x[0]);
    start_drawing_lines(porta_x[0], porta_x[1]);
    start_drawing_lines(porta_x[1], porta_x[3]);
    start_drawing_lines(porta_x[2], porta_x[3]);

    // Reflexão na origem
    for (int i = 0; i < 4; i++)
        start_drawing_lines(base_o[i], base_o[(i + 1) % 4]);
    start_drawing_lines(teto_o[0], teto_o[1]);
    start_drawing_lines(teto_o[1], teto_o[2]);
    start_drawing_lines(teto_o[2], teto_o[0]);
    start_drawing_lines(porta_o[0], porta_o[1]);
    start_drawing_lines(porta_o[1], porta_o[3]);
    start_drawing_lines(porta_o[2], porta_o[3]);
}