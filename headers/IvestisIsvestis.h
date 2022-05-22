#pragma once

#include "data.h"
#include "tikrinimas.h"

int ivestiPazymiai;
void ivestis(mokinys& temp, bool kurimas);
int pazymioIvedimas();
void buferioSkaitymas(vector<mokinys>& mokiniai, string file_name);
void buferioRasymas(vector<mokinys>& mokiniai);
void vectoriusToFile(string file_name, vector<mokinys>& data);
