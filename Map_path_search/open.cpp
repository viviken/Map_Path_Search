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
    ListNode *head = GetFront();
    while (head < node)
}

ListNode_* OPEN::GetFront() const {
    ListNode* a = head_;
    if (a == NULL) {
        return NULL;
    } else {
        return a;
    }
}

bool OPEN::SearchElement(ListNode_ *element) const {
    ListNode_* head = GetFront();
    while((head != element) && (head != NULL)) {
        head = head->next;
    }
    if((head == element) && (head != NULL)) {
        return true;
    } else {
        return false;
    }
}
