#include "astarsearch.h"

AstarSearch::AstarSearch() {}

int AstarSearch::h_cost(std::pair<int, int>& s, std::pair<int, int>& f) {
    int res = 0;
    if (abs(s.first - f.first) < abs(s.second - f.second)) {
        res += cost_d * abs(s.first - f.first) + cost_nd * (abs(s.second - f.second) - abs(s.first - f.first));
    } else {
        res += cost_d * abs(s.second - f.second) + cost_nd * (abs(s.first - f.first) - abs(s.second - f.second));
    }
    return res;
}

void AstarSearch::help(ListNode& s, ListNode& s1, long long int infinity, AstarSearch& A, int cost) {
//    std::cout << std::endl << "000" << std::endl;
    if (A.CLOSE.SearchElement(s1) == false) {
//        std::cout << std::endl << "111" << std::endl;
//        std::cout << A->OPEN.Size() << std::endl;
        if (A.OPEN.SearchElement(s1) == false) {
//            std::cout << std::endl << "222" << std::endl;
            s1.g_value = infinity;
//            std::cout << std::endl << "333" << std::endl;
//            std::cout << s1.g_value << " " << s.g_value;
            if (s1.g_value > s.g_value + cost) {
//                std::cout << std::endl << "444" << std::endl;
                s1.g_value = s.g_value + cost;
//                std::cout << s1.g_value << " " << s.g_value;
//                std::cout << std::endl << "555" << std::endl;
                s1.parent = &s;
                A.OPEN.PushSort(s1);
//                std::cout << std::endl << "666" << std::endl;
            }// else A->OPEN.PushSort(s1);
        } else {
//            std::cout << std::endl << "777" << std::endl;
            s1 = A.OPEN.FindElement(s1);
//            std::cout << std::endl << "888" << std::endl;
//            std::cout << std::endl << s1.g_value << " " <<s.g_value << " " << cost << std::endl;
//            std::cout << std::endl << s1.coor.first << " " << s1.coor.second << std::endl;
//            std::cout << std::endl << s1.parent->coor.first << " " << s1.parent->coor.second <<std::endl;
            if (s1.g_value != -1) {
//                std::cout << std::endl << "cccccccc" << std::endl;
                if (s1.g_value > s.g_value + cost) {
                    s1.g_value = s.g_value + cost;
//                    std::cout << std::endl << "9" << std::endl;
                    s1.parent = &s;
                    A.OPEN.PushSort(s1);
//                    std::cout << std::endl << "10" << std::endl;
                }
            } else {
//                std::cout << std::endl << "1111" << std::endl;
                s1.g_value = s.g_value + cost;
//                std::cout << std::endl << "2222" << std::endl;
                s1.parent = &s;
                A.OPEN.PushSort(s1);
//                std::cout << std::endl << "3333" << std::endl;
            }
        }
    }
}

