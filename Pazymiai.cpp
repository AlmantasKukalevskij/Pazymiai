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
    //int pazymiuSk = 0;
    int egzaminas;
    double rezult = 0;
};

void ivestis(mokinys& temp, bool kurimas);
void isved(mokinys& temp, bool mediana, std::ofstream &fout);
//ka fout daro? iraso info i txt?
//void RandomNdIvedimas(mokinys& temp, int pazimys);
bool PazTikrinimas(int t);
int pazymioIvedimas();
int IntTikrinimas();
string atsakymoTikrinimas();
void skaitymas(ifstream& fin, vector<string>& length, vector<mokinys> &mokiniai);


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

    cout << "Ar norite vesti pazymius ranka (taip), kitaip (ne) pazymiai bus nuskaityti is failo" << endl;
    failoNuskaitymas = atsakymoTikrinimas();

    vector<string> length; 
    vector<mokinys> mokiniai;
    std::ofstream fout("rezultatai.txt");

    if (suvedimas == false)
    {
        std::ifstream fin("mokiniai.txt");
            skaitymas(fin, length, mokiniai);
    }
    else
    {
        //sukeliam visus pries tai keltus klausimus i else, jeigu pasirenkama irasyti info ranka
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



    }

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

    std::sort(mokiniai.begin(), mokiniai.end(), [](mokinys& a, mokinys& b) {return a.vardas < b.vardas; });;

    if (mediana) cout << std::setw(20) << "PAVARDE" << std::setw(20) << "VARDAS" << std::setw(20) << "GALUTINE MEDIANA" << endl;
    else cout << std::setw(20) << "PAVARDE" << std::setw(20) << "VARDAS" << std::setw(20) << "GALUTINIS VIDURKIS" << endl;

    for (mokinys mokinys : VisiMokiniai) isved(mokinys, mediana);
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
            temp.pazymiai[i] = rand() % 10 + 1;
            cout << "Ivestas" << i + 1 << " pazimys bus: " << temp.pazymiai[i] << endl;
        }
        temp.egzaminas = rand() % 10 + 1;
        cout << "Egzamino pazimys bus: " << temp.egzaminas << endl;
    }
    else
    {
        for (int i = 0; i < temp.pazymiuSk; i++) {
            cout << "Iveskite " << i + 1 << " -a(-i) pazymi: ";
            temp.pazymiai[i] = pazymioIvedimas();
        }
        cout << "Veskite egzamino ivertinima: ";
        temp.egzaminas = pazymioIvedimas();
    }

    cout << endl;

}

void isved(mokinys& temp, bool mediana)
{
    cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde;

    if (mediana)
    {
        std::sort(temp.pazymiai, temp.pazymiai + temp.pazymiuSk);
        if (temp.pazymiuSk % 2 != 0)
            temp.rezult = 0.4 * (double)temp.pazymiai[temp.pazymiuSk / 2] + 0.6 * temp.egzaminas;
        else
            temp.rezult = 0.4 * ((double)(temp.pazymiai[(temp.pazymiuSk - 1) / 2] + temp.pazymiai[temp.pazymiuSk / 2]) / 2.0) + 0.6 * temp.egzaminas;
    }
    else
    {
        for (int i = 0; i < temp.pazymiuSk; i++) temp.rezult += temp.pazymiai[i] * 1.0;
        temp.rezult = (0.44 * (temp.rezult / temp.pazymiuSk)) + 0.6 * temp.egzaminas;
    }

    cout << std::setw(20) << temp.rezult << endl;
    delete[] temp.pazymiai;
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
            t.pazymiuSk.push_back(p);
        }
        fin >> t.egzaminas;
        t.pazymiuSk = t.pazymiai.size(); // what it do?
        mokiniai.push_back(t);
    }
}