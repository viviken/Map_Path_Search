#ifndef CLOSE_H
#define CLOSE_H
#include <iostream>

struct ListNode {
    std::pair<int, int> coor_;
    ListNode* next;
    explicit ListNode() : next(NULL) {};
    explicit ListNode (std::pair<int, int> coor) : coor_(coor), next(NULL) {};
};

class CLOSE {
    ListNode *head_;
public:
    CLOSE();
    ~CLOSE();
    void PushBack(ListNode *node);
    bool SearchElement(ListNode *element) const;
    ListNode* GetFront() const;
    ListNode* GetBack() const;
    bool operator == (ListNode other);
};

#endif // CLOSE_H
