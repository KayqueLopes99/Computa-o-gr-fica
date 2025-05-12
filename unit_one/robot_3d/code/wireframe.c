#include "model.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Cria ponteiros para armazenar os vértices e faces do modelo .obj, e contadores para cada um.
    Vertex *vertices = NULL;
    Face *faces = NULL;
    int vcount = 0, fcount = 0;

    clr(); 

    if (!load_obj("models/robot.obj", &vertices, &vcount, &faces, &fcount))
    {
        printf("Erro ao carregar o OBJ\n");
        return 1;
    }

    // Desenha as faces do modelo na imagem
    render_faces(vertices, faces, vcount, fcount);

    //render_point_cloud(vertices, vcount);


    save();

    free(vertices);
    free(faces);

    return 0;
}
// gcc wireframe.c model.c -o imageff -lm
// ./imageff