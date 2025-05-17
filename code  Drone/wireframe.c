#include "model.h"
#include <stdio.h>

int main()
{
    printf("Iniciando o programa...\n");

    Vertex vertices[MAX_VERTICES];
    Face faces[MAX_FACES];
    int vcount, fcount;
    int angulo = 0;

    set_pixel(100, 100, 255, 0, 0); 
    clr();  

    if (!load_obj("models/drone.obj", vertices, &vcount, faces, &fcount))
    {
        printf("Erro ao carregar o OBJ\n");
        return 1;
    }

    printf("Modelo carregado: %d vertices, %d faces\n", vcount, fcount);

    Vertex centro = {0.0f, 0.0f, 0.0f}; 
    float sx = 0.5f, sy = 0.5f, sz = 0.5f; 

    apply_transformations(vertices, vcount, faces, fcount, centro, sx, sy, sz, 'z', angulo, 0);

    printf("Renderizacao finalizada.\n");

    save(); 

    return 0;
}

/* ##### DETALHES DO CÓDIGO: 
   - A transformação de Translação já está incluida na de escala e rotação. 
   - O restante se encontra nas funções
   - Compilação: 
   . 
*/