#pragma once

#include "data.h"
#include "tikrinimas.h"
#include "IvestisIsvestis.h"


//double vidurkis(vector<int> pazymys, int egzaminas);
//double mediana(vector<int> pazymys, int egzaminas);
//void atsSk(vector<mokinys>& mokiniai, bool rezultatas, bool manual);
//void galutinisMedVid(vector<mokinys>& mokiniai);

double galutinisVid(vector<int> paz, int egz);
double galutinisMed(vector<int> paz, int egz);
void RezSk(vector<mokinys>& mokiniai, bool rez, bool manual);

double galutinisVid(list<int> paz, int egz);
double galutinisMed(list<int> paz, int egz);
void RezSk(list<mokinys>& mokiniai, bool rez, bool manual);

double galutinisVid(deque<int> paz, int egz);
double galutinisMed(deque<int> paz, int egz);
void RezSk(deque<mokinys>& mokiniai, bool rez, bool manual);

void MokiniuSortiravimas(vector<mokinys>& kietekai, vector<mokinys>& vargsai, vector<mokinys>& VisiMokiniai);
void MokiniuSortiravimas(list<mokinys>& kietekai, list<mokinys>& vargsai, list<mokinys>& VisiMokiniai);
void MokiniuSortiravimas(deque<mokinys>& kietekai, deque<mokinys>& vargsai, deque<mokinys>& VisiMokiniai);

void MokiniuSortiravimasV2(vector<mokinys>& kietekai, vector<mokinys>& vargsai);
void MokiniuSortiravimasV2(list<mokinys>& kietekai, list<mokinys>& vargsai);
void MokiniuSortiravimasV2(deque<mokinys>& kietekai, deque<mokinys>& vargsai);