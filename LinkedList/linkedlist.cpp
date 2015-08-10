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
    ListNode *head = GetFront();
    if (head == NULL) {
        this->PushFront(nod);
    } else {
/*        if (head->next == NULL) {
            if ((head->g_value + head->h_value) > (nod.g_value + nod.h_value)) {
                head_ = &nod;
                head_->next = head;
            } else {
                head_->next = &nod;
            }
        } else {
*/
//        std::cout << "2" << std::endl;
//        std::cout << nod.coor.first << " " << nod.coor.second << std::endl;
//        std::cout << nod.g_value << " " << nod.h_value;
//        std::cout << "3" << std::endl;
        while (head->next != NULL && ((head->next->g_value + head->next->h_value) <= (nod.g_value + nod.h_value))) {
//            std::cout << "a";
            head = head->next;
        }
//        std::cout << std::endl << "3.1" << std::endl;
        if (head->next == NULL) {
//            std::cout << std::endl << "3.2" << std::endl;
            if ((head->g_value + head->h_value) >= (nod.g_value + nod.h_value)) {
//                std::cout << std::endl << "3.3" << std::endl;
                ListNode* tmp = GetFront();
//                std::cout << std::endl << "3.4" << std::endl;
                if (tmp != head) {
                    while (tmp->next != head) {
                        tmp = tmp->next;
                    }
                    ListNode* t = new ListNode;
                    t->coor = nod.coor;
                    t->g_value = nod.g_value;
                    t->h_value = nod.h_value;
                    t->parent = nod.parent;
                    tmp->next = t;
                    t->next = head;
                } else {
                    ListNode* t = new ListNode;
                    t->coor = nod.coor;
                    t->g_value = nod.g_value;
                    t->h_value = nod.h_value;
                    t->parent = nod.parent;
                    t->next = tmp;
                    head_ = t;
                }
/*                ListNode* t = new ListNode;
                t->coor = nod.coor;
                t->g_value = nod.g_value;
                t->h_value = nod.h_value;
                t->parent = nod.parent;
                tmp->next = t;
                t->next = head;*/
            } else {
                ListNode* t = new ListNode;
                t->coor = nod.coor;
                t->g_value = nod.g_value;
                t->h_value = nod.h_value;
                t->parent = nod.parent;
                head->next = t;
                t->next = NULL;
            }
        } else {
//          std::cout << std::endl << "4" << std::endl;
            if ((head->g_value + head->h_value) >= (nod.g_value + nod.h_value)) {
                ListNode* tmp = GetFront();
                if (tmp != head) {
                    while (tmp->next != head) tmp = tmp->next;
                    ListNode* t = new ListNode;
                    t->coor = nod.coor;
                    t->g_value = nod.g_value;
                    t->h_value = nod.h_value;
                    t->parent = nod.parent;
                    t->next = head;
                    tmp->next = t;
                } else {
                    ListNode* t = new ListNode;
                    t->coor = nod.coor;
                    t->g_value = nod.g_value;
                    t->h_value = nod.h_value;
                    t->parent = nod.parent;
                    t->next = tmp;
                    head_ = t;
                }
            }
/*
                ListNode* t = new ListNode;
                t->coor = nod.coor;
                t->g_value = nod.g_value;
                t->h_value = nod.h_value;
                t->parent = nod.parent;
                t->next = nod->next;
                head->next = t;
                head = head->next;*/

//          ListNode* a = head;
//          std::cout << std::endl << "5" << std::endl;
//          ListNode* c = head->next;
//          std::cout << std::endl << "6" << std::endl;
            while (head->next != NULL) {
                if (head->coor == nod.coor) break;
//              std::cout << std::endl << "655" << std::endl;
                head = head->next;
            }
//          std::cout << std::endl << "7" << std::endl;

            if (head->next != NULL && head->coor == nod.coor) {
                ListNode* h = GetFront();
                while (h->next != head) h = h->next;
                ListNode* d = head->next;
                delete head;
                h->next = d;
            }

            if (head->next == NULL && head->coor == nod.coor) {
                delete head;
            }

        }
    }
}

bool LinkedList::SearchElement(ListNode element) {
    ListNode* head = this->GetFront();
    if (head == NULL) return false;
//    std::cout << this->Size();
//    std::cout << std::endl << head->coor.second << " " << head->coor.first << std::endl;
//    std::cout << std::endl << element.coor.second << " " << element.coor.first << std::endl;
    while (head != NULL) {
        if (head->coor == element.coor) break;
//        if(head == head->next) break;
        head = head->next;
//        std::cout << std::endl << head << " " << std::endl;
    }
//    std::cout << std::endl << "2.2" << std::endl;
    if (head == NULL) {
        return false;
    } else return true;
}

ListNode LinkedList::FindElement(ListNode element) {
    ListNode* head = this->GetFront();
    ListNode h;
    if (head == NULL) return h;
//    std::cout << std::endl << head->coor.second << " " << head->coor.first << std::endl;
    while (head != NULL) {
        if (head->coor == element.coor) {
            break;
        } else {
            head = head->next;
        }
    }
    if (head != NULL) {
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
        if (a->next == NULL) {
            this->head_ = NULL;
            ListNode b;
            b.coor = a->coor;
            b.g_value = a->g_value;
            b.h_value = a->h_value;
            b.next = a->next;
            b.parent = a->parent;
            delete a;
            return b;
        } else {
            this->head_ = a->next;
            ListNode b;
            b.coor = a->coor;
            b.g_value = a->g_value;
            b.h_value = a->h_value;
            b.next = a->next;
            b.parent = a->parent;
            delete a;
            return b;
        }
    }
}

int LinkedList::Size() {
    ListNode* a = this->GetFront();
    int k = 0;
    if (a == NULL) return k;
    while (a != NULL) {
        ++k;
        a = a->next;
    }
    return k;
}

ListNode* LinkedList::GetFront() {
    return this->head_;
/*    ListNode* a = this->head_;
    if (a == NULL) {
        return NULL;
    } else {
        return a;
    }*/
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
