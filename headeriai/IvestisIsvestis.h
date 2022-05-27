#pragma once

#include "data.h"
#include "tikrinimas.h"
#include "generavimas.h"

void ivestis(mokinys& temp);
void rankinisPazIvedimas(mokinys& temp);

void buferioSkaitymas(vector<mokinys>& mokiniai, string file_name, bool gen, double& fopenTime);
void buferioRasymas(std::string write_vardas, vector<mokinys>& mokiniai, bool manual, bool rez);

void buferioSkaitymas(list<mokinys>& mokiniai, string file_name, bool gen, double& fopenTime);
void buferioRasymas(std::string write_vardas, list<mokinys>& mokiniai, bool manual, bool rez);

void buferioSkaitymas(deque<mokinys>& mokiniai, string file_name, bool gen, double& fopenTime);
void buferioRasymas(std::string write_vardas, deque<mokinys>& mokiniai, bool manual, bool rez);


void failoGen(int size, string file_name, int ndSkaicius);
void contToFile(string file_name, vector<mokinys>& data);
void contToFile(string file_name, list<mokinys>& data);
void contToFile(string file_name, deque<mokinys>& data);
void openFile(std::ifstream& open_f);

