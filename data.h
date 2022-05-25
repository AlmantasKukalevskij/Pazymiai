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
#include <list>
#include <deque>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::deque;
using std::list;
using std::mt19937;

using namespace std;
using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;

struct mokinys
{
    string vardas, pavarde;
    vector<int> pazymiai;
    //int pazymiuSk = 0;
    int egzaminas;
    double vidurkis = 0;
    double mediana = 0;
};

extern bool egzaminas;
extern bool pazymys;
extern bool rezultatas;
extern bool manual;