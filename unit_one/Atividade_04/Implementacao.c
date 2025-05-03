#include <stdio.h>
#define HEIGHT 256
#define WIDTH 256
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

void draw_image_with_colors(Ponto origem,unsigned char r, unsigned char g, unsigned char b) {

    // Esse 40 vai ser tipo o aumento e diminuição. MUDA FUTURAMENTE

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
        {origem.x + 25, origem.y -20}

    };

    desenharLinha(porta[0], porta[1]);
    desenharLinha(porta[1], porta[3]);
    desenharLinha(porta[2], porta[3]);


    desenharLinha(base[0], base[1]);
    desenharLinha(base[1], base[2]);
    desenharLinha(base[2], base[3]);
    desenharLinha(base[3], base[0]);

    desenharLinha(teto[0], teto[1]);
    desenharLinha(teto[1], teto[2]);
    desenharLinha(teto[2], teto[0]);

    

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


// void inicia_escala(){

// }


int main(){
    initialize_image(0, 0, 0); 
    Ponto origem = {0, 255};
    draw_image_with_colors(origem, 255, 0, 0);


    saveImg(); 



    return 0;
}

/*gcc implementacao.c -o image ------ ./image > output.ppm*/