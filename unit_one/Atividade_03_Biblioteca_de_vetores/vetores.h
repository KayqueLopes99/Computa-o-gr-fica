#ifndef VETORES_H
#define VETORES_H

// Funções para vetores 3D
void vetor_3d(int x1, int y1, int z1, int x2, int y2, int z2);
void norma_vetor_3d(int x, int y, int z);
void deslocar_ponto_vetor_3d(int xp, int yp, int zp, int xv, int yv, int zv);
void soma_subtracao_vetores_3d(int x1, int y1, int z1, int x2, int y2, int z2, char *operacao);
void multiplicar_vetor_escalar_3d(int xv, int yv, int zv, int escalar);
void normalizar_vetor_3d(int xv, int yv, int zv);
void produto_escalar_3d(int x1, int y1, int z1, int x2, int y2, int z2);
void produto_vetorial_3d(int x1, int y1, int z1, int x2, int y2, int z2);

// Funções para vetores 2D
void vetor_2d(int x1, int y1, int x2, int y2);
void norma_vetor_2d(int x, int y);
void deslocar_ponto_vetor_2d(int xp, int yp, int xv, int yv);
void soma_subtracao_vetores_2d(int x1, int y1, int x2, int y2, char *operacao);
void multiplicar_vetor_escalar_2d(int xv, int yv, int escalar);
void normalizar_vetor_2d(int xv, int yv);
void produto_escalar_2d(int x1, int y1, int x2, int y2);
void produto_vetorial_2d(int x1, int y1, int x2, int y2);

#endif 
