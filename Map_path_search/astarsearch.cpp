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

void AstarSearch::Expand(ListNode* s, long long int infinity, Map* map, LinkedList* CLOSE, LinkedList* OPEN) {
    //ListNode* s1;

    if (s->node->coor.first + 1 < map->height_()) {
        if (map->grid[s->node->coor.first + 1][s->node->coor.second] == 0) {
            ListNode* s1;
            s1->node->coor = s->node->coor;
            ++s1->node->coor.first;
            std::pair<int, int>& a = map->finish_();
            s1->node->h_value = h_cost(s1->node->coor, a);
            if (CLOSE->SearchElement(s1) == false && OPEN->SearchElement(s1) == false) {
                s1->node->g_value = infinity;
                if (s1->node->g_value > s->node->g_value + cost_nd) {
                    s1->node->g_value = s->node->g_value + cost_nd;
                    OPEN->PushSort(s1);
                }
            }
            ++s1->node->coor.first;
        }
    }
}

bool AstarSearch::Search(Map *map) {
    long long int infinity = map->width_() * map->height_();
    LinkedList* CLOSE;
    LinkedList* OPEN;
    ListNode* s0, goal;
    s0->node->coor = map->start_();
    goal.node->coor = map->finish_();
    s0->node->g_value = 0;
    s0->node->h_value = h_cost(s0->node->coor, goal.node->coor);
    OPEN->PushSort(s0);
    while (OPEN->GetFront() != NULL) {
        ListNode* s = OPEN->GetFrontAndDelete();
        if (s->node->coor == goal.node->coor) {
            return true;
        }

        Expand(s, infinity, map, CLOSE, OPEN);

        CLOSE->PushBack(s);
    }
}
