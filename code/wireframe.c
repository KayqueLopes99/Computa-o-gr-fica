/**
 * \file wireframe.c
 *
 * \brief Implementação do arquivo principal de renderização do modelo 3D.
 *
 * \author
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Engenharias e Tecnologia \n
 * petrucio at ufersa (dot) edu (dot) br
 *
 * \version 1.0
 * \date May 2025
 */

#include "model.h"
#include <stdio.h>
int main()
{
    printf("Iniciando o programa...\n");
    Vertex vertices[MAX_VERTICES];
    Face faces[MAX_FACES];
    int vcount, fcount;
    set_pixel(100, 100, 255, 0, 0); // Um pixel vermelho

    clr();

    // Lê o arquivo OBJ enviado
    printf("Iniciando o programa...\n");

    if (!load_obj("models/wolf.obj", vertices, &vcount, faces, &fcount))
    {
        printf("Erro ao carregar o OBJ\n");
        return 1;
    }

    printf("Modelo carregado: %d vértices, %d faces\n", vcount, fcount);

    clr();
    render_faces(vertices, faces, vcount, fcount);

    printf("Renderização finalizada.\n");

    save();

    return 0;
}