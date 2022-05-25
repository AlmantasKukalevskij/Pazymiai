#include "atsSk.h"


double galutinisVid(vector<int> paz, int egz)
{
    double sum = 0;
    for (auto& el : paz)
    {
        sum += el;
    }
    if (paz.size() != 0)
        return sum / (paz.size() * 1.0) * 0.4 + egz * 0.6;
    else
        return
        egz * 0.6;
}
double galutinisMed(vector<int> paz, int egz)
{
    sort(paz.begin(), paz.end());
    if (paz.size() % 2 == 0 && paz.size() != 0)
    {
        return (paz[paz.size() / 2] + paz[paz.size() / 2 - 1]) * 1.0 / 2;
    }
    else if (paz.size() % 2 != 0 && paz.size() != 0)
    {
        return paz[paz.size() / 2] * 0.4 + egz * 0.6;
    }
    else
        return egz * 0.6;
}
void MokiniuSortiravimas(vector<mokinys>& kietekai, vector<mokinys>& vargsai, vector<mokinys>& mokiniai)
{
    auto sortStart = hrClock::now();
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
    cout << "Mokiniai padalinti i dvi gupes per: " << durationDouble(hrClock::now() - sortStart).count() << " sek." << endl;
}

void MokiniuSortiravimas(list<mokinys>& kietekai, list<mokinys>& vargsai, list<mokinys>& mokiniai)
{
    auto sortStart = hrClock::now();
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
    cout << "Mokiniai padalinti i dvi gupes per: " << durationDouble(hrClock::now() - sortStart).count() << " sek." << endl;
}

void MokiniuSortiravimas(deque<mokinys>& kietekai, deque<mokinys>& vargsai, deque<mokinys>& mokiniai)
{
    auto sortStart = hrClock::now();
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
    cout << "Mokiniai padalinti i dvi gupes per: " << durationDouble(hrClock::now() - sortStart).count() << " sek." << endl;
}

void RezSk(vector<mokinys>& mokiniai, bool rez, bool manual)
{
    for (auto& el : mokiniai)
    {
        if (rez || !manual)
            el.vidurkis = galutinisVid(el.pazymiai, el.egzaminas);
        if (!rez || !manual)
            el.mediana = galutinisMed(el.pazymiai, el.egzaminas);
    }
}

void RezSk(list<mokinys>& mokiniai, bool rez, bool manual)
{
    for (auto& el : mokiniai)
    {
        if (rez || !manual)
            el.vidurkis = galutinisVid(el.pazymiai, el.egzaminas);
        if (!rez || !manual)
            el.mediana = galutinisMed(el.pazymiai, el.egzaminas);
    }
}

void RezSk(deque<mokinys>& mokiniai, bool rez, bool manual)
{
    for (auto& el : mokiniai)
    {
        if (rez || !manual)
            el.vidurkis = galutinisVid(el.pazymiai, el.egzaminas);
        if (!rez || !manual)
            el.mediana = galutinisMed(el.pazymiai, el.egzaminas);
    }
}
