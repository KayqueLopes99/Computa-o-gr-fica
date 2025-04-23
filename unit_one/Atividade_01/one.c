/**
 * \file ppm_create.c
 *
 * \brief Criacao de uma imagem em PPM.
 *
 * \author
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Engenharias e Tecnologia \n
 * petrucio at ufersa (dot) edu (dot) br
 *
 * \version 1.0
 * \date April 2025
 */
// Construa uma imagem 1 0 0 × 1 0 0 usando o formato PPM com fundo preto que tem apenas 1 pixel vermelho no centro da imagem.
// Implemente uma função que altera o valor de um pixel da imagem.
// Crie uma função que inicializa uma imagem com branco.
// Codifique uma função que salva a imagem no formato PPM.
// Construa uma imagem 1 0 0 × 1 0 0 usando o formato PPM com fundo preto e escreva o caractere ' T ' no centro da imagem com alto contraste em relação ao fundo da imagem.
/*
Altura
1
2
37
...

Largura
1 2 3 ...
*/




#include <stdio.h>
#define WIDTH 100
#define HEIGHT 100

int image[HEIGHT][WIDTH][3]; // Array global altura e largura com 3 indices de  R, G, B para matriz da imagem.

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

void changes_value_pixel(int p1, int p2, int r, int g, int b) {
    /*Função para alterar um pixel especifico*/
    if (p1 >= 0 && p1 < HEIGHT && p2 >= 0 && p2 < WIDTH) {
        image[p1][p2][0] = r;
        image[p1][p2][1] = g;
        image[p1][p2][2] = b;
    } else {
        printf("ERRO: Posição inserida não correspondente!\n");
    }} 

void print_image_ppm() {
    /*Função que imprime a imagem ppm*/
        printf("P3\n %d \t %d\n 255\n", WIDTH, HEIGHT);
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {

                printf("%d \t %d \t %d \n", image[i][j][0], image[i][j][1], image[i][j][2]);
            }
        }
    }

void fuction_of_save_image_ppm(char *name_file){
    /*Função para Salvar Imagem PPM em Arquivo*/
        FILE *file = fopen(name_file, "w");
        if (file == NULL){
            printf("Erro ao criar o arquivo!\n");
            return;
        } 
    
        fprintf(file, "P3\n %d \t %d\n 255\n", WIDTH, HEIGHT);
    
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                fprintf(file, "%d %d %d\n", image[i][j][0], image[i][j][1], image[i][j][2]);
            }
        }
    
        fclose(file);
        printf("Imagem salva em '%s' com sucesso!\n", name_file);
    }

void draw_image_with_t(int r, int g, int b, int bar_width, int leg_height) {
    /*Função para centralização do T na imagem.=\*/
    
    initialize_image(0,0,0);

    // Coordenadas do centro
    int center_of_index_height_i = HEIGHT / 2;
    int center_of_index_width_j = WIDTH / 2;

    int start_bar = center_of_index_width_j - bar_width / 2; 
    int end_bar = center_of_index_width_j + bar_width / 2;

    // posiconando a barra (em cima / no inicio) da perna. 
    for (int j = start_bar; j <= end_bar; j++) {
        if (j >= 0 && j < WIDTH) {
            image[center_of_index_height_i - leg_height / 2][j][0] = r;
            image[center_of_index_height_i - leg_height / 2][j][1] = g;
            image[center_of_index_height_i - leg_height / 2][j][2] = b;
        }
    }


    int start_leg = center_of_index_height_i - leg_height / 2;
    int end_leg = center_of_index_height_i + leg_height / 2;


    for (int i = start_leg; i <= end_leg; i++) {
        if (i >= 0 && i < HEIGHT) {
            image[i][center_of_index_width_j][0] = r;
            image[i][center_of_index_width_j][1] = g;
            image[i][center_of_index_width_j][2] = b;
        }
    }





}

int main() {
    //initialize_image(255, 255, 255);  // Cria uma imagem inicial toda branco
    //changes_value_pixel(50, 50, 255, 255, 0);     // Muda a cor do pixel central para vermelho ou de qualquer outra posição

    draw_image_with_t(255, 255, 0, 10, 10); // Desenha o "T" amarelo
    print_image_ppm();
    fuction_of_save_image_ppm("imagem.ppm"); 
    return 0;
}
