## Computação Gráfica
- CG é uma área da computação dedicada a criação, armazenamento e manipulação de imagens baseada em modelos matemáticos.

![imagem](img\image.png)

## Lecture 1
- Iniciaremos nosso curso aprendendo como construir uma imagem
- Portable Pixel Map (PPM)
- O formato PPM nasceu no final da década de 80 para compartilhar imagens facilmente entre diferentes plataformas.

![imagem](img\1.png)

## Código
- Podemos escrever um código em C para construir uma imagem usando o formato PPM. 
- objetivo será alcançado através da análise do programa ppm_create.c.
Claro! Aqui está a organização das anotações em formato Markdown (`.md`), com explicações estruturadas e o exercício formatado de forma clara:

```markdown
# Construção de Imagens com Formato PPM em C

## Visão Geral

Podemos escrever um código em C para construir uma imagem no formato **PPM**. Abaixo está um exemplo básico de programa (`ppm_create.c`) que gera uma imagem utilizando esse formato.

### Exemplo de Código: `ppm_create.c`

```c
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

  for (int i = 0; i < height; i++){ // Altura
    for (int j = 0; j < width; j++){ // Largura
      printf("%d \t %d \t %d \n", i, j, 63);
    }
  }

  return 0;
}
```

## Explicação do Programa

- Inclusão da biblioteca padrão de entrada e saída:
  ```c
  #include <stdio.h>
  ```

- Definição das dimensões da imagem:
  ```c
  int width = 256;
  int height = 256;
  ```

- Impressão do cabeçalho PPM (formato P3, largura, altura e valor máximo de cor):
  ```c
  printf("P3\n %d \t %d\n 255\n", width, height);
  ```

- Laços `for` que percorrem cada pixel da imagem preenchendo com valores RGB:
  ```c
  for (int i = 0; i < height; i++){
      for (int j = 0; j < width; j++){
          printf("%d \t %d \t %d \n", i, j, 63);
      }
  }
  ```

## Compilação
Utilize o comando abaixo para compilar o código com o GCC:

```bash
gcc ppm_create.c -o ppm_create
```

Gere o arquivo PPM com a saída redirecionada:

```bash
./ppm_create > output.ppm
```

---

## Exercício

### Objetivo

1. Construa uma imagem **256x256** com fundo preto e **apenas 1 pixel vermelho no centro**.
2. Implemente uma **função para alterar o valor de um pixel**.
3. Codifique uma **função que salva a imagem no formato PPM**.
4. Crie uma **função que inicializa a imagem com fundo branco**.
5. Construa uma imagem **com fundo preto** e escreva a letra **'T'** em **alto contraste** no centro.



