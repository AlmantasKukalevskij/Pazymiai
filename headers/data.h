#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <random>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::setw;
using std::left;
using std::right;

using namespace std;
using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;

struct mokinys
{
    string vardas = "", pavarde = "";
    vector<int> pazymiai;
    int pazymiuSk = 0;
    int egzaminas;
    //double rezult = 0;
    double vidurkis = 0;
    double mediana = 0;
};

extern bool egzaminas;
extern bool pazymys;
extern bool rezultatas;
extern bool manual;