#include <stdio.h>
#include <math.h>
#include <string.h>



void vetor_3d(int x1, int y1, int z1, int x2, int y2, int z2){
    int x_result = x2 - x1;
    int y_result = y2 - y1;
    int z_result = z2 - z1;

    printf("\033[32mO vetor 3D entre os pontos (%d, %d, %d) e (%d, %d, %d)\033[0m: <%d, %d, %d>.\n", x1, y1, z1, x2, y2, z2, x_result, y_result, z_result);    


}

void vetor_2d(int x1, int y1, int x2, int y2){
    int x_result = x2 - x1;
    int y_result = y2 - y1;

    printf("\033[32mO vetor 2D entre os pontos (%d, %d) e (%d, %d)\033[0m: <%d, %d>.\n", x1, y1, x2, y2, x_result, y_result);    

    return;

}

void norma_do_vetor_3d(int x1, int y1, int z1){
    int norma_result = (pow(x1, 2) + pow(y1, 2)+ pow(z1, 2));

    printf("\033[31mA norma do vetor 3D <%d, %d, %d>:\033[0m Raiz de %d\n",x1, y1, z1, norma_result);

}

void norma_do_vetor_2d(int x1, int y1){
    int norma_result = (pow(x1, 2) + pow(y1, 2));

    printf("\033[31mA norma do vetor 2D <%d, %d>:\033[0m Raiz de %d\n", x1, y1, norma_result);
}

void deslocamento_do_ponto_usando_vetor_3d(int xp, int yp, int zp, int xv, int yv, int zv){
    int x_result = xp + xv;
    int y_result = yp + yv;
    int z_result = zp + zv;

    printf("\033[33mO deslocamento de ponto (%d, %d, %d) no espaco atraves de um vetor <%d, %d, %d>:\033[0m: (%d, %d, %d)\n",xp, yp, zp, xv, yv, zv, x_result, y_result, z_result);



}

void deslocamento_do_ponto_usando_vetor_2d(int xp, int yp, int xv, int yv){
    int x_result = xp + xv;
    int y_result = yp + yv;

    printf("\033[33mO deslocamento de ponto (%d, %d) no espaco atraves de um vetor <%d, %d>:\033[0m: (%d, %d)\n",xp, yp, xv, yv, x_result, y_result);



}

void soma_e_subtracao_de_vetores_3d(int x1, int y1, int z1, int x2, int y2, int z2, char *operacao) {
    if (strcmp(operacao, "soma") == 0) {
        int x_result = x1 + x2;
        int y_result = y1 + y2;
        int z_result = z1 + z2;
        printf("\033[34mA Soma entre os vetores <%d, %d, %d> e <%d, %d, %d>\033[0m: <%d, %d, %d>.\n", x1, y1, z1, x2, y2, z2, x_result, y_result, z_result);
    } else if (strcmp(operacao, "subtracao") == 0) {
        int x_result = x1 - x2;
        int y_result = y1 - y2;
        int z_result = z1 - z2;
        printf("\033[34mA Subtracao entre os vetores <%d, %d, %d> e <%d, %d, %d>\033[0m: <%d, %d, %d>.\n", x1, y1, z1, x2, y2, z2, x_result, y_result, z_result);
    } else {
        printf("ERRO: Operação não correspondente.\n");
    }
}

void soma_e_subtracao_de_vetores_2d(int x1, int y1, int x2, int y2, char *operacao) {
    if (strcmp(operacao, "soma") == 0) {
        int x_result = x1 + x2;
        int y_result = y1 + y2;
        printf("\033[34mA Soma entre os vetores <%d, %d> e <%d, %d>\033[0m: <%d, %d>.\n", x1, y1, x2, y2, x_result, y_result);
    } else if (strcmp(operacao, "subtracao") == 0) {
        int x_result = x1 - x2;
        int y_result = y1 - y2;
        printf("\033[34mA Subtracao entre os vetores <%d, %d> e <%d, %d>\033[0m: <%d, %d>.\n", x1, y1, x2, y2, x_result, y_result);
    } else {
        printf("ERRO: Operação não correspondente.\n");
    }
}

void multiplicacao_por_escalar_3d(int xv, int yv, int zv, int escalar){
    int x_result = xv * escalar;
    int y_result = yv * escalar;
    int z_result = zv * escalar;

    printf("\033[35mA Multilicacao do vetor <%d, %d, %d> pelo escalar %d\033[0m: <%d, %d, %d>.\n", xv, yv, zv, escalar, x_result, y_result, z_result);
}

