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

#include <stdio.h>

int main(){
 
   // dimensoes da imagem
   int width = 256;
   int height = 256;
 
   // Configurando o header do formato PPM
  printf("P3\n %d \t %d\n 255\n", width, height);
 
//No laço de repetição, percorremos a largura e altura da imagem preenchendo as cores dos pixels.

/*
No final, ela tem um degradê horizontal e vertical:
Começa escura no canto superior esquerdo (0, 0, 63),
E vai ficando mais clara e colorida conforme aumenta para (255, 255, 63).
*/

  for (int i = 0; i < height; i++){ // Altura
    for (int j = 0; j < width; j++){ // Largura
       printf("%d \t %d \t %d \n", i, j, 63);
     }
   }
 
   return 0;
 }
 
