## Transformações Geométricas e Geração de Imagem PPM com Desenho de Casa
- O código consiste na geração de uma imagem no formato PPM contendo o desenho de uma casa, construída a partir da definição de vértices e das arestas que os conectam. Em seguida, são aplicadas transformações geométricas, utilizando conceitos de álgebra linear, como transformações lineares de escala e rotação em relação a um ponto central definido.
## Objetivos
- Compreender a representação de imagens em formato PPM.
- Implementar transformações geométricas em imagens, como translação, escala e rotação.
- Aplicar conceitos de álgebra linear para manipulação de imagens.
- Interagir com o desenho da imagem manipulando os seus vértices e arestas.

## Funcionamento e Estrutura:
### Bibliotecas e definições
- Utiliza-se duas bibliotecas e definimos a altura (HEIGHT) e largura (WIDTH) da imagem. Além disso, definimos o valor de π com alta precisão e declaramos uma Matriz de pixels da imagem. Cada pixel tem 3 valores (RGB de 0 a 255). 
- Observação: estão localizadas no `implementacao.h`.
```c
#include <stdio.h>
#include <math.h>
#define HEIGHT 1000
#define WIDTH 1000
#define PI 3.14159265358979323846
unsigned char image[HEIGHT][WIDTH][3];

```
### Estrutura Ponto
- Representa um ponto 2D com coordenadas reais (float).
- Acesso: variável.x e variavel.y.
```c
typedef struct{
    float x, y;
} Ponto;
```
## Funções 
### **initialize_image**
- Função para inicializar a imagem ppm, pintando com a cor atribuida. 
```c
void initialize_image(int r, int g, int b);
```
### **saveimg**
- Imprime os dados no formato PPM (P3), que pode ser salvo como .ppm e visualizado com visualizadores de imagem.
```c
void save_image();
```

### **set_pixel**
- Desenhar um único pixel na imagem, atribuindo a ele uma cor RGB específica, desde que ele esteja dentro dos limites da imagem.
```c
void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
```

### **draw_line**
- Desenha uma linha reta entre dois pontos na imagem, utilizando a função set_pixel (ou setpixel) para colorir os pixels ao longo da linha.
- Usa o loop for para percorrer (de 0.0001 em 0.0001).
- float para precisão do ponto intermediário
- Para cada valor de t, ele calcula um pontinho entre o ponto inicial (x1, y1) e o final (x2, y2).
- Equação paramétrica de uma reta que liga dois pontos (x1 , y1) e (x2, y2), onde t varia de 0 inicio a 1 fim. 

```` md
x = (x2 - x1) * t + x1  
y = (y2 - y1) * t + y1
````


```c
void draw_line(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b);
/*
x1, y1: coordenadas do ponto inicial da linha.
x2, y2: coordenadas do ponto final da linha.

*/
```

### **start_drawing_lines**
- Desenha uma linha vermelha entre dois pontos do tipo Ponto.
- Ponto p1 e Ponto p2: São dois pontos dados como entrada da função. Cada ponto tem coordenadas x e y.

```c
void start_drawing_lines(Ponto p1, Ponto p2);
```

### **apply_scale**
- Aplica uma transformação de escala *a um ponto p fornecido*, em relação a um centro de escala (outro ponto), usando fatores de escala sx (horizontal) e sy (vertical).

- Transformação que aumenta ou diminui o tamanho de uma figura.

- Primeiro, a figura que está em um determinado local é transladada para que fique centralizada em relação a um ponto de referência (o centro). Em seguida, aplicamos a transformação de escala, aumentando ou diminuindo a figura em torno desse centro. Assim, a figura é transladada de volta para sua posição original, agora ajustada com o novo tamanho.
- Observação: ela faz isto em pontos. 

```c
Ponto apply_scale(Ponto p, Ponto centro, float sx, float sy);
```

### **rotation**
- Aplica uma transformação de rotação para um ponto `p` em torno de um centro de rotação `centro`, usando um ângulo (em graus).
- Primeiro, cada ponto da figura que está em um determinado local, é transladado de forma que fique centralizado em relação a um ponto de referência (o centro). Em seguida, aplicamos a transformação de rotação, ou seja, o ponto da figura é rotacionado em torno desse centro conforme o ângulo fornecido. Assim, pós rotação, o ponto é transladado de volta para sua posição original, mas agora com uma nova orientação angular.

```c
Ponto rotation(Ponto p, Ponto centro, int angulo);
```
### **reflection** e **shear**
- Aplica uma transformação de reflexão para um ponto `p` em relação a uma linha definida por dois pontos `p1` e `p2`.
- Cada ponto da figura que está em um determinado local, é transladado de forma que fique centralizado em relação a um ponto de referência (o centro).
- Assim desenhamos. 

- O cizalhamento (shear) é uma transformação geométrica que distorce a figura, fazendo com que ela pareça inclinada ou torcida.
- A variavel `s_x` representa o fator de cisalhamento na direção x.
- Exemplo: se `s_x` = 1, a figura é distorcida para a esquerda.
- Se `s_x` = -1, a figura é distorcida para a direita.

```c
Ponto reflection(Ponto p, Ponto p1, Ponto p2);
Ponto shear(Ponto p, float s_x);
```












### **draw_image_with_colors**
- Essa função é responsável por desenhar uma casa (formada por base, teto e porta) em uma imagem, com transformações geométricas aplicadas (escala e rotação), e depois ajustar sua posição de volta à origem desejada.

- A estrutura da figura:
``` md
>Base (4 pontos): um quadrado de 40x40 pixels.

>Teto (3 pontos): um triângulo que fica acima da base, simulando o telhado.

>Porta (4 pontos): um pequeno retângulo dentro da base.
```
- Definidos pelo fornecimento da variável ``Ponto origem``

- Aplicação das transformações: Escala (apply_scale) e Rotação (rotation), Cisalhamento (shear) e Reflexão (reflection).
- Reposicionamento para a origem desejada
- Esse deslocamento e reposionamento é adicionado a todos os pontos.
- Desenho das linhas (arestas) com start_drawing_lines(...)

``` c

void draw_image_with_colors(Ponto origem, unsigned char r, unsigned char g, unsigned char b, Ponto centro, float sx, float sy, int angulo, int s_x)
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
        base[i] = shear(base[i], s_x);
    }
    for (int i = 0; i < 3; i++)
    {
        teto[i] = apply_scale(teto[i], centro, sx, sy);
        teto[i] = rotation(teto[i], centro, angulo);
        teto[i] = shear(teto[i], s_x);

    }
    for (int i = 0; i < 4; i++)
    {
        porta[i] = apply_scale(porta[i], centro, sx, sy);
        porta[i] = rotation(porta[i], centro, angulo);
        porta[i] = shear(porta[i], s_x);

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

    

    // --- REFLEXÕES ---
    // 4. Gera reflexões com base na figura transformada
    Ponto base_y[4], teto_y[3], porta_y[4];
    Ponto base_x[4], teto_x[3], porta_x[4];
    Ponto base_o[4], teto_o[3], porta_o[4];


    for (int i = 0; i < 4; i++)
    {
        base_y[i] = reflection(base[i], -1, 1, centro);
        porta_y[i] = reflection(porta[i], -1, 1, centro);
        base_x[i] = reflection(base[i], 1, -1, centro);
        porta_x[i] = reflection(porta[i], 1, -1, centro);
        base_o[i] = reflection(base[i], -1, -1, centro);
        porta_o[i] = reflection(porta[i], -1, -1, centro);
    }

    for (int i = 0; i < 3; i++)
    {
        teto_y[i] = reflection(teto[i], -1, 1, centro);
        teto_x[i] = reflection(teto[i], 1, -1, centro);
        teto_o[i] = reflection(teto[i], -1, -1, centro);
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

   // 6. Desenha reflexões

    // Reflexão no eixo Y
    for (int i = 0; i < 4; i++) start_drawing_lines(base_y[i], base_y[(i + 1) % 4]);
    start_drawing_lines(teto_y[0], teto_y[1]);
    start_drawing_lines(teto_y[1], teto_y[2]);
    start_drawing_lines(teto_y[2], teto_y[0]);
    start_drawing_lines(porta_y[0], porta_y[1]);
    start_drawing_lines(porta_y[1], porta_y[3]);
    start_drawing_lines(porta_y[2], porta_y[3]);

    // Reflexão no eixo X
    for (int i = 0; i < 4; i++) start_drawing_lines(base_x[i], base_x[(i + 1) % 4]);
    start_drawing_lines(teto_x[0], teto_x[1]);
    start_drawing_lines(teto_x[1], teto_x[2]);
    start_drawing_lines(teto_x[2], teto_x[0]);
    start_drawing_lines(porta_x[0], porta_x[1]);
    start_drawing_lines(porta_x[1], porta_x[3]);
    start_drawing_lines(porta_x[2], porta_x[3]);

    // Reflexão na origem
    for (int i = 0; i < 4; i++) start_drawing_lines(base_o[i], base_o[(i + 1) % 4]);
    start_drawing_lines(teto_o[0], teto_o[1]);
    start_drawing_lines(teto_o[1], teto_o[2]);
    start_drawing_lines(teto_o[2], teto_o[0]);
    start_drawing_lines(porta_o[0], porta_o[1]);
    start_drawing_lines(porta_o[1], porta_o[3]);
    start_drawing_lines(porta_o[2], porta_o[3]);
}
```
## Compilação:
> gcc main.c implementacao.c -o image 
> ./image > output.ppm