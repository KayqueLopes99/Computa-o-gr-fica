#include <stdio.h>
#define h 256
#define w 256

unsigned char img [h][w][3];
void setpixel (int x, int y, unsigned char r, unsigned char g, unsigned char b){
    img [x][y][0] = r;
    img [x][y][1] = g;
    img [x][y][2] = b;
}
void clearImg() {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            img[i][j][0] = 173;  // R
            img[i][j][1] = 216;  // G
            img[i][j][2] = 230;  // B
        }
}


void saveImg(){
    printf("P3\n%d %d\n255\n", w, h);  
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d %d %d ", img[i][j][0], img[i][j][1], img[i][j][2]);
        }
        printf("\n");
    }
}
void drawLine (int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b){
    for (float t = 0.0; t<1; t = t+0.0001){
        setpixel((int)(x2 -x1)*t+x1,(int) (y2-y1)*t+y1, r,g,b );

    }

}
void draw_image_with_colors(unsigned char r, unsigned char g, unsigned char b) {

    /* Considere as posições: (i Altura, j Largura)
        I(64,64)  |   II (64, 192)
       ---------------------------
       III(192,64)| IV (192,192)
    
    */
    
    
    int first_quadrant_center_i = h / 4;       
    int first_quadrant_center_j = w / 4;      

    int second_quadrant_center_i = h / 4;      
    int second_quadrant_center_j = w - w / 4;  

    int third_quadrant_center_i = h - h / 4;  
    int third_quadrant_center_j = w / 4;     
    
    int fourth_quadrant_center_i = h - h / 4;  
    int fourth_quadrant_center_j = w - w / 4; 

    // Desenhar linha horizontal entre o primeiro e segundo quadrante
    for (int j = first_quadrant_center_j; j <= second_quadrant_center_j; j++) {
        if (j >= 0 && j < w) {
            img[first_quadrant_center_i][j][0] = r; 
            img[first_quadrant_center_i][j][1] = g; 
            img[first_quadrant_center_i][j][2] = b; 
        }
    }
    
    // Desenhar linha vertical entre o primeiro e terceiro quadrante
    for (int i = first_quadrant_center_i; i <= third_quadrant_center_i; i++) {
        if (i >= 0 && i < h) {
            img[i][first_quadrant_center_j][0] = r; 
            img[i][first_quadrant_center_j][1] = g; 
            img[i][first_quadrant_center_j][2] = b; 
        }
    }

    // Desenhar linha horizontal entre o terceiro e quarto quadrante
    for (int j = third_quadrant_center_j; j <= fourth_quadrant_center_j; j++) {
        if (j >= 0 && j < h) {
            img[third_quadrant_center_i][j][0] = r; 
            img[third_quadrant_center_i][j][1] = g; 
            img[third_quadrant_center_i][j][2] = b; 
        }
    }

    // Desenhar linha vertical entre o segundo e quarto quadrante
    for (int i = second_quadrant_center_i; i <= fourth_quadrant_center_i; i++) {
        if (i >= 0 && i < h) {
            img[i][second_quadrant_center_j][0] = r; 
            img[i][second_quadrant_center_j][1] = g; 
            img[i][second_quadrant_center_j][2] = b; 
        }
    }

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (i >= 192){
            img[i][j][0] = 190;  // R
            img[i][j][1] = 255;  // G
            img[i][j][2] = 190;  // B
        }
    }

    // Telhado com linhas vermelhas de (64,j) a (0,128)
    drawLine(64, 64, 10, 128, 255, 0, 0);  
    drawLine(64, 192, 10, 128, 255, 0, 0);
    drawLine(64, 84, 10, 128, 255, 0, 0);
    drawLine(64, 104, 10, 128, 255, 0, 0);
    drawLine(64, 128, 10, 128, 255, 0, 0);
    drawLine(64, 152, 10, 128, 255, 0, 0);
    drawLine(64, 172, 10, 128, 255, 0, 0);

    // Desenhar a porta 
    int door_top_i = h / 2;   // Topo da po
    int door_base_i = h - 64;   // Base da imagem

    int door_left_j = w / 2 - 28;        // esquerda 
    int door_right_j = w / 2 + 28;       // direita

    // Topo
    for (int j = door_left_j; j <= door_right_j; j++) {
        if (j >= 0 && j < w) {
            img[door_top_i][j][0] = r;
            img[door_top_i][j][1] = g;
            img[door_top_i][j][2] = b;
        }
    }

    // Linha vertical esquerda da porta
    for (int i = door_top_i; i <= door_base_i; i++) {
        if (i >= 0 && i < h) {
            img[i][door_left_j][0] = r;
            img[i][door_left_j][1] = g;
            img[i][door_left_j][2] = b;
        }
    }

    // Linha vertical direita da porta
    for (int i = door_top_i; i <= door_base_i; i++) {
        if (i >= 0 && i < h) {
            img[i][door_right_j][0] = r;
            img[i][door_right_j][1] = g;
            img[i][door_right_j][2] = b;
        }
    }

    for (int j = 0; j <= 256; j++) {
        if (j >= 0 && j < w) {
            img[192][j][0] = r;
            img[192][j][1] = g;
            img[192][j][2] = b;
        }
    }
    







}
int main (void){
    clearImg();
    //drawLine((int) h/2,(int) w/2, h-1, w-1,255,0,0);
    draw_image_with_colors(255, 0, 0); 

    saveImg();

return -1;
}