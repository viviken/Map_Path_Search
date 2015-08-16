#include "astarsearch.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Not arguments!" << std::endl;
        return 0;
    }
/*
    std::string adds;
    adds = argv[1];
    int len = adds.size() - 4;
    std::string a = "_log";
    adds.insert(len, a);
*/
    Map map;
    if (!map.GetMapFromXML(argv[1])) {
        std::cout << "An error occurred while reading the map." << std::endl;
        return 0;
    }
    map.Get_Result_Address(argv[1]);
    map.PrintMap();
//    map.GetRatio();
//    map.CreateResult(argv[1]);
    AstarSearch a;
    bool c = a.Search(map);
    std::cout << std::endl << c << std::endl;
/*    std::cout << std::endl << "0" << std::endl;
    AstarSearch a;
    std::cout << std::endl << "1" << std::endl;
    ListNode s0;
    ListNode goal;
    std::cout << std::endl << "2" << std::endl;
    s0.coor = map.start_();
    std::cout << std::endl << "3" << std::endl;
    std::cout << goal.coor.first << " " << goal.coor.second;
    goal.coor = map.finish_();
    std::cout << std::endl << "4" << std::endl;
    s0.g_value = 0;
    goal.g_value = map.width_() * map.height_();
    goal.h_value = 0;
    std::cout << std::endl << "5" << std::endl;
    s0.h_value = a.h_cost(s0.coor, goal.coor);
    std::cout << std::endl << "6" << std::endl;
    a.OPEN.PushSort(s0);
    a.OPEN.PushSort(goal);
    std::cout << std::endl << "777777777777" << std::endl;
*/
//    map.grid[1][2] = 5;
    map.PrintMap();

    //std::cout << std::endl << map.adds;
    return 0;
}
