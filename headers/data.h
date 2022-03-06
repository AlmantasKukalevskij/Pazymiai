#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;

struct mokinys
{
    string vardas = "", pavarde = "";
    vector<int> pazymiai;
    int pazymiuSk = 0;
    int egzaminas;
    double rezult = 0;
    double vidurkis = 0;
    double mediana = 0;
};
