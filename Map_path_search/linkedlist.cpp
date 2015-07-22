#include "linkedlist.h"

LinkedList::LinkedList() {
    head_ = NULL;
    /*head_->node->coor.first = -1;
    head_->node->coor.second = -1;
    head_->node->parent = NULL;
    head_->node->g_value = -1;
    head_->node->h_value = -1;*/
}

LinkedList::~LinkedList() {
    while (head_ != NULL) {
        ListNode* head0 = head_->next;
        delete head_;
        head_ = head0;
    }
}

void LinkedList::PushFront(ListNode node) {
    ListNode* tmp = new ListNode;
    tmp->coor = node.coor;
    tmp->g_value = node.g_value;
    tmp->h_value = node.h_value;
    tmp->parent = node.parent;
    tmp->next = head_;
    head_ = tmp;
}

void LinkedList::PushSort(ListNode nod) {
//    std::cout << "1" << std::endl;
    ListNode *head = head_;
    if (head == NULL) {
        this->PushFront(nod);
    } else {
//        std::cout << "2" << std::endl;
//        std::cout << nod.coor.first << " " << nod.coor.second << std::endl;
//        std::cout << nod.g_value << " " << nod.h_value;
//        std::cout << "3" << std::endl;
        while (head->next != NULL && ((head->next->g_value + head->next->h_value) <= (nod.g_value + nod.h_value))) {
//            std::cout << "a";
            head = head->next;
        }

//        std::cout << std::endl << "4" << std::endl;
        ListNode* a = head;
//        std::cout << std::endl << "5" << std::endl;
        ListNode* c = head->next;
//        std::cout << std::endl << "6" << std::endl;
        while ((head->coor != nod.coor) && (head != NULL)) {
//            std::cout << std::endl << "655" << std::endl;
            if (head->next != NULL) {
                head = head->next;
            } else {
                head = NULL;
                break;
            }
        }
//        std::cout << std::endl << "7" << std::endl;
        if (head == NULL) {
            ListNode* tmp = new ListNode;
            tmp->coor = nod.coor;
            tmp->g_value = nod.g_value;
            tmp->h_value = nod.h_value;
            tmp->parent = nod.parent;
            a->next = tmp;
            tmp->next = c;
        } else {
            ListNode* h = GetFront();
            while (h->next != head) h = h->next;
            ListNode* d = head->next;
            delete head;
            h->next = d;
            ListNode* tmp = new ListNode;
            tmp->coor = nod.coor;
            tmp->g_value = nod.g_value;
            tmp->h_value = nod.h_value;
            tmp->parent = nod.parent;
            a->next = tmp;
            tmp->next = c;
        }
    }
}

bool LinkedList::SearchElement(ListNode element) {
    ListNode* head = head_;
    if (head == NULL) return false;
    while((head->coor != element.coor) && (head != NULL)) {
        head = head->next;
    }
    if (head != NULL) {
        return true;
    } else {
        return false;
    }
}

ListNode LinkedList::FindElement(ListNode element) {
    ListNode* head = GetFront();
    ListNode h;
    while((head->coor != element.coor) && (head != NULL)) {
        head = head->next;
    }
    if((head->coor == element.coor) && (head != NULL)) {
        h.coor = head->coor;
        h.g_value = head->g_value;
        h.h_value = head->h_value;
        h.parent = head->parent;
        h.next = head->next;
        return h;
    } else return h;
}

ListNode LinkedList::GetFrontAndDelete() {
    ListNode* a = this->head_;
    if (a == NULL) {
        return *a;
    } else {
        this->head_ = a->next;
        ListNode* b = a;
        delete a;
        return *b;
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
