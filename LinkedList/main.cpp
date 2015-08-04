#include "linkedlist.h"

int main() {
    LinkedList OPEN;
    ListNode a, b, c, d;
    a.coor = std::make_pair(1, 1);
    b.coor = std::make_pair(2, 2);
    c.coor = std::make_pair(3, 3);
    d.coor = std::make_pair(4, 4);
    a.g_value = 100;
    a.h_value = 100;
    b.g_value = 50;
    b.h_value = 50;
    c.g_value = 200;
    c.h_value = 200;
    d.g_value = 25;
    d.h_value = 25;
    OPEN.PushSort(a);
    OPEN.PushSort(b);
    OPEN.PushSort(c);
    OPEN.PushSort(d);
    std::cout << OPEN.Size() << "aaaaaaaaaaa" << std::endl;
    ListNode e, f;
    e.coor = std::make_pair(1, 1);
//    e.g_value = 100;
//    e.h_value = 100;
    f = OPEN.FindElement(e);
    std::cout << f.coor.first << " " << f.coor.second << std::endl;
    std::cout << f.g_value << " " << f.h_value << std::endl;
    std::cout << OPEN.SearchElement(a);
    std::cout << OPEN.SearchElement(d);
    std::cout << OPEN.SearchElement(e);
    std::cout << std::endl << OPEN.Size() << std::endl;
    while (OPEN.Size() != 0) {
        ListNode aa = OPEN.GetFrontAndDelete();
        std::cout << aa.coor.first << " " << aa.coor.second << std::endl;
    }
    return 0;
}

