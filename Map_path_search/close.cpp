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

ListNode* CLOSE::GetFront() {
    ListNode* a = head_;
    if (a == NULL) {
        return NULL;
    } else {
        return a;
    }
}

ListNode* CLOSE::GetBack() {
    ListNode* a = head_;
    if(a == NULL) {
        return NULL;
    }
    while (a->next != NULL) {
        a = a->next;
    }
    return a;
}

bool CLOSE::SearchElement(ListNode *element) {
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

bool CLOSE::operator == (CLOSE other) {
    if ((this->head_->coor_.first == other.head_->coor_.first) && (this->head_->coor_.second == other.head_->coor_.second)) {
        return true;
    } else {
        return false;
    }
}
