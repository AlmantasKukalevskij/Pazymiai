#include "data.h"

#include "tikrinimas.h"


int IntTikrinimas()
{
    int t;
    while (true)
    {
        cin >> t;
        if (cin.good())
            return t;
        else
        {
            cout << " Ivedete neteisinga reiksme" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
}

string atsakymoTikrinimas()
{
    string ats;
    do {
        cin >> ats;
        if (ats != "taip" && ats != "ne")
        {
            cout << ats;
            cout << " Atsakymas klaidingas, iveskite taip arba ne" << endl;
        }
    } while (ats != "taip" && ats != "ne");
    return ats;
}

bool PazTikrinimas(int t)
{
    if (t > 0 && t <= 10)
        return true;
    else
    {
        cout << " Ivestas neteisingas pazimys (desimtbale sistema)" << endl;
        return false;
    }
}

int validMode(int from, int to)
{
    while (true)
    {
        int mode = IntTikrinimas();
        for (int i = from; i <= to; i++)
            if (mode == i)
                return mode;
        cout << "Neteisingas skaicius" << endl;
    }
}

bool lyginimas(mokinys& a, mokinys& b)
{
    return a.vardas < b.pavarde;
}