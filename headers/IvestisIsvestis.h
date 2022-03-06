#pragma once

#include "data.h"

void ivestis(mokinys& temp, bool kurimas);
void isved(mokinys& temp, ofstream& fout);
int pazymioIvedimas();
void skaitymas(ifstream& fin, vector<string>& length, vector<mokinys>& mokiniai);
