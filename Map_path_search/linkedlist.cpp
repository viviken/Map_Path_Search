#include "linkedlist.h"

LinkedList::LinkedList() {
    head_->next = NULL;
    head_->node->coor = std::make_pair(-1, -1);
    head_->node->parent = NULL;
    head_->node->g_value = -1;
    head_->node->h_value = -1;
}

LinkedList::~LinkedList() {
    ListNode* head = GetFront();
    while (head != NULL) {
        ListNode* head0 = head;
        delete head;
        head = head0->next;
    }
}

void LinkedList::PushBack(ListNode *nod) {
    ListNode *back = GetBack();
    if (back != NULL) {
        back->next = nod;
    } else {
        head_ = nod;
    }
}

void LinkedList::PushSort(ListNode *nod) {
    ListNode *head = GetFront();
    while ((head->next->node->g_value + head->next->node->h_value) >= (nod->node->g_value + nod->node->h_value)) {
        head = head->next;
    }
    ListNode* a = head;
    ListNode* c = head->next;
    while ((head->node->coor != nod->node->coor) && (head != NULL)) {
        head = head->next;
    }
    if (head == NULL) {
        a->next = nod;
        nod->next = c;
    } else {
        ListNode* h = GetFront();
        while (h->next != head) h = h->next;
        ListNode* d = head->next;
        delete head;
        h->next = d;
        a->next = nod;
        nod->next = c;
    }
}

bool LinkedList::SearchElement(ListNode *element) {
    ListNode* head = GetFront();
    while((head->node->coor != element->node->coor) && (head != NULL)) {
        head = head->next;
    }
    if((head->node->coor == element->node->coor) && (head != NULL)) {
        return true;
    } else {
        return false;
    }
}

ListNode* LinkedList::FindElement(ListNode *element) {
    ListNode* head = GetFront();
    while((head->node->coor != element->node->coor) && (head != NULL)) {
        head = head->next;
    }
    if((head->node->coor == element->node->coor) && (head != NULL)) {
        return head;
    }
}

ListNode *LinkedList::GetFrontAndDelete() {
    ListNode* a = this->head_;
    if (a == NULL) {
        return NULL;
    } else {
        this->head_ = a->next;
        ListNode* b = a;
        delete a;
        return b;
    }
}


ListNode* LinkedList::GetFront() {
    ListNode* a = head_;
    if (a == NULL) {
        return NULL;
    } else {
        return a;
    }
}

ListNode* LinkedList::GetBack() {
    ListNode* a = head_;
    if(a == NULL) {
        return NULL;
    }
    while (a->next != NULL) {
        a = a->next;
    }
    return a;
}
