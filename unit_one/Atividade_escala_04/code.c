#include <stdio.h>
#include <math.h>
#define HEIGHT 256
#define WIDTH 256
#define PI 3.14159265358979323846


unsigned char image[HEIGHT][WIDTH][3]; // [linha][coluna][RGB]





typedef struct {
    float x, y;
} Ponto;

void initialize_image(int r, int g, int b) {
    /*Função para inicializar a imagem ppm, pintando com a cor atribuida*/
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j][0] = r;
            image[i][j][1] = g;
            image[i][j][2] = b;
        }
    }

}

void saveImg(){
    printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);  
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d %d %d ", image[i][j][0], image[i][j][1], image[i][j][2]);
        }
        printf("\n");
    }
}

void setpixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        image[y][x][0] = r;
        image[y][x][1] = g;
        image[y][x][2] = b;
    }
}

void drawLine (int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b){
    for (float t = 0.0; t<1; t = t+0.0001){
        setpixel((int)(x2 -x1)*t+x1,(int) (y2-y1)*t+y1, r,g,b );
    }

}

void desenharLinha(Ponto p1, Ponto p2) {
     drawLine(p1.x, p1.y, p2.x, p2.y, 255, 0, 0); 
 }


Ponto aplicar_escala(Ponto p, Ponto centro, float sx, float sy){
    Ponto result;

    // Translada para origem
    float x = p.x - centro.x;
    float y = p.y - centro.y;

    // Aplica escala
    float x1 = sx * x;
    float y1 = sy * y;

    // Translada de volta
    result.x = x1 + centro.x;
    result.y = y1 + centro.y;

    return result;

}



void draw_image_with_colors(Ponto origem, unsigned char r, unsigned char g, unsigned char b, Ponto centro, float sx, float sy) {
    Ponto base[4] = {
        {origem.x, origem.y},
        {origem.x + 40, origem.y},
        {origem.x + 40, origem.y - 40},
        {origem.x, origem.y - 40}
    };

    Ponto teto[3] = {
        {origem.x, origem.y - 40},
        {origem.x + 20, origem.y - 60},
        {origem.x + 40, origem.y - 40}
    };

    Ponto porta[4] = {
        {origem.x + 15, origem.y},
        {origem.x + 15, origem.y - 20},
        {origem.x + 25, origem.y},
        {origem.x + 25, origem.y - 20}
    };

    // Aplica a escala em cada ponto
    for (int i = 0; i < 4; i++) {
        base[i] = aplicar_escala(base[i], centro, sx, sy);
    }
    for (int i = 0; i < 3; i++) {
        teto[i] = aplicar_escala(teto[i], centro, sx, sy);
    }
    for (int i = 0; i < 4; i++) {
        porta[i] = aplicar_escala(porta[i], centro, sx, sy);
    }

    // Após aplicar a escala, ajusta a origem para sempre começar em (0, 255)
    float offsetX = origem.x - base[0].x;
    float offsetY = origem.y - base[0].y;

    // Desenha a casa com as coordenadas ajustadas pela origem (0, 255)
    for (int i = 0; i < 4; i++) {
        base[i].x += offsetX;
        base[i].y += offsetY;
    }
    for (int i = 0; i < 3; i++) {
        teto[i].x += offsetX;
        teto[i].y += offsetY;
    }
    for (int i = 0; i < 4; i++) {
        porta[i].x += offsetX;
        porta[i].y += offsetY;
    }

    // Desenha a porta
    desenharLinha(porta[0], porta[1]);
    desenharLinha(porta[1], porta[3]);
    desenharLinha(porta[2], porta[3]);

    // Desenha a base
    desenharLinha(base[0], base[1]);
    desenharLinha(base[1], base[2]);
    desenharLinha(base[2], base[3]);
    desenharLinha(base[3], base[0]);

    // Desenha o teto
    desenharLinha(teto[0], teto[1]);
    desenharLinha(teto[1], teto[2]);
    desenharLinha(teto[2], teto[0]);
}


Ponto rotation(Ponto p, Ponto centro, int angulo){
    Ponto result;
    float rad = angulo * PI / 180.0;


    // Translada para origem
    float x = p.x - centro.x;
    float y = p.y - centro.y;

    // Aplica a rotação
    float x1 = cos(rad) * x - sin(rad) * y;
    float y1 = sin(rad) * x + cos(rad) * y;

    // Translada de volta
    result.x = x1 + centro.x;
    result.y = y1 + centro.y;

    return result;

}














int main(){
    initialize_image(255, 255, 255); // fundo branco
    
    Ponto origem = {0, 255};
    Ponto centro = {128, 128};
    float sx = 3, sy = 3; // escalas para x e y

    draw_image_with_colors(origem, 255, 0, 0, centro, sx, sy);
    saveImg(); 
    return 0;
}

/*gcc implementacao.c -o image ------ ./image > output.ppm*/