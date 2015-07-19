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

void AstarSearch::help(ListNode* s, ListNode* s1, long long int infinity, LinkedList* CLOSE, LinkedList* OPEN, int cost) {
    if (CLOSE->SearchElement(s1) == false) {
        if (OPEN->SearchElement(s1) == false) {
            s1->g_value = infinity;
            if (s1->g_value > s->g_value + cost) {
                s1->g_value = s->g_value + cost;
                OPEN->PushSort(s1);
            }
        } else {
            s1 = OPEN->FindElement(s1);
            if (s1->g_value > s->g_value + cost) {
                s1->g_value = s->g_value + cost;
                OPEN->PushSort(s1);
            }
        }
    }
}

void AstarSearch::Expand(ListNode* s, long long int infinity, Map* map, LinkedList* CLOSE, LinkedList* OPEN) {

    if (-1 < s->coor.first + 1 && s->coor.first + 1 < map->height_()) {
        if (map->grid[s->coor.first + 1][s->coor.second] == 0) {
            ListNode* s1;
            s1->coor = s->coor;
            ++s1->coor.first;
            s1->h_value = h_cost(s1->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_nd);
            s1->parent = s;
        }
    }

    if (-1 < s->coor.first - 1 && s->coor.first - 1 < map->height_()) {
        if (map->grid[s->coor.first - 1][s->coor.second] == 0) {
            ListNode* s1;
            s1->coor = s->coor;
            --s1->coor.first;
            s1->h_value = h_cost(s1->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_nd);
            s1->parent = s;
        }
    }

    if (-1 < s->coor.second + 1 && s->coor.second + 1 < map->height_()) {
        if (map->grid[s->coor.first][s->coor.second + 1] == 0) {
            ListNode* s1;
            s1->coor = s->coor;
            ++s1->coor.second;
            s1->h_value = h_cost(s1->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_nd);
            s1->parent = s;
        }
    }

    if (-1 < s->coor.second - 1 && s->coor.second - 1 < map->height_()) {
        if (map->grid[s->coor.first][s->coor.second - 1] == 0) {
            ListNode* s1;
            s1->coor = s->coor;
            --s1->coor.second;
            s1->h_value = h_cost(s1->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_nd);
            s1->parent = s;
        }
    }

    if (-1 < s->coor.first + 1 && s->coor.first + 1 < map->height_() && -1 < s->coor.second + 1 && s->coor.second + 1 < map->height_()) {
        if (map->grid[s->coor.first + 1][s->coor.second + 1] == 0) {
            ListNode* s1;
            s1->coor = s->coor;
            ++s1->coor.first;
            ++s1->coor.second;
            s1->h_value = h_cost(s1->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_d);
            s1->parent = s;
        }
    }

    if (-1 < s->coor.first - 1 && s->coor.first - 1 < map->height_() && -1 < s->coor.second - 1 && s->coor.second - 1 < map->height_()) {
        if (map->grid[s->coor.first + 1][s->coor.second + 1] == 0) {
            ListNode* s1;
            s1->coor = s->coor;
            --s1->coor.first;
            --s1->coor.second;
            s1->h_value = h_cost(s1->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_d);
            s1->parent = s;
        }
    }

    if (-1 < s->coor.first + 1 && s->coor.first + 1 < map->height_() && -1 < s->coor.second - 1 && s->coor.second - 1 < map->height_()) {
        if (map->grid[s->coor.first + 1][s->coor.second + 1] == 0) {
            ListNode* s1;
            s1->coor = s->coor;
            ++s1->coor.first;
            --s1->coor.second;
            s1->h_value = h_cost(s1->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_d);
            s1->parent = s;
        }
    }

    if (-1 < s->coor.first - 1 && s->coor.first - 1 < map->height_() && -1 < s->coor.second + 1 && s->coor.second + 1 < map->height_()) {
        if (map->grid[s->coor.first + 1][s->coor.second + 1] == 0) {
            ListNode* s1;
            s1->coor = s->coor;
            --s1->coor.first;
            ++s1->coor.second;
            s1->h_value = h_cost(s1->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_d);
            s1->parent = s;
        }
    }
}

bool AstarSearch::Search(Map *map) {
    long long int infinity = map->width_() * map->height_();
    LinkedList* CLOSE;
    LinkedList* OPEN;
    ListNode* s0, goal;

    std::cout << s0->coor.first << " " << s0->coor.second << std::endl;
    std::cout << s0->g_value << " " << s0->h_value << std::endl;

    s0->coor = map->start_();
    goal.coor = map->finish_();
    s0->g_value = 0;

    s0->h_value = h_cost(s0->coor, goal.coor);

    std::cout << s0->g_value << " " << s0->h_value << std::endl;

    OPEN->PushSort(s0);
    std::cout << std::endl << "aaaaaaaaa" << std::endl;
/*    while (OPEN->GetFront() != NULL) {
        ListNode* s = OPEN->GetFrontAndDelete();
        if (s->coor == goal.coor) {
            //RecoveryPath(s0, goal, map);
            ListNode aa = goal;
            while (aa.coor != s->coor) {
                map->grid[aa.coor.second][aa.coor.first] = 8;
                aa = aa.parent;
            }
            return true;
        }

        Expand(s, infinity, map, CLOSE, OPEN);

        CLOSE->PushBack(s);
    }*/
    return false;
}

void AstarSearch::RecoveryPath(ListNode* s, ListNode* goal, Map* map) {
    ListNode* a = goal;
    while (a->coor != s->coor) {
        map->grid[a->coor.second][a->coor.first] = 8;
        a = a->parent;
    }
}
