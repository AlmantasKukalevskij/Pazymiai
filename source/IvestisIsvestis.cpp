
#include "data.h"
#include "IvestisIsvestis.h"
#include "tikrinimas.h"

void ivestis(mokinys& temp, bool kurimas)
{
    cout << endl;

    cout << "Veskite varda: "; cin >> temp.vardas;
    cout << "Veskite pavarde: "; cin >> temp.pavarde;

    cout << "Iveskite namu darbu skaiciu: ";
    temp.pazymiuSk = IntTikrinimas();



    if (kurimas)
    {
        for (int i = 0; i < temp.pazymiuSk; i++)
        {
            temp.pazymiai.push_back(rand() % 10 + 1);
            cout << "Ivestas" << i + 1 << " pazimys bus: " << temp.pazymiai[i] << endl;
        }
        temp.egzaminas = rand() % 10 + 1;
        cout << "Egzamino pazimys bus: " << temp.egzaminas << endl;
    }
    else
    {
        for (int i = 0; i < temp.pazymiuSk; i++) {
            cout << "Iveskite " << i + 1 << " -a(-i) pazymi: ";
            temp.pazymiai.push_back(pazymioIvedimas());
        }
        cout << "Veskite egzamino ivertinima: ";
        temp.egzaminas = pazymioIvedimas();
    }

    cout << endl;

}

void isved(mokinys& temp, ofstream& fout)
{

    fout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde;

    std::sort(temp.pazymiai.begin(), temp.pazymiai.end());
    if (temp.pazymiuSk % 2 != 0) temp.mediana = 0.4 * (double)temp.pazymiai[temp.pazymiuSk / 2] + 0.6 * temp.egzaminas;
    else temp.mediana = 0.4 * ((double)(temp.pazymiai[(temp.pazymiuSk - 1) / 2] + temp.pazymiai[temp.pazymiuSk / 2]) / 2.0) + 0.6 * temp.egzaminas;

    for (int x = 0; x < temp.pazymiuSk; x++) temp.vidurkis += temp.pazymiai[x] * 1.0;
    temp.vidurkis = (0.4 * (temp.vidurkis / temp.pazymiuSk)) + 0.6 * temp.egzaminas;

    fout << std::setw(20) << temp.mediana << std::setw(20) << temp.vidurkis << endl;

}

int pazymioIvedimas()
{
    while (true)
    {
        int pazimys = IntTikrinimas();
        if (PazTikrinimas(pazimys)) return pazimys;
    }
}

void skaitymas(std::ifstream& fin, std::vector<string>& length, std::vector<mokinys>& mokiniai)
{
    string t;
    while ((fin.peek() != '\n') && (fin >> t))
        length.push_back(t);
    length.resize(length.size() - 3);

    while (!fin.eof())
    {
        int p;
        mokinys t;
        fin >> t.vardas >> t.pavarde;
        for (auto& el : length)
        {
            fin >> p;
            t.pazymiai.push_back(p);
        }
        fin >> t.egzaminas;
        t.pazymiuSk = t.pazymiai.size();
        mokiniai.push_back(t);
    }
}