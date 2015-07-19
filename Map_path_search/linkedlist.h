#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "map.h"

/*
struct Node {
    long long int g_value;
    long long int h_value;
//    long long int f_value;
    std::pair<int, int> coor;
    Node* parent;
    Node() {
        g_value = -1;
        h_value = -1;
        coor = std::make_pair(-1, -1);
        parent = NULL;
    }
};*/

struct ListNode {
//    Node* node;
    long long int g_value;
    long long int h_value;
    std::pair<int, int> coor;
    ListNode* parent;
    ListNode* next;

//    explicit ListNode() : next(NULL) {};
    ListNode() {
        next = NULL;
        g_value = -1;
        h_value = -1;
        coor = std::make_pair(-1, -1);
        parent = NULL;
    }

    ListNode operator = (ListNode* other) {
        this->coor = other->coor;
        this->g_value = other->g_value;
        this->parent = other->parent;
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
