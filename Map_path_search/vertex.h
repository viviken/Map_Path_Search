#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
    int f_value;
    std::pair<int, int> coor;
    Vertex* parent;
public:
    Vertex();
    Vertex* BackPointer(Vertex* a);
    void CreateVertex(int f, int x, int y);
};

#endif // VERTEX_H
