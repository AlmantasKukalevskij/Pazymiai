#include "atsSk.h"
#include "generavimas.h"

int randomInt(int from, int to)
{
    std::uniform_int_distribution<int> dist(from, to);
    return dist(mt);
}
string randFirstName()
{
    return firstNames[randomInt(0, firstNames.size() - 1)];
}
string randLastName()
{
    return lastNames[randomInt(0, lastNames.size() - 1)];
}

void atsitiktinioPazKurimas(mokinys& temp)
{
    cout << "Jeigu norite sugeneruoti nauja pazymi iveskite 1, jei ne spauskite 0" << endl;
    while (true)
    {
        int run = validMode(0, 1);
        if (run)
        {
            temp.pazymiai.push_back(randomInt(1, 10));
        }
        else
            break;
    }
}
std::stringstream genMokString(int ndSkaicius)
{
    std::stringstream mok;

    mok << left << setw(20) << randFirstName();
    mok << left << setw(20) << randLastName();
    for (int i = 0; i < ndSkaicius; i++)
        mok << std::left << std::setw(7) << randomInt(1, 10);
    mok << std::left << std::setw(7) << randomInt(1, 10) << endl;
    return mok;

}