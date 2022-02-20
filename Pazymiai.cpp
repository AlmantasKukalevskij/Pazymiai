

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct mokinys {
    string vardas = "",
        pavarde = "";
    int* pazymiai = nullptr;
    int pazymiuSk = 0;
    int egzaminas;
    double rezult = 0;
};

void ivestis(mokinys& temp, bool NDskaicius, bool kurimas);
void isved(mokinys& temp, bool mediana);
void RandomNdGeneravimas(mokinys& temp, int pazimys);

int main()
{
    srand(time(NULL));

    bool NDskaicius = false;
    bool kurimas = false;
    bool mediana = false;
    string Mediana;
    string DarbuSk;
    string generuotiNd;

    int mokiniuSk = 0;

    cout << "iveskite mokiniu skaiciu: "; cin >> mokiniuSk;
    
    mokinys* VisiMokiniai = new mokinys[mokiniuSk];
    cout << " Ar norite gauti pazymiu mediana(taip), kitaip bus skaiciuojamas vidurkis (ne) "; cin >> Mediana;
    if (Mediana == "taip")
    {
        cout << "Atsakymas bus skaiciuojamas su mediana" << endl;
        mediana = true;
    }
    else
    {
        cout << "Atsakymas bus skaiciuojamas su vidurkiu" << endl;
    }


    cout << "Ar namu darbu skaicius yra zinomas (taip/ne)?"; cin >> DarbuSk;
    if (DarbuSk == "taip")
    {
        cout << "Namu darbu skaicius zinomas" << endl;
        NDskaicius = true;
    }
    else
    {
        cout << "Namu darbu skaicius nezinomas" << endl;
    }


    cout << "Ar norite jog namu darbu pazymiai butu sugeneruoti automatiskai (taip/ne)?"; cin >> generuotiNd;
    if (generuotiNd == "taip")
    {
        cout << "Namu darbu pazymiai bus automatiskai sugeneruoti" << endl;
        kurimas = true;
    }
    else
    {
        cout << "Namu darbu pazymiai nebus automatiskai generuojami" << endl;
    }


    for (mokinys* mokinys = VisiMokiniai; mokinys < VisiMokiniai + mokiniuSk; mokinys++) ivestis(*mokinys, NDskaicius, kurimas);

    if (mediana) cout << std::setw(20) << "PAVARDE" << std::setw(20) << "VARDAS" << std::setw(20) << "GALUTINE MEDIANA" << endl;
    else cout << std::setw(20) << "PAVARDE" << std::setw(20) << "VARDAS" << std::setw(20) << "GALUTINIS VIDURKIS" << endl;

    for (mokinys* mokinys = VisiMokiniai; mokinys < VisiMokiniai + mokiniuSk; mokinys++) isved(*mokinys, mediana);
 }
void ivestis(mokinys& temp, bool NDskaicius, bool kurimas)
{
    cout << endl;

    cout << "Veskite varda: "; cin >> temp.vardas;
    cout << "Veskite pavarde: "; cin >> temp.pavarde;


    if (NDskaicius)
    {
        cout << "Iveskite namu darbu skaiciu: "; cin >> temp.pazymiuSk;
        
        temp.pazymiai = new int[temp.pazymiuSk];
        if (kurimas)
        {
            cout << "dgzasgesgdsfhgsdhsdfh";
                cout << "dgzasgesgdsfhgsdhsdfh";
                cout << "dgzasgesgdsfhgsdhsdfh";
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
                cin >> temp.pazymiai[i];
            }
            cout << "Veskite egzamino ivertinima: "; cin >> temp.egzaminas;
        }

    }
    else
    {
        if (kurimas)
        {
            int pazimys;
            
            while (true)
            {
                cout << "Spauskite Enter tiek kartu, kiek norite sugeneruoti pazimi" << temp.pazymiuSk + 1 << "arba kita klavisa jeigu norite sustoti" << endl;
                if (cin.get() != '\n')
                    break;
                pazimys = rand() % 10 + 1;
                cout << "Sukurtas pazimys yra: " << pazimys << endl;
                RandomNdGeneravimas(temp, pazimys);

            }
            temp.egzaminas = rand() % 10 + 1;
            cout << "Mokinio egzamino pazimys: " << temp.egzaminas << endl;
        }
        else
        {
            int pazimys;
            
            while (true)
            {
                cout << "Iveskite pazimi" << temp.pazymiuSk + 1 << " arba 0 jeigu norite baigti "; cin >> pazimys;
                if (pazimys == 0)
                    break;
                RandomNdGeneravimas(temp, pazimys);
            }
        cout << "Iveskite egzamino pazimi "; cin >> temp.egzaminas;
        }

    }
    cout <<  endl;
    
}

void isved(mokinys& temp, bool mediana) 
{
    cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde;

    if(mediana) 
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

bool PazTikrinimas(int t)
{
    if (t > 0 && t <= 10)
        return true;
    else
    {
        cout << "Ivestas neteisingas pazimys (desimtbale sistema)" << endl;
        return false;
    }
}

void RandomNdGeneravimas(mokinys& temp, int pazimys)
{
    int* data = new int[temp.pazymiuSk];
    for (int i = 0; i < temp.pazymiuSk; i++) data[i] = temp.pazymiai[i];
    delete[] temp.pazymiai;
    temp.pazymiuSk++;
    temp.pazymiai = new int[temp.pazymiuSk];
    for (int i = 0; i < temp.pazymiuSk - 1; i++) temp.pazymiai[i] = data[i];
    temp.pazymiai[temp.pazymiuSk - 1] = pazimys;

}






