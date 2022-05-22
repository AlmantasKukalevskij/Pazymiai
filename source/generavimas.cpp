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

void failoGen(int size, string file_name, int ndCount)
{
    std::stringstream outputas;
    outputas << std::left << std::setw(20) << "Vardas";
    outputas << std::left << std::setw(20) << "Pavarde";
    for (int i = 1; i <= ndCount; i++)
    {
        outputas << std::left << "ND" << std::setw(5) << i;
    }

    outputas << std::left << std::setw(7) << "Egz" << endl;

    for (int i = 0; i < size; i++)
    {
        outputas << genMokString(ndCount).str();
    }
    std::ofstream out_f(file_name);
    out_f << outputas.rdbuf();
    out_f.close();
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