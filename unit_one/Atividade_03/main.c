#include <stdio.h>
#include "vetores.h"


int main() {
    // Questão 1
    printf("\033[1;30mQuestao 1\033[0m\n");
    vetor_2d(2, 4, 6, 2);
    vetor_2d(6, 7, -1, -2);
    vetor_3d(2, 2, 4, 1, 1, 1);
    vetor_3d(-2, 4, -5, 5, 2, -5);

    // Questão 2
    printf("\033[1;30mQuestao 2\033[0m\n");
    norma_vetor_2d(2, -5);
    norma_vetor_2d(4, 2);
    norma_vetor_3d(3, 5, -6);
    norma_vetor_3d(6, -2, 1);

    // Questão 3
    printf("\033[1;30mQuestao 3\033[0m\n");
    deslocar_ponto_vetor_2d(2, -5, 2, 4);
    deslocar_ponto_vetor_3d(3, 5, -6, -3, 2, -3);

    // Questão 4
    printf("\033[1;30mQuestao 4\033[0m\n");
    soma_subtracao_vetores_2d(2, -5, 2, 4, "soma");
    soma_subtracao_vetores_2d(3, 2, 1, 7, "subtracao");
    soma_subtracao_vetores_3d(3, 5, -6, -3, 2, -3, "soma");
    soma_subtracao_vetores_3d(5, 5, 1, 3, 1, 7, "subtracao");

    // Questão 5
    printf("\033[1;30mQuestao 5\033[0m\n");
    multiplicar_vetor_escalar_2d(2, 4, 3);
    multiplicar_vetor_escalar_3d(1, 7, 5, -5);
    normalizar_vetor_2d(12, 3);
    normalizar_vetor_3d(-3, 4, -5);

    // Questão 6
    printf("\033[1;30mQuestao 6\033[0m\n");
    produto_escalar_2d(2, -4, 5, 3);
    produto_escalar_3d(1, 7, 5, 2, 4, 5);

    // Obs: Estas duas últimas questões seguem a mesma lógica que a anterior.
    normalizar_vetor_2d(12, 3);
    normalizar_vetor_3d(-3, 4, -5);

    // Questão 7
    printf("\033[1;30mQuestao 7\033[0m\n");
    produto_vetorial_2d(2, -4, 5, 3);
    produto_vetorial_3d(1, 7, 5, 2, 4, 5);

    return 0;
}

// compilação: gcc main.c funcoes_vetoriais.c -o programa  ./programa
