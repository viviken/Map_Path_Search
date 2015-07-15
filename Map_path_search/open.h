#ifndef OPEN_H
#define OPEN_H
#include "map.h"

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
    bool SearchElement(ListNode_ *element) const;
    ListNode_* GetFront() const;
};

#endif // OPEN_H
