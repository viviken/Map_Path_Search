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

void AstarSearch::help(ListNode s, ListNode s1, long long int infinity, AstarSearch* A, int cost) {
//    std::cout << std::endl << "0" << std::endl;
    if (A->CLOSE.SearchElement(s1) == false) {
//        std::cout << std::endl << "1" << std::endl;
        if (A->OPEN.SearchElement(s1) == false) {
//            std::cout << std::endl << "2" << std::endl;
            s1.g_value = infinity;
//            std::cout << std::endl << "3" << std::endl;
            if (s1.g_value > s.g_value + cost) {
//                std::cout << std::endl << "4" << std::endl;
                s1.g_value = s.g_value + cost;
//                std::cout << std::endl << "5" << std::endl;
                A->OPEN.PushSort(s1);
//                std::cout << std::endl << "6" << std::endl;
            }
        } else {
//            std::cout << std::endl << "7" << std::endl;
            s1 = A->OPEN.FindElement(s1);
//            std::cout << std::endl << "8" << std::endl;
            if (s1.g_value > s.g_value + cost) {
                s1.g_value = s.g_value + cost;
//                std::cout << std::endl << "9" << std::endl;
                A->OPEN.PushSort(s1);
//                std::cout << std::endl << "10" << std::endl;
            }
        }
    }
}

void AstarSearch::Expand(ListNode s, long long int infinity, Map* map, AstarSearch* A) {
//    std::cout << std::endl << "0" << std::endl;

    if (-1 < s.coor.first + 1 && s.coor.first + 1 < map->height_()) {
//        std::cout << std::endl << "00" << std::endl;
        if (map->grid[s.coor.first + 1][s.coor.second] == 0) {
//            std::cout << std::endl << "000" << std::endl;
            ListNode s1;
            s1.coor = s.coor;
            ++s1.coor.first;
            s1.h_value = h_cost(s1.coor, map->finish__());
            help(s, s1, infinity, A, cost_nd);
            s1.parent = &s;
        }
    }

//    std::cout << std::endl << "1" << std::endl;
    if (-1 < s.coor.first - 1 && s.coor.first - 1 < map->height_()) {
//        std::cout << std::endl << "11" << std::endl;
        if (map->grid[s.coor.first - 1][s.coor.second] == 0) {
//            std::cout << std::endl << "111" << std::endl;
            ListNode s1;
            s1.coor = s.coor;
//            std::cout << std::endl << "1.2" << std::endl;
            --s1.coor.first;
//            std::cout << std::endl << "1.3" << std::endl;
            s1.h_value = h_cost(s1.coor, map->finish__());
//            std::cout << std::endl << "1.4" << std::endl;
            help(s, s1, infinity, A, cost_nd);
//            std::cout << std::endl << "1.5" << std::endl;
            s1.parent = &s;
//            std::cout << std::endl << "1.6" << std::endl;
        }
    }

//    std::cout << std::endl << "2" << std::endl;
    if (-1 < s.coor.second + 1 && s.coor.second + 1 < map->height_()) {
        if (map->grid[s.coor.first][s.coor.second + 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            ++s1.coor.second;
            s1.h_value = h_cost(s1.coor, map->finish__());
            help(s, s1, infinity, A, cost_nd);
            s1.parent = &s;
        }
    }

//    std::cout << std::endl << "3" << std::endl;
    if (-1 < s.coor.second - 1 && s.coor.second - 1 < map->height_()) {
        if (map->grid[s.coor.first][s.coor.second - 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            --s1.coor.second;
            s1.h_value = h_cost(s1.coor, map->finish__());
            help(s, s1, infinity, A, cost_nd);
            s1.parent = &s;
        }
    }

//    std::cout << std::endl << "4" << std::endl;
    if (-1 < s.coor.first + 1 && s.coor.first + 1 < map->height_() && -1 < s.coor.second + 1 && s.coor.second + 1 < map->height_()) {
        if (map->grid[s.coor.first + 1][s.coor.second + 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            ++s1.coor.first;
            ++s1.coor.second;
            s1.h_value = h_cost(s1.coor, map->finish__());
            help(s, s1, infinity, A, cost_d);
            s1.parent = &s;
        }
    }

//   std::cout << std::endl << "5" << std::endl;
    if (-1 < s.coor.first - 1 && s.coor.first - 1 < map->height_() && -1 < s.coor.second - 1 && s.coor.second - 1 < map->height_()) {
        if (map->grid[s.coor.first + 1][s.coor.second + 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            --s1.coor.first;
            --s1.coor.second;
            s1.h_value = h_cost(s1.coor, map->finish__());
            help(s, s1, infinity, A, cost_d);
            s1.parent = &s;
        }
    }

//    std::cout << std::endl << "6" << std::endl;
    if (-1 < s.coor.first + 1 && s.coor.first + 1 < map->height_() && -1 < s.coor.second - 1 && s.coor.second - 1 < map->height_()) {
        if (map->grid[s.coor.first + 1][s.coor.second + 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            ++s1.coor.first;
            --s1.coor.second;
            s1.h_value = h_cost(s1.coor, map->finish__());
            help(s, s1, infinity, A, cost_d);
            s1.parent = &s;
        }
    }

//    std::cout << std::endl << "7" << std::endl;
    if (-1 < s.coor.first - 1 && s.coor.first - 1 < map->height_() && -1 < s.coor.second + 1 && s.coor.second + 1 < map->height_()) {
        if (map->grid[s.coor.first + 1][s.coor.second + 1] == 0) {
            ListNode s1;
            s1.coor = s.coor;
            --s1.coor.first;
            ++s1.coor.second;
            s1.h_value = h_cost(s1.coor, map->finish__());
            help(s, s1, infinity, A, cost_d);
            s1.parent = &s;
        }
    }
}

bool AstarSearch::Search(Map *map) {
    long long int infinity = map->width_() * map->height_();
    AstarSearch A;
    ListNode s0, goal;

//    std::cout << s0.coor.first << " " << s0.coor.second << std::endl;
//    std::cout << s0.g_value << " " << s0.h_value << std::endl;

    s0.coor = map->start_();
    goal.coor = map->finish_();
    s0.g_value = 0;

    s0.h_value = h_cost(s0.coor, goal.coor);

//    std::cout << s0.g_value << " " << s0.h_value << std::endl;

    A.OPEN.PushSort(s0);
//    std::cout << std::endl << "aaaaaaaaa" << std::endl;
    while (A.OPEN.GetFront() != NULL) {
//        std::cout << std::endl << "bbbb" << std::endl;
        ListNode s = A.OPEN.GetFrontAndDelete();
//        std::cout << std::endl << "1" << std::endl;
        if (s.coor == goal.coor) {
//            std::cout << std::endl << "2" << std::endl;
            RecoveryPath(s0, goal, map);
            ListNode aa = goal;
            while (aa.coor != s.coor) {
                map->grid[aa.coor.second][aa.coor.first] = 8;
                aa = *aa.parent;
            }
            return true;
        }
//        std::cout << std::endl << "3" << std::endl;
        Expand(s, infinity, map, &A);
//        std::cout << std::endl << "4" << std::endl;
        A.CLOSE.PushFront(s);
    }
    return false;
}

void AstarSearch::RecoveryPath(ListNode s, ListNode goal, Map* map) {
    ListNode a = goal;
    while (a.coor != s.coor) {
        map->grid[a.coor.second][a.coor.first] = 8;
        a = *a.parent;
    }
}
