#ifndef MAP_H
#define MAP_H

#include "tinyxml.h"
#include "tinystr.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include "gl_const.h"
#include "linkedlist.h"


class Map {
private:
    int height;
    int width;
    //int **grid;
    std::string adds_result;
    double ratio;
    void InitMap(int m, int n);
    std::pair<int, int> start;
    std::pair<int, int> finish;

public:
    Map();
    Map(int n, int m);
    ~Map();
    bool GetMapFromXML(char* Filename);
    void PrintMap();
    void AnalyzeMap();
    void GetRatio();
    void CreateResult(char* Filename);
    void Get_Result_Address(char* Route);
    int height_() {return height;}
    int width_() {return width;}
    std::pair<int, int> start_() {return start;}
    std::pair<int, int> finish_() {return finish;}
    int **grid;
    std::pair<int, int>& finish__() {return finish;}
};

#endif // MAP_H
