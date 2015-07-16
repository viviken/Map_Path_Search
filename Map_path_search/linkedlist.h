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
    bool operator = (ListNode* other) {
        this->node->coor = other->node->coor;
        this->node->g_value = other->node->g_value;
        this->node->parent = other->node->parent;
        this->next = other->next;
    }
};


class LinkedList {
    ListNode *head_;
public:
    LinkedList();
    ~LinkedList();
    void PushBack(ListNode *nod);
    void PushSort(ListNode *nod);
    bool SearchElement(ListNode *element);
    ListNode* FindElement(ListNode *element);
    ListNode* GetFront();
    ListNode* GetFrontAndDelete();
    ListNode* GetBack();
//    bool operator =(ListNode* other);
};

#endif // LINKEDLIST_H
