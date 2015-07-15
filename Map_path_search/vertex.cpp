#include "vertex.h"

Vertex::Vertex(){}

Vertex* Vertex::BackPointer(Vertex *a) {
    return a->parent;
}

void Vertex::CreateVertex(int f, int x, int y) {
    coor.first = x;
    coor.second = y;
    f_value = f;
}
