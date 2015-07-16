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
    AstarSearch a;
    Map* b = &map;
    bool c = a.Search(b);
    map.PrintMap();
    map.GetRatio();
    map.CreateResult(argv[1]);
    //std::cout << std::endl << map.adds;
    return 0;
}
