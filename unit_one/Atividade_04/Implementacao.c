#include <stdio.h>
#include <math.h>
#define HEIGHT 1000
#define WIDTH 1000
#define PI 3.14159265358979323846
unsigned char image[HEIGHT][WIDTH][3]; // [linha][coluna][RGB]

typedef struct{
    float x, y;
} Ponto;

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

void start_drawing_lines (Ponto p1, Ponto p2)
{
    draw_line(p1.x, p1.y, p2.x, p2.y, 255, 0, 0);
}

Ponto apply_scale(Ponto p, Ponto centro, float sx, float sy){
    Ponto result;
    float x = p.x - centro.x;
    float y = p.y - centro.y;

    float x1 = sx * x;
    float y1 = sy * y;

    result.x = x1 + centro.x;
    result.y = y1 + centro.y;

    return result;
}

Ponto rotation(Ponto p, Ponto centro, int angulo)
{
    Ponto result;
    float rad = -angulo * PI / 180.0;

    float x = p.x - centro.x;
    float y = p.y - centro.y;

    float x1 = cos(rad) * x - sin(rad) * y;
    float y1 = sin(rad) * x + cos(rad) * y;

    result.x = x1 + centro.x;
    result.y = y1 + centro.y;

    return result;
}

void draw_image_with_colors(Ponto origem, unsigned char r, unsigned char g, unsigned char b, Ponto centro, float sx, float sy, int angulo)
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
        base[i] = rotation(base[i], centro, angulo);
    }
    for (int i = 0; i < 3; i++)
    {
        teto[i] = apply_scale(teto[i], centro, sx, sy);
        teto[i] = rotation(teto[i], centro, angulo);
    }
    for (int i = 0; i < 4; i++)
    {
        porta[i] = apply_scale(porta[i], centro, sx, sy);
        porta[i] = rotation(porta[i], centro, angulo);
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
}

int main()
{
    initialize_image(0, 0, 0); 
    Ponto origem = {500, 999};
    Ponto centro = {500, 500};
    float sx = 7, sy = 7;
    int angulo = 30;                 
    draw_image_with_colors(origem, 255, 0, 0, centro, sx, sy, angulo);
    save_image();
    return 0;
}

/*gcc implementacao.c -o image ------ ./image > output.ppm*/