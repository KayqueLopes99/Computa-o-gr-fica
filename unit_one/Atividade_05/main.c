#include "implementacao.h"

int main()
{
    initialize_image(0, 0, 0);
    Ponto origem = {750, 250};
    Ponto centro = {500, 500};
    float sx = 4, sy = 4;
    int angulo = -30;
    int s_x = 1;
    draw_image_with_colors(origem, 255, 0, 0, centro, sx, sy, angulo, s_x);
    save_image();
    return 0;
}

/*gcc implementacao.c -o image ------ ./image > output.ppm*/