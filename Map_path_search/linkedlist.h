#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "map.h"

struct Node {
    long long int g_value;
    long long int h_value;
//    long long int f_value;
    std::pair<int, int> coor;
    Node* parent;
};

struct ListNode {
    Node* node;
    ListNode* next;
//    explicit ListNode() : next(NULL) {};
};

class LinkedList {
    ListNode *head_;
public:
    LinkedList();
    ~LinkedList();
    void PushBack(ListNode *nod);
    void PushSort(ListNode *nod);
    bool SearchElement(ListNode *element);
    ListNode* GetFront();
    ListNode* GetFrontAndDelete();
    ListNode* GetBack();
};

#endif // LINKEDLIST_H