void multiplicacao_por_escalar_2d(int xv, int yv, int escalar){
    int x_result = xv * escalar;
    int y_result = yv * escalar;

    printf("\033[35mA Multilicacao do vetor <%d, %d> pelo escalar %d\033[0m: <%d, %d>.\n", xv, yv, escalar, x_result, y_result);
}

void normalizacao_e_transformacao_em_vator_unitario_3d(int xv, int yv, int zv){
    int norma_result = (pow(xv, 2) + pow(yv, 2)+ pow(zv, 2));
    printf("\033[35mA Normalizacao ou Transformacao do vetor <%d, %d, %d> em unitario\033[0m: <%d/raiz de %d, %d/raiz de %d, %d/raiz de %d>.\n", xv, yv, zv, xv, norma_result, yv, norma_result, zv, norma_result);

}

void normalizacao_e_transformacao_em_vator_unitario_2d(int xv, int yv){
    int norma_result = (pow(xv, 2) + pow(yv, 2));

    printf("\033[35mA Normalizacao ou Transformacao do vetor <%d, %d> em unitario\033[0m: <%d/raiz de %d, %d/raiz de %d>.\n", xv, yv, xv, norma_result, yv, norma_result);

}

void produto_escalar_entre_vetores_3d(int x1, int y1, int z1, int x2, int y2, int z2){
    int result_the_operation = ((x2 * x1) + (y2 * y1) + (z2 * z1));
   
    printf("\033[36mO produto escalar entre os vetores <%d, %d, %d> e <%d, %d, %d>\033[0m: %d.\n", x1, y1, z1, x2, y2, z2, result_the_operation);
}

void produto_escalar_entre_vetores_2d(int x1, int y1, int x2, int y2){
    int result_the_operation = ((x2 * x1) + (y2 * y1) );
    printf("\033[36mO produto escalar entre os vetores <%d, %d> e <%d, %d>\033[0m: %d.\n", x1, y1, x2, y2, result_the_operation);
}


void cor(){
    printf("\033[31mTexto em vermelho\033[0m\n");
    printf("\033[32mTexto em verde\033[0m\n");
    printf("\033[33mTexto em amarelo\033[0m\n");
    printf("\033[34mTexto em azul\033[0m\n");
    printf("\033[1;35mTexto em magenta negrito\033[0m\n");
    printf("\033[1;36mTexto em ciano negrito\033[0m\n");
    printf("\033[1;30mTexto em preto negrito\033[0m\n");
    printf("\033[1;31mTexto em vermelho negrito\033[0m\n");
}


int main(){
    // Questão 1
    printf("\033[1;30mQuestao 1\033[0m\n");
    vetor_2d(2, 4, 6, 2);
    vetor_2d(6, 7, -1, -2);
    vetor_3d(2, 2, 4, 1, 1, 1);
    vetor_3d(-2, 4, -5, 5, 2, -5);
    

    // Questão 2
    printf("\033[1;30mQuestao 2\033[0m\n");
    norma_do_vetor_2d(2, -5);
    norma_do_vetor_2d(4, 2);
    norma_do_vetor_3d(3, 5, -6);
    norma_do_vetor_3d(6, -2, 1);

    // Questão 3
    printf("\033[1;30mQuestao 3\033[0m\n");
    deslocamento_do_ponto_usando_vetor_2d(2, -5, 2, 4);
    deslocamento_do_ponto_usando_vetor_3d(3, 5, -6, -3, 2, -3);

    // Questão 4
    printf("\033[1;30mQuestao 4\033[0m\n");
    soma_e_subtracao_de_vetores_2d(2, -5, 2, 4, "soma");
    soma_e_subtracao_de_vetores_2d(3, 2, 1, 7, "subtracao");
    soma_e_subtracao_de_vetores_3d(3, 5, -6, -3, 2, -3, "soma");
    soma_e_subtracao_de_vetores_3d(5, 5, 1, 3, 1, 7, "subtracao");

    // Questão 5
    printf("\033[1;30mQuestao 5\033[0m\n");
    multiplicacao_por_escalar_2d(2, 4, 3);
    multiplicacao_por_escalar_3d(1, 7, 5, -5);
    normalizacao_e_transformacao_em_vator_unitario_2d(12, 3);
    normalizacao_e_transformacao_em_vator_unitario_3d(-3,4,-5);

    // Questão 6
    printf("\033[1;30mQuestao 6\033[0m\n");
    produto_escalar_entre_vetores_2d(2, -4, 5, 3);
    produto_escalar_entre_vetores_3d(1, 7, 5, 2, 4, 5);

    // Obs: Estas duas ultimas questões seguem a mesma lógica que a anterior.
    normalizacao_e_transformacao_em_vator_unitario_2d(12, 3);
    normalizacao_e_transformacao_em_vator_unitario_3d(-3,4,-5);


    return -1;
}