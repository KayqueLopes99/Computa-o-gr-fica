#include <stdio.h>
#include <math.h>
#include <string.h>
#include "vetores.h"
/*Calcula o vetor 3D entre dois pontos.*/
void vetor_3d(int x1, int y1, int z1, int x2, int y2, int z2) {
    int resultado_x = x2 - x1;
    int resultado_y = y2 - y1;
    int resultado_z = z2 - z1;

    printf("\033[32mO vetor 3D entre os pontos (%d, %d, %d) e (%d, %d, %d)\033[0m: <%d, %d, %d>.\n", 
           x1, y1, z1, x2, y2, z2, resultado_x, resultado_y, resultado_z);
}

/*Calcula o vetor 2D entre dois pontos.*/
void vetor_2d(int x1, int y1, int x2, int y2) {
    int resultado_x = x2 - x1;
    int resultado_y = y2 - y1;

    printf("\033[32mO vetor 2D entre os pontos (%d, %d) e (%d, %d)\033[0m: <%d, %d>.\n", 
           x1, y1, x2, y2, resultado_x, resultado_y);
}

/*Calcula a norma de um vetor 3D.*/
void norma_vetor_3d(int x, int y, int z) {
    int resultado_norma = (pow(x, 2) + pow(y, 2) + pow(z, 2));

    printf("\033[31mA norma do vetor 3D <%d, %d, %d>:\033[0m Raiz de %d\n", x, y, z, resultado_norma);
}

/*Calcula a norma de um vetor 2D.*/
void norma_vetor_2d(int x, int y) {
    int resultado_norma = (pow(x, 2) + pow(y, 2));

    printf("\033[31mA norma do vetor 2D <%d, %d>:\033[0m Raiz de %d\n", x, y, resultado_norma);
}

/*Desloca um ponto 3D usando um vetor.*/
void deslocar_ponto_vetor_3d(int xp, int yp, int zp, int xv, int yv, int zv) {
    int resultado_x = xp + xv;
    int resultado_y = yp + yv;
    int resultado_z = zp + zv;

    printf("\033[33mO deslocamento do ponto (%d, %d, %d) usando o vetor <%d, %d, %d>:\033[0m (%d, %d, %d)\n", 
           xp, yp, zp, xv, yv, zv, resultado_x, resultado_y, resultado_z);
}

/*Desloca um ponto 2D usando um vetor.*/
void deslocar_ponto_vetor_2d(int xp, int yp, int xv, int yv) {
    int resultado_x = xp + xv;
    int resultado_y = yp + yv;

    printf("\033[33mO deslocamento do ponto (%d, %d) usando o vetor <%d, %d>:\033[0m (%d, %d)\n", 
           xp, yp, xv, yv, resultado_x, resultado_y);
}

/*Realiza soma ou subtração entre vetores 3D.*/
void soma_subtracao_vetores_3d(int x1, int y1, int z1, int x2, int y2, int z2, char *operacao) {
    if (strcmp(operacao, "soma") == 0) {
        int resultado_x = x1 + x2;
        int resultado_y = y1 + y2;
        int resultado_z = z1 + z2;
        printf("\033[34mA soma entre os vetores <%d, %d, %d> e <%d, %d, %d>\033[0m: <%d, %d, %d>.\n",
               x1, y1, z1, x2, y2, z2, resultado_x, resultado_y, resultado_z);
    } else if (strcmp(operacao, "subtracao") == 0) {
        int resultado_x = x1 - x2;
        int resultado_y = y1 - y2;
        int resultado_z = z1 - z2;
        printf("\033[34mA subtracao entre os vetores <%d, %d, %d> e <%d, %d, %d>\033[0m: <%d, %d, %d>.\n",
               x1, y1, z1, x2, y2, z2, resultado_x, resultado_y, resultado_z);
    } else {
        printf("ERRO: Operacao nao correspondente.\n");
    }
}

/*Realiza soma ou subtração entre vetores 2D.*/
void soma_subtracao_vetores_2d(int x1, int y1, int x2, int y2, char *operacao) {
    if (strcmp(operacao, "soma") == 0) {
        int resultado_x = x1 + x2;
        int resultado_y = y1 + y2;
        printf("\033[34mA soma entre os vetores <%d, %d> e <%d, %d>\033[0m: <%d, %d>.\n",
               x1, y1, x2, y2, resultado_x, resultado_y);
    } else if (strcmp(operacao, "subtracao") == 0) {
        int resultado_x = x1 - x2;
        int resultado_y = y1 - y2;
        printf("\033[34mA subtracao entre os vetores <%d, %d> e <%d, %d>\033[0m: <%d, %d>.\n",
               x1, y1, x2, y2, resultado_x, resultado_y);
    } else {
        printf("ERRO: Operacao nao correspondente.\n");
    }
}

/*Multiplica vetor 3D por um escalar.*/
void multiplicar_vetor_escalar_3d(int xv, int yv, int zv, int escalar) {
    int resultado_x = xv * escalar;
    int resultado_y = yv * escalar;
    int resultado_z = zv * escalar;

    printf("\033[35mA multiplicacao do vetor <%d, %d, %d> pelo escalar %d\033[0m: <%d, %d, %d>.\n",
           xv, yv, zv, escalar, resultado_x, resultado_y, resultado_z);
}

/*Multiplica vetor 2D por um escalar.*/
void multiplicar_vetor_escalar_2d(int xv, int yv, int escalar) {
    int resultado_x = xv * escalar;
    int resultado_y = yv * escalar;

    printf("\033[35mA multiplicacao do vetor <%d, %d> pelo escalar %d\033[0m: <%d, %d>.\n",
           xv, yv, escalar, resultado_x, resultado_y);
}

/*Normaliza um vetor 3D, transformando-o em unitário.*/
void normalizar_vetor_3d(int xv, int yv, int zv) {
    int resultado_norma = (pow(xv, 2) + pow(yv, 2) + pow(zv, 2));
    printf("\033[35mA normalizacao do vetor <%d, %d, %d>\033[0m: <%d/raiz de %d, %d/raiz de %d, %d/raiz de %d>.\n",
           xv, yv, zv, xv, resultado_norma, yv, resultado_norma, zv, resultado_norma);
}

/*Normaliza um vetor 2D, transformando-o em unitário.*/
void normalizar_vetor_2d(int xv, int yv) {
    int resultado_norma = (pow(xv, 2) + pow(yv, 2));
    printf("\033[35mA normalizacao do vetor <%d, %d>\033[0m: <%d/raiz de %d, %d/raiz de %d>.\n",
           xv, yv, xv, resultado_norma, yv, resultado_norma);
}

/*Calcula o produto escalar entre vetores 3D.*/
void produto_escalar_3d(int x1, int y1, int z1, int x2, int y2, int z2) {
    int resultado = (x2 * x1) + (y2 * y1) + (z2 * z1);
    printf("\033[36mO produto escalar entre <%d, %d, %d> e <%d, %d, %d>\033[0m: %d.\n",
           x1, y1, z1, x2, y2, z2, resultado);
}

/*Calcula o produto escalar entre vetores 2D.*/
void produto_escalar_2d(int x1, int y1, int x2, int y2) {
    int resultado = (x2 * x1) + (y2 * y1);
    printf("\033[36mO produto escalar entre <%d, %d> e <%d, %d>\033[0m: %d.\n",
           x1, y1, x2, y2, resultado);
}

/*Calcula o produto vetorial entre vetores 3D.*/
void produto_vetorial_3d(int x1, int y1, int z1, int x2, int y2, int z2) {
    int resultado_x = y1 * z2 - z1 * y2;
    int resultado_y = z1 * x2 - x1 * z2;
    int resultado_z = x1 * y2 - y1 * x2;

    printf("\033[1;31mO produto vetorial entre <%d, %d, %d> e <%d, %d, %d>\033[0m: <%d, %d, %d>\n",
           x1, y1, z1, x2, y2, z2, resultado_x, resultado_y, resultado_z);
}

/*Calcula o produto vetorial (escalar) entre vetores 2D.*/
void produto_vetorial_2d(int x1, int y1, int x2, int y2) {
    int z1 = 0;
    int z2 = 0; 
    
    // como os pontos são (x, y) o vetor resultante será (0,0,zk)
    int resultado_x = y1 * z2 - z1 * y2;
    int resultado_y = z1 * x2 - x1 * z2;
    int resultado_z = x1 * y2 - y1 * x2;   
    printf("\033[1;31mO produto vetorial (escalar) entre <%d, %d> e <%d, %d>\033[0m: <%d , %d, %d>\n", x1, y1, x2, y2, resultado_x, resultado_y, resultado_z);
}