void AstarSearch::Expand(ListNode& s, long long int infinity, Map& map, AstarSearch& A) {
//    std::cout << std::endl << "0" << std::endl;

    if (-1 < s.coor.first + 1 && s.coor.first + 1 < map.width_()) {
//        std::cout << std::endl << "00" << std::endl;
        if (map.grid[s.coor.first + 1][s.coor.second] == 0) {
//            std::cout << std::endl << "000" << std::endl;
            ListNode s1;
            s1.coor = s.coor;
            ++s1.coor.first;
            s1.h_value = h_cost(s1.coor, map.finish__());
            help(s, s1, infinity, A, cost_nd);
//            s1.parent = &s;
//            A->OPEN.PushSort(s1);
        }
    }

//    std::cout << std::endl << "1" << std::endl;
    if (-1 < s.coor.first - 1 && s.coor.first - 1 < map.width_()) {
        if (map.grid[s.coor.first - 1][s.coor.second] == 0) {
//            std::cout << std::endl << "1.1" << std::endl;
            ListNode s1;
//            std::cout << std::endl << "1.2" << std::endl;
            s1.coor = s.coor;
//            std::cout << std::endl << "1.3" << std::endl;
            --s1.coor.first;
//            std::cout << std::endl << "1.4" << std::endl;
            s1.h_value = h_cost(s1.coor, map.finish__());
//            std::cout << std::endl << "1.5" << std::endl;
            help(s, s1, infinity, A, cost_nd);
//            std::cout << std::endl << "1.6" << std::endl;
//            s1.parent = &s;
//            std::cout << std::endl << "1.7" << std::endl;
//            A->OPEN.PushSort(s1);
//            std::cout << std::endl << "1.8" << std::endl;
        }
    }

//    std::cout << std::endl << "2" << std::endl;
    if (-1 < s.coor.second + 1 && s.coor.second + 1 < map.height_()) {
        if (map.grid[s.coor.first][s.coor.second + 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            ++s1.coor.second;
            s1.h_value = h_cost(s1.coor, map.finish__());
            help(s, s1, infinity, A, cost_nd);
//            s1.parent = &s;
//            A->OPEN.PushSort(s1);
        }
    }

//    std::cout << std::endl << "3" << std::endl;
    if (-1 < s.coor.second - 1 && s.coor.second - 1 < map.height_()) {
        if (map.grid[s.coor.first][s.coor.second - 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            --s1.coor.second;
            s1.h_value = h_cost(s1.coor, map.finish__());
            help(s, s1, infinity, A, cost_nd);
//            s1.parent = &s;
//            A->OPEN.PushSort(s1);
        }
    }

//    std::cout << std::endl << "4" << std::endl;
    if (-1 < s.coor.first + 1 && s.coor.first + 1 < map.width_() && -1 < s.coor.second + 1 && s.coor.second + 1 < map.height_()) {
        if (map.grid[s.coor.first + 1][s.coor.second + 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            ++s1.coor.first;
            ++s1.coor.second;
            s1.h_value = h_cost(s1.coor, map.finish__());
            help(s, s1, infinity, A, cost_d);
//            s1.parent = &s;
//            A->OPEN.PushSort(s1);
        }
    }

//   std::cout << std::endl << "5" << std::endl;
    if (-1 < s.coor.first - 1 && s.coor.first - 1 < map.width_() && -1 < s.coor.second - 1 && s.coor.second - 1 < map.height_()) {
//        std::cout << std::endl << "5.1" << std::endl;
        if (map.grid[s.coor.first - 1][s.coor.second - 1] == 0) {
//            std::cout << std::endl << "5.2" << std::endl;
            ListNode s1;
            s1.coor = s.coor;
            --s1.coor.first;
            --s1.coor.second;
//            std::cout << std::endl << "5.3" << std::endl;
            s1.h_value = h_cost(s1.coor, map.finish__());
//            std::cout << std::endl << "5.4" << std::endl;
            help(s, s1, infinity, A, cost_d);
//            std::cout << std::endl << "5.5" << std::endl;
//            s1.parent = &s;
//            A->OPEN.PushSort(s1);
        }
    }

//    std::cout << std::endl << "6" << std::endl;
    if (-1 < s.coor.first + 1 && s.coor.first + 1 < map.width_() && -1 < s.coor.second - 1 && s.coor.second - 1 < map.height_()) {
        if (map.grid[s.coor.first + 1][s.coor.second - 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            ++s1.coor.first;
            --s1.coor.second;
            s1.h_value = h_cost(s1.coor, map.finish__());
            help(s, s1, infinity, A, cost_d);
//            s1.parent = &s;
//            A->OPEN.PushSort(s1);
        }
    }

//    std::cout << std::endl << "7" << std::endl;
    if (-1 < s.coor.first - 1 && s.coor.first - 1 < map.width_() && -1 < s.coor.second + 1 && s.coor.second + 1 < map.height_()) {
        if (map.grid[s.coor.first - 1][s.coor.second + 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            --s1.coor.first;
            ++s1.coor.second;
            s1.h_value = h_cost(s1.coor, map.finish__());
            help(s, s1, infinity, A, cost_d);
//            s1.parent = &s;
//            A->OPEN.PushSort(s1);
        }
    }
}

bool AstarSearch::Search(Map& map) {
    long long int infinity = map.width_() * map.height_() * 20;
    AstarSearch A;
    ListNode s0, goal;

//    std::cout << s0.coor.first << " " << s0.coor.second << std::endl;
//    std::cout << s0.g_value << " " << s0.h_value << std::endl;

    s0.coor.first = map.start_().second;
    s0.coor.second = map.start_().first;
    goal.coor.first = map.finish_().second;
    goal.coor.second = map.finish_().first;
    s0.g_value = 0;

    s0.h_value = h_cost(s0.coor, goal.coor);

//    map->grid[s0.coor.first][s0.coor.second] = 3;
//    map->grid[goal.coor.first][goal.coor.second] = 4;
//    std::cout << s0.g_value << " " << s0.h_value << std::endl;

    A.OPEN.PushSort(s0);
//    std::cout << std::endl << "aaaaaaaaa" << std::endl;
    while (A.OPEN.Size() != 0) {
//        std::cout << std::endl << "bbbb" << std::endl;
        ListNode s = A.OPEN.GetFrontAndDelete();
//        std::cout << std::endl << s.g_value << " " << s.h_value << std::endl;
//        std::cout << std::endl << "1" << std::endl;
        if (s.coor == goal.coor) {
            std::cout << std::endl << "GOOD END!" << std::endl;
//            Expand(s, infinity, map, &A);
            A.CLOSE.PushFront(s);
            RecoveryPath(s, map, A);
            return true;
        } else {
//            std::cout << std::endl << "3" << std::endl;
//            std::cout << std::endl << s.coor.first << " " << s.coor.second;
            Expand(s, infinity, map, A);
//            std::cout << std::endl << "4" << std::endl;
            A.CLOSE.PushFront(s);
        }
    }
    return false;
}

void AstarSearch::RecoveryPath(ListNode& s,  Map& map, AstarSearch& A) {
    std::cout << std::endl << "1" << std::endl;
    ListNode a = A.CLOSE.FindElement(s);
    std::cout << std::endl << "2" << std::endl;
    std::cout << s.coor.first << " " << s.coor.second << std::endl;
    std::cout << s.parent->coor.first << " " << s.parent->coor.second;
//    a.coor = s.parent->coor;
    std::cout << std::endl << "3" << std::endl;
//    a.parent = s.parent->parent;
    std::cout << std::endl << "4" << std::endl;
    std::cout << a.coor.first << " " << a.coor.second <<std::endl;
    std::cout << a.parent->coor.first << " " << a.parent->coor.second <<std::endl;
    std::cout << a.parent->parent->coor.first << " " << a.parent->parent->coor.second <<std::endl;
/*    while (a.coor != map.start_()) {
//        std::cout << std::endl << a.coor.second << " " << a.coor.first << std::endl;
        map.grid[a.coor.second][a.coor.first] = 8;
        std::cout << std::endl << "ssssssss" << std::endl;
        std::cout << std::endl << a.parent->coor.first << " " << a.parent->coor.second << std::endl;
        a.coor = a.parent->coor;
//        a.g_value = a.parent->g_value;
//        a.h_value = a.parent->h_value;
//        a.next = a.parent->next;
        a.parent = a.parent->parent;
        std::cout << std::endl << "aaaaaaaa" << std::endl;
    }*/
}
