#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;

struct mokinys
{
    string vardas = "", pavarde = "";
    vector<int> pazymiai;
    int pazymiuSk = 0;
    int egzaminas;
    double rezult = 0;
    double vidurkis = 0;
    double mediana = 0;
};

void ivestis(mokinys& temp, bool kurimas);
void isved(mokinys& temp, ofstream& fout);
//void RandomNdIvedimas(mokinys& temp, int pazimys);
bool PazTikrinimas(int t);
int pazymioIvedimas();
int IntTikrinimas();
string atsakymoTikrinimas();
void skaitymas(ifstream& fin, vector<string>& length, vector<mokinys>& mokiniai);



//bool egzaminas;
//bool pazimys;
//bool rezultatas;
bool suvedimas;


int main()
{
    srand(time(NULL));

    bool kurimas = false;
    bool mediana = false;
    bool mokiniuSkaicius = false;
    string Mediana;
    string generuotiNd;
    string MokiniuSkaicius;
    string failoNuskaitymas;

    int mokiniuSk = 0;

    //cout << "iveskite mokiniu skaiciu: "; cin >> mokiniuSk;
    //mokinys* VisiMokiniai = new mokinys[mokiniuSk];

    vector<mokinys> VisiMokiniai;
    std::ofstream fout("atsakymai.txt");

    cout << "Ar norite vesti pazymius ranka (taip), kitaip (ne) pazymiai bus nuskaityti is failo" << endl;
    failoNuskaitymas = atsakymoTikrinimas();


    if (failoNuskaitymas == "ne")
    {
        vector<string> length;
        std::ifstream fin("mokiniai.txt");
        skaitymas(fin, length, VisiMokiniai);
    }
    else
    {

        cout << " Ar norite gauti pazymiu mediana(taip), kitaip bus skaiciuojamas vidurkis (ne) ";
        Mediana = atsakymoTikrinimas();
        if (Mediana == "taip")
        {
            cout << "Atsakymas bus skaiciuojamas su mediana" << endl;
            mediana = true;
        }
        else
        {
            cout << "Atsakymas bus skaiciuojamas su vidurkiu" << endl;
        }

        cout << "Ar mokiniu skaicius yra zinomas (taip/ne)?";
        MokiniuSkaicius = atsakymoTikrinimas();
        if (MokiniuSkaicius == "taip")
        {
            cout << "Mokiniu skaicius zinomas" << endl;
            mokiniuSkaicius = true;
        }
        else
        {
            cout << "Mokiniu skaicius nezinomas" << endl;
        }


        cout << "Ar norite jog namu darbu pazymiai butu sugeneruoti automatiskai (taip/ne)?";
        generuotiNd = atsakymoTikrinimas();
        if (generuotiNd == "taip")
        {
            cout << "Namu darbu pazymiai bus automatiskai sugeneruoti" << endl;
            kurimas = true;
        }
        else
        {
            cout << "Namu darbu pazymiai nebus automatiskai generuojami" << endl;
        }

        if (mokiniuSkaicius)
        {
            cout << "Iveskite mokiniu skaiciu: ";
            mokiniuSk = IntTikrinimas();
            for (int i = 0; i < mokiniuSk; i++)
            {
                mokinys data;
                ivestis(data, kurimas);
                VisiMokiniai.push_back(data);
            }
        }
        else
        {
            string mok;
            while (true)
            {
                cout << "Ar norite irasyti dar viena mokini? (taip/ne) ";  mok = atsakymoTikrinimas();
                if (mok == "ne")
                    break;
                mokinys data;
                ivestis(data, kurimas);
                VisiMokiniai.push_back(data);
            }

        }


    }



    std::sort(VisiMokiniai.begin(), VisiMokiniai.end(), [](mokinys& a, mokinys& b) {return a.vardas < b.vardas; });
    fout << std::setw(20) << "VARDAS" << std::setw(20) << "PAVARDE" << std::setw(20) << "VIDURKIS" << std::setw(20) << "MEDIANA" << endl;
    fout << "====================================================================================" << endl;

    for (mokinys mokinys : VisiMokiniai) isved(mokinys, fout);


}
void ivestis(mokinys& temp, bool kurimas)
{
    cout << endl;

    cout << "Veskite varda: "; cin >> temp.vardas;
    cout << "Veskite pavarde: "; cin >> temp.pavarde;

    cout << "Iveskite namu darbu skaiciu: ";
    temp.pazymiuSk = IntTikrinimas();


    //temp.pazymiai = new int[temp.pazymiuSk];
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
        t.pazymiuSk = t.pazymiai.size(); // what it do?
        mokiniai.push_back(t);
    }
}