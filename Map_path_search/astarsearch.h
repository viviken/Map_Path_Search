#ifndef ASTARSEARCH_H
#define ASTARSEARCH_H
#include "map.h"


class AstarSearch {
    const int cost_d = 14;
    const int cost_nd = 10;
public:
    AstarSearch();
    bool Search(Map* map);
    void Expand(ListNode* s, long long infinity, Map* map, LinkedList *CLOSE, LinkedList *OPEN);
    int h_cost(std::pair<int, int> &s, std::pair<int, int> &f);
    void help(ListNode* s, ListNode* s1, long long int infinity, LinkedList* CLOSE, LinkedList* OPEN, int cost);
    //void RecoveryPath(ListNode* s, ListNode* goal, Map& map);
};

#endif // ASTARSEARCH_H
