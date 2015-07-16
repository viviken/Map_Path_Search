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
            s1->node->g_value = infinity;
            if (s1->node->g_value > s->node->g_value + cost) {
                s1->node->g_value = s->node->g_value + cost;
                OPEN->PushSort(s1);
            }
        } else {
            s1 = OPEN->FindElement(s1);
            if (s1->node->g_value > s->node->g_value + cost) {
                s1->node->g_value = s->node->g_value + cost;
                OPEN->PushSort(s1);
            }
        }
    }
}

void AstarSearch::Expand(ListNode* s, long long int infinity, Map* map, LinkedList* CLOSE, LinkedList* OPEN) {
    //ListNode* s1;
/*
    if (-1 < s->node->coor.first + 1 < map->height_()) {
        if (map->grid[s->node->coor.first + 1][s->node->coor.second] == 0) {
            ListNode* s1;
            s1->node->coor = s->node->coor;
            ++s1->node->coor.first;
            s1->node->h_value = h_cost(s1->node->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_nd);
            s1->node->parent = s->node;
        }
    }

    if (-1 < s->node->coor.first - 1 < map->height_()) {
        if (map->grid[s->node->coor.first - 1][s->node->coor.second] == 0) {
            ListNode* s1;
            s1->node->coor = s->node->coor;
            --s1->node->coor.first;
            s1->node->h_value = h_cost(s1->node->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_nd);
            s1->node->parent = s->node;
        }
    }

    if (-1 < s->node->coor.second + 1 < map->height_()) {
        if (map->grid[s->node->coor.first][s->node->coor.second + 1] == 0) {
            ListNode* s1;
            s1->node->coor = s->node->coor;
            ++s1->node->coor.second;
            s1->node->h_value = h_cost(s1->node->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_nd);
            s1->node->parent = s->node;
        }
    }

    if (-1 < s->node->coor.second - 1 < map->height_()) {
        if (map->grid[s->node->coor.first][s->node->coor.second - 1] == 0) {
            ListNode* s1;
            s1->node->coor = s->node->coor;
            --s1->node->coor.second;
            s1->node->h_value = h_cost(s1->node->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_nd);
            s1->node->parent = s->node;
        }
    }

    if (-1 < s->node->coor.first + 1 < map->height_() && -1 < s->node->coor.second + 1 < map->height_()) {
        if (map->grid[s->node->coor.first + 1][s->node->coor.second + 1] == 0) {
            ListNode* s1;
            s1->node->coor = s->node->coor;
            ++s1->node->coor.first;
            ++s1->node->coor.second;
            s1->node->h_value = h_cost(s1->node->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_d);
            s1->node->parent = s->node;
        }
    }

    if (-1 < s->node->coor.first - 1 < map->height_() && -1 < s->node->coor.second - 1 < map->height_()) {
        if (map->grid[s->node->coor.first + 1][s->node->coor.second + 1] == 0) {
            ListNode* s1;
            s1->node->coor = s->node->coor;
            --s1->node->coor.first;
            --s1->node->coor.second;
            s1->node->h_value = h_cost(s1->node->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_d);
            s1->node->parent = s->node;
        }
    }

    if (-1 < s->node->coor.first + 1 < map->height_() && -1 < s->node->coor.second - 1 < map->height_()) {
        if (map->grid[s->node->coor.first + 1][s->node->coor.second + 1] == 0) {
            ListNode* s1;
            s1->node->coor = s->node->coor;
            ++s1->node->coor.first;
            --s1->node->coor.second;
            s1->node->h_value = h_cost(s1->node->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_d);
            s1->node->parent = s->node;
        }
    }

    if (-1 < s->node->coor.first - 1 < map->height_() && -1 < s->node->coor.second + 1 < map->height_()) {
        if (map->grid[s->node->coor.first + 1][s->node->coor.second + 1] == 0) {
            ListNode* s1;
            s1->node->coor = s->node->coor;
            --s1->node->coor.first;
            ++s1->node->coor.second;
            s1->node->h_value = h_cost(s1->node->coor, map->finish__());
            help(s, s1, infinity, CLOSE, OPEN, cost_d);
            s1->node->parent = s->node;
        }
    }*/
}

bool AstarSearch::Search(Map *map) {
    long long int infinity = map->width_() * map->height_();
    LinkedList* CLOSE;
    LinkedList* OPEN;
    ListNode* s0, goal;

    std::cout << std::endl << map->start_().first << " " << map->start_().second << std::endl;
    s0->node->coor = map->start_();
//    goal.node->coor = map->finish_();
/*    s0->node->g_value = 0;
    s0->node->h_value = h_cost(s0->node->coor, goal.node->coor);
    OPEN->PushSort(s0);
    while (OPEN->GetFront() != NULL) {
        ListNode* s = OPEN->GetFrontAndDelete();
        if (s->node->coor == goal.node->coor) {
//            RecoveryPath(s0, goal, map);
            ListNode aa = goal;
            while (aa.node->coor != s->node->coor) {
                map->grid[aa.node->coor.second][aa.node->coor.first] = 8;
                aa.node = aa.node->parent;
            }
            return true;
        }

        Expand(s, infinity, map, CLOSE, OPEN);

        CLOSE->PushBack(s);
    }
    return false;*/
}
/*
void AstarSearch::RecoveryPath(ListNode* s, ListNode* goal, Map& map) {
    ListNode* a = goal;
    while (a->node->coor != s->node->coor) {
        map->grid[a->node->coor.second][a->node->coor.first] = 8;
        a->node = a->node->parent;
    }
}
*/
