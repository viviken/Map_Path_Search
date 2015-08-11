#include "linkedlist.h"

int main() {
    std::cout << "azaz" << std::endl;
    LinkedList OPEN;
    ListNode a, b, c, d, h, i, g, k;
    a.coor = std::make_pair(1, 1);
    b.coor = std::make_pair(2, 2);
    c.coor = std::make_pair(3, 3);
    d.coor = std::make_pair(4, 4);
    g.coor = std::make_pair(5, 5);
    h.coor = std::make_pair(7, 7);
    i.coor = std::make_pair(7, 7);
    k.coor = std::make_pair(7, 7);
    a.g_value = 100;
    a.h_value = 100;
    b.g_value = 50;
    b.h_value = 50;
    c.g_value = 200;
    c.h_value = 200;
    d.g_value = 25;
    d.h_value = 25;
    g.g_value = 75;
    g.h_value = 75;
    h.g_value = 300;
    h.h_value = 300;
    i.g_value = 150;
    i.h_value = 150;
    k.g_value = 125;
    k.h_value = 125;
    OPEN.PushSort(a);
    std::cout << std::endl << "Element 1 pushed!" << std::endl;
    OPEN.PushSort(b);
    std::cout << std::endl << "Element 2 pushed!" << std::endl;
    OPEN.PushSort(c);
    std::cout << std::endl << "Element 3 pushed!" << std::endl;
    OPEN.PushSort(d);
    std::cout << std::endl << "Element 4 pushed!" << std::endl;
    std::cout << std::endl << OPEN.Size() << std::endl;
    OPEN.PushSort(h);
    std::cout << std::endl << OPEN.Size() << std::endl;
    OPEN.PushSort(g);
    std::cout << std::endl << OPEN.Size() << std::endl;


    OPEN.PushSort(i);
    std::cout << std::endl << OPEN.Size() << std::endl;


    OPEN.PushSort(k);
    std::cout << std::endl << OPEN.Size() << std::endl;
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
        std::cout << aa.coor.first << " " << aa.coor.second << " " << "f_value = " << aa.g_value + aa.h_value << std::endl;
    }
    return 0;
}

