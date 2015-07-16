#ifndef OPEN_H
#define OPEN_H
#include "map.h"

struct Vertex { //  Node
    int f_value;
    std::pair<int, int> coor;
    Vertex* parent;
    Vertex* BackPointer(Vertex* a) const{
        return a->parent;
    }
};

struct ListNode_ {
    Vertex v;
    ListNode_* next;
    explicit ListNode_() : next(NULL) {};
    //explicit ListNode_ (std::pair<int, int> coor) : coor_(coor), next(NULL) {};
};

class OPEN {
    ListNode_ *head_;
public:
    OPEN();
    ~OPEN();
    void Push(ListNode_ *node);
    bool SearchElement(ListNode_ *element);
    ListNode_* GetFront();
};

#endif // OPEN_H
