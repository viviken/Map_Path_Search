#include "open.h"

OPEN::OPEN() {
    head_ = NULL;
}

OPEN::~OPEN() {
    ListNode_ *curNode = head_;
    while (curNode != NULL) {
        ListNode_ *tmpNode = curNode;
        curNode = curNode->next;
        delete tmpNode;
    }
}
// Доделать PUSH.
void OPEN::Push(ListNode_ *node) {
    ListNode_ *head = GetFront();
    while (head->next->v.f_value > node->v.f_value) {
        head = head->next;
    }
    ListNode_* elem = head;
    head->next = node;
    node->next = elem;
}

ListNode_* OPEN::GetFront() {
     ListNode_* a = head_;
    if (a == NULL) {
        return NULL;
    } else {
        return a;
    }
}

bool OPEN::SearchElement(ListNode_ *element) {
    ListNode_* head = GetFront();
    while((head != element) && (head != NULL)) {
        head = head->next;
    }
    if((head->v.coor.first == element->v.coor.first && head->v.coor.second == element->v.coor.second) && (head != NULL)) {
        return true;
    } else {
        return false;
    }
}
