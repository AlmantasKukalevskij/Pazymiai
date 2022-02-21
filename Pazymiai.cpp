#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;


struct mokinys
{
    string vardas = "", pavarde = "";
    int* pazymiai = nullptr;
    int pazymiuSk = 0;
    int egzaminas;
    double rezult = 0;
};

void ivestis(mokinys& temp, bool NDskaicius, bool kurimas);
void isved(mokinys& temp, bool mediana);
void RandomNdIvedimas(mokinys& temp, int pazimys);
int IntTikrinimas();
bool PazTikrinimas(int t);
int PazymioIvestis();
string atsakymoTikrinimas();

int main()
{


    bool NDskaicius = false;
    bool kurimas = false;
    bool mediana = false;
    bool MokiniuSkaicius = false;
    string Mediana;
    string DarbuSk;
    string generuotiNd;
    string mokiniuSkaicius;

    int mokiniuSk = 0;

    mokinys* visiMokiniai = nullptr;

    //cout << "iveskite mokiniu skaiciu: "; cin >> mokiniuSk;

    //mokinys* visiMokiniai = new mokinys[mokiniuSk];
    cout << " Ar norite gauti pazymiu mediana(taip), kitaip bus skaiciuojamas vidurkis (ne) ";  Mediana = atsakymoTikrinimas();
    if (Mediana == "taip")
    {
        cout << "Atsakymas bus skaiciuojamas su mediana" << endl;
        mediana = true;
    }
    else
    {
        cout << "Atsakymas bus skaiciuojamas su vidurkiu" << endl;
    }


    cout << "Ar namu darbu skaicius yra zinomas (taip/ne)?"; DarbuSk = atsakymoTikrinimas();
    if (DarbuSk == "taip")
    {
        cout << "Namu darbu skaicius zinomas" << endl;
        NDskaicius = true;
    }
    else
    {
        cout << "Namu darbu skaicius nezinomas" << endl;
    }


    cout << "Ar norite jog namu darbu pazymiai butu sugeneruoti automatiskai (taip/ne)?"; generuotiNd = atsakymoTikrinimas();
    if (generuotiNd == "taip")
    {
        cout << "Namu darbu pazymiai bus automatiskai sugeneruoti" << endl;
        kurimas = true;
    }
    else
    {
        cout << "Namu darbu pazymiai nebus automatiskai generuojami" << endl;
    }

    if (MokiniuSkaicius)
    {
        cout << "Iveskite studentu kieki: "; mokiniuSk = IntTikrinimas();
        visiMokiniai = new mokinys[mokiniuSk];
        for (mokinys* mokinys = visiMokiniai; mokinys < visiMokiniai + mokiniuSk; mokinys++) ivestis(*mokinys, NDskaicius, kurimas);
    }
    else
    {
        string mok;
        while (true) {
            cout << "Iveskite betkoki simboli ir spauskite Enter, kad ivesti " << mokiniuSk + 1 << " -a(-i) studenta arba stop ir enter, kad sustoti: ";
            cin >> mok;
            if (mok == "stop")
                break;
            mokiniuSk++;
            mokinys temp;
            ivestis(temp, NDskaicius, kurimas);
            mokinys* naujasMokinys = new mokinys[mokiniuSk - 1];
            for (int i = 0; i < mokiniuSk - 1; i++) naujasMokinys[i] = visiMokiniai[i];
            delete[] visiMokiniai;
            visiMokiniai = new mokinys[mokiniuSk];
            for (int i = 0; i < mokiniuSk - 1; i++) visiMokiniai[i] = naujasMokinys[i];
            visiMokiniai[mokiniuSk - 1] = temp;
            delete[] naujasMokinys;
        }
    }




    if (mediana) cout << std::setw(20) << "PAVARDE" << std::setw(20) << "VARDAS" << std::setw(20) << "GALUTINE MEDIANA" << endl;
    else cout << std::setw(20) << "PAVARDE" << std::setw(20) << "VARDAS" << std::setw(20) << "GALUTINIS VIDURKIS" << endl;

    for (mokinys* mokinys = visiMokiniai; mokinys < visiMokiniai + mokiniuSk; mokinys++) isved(*mokinys, mediana);
}
void ivestis(mokinys& temp, bool NDskaicius, bool kurimas)
{
    cout << endl;

    cout << "Veskite varda: "; cin >> temp.vardas;
    cout << "Veskite pavarde: "; cin >> temp.pavarde;


    if (NDskaicius)
    {
        cout << "Iveskite namu darbu skaiciu: "; temp.pazymiuSk = IntTikrinimas();

        temp.pazymiai = new int[temp.pazymiuSk];
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
                temp.pazymiai[i] = PazymioIvestis();
            }
            cout << "Veskite egzamino ivertinima: "; temp.egzaminas = PazymioIvestis();
        }

    }
    else
    {
        if (kurimas)
        {
            int pazimys;

            while (true)
            {
                cout << "Spauskite Enter tiek kartu, kiek norite sugeneruoti pazimi " << temp.pazymiuSk + 1 << " arba kita klavisa jeigu norite sustoti" << endl;
                if (cin.get() != '\n')
                    break;
                pazimys = rand() % 10 + 1;
                cout << "Sukurtas pazimys yra: " << pazimys << endl;
                RandomNdIvedimas(temp, pazimys);

            }
            temp.egzaminas = rand() % 10 + 1;
            cout << "Mokinio egzamino pazimys: " << temp.egzaminas << endl;
        }
        else
        {
            int pazimys;

            while (true)
            {
                cout << "Iveskite pazimi" << temp.pazymiuSk + 1 << " arba 0 jeigu norite baigti "; pazimys = IntTikrinimas();
                if (pazimys == 0)
                    break;
                while (true)
                {
                    if (PazTikrinimas(pazimys))
                        break;
                }
                RandomNdIvedimas(temp, pazimys);
            }
            cout << "Iveskite egzamino pazimi "; cin >> temp.egzaminas;
        }

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
            cout << "Ivedete neteisinga reiksme" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
}

bool PazTikrinimas(int pazimys)
{
    if (pazimys > 0 && pazimys <= 10)
        return true;
    else
    {
        cout << "Ivestas neteisingas pazimys (desimtbale sistema)" << endl;
        return false;
    }
}

int PazymioIvestis()
{
    while (true)
    {
        int pazimys = IntTikrinimas();
        if (PazTikrinimas(pazimys)) return pazimys;
    }
}

string atsakymoTikrinimas() {
    string ats;
    do {
        cin >> ats;
        if (ats != "taip" && ats != "ne")
        {
            cout << ats;
            cout << " Sis ataskymas klaidingas! (turi buti tik taip arba ne)" << endl;
        }
    } while (ats != "taip" && ats != "ne");
    return ats;
}

void RandomNdIvedimas(mokinys& temp, int pazimys)
{
    int* data = new int[temp.pazymiuSk];
    for (int i = 0; i < temp.pazymiuSk; i++) data[i] = temp.pazymiai[i];
    delete[] temp.pazymiai;
    temp.pazymiuSk++;
    temp.pazymiai = new int[temp.pazymiuSk];
    for (int i = 0; i < temp.pazymiuSk - 1; i++) temp.pazymiai[i] = data[i];
    temp.pazymiai[temp.pazymiuSk - 1] = pazimys;

}




