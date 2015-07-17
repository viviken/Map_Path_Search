#include "linkedlist.h"

LinkedList::LinkedList() {
    head_->next = NULL;
    /*head_->node->coor.first = -1;
    head_->node->coor.second = -1;
    head_->node->parent = NULL;
    head_->node->g_value = -1;
    head_->node->h_value = -1;*/
}

LinkedList::~LinkedList() {
    ListNode* head = GetFront();
    while (head != NULL) {
        ListNode* head0 = head->next;
        delete head;
        head = head0;
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

void LinkedList::PushSort(ListNode* nod) {
    std::cout << "1" << std::endl;
    ListNode *head = this->GetFront();
    if (head == NULL) {
        this->PushBack(nod);
    } else {
    std::cout << "2" << std::endl;
    std::cout << nod->coor.first << " " << nod->coor.second << std::endl;
    std::cout << nod->g_value << " " << nod->h_value;
    std::cout << "3" << std::endl;
    while (((head->next->g_value + head->next->h_value) <= (nod->g_value + nod->h_value)) && head->next != NULL) {
        std::cout << "a";
        head = head->next;
    }

    ListNode* a = head;
    ListNode* c = head->next;
    while ((head->coor != nod->coor) && (head != NULL)) {
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
}

bool LinkedList::SearchElement(ListNode *element) {
    ListNode* head = GetFront();
    while((head->coor != element->coor) && (head != NULL)) {
        head = head->next;
    }
    if((head->coor == element->coor) && (head != NULL)) {
        return true;
    } else {
        return false;
    }
}

ListNode* LinkedList::FindElement(ListNode *element) {
    ListNode* head = GetFront();
    while((head->coor != element->coor) && (head != NULL)) {
        head = head->next;
    }
    if((head->coor == element->coor) && (head != NULL)) {
        return head;
    } else return NULL;
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
