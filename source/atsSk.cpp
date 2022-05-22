#include "atsSk.h"


void galutinisMedVid(vector<mokinys>& VisiMokiniai)
{
    for (auto& data : VisiMokiniai)
    {
        std::sort(data.pazymiai.begin(), data.pazymiai.end());
        if (data.pazymiai.size() % 2 != 0)
            data.mediana = 0.4 * (double)data.pazymiai[data.pazymiai.size() / 2] + 0.6 * data.egzaminas;
        else
        {
            data.mediana = 0.4 * ((double)(data.pazymiai[(data.pazymiai.size() - 1) / 2] + data.pazymiai[data.pazymiai.size() / 2]) / 2.0) + 0.6 * data.egzaminas;
        }
        for (int x = 0; x < data.pazymiai.size(); x++)
            data.vidurkis += data.pazymiai[x] * 1.0;
        data.vidurkis = (0.4 * (data.vidurkis / data.pazymiai.size())) + 0.6 * data.egzaminas;
    }
}
void MokiniuSortiravimas(vector<mokinys>& kietekai, vector<mokinys>& vargsai, vector<mokinys>& mokiniai)
{
    for (auto& mok : mokiniai)
    {
        if (mok.vidurkis < 5)
        {
            vargsai.push_back(mok);
        }
        else
        {
            kietekai.push_back(mok);
        }
    }
    mokiniai.clear();
}
