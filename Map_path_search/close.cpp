#include "close.h"

CLOSE::CLOSE() {
    head_ = NULL;
}

CLOSE::~CLOSE() {
    ListNode *curNode = head_;
    while (curNode != NULL) {
        ListNode *tmpNode = curNode;
        curNode = curNode->next;
        delete tmpNode;
    }
}

void CLOSE::PushBack(ListNode *node) {
    ListNode *back = GetBack();
    if (back != NULL) {
        back->next = node;
    } else {
        head_ = node;
    }
}

ListNode* CLOSE::GetFront() const {
    ListNode* a = head_;
    if (a == NULL) {
        return NULL;
    } else {
        return a;
    }
}

ListNode* CLOSE::GetBack() const {
    ListNode* a = head_;
    if(a == NULL) {
        return NULL;
    }
    while (a->next != NULL) {
        a = a->next;
    }
    return a;
}

bool CLOSE::SearchElement(ListNode *element) const {
    ListNode* head = GetFront();
    while((head != element) && (head != NULL)) {
        head = head->next;
    }
    if((head == element) && (head != NULL)) {
        return true;
    } else {
        return false;
    }
}

bool CLOSE::operator == (ListNode other) {
    if ((this->coor_.first == other.coor_.first) && (this->coor_.second == other.coor_.second)) {
        return true;
    } else {
        return false;
    }
}
