#include "map.h"


Map::Map() {
    height = -1;
    width = -1;
    grid = NULL;
}

Map::Map(int n, int m) {
    InitMap(m, n);
}


Map::~Map() {
    if (grid != NULL) {
        for (int i = 0; i < height; i++) {
            delete [] grid[i];
        }
        delete [] grid;
    }
}


void Map::InitMap(int m, int n) {
    if (grid != NULL) {
        for (int i = 0; i < height; i++) {
            delete [] grid[i];
        }
        delete [] grid;
    }
    height = m;
    width = n;
    grid = new int *[height];
    for (int i = 0; i < height; i++) {
        grid[i] = new int[width];
        for (int j = 0; j < width; j++) {
            grid[i][j] = -1;
        }
    }
}


void Map::GetRatio() {
    std::cout << "Отношение количества 1 к 0 = " << this->ratio << std::endl;
}


void Map::Get_Result_Address(char* Route) {
    std::string ad;
    ad = Route;
    std::string a = "_log";
    size_t pos = ad.find_last_of(".");
    if (pos != std::string::npos) {
        ad.insert(pos, a);
    } else {
        ad.append(a);
    }
    adds_result = ad;

//    std::stringstream str;
//    std::string& add = ad;
//    add = (const char*) ad;
//    str << ad;
//    str >> add;
//   return ad.c_str();
}


void Map::CreateResult(char* Filename) {
/*
    // Make xml: <?xml ..><Hello>World</Hello>
    TiXmlDocument doc;
    TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "utf-8", "");
    doc.LinkEndChild( decl );

    TiXmlElement * element = new TiXmlElement( "desc" );
    TiXmlText * text = new TiXmlText( "This file contains result analyze map" );
    element->LinkEndChild( text );
    doc.LinkEndChild( element );

    TiXmlElement * map = new TiXmlElement("width");
    TiXmlText * text_width = new TiXmlText("50");
    map->LinkEndChild(text_width);
    doc.LinkEndChild(map);
//    doc.SaveFile( "/home/alex/Project/HSE Project/First_course_spring/Map_analyzer/result.xml" );
*/
    /*    std::string ratio;
        std::stringstream str1;
        str1 << rati;
        str1 >> ratio;
        std::string rat = ratio;
    */


//    double ratio_double = this->ratio;

    TiXmlDocument *xml_file = new TiXmlDocument(Filename);
    if(!xml_file->LoadFile()) {
        std::cout << "Неправильный файл!" << std::endl;
    }
    TiXmlElement *xml_root = 0;
    xml_root = xml_file->FirstChildElement(CNS_root);
    TiXmlElement *xml_map = 0;
    xml_map = xml_root->FirstChildElement(CNS_map);
    TiXmlElement *xml_grid = 0;
    xml_grid = xml_map->FirstChildElement(CNS_grid);



    TiXmlDocument doc;
    TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "utf-8", "");
    doc.LinkEndChild(decl);

    TiXmlElement * root = new TiXmlElement(CNS_root);
    doc.LinkEndChild(root);

    TiXmlElement * desc = new TiXmlElement(CNS_desc);
    desc->LinkEndChild( new TiXmlText( "This file contains result analyze map" ));
    root->LinkEndChild( desc );

    TiXmlElement * map = new TiXmlElement(CNS_map);
    root->LinkEndChild(map);

    TiXmlElement * result = new TiXmlElement(CNS_result);
    map->LinkEndChild(xml_grid->Clone());
    map->LinkEndChild(result);

    TiXmlElement * density = new TiXmlElement(CNS_density);
    result->LinkEndChild(density);
    std::string a;
    std::stringstream str;
    str << ratio;
    str >> a;
    density->LinkEndChild( new TiXmlText(a.c_str()));

    doc.SaveFile(adds_result.c_str());
}


bool Map::GetMapFromXML(char* Filename) {

    TiXmlDocument *xml_file = new TiXmlDocument(Filename);

    if(!xml_file->LoadFile()) {
        std::cout << "Incorrect file!" << std::endl;
        return false;
    }

    TiXmlElement *xml_root = 0;
    xml_root = xml_file->FirstChildElement(CNS_root);
    TiXmlElement *xml_map = 0;
    xml_map = xml_root->FirstChildElement(CNS_map);

    TiXmlElement *xml_startx = 0;
    TiXmlElement *xml_starty = 0;
    TiXmlElement *xml_finishx = 0;
    TiXmlElement *xml_finishy = 0;
    xml_startx = xml_map->FirstChildElement(CNS_startx);
    xml_starty = xml_map->FirstChildElement(CNS_starty);
    xml_finishx = xml_map->FirstChildElement(CNS_finishx);
    xml_finishy = xml_map->FirstChildElement(CNS_finishy);
    std::string n2 = xml_startx->GetText();
    std::string n3 = xml_starty->GetText();
    std::string m2 = xml_finishx->GetText();
    std::string m3 = xml_finishy->GetText();
    std::stringstream str3, str4, str5, str6;
    str3 << n2;
    str3 >> this->start.first;
    str4 << n3;
    str4 >> this->start.second;
    str5 << m2;
    str5 >> this->finish.first;
    str6 << m3;
    str6 >> this->finish.second;


// Инициализирование матрицы проходимости по заданным в файле данных(высота и ширина).
    TiXmlElement *xml_height = 0;
    TiXmlElement *xml_width = 0;
    xml_height = xml_map->FirstChildElement(CNS_height);
    xml_width = xml_map->FirstChildElement(CNS_width);
    std::string m1 = xml_height->GetText();
    std::string n1 = xml_width->GetText();

    int m, n = 0;
    std::stringstream str1, str2;
    str1 << m1;
    str2 << n1;
    str1 >> m;
    str2 >> n;

    InitMap(n, m);


// Переход к области со значениями ячеек матрицы.
    TiXmlElement *xml_grid = 0;
    xml_grid = xml_map->FirstChildElement(CNS_grid);
    TiXmlElement *xml_row = 0;
    xml_row = xml_grid->FirstChildElement(CNS_row);
// Заполнение матрицы проходимости.
    int i = 0;
    long double number_of_zero = 0;
    while(xml_row != NULL) {
        if (i > this->height) {
            std::cout << "Несоответствие кол-ва строк со значением высоты : ";
            std::cout << i << " " << this->height;
            return false;
        }
        std::string a = xml_row->GetText();
        const char* space = " ";
        std::vector<int> b;
        for (size_t q = 0; q < a.size(); ++q) {
            if (a[q] != *space) {
                std::stringstream ss;
                ss << a[q];
                int k = 0;
                ss >> k;
                b.push_back(k);
            }
        }

        if (b.size() != this->width) {
            std::cout << "Несоответствие кол-ва символов в строке и указанной ширины : ";
            std::cout << b.size() << " " << this->width << std::endl;
            return false;
        }

        int j = 0;
        while (j < this->width) {
            this->grid[i][j] = b[j];
            if (b[j] == 0) {
                number_of_zero++;
            }
            ++j;
        }
        ++i;
        xml_row = xml_row->NextSiblingElement(CNS_row);  // перебор всех row`ов
    }
    this->ratio = (this->width * this->height - number_of_zero) / (this->width * this->height);
    return true;
}


void Map::PrintMap() {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            std::cout << this->grid[i][j];
        }
        std::cout << std::endl;
    }
}
