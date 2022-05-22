#include "data.h"
#include "tikrinimas.h"
#include "IvestisIsvestis.h"
#include "atsSk.h"
#include "generavimas.h"

#include <chrono>





int main()
{
    auto programStart = hrClock::now();

    srand(time(NULL));

    bool kurimas = false;
    // bool mediana = false;
    bool mokiniuSkaicius = false;
    bool failoGeneravimas = false;
    bool failoSkaitymas = false;

    string generuotiNd;
    string MokiniuSkaicius;
    string failoNuskaitymas;
    string atsFailoGeneravimas;
    int mokiniuSk = 0;

    string genFile_name;

    vector<mokinys> VisiMokiniai;

    //vector<string> length;
    //std::ofstream fout("atsakymai.txt");

    //cout << "Ar norite sugeneruoti faila?(taip/ne)" << endl;
    //atsFailoGeneravimas = atsakymoTikrinimas();
    //if (atsFailoGeneravimas=="taip")
    //{
    //    cin.ignore();
    //    cout << "Iveskite norima failo pavadinima(kitaip liks mokiniai.txt)";
    //    
    //}



    cout << "Ar norite vesti pazymius ranka (taip), kitaip (ne) pazymiai bus nuskaityti is failo" << endl;
    failoNuskaitymas = atsakymoTikrinimas();
    if (failoNuskaitymas == "ne")
    {
        cout << "Ar norite mokiniu duomenis sugeneruoti automatiskai? (taip/ne) "; atsFailoGeneravimas = atsakymoTikrinimas();
        if (atsFailoGeneravimas == "taip")
        {

            cin.ignore();
            cout << "Iveskite failo pavadinima (kitaip bus mokiniai.txt)";
            getline(cin, genFile_name);
            genFile_name.empty() ? genFile_name = "mokiniai1.txt" : genFile_name += ".txt";
            cout << "Kiek generuoti mokiniu?" << endl;
            int mokSkaicius;
            mokSkaicius = IntTikrinimas();
            VisiMokiniai.reserve(mokSkaicius);
            cout << "Kiek generuoti namu darbu?" << endl;
            int ndSkaicius;
            ndSkaicius = IntTikrinimas();
            cout << "===================" << endl;
            cout << mokSkaicius << "irasu testavimas" << endl;
            auto genStart = hrClock::now();
            failoGen(mokSkaicius, genFile_name, ndSkaicius);
            cout << "Failo generavimo laikas: " << durationDouble(hrClock::now() - genStart).count() << " sek" << endl;

            buferioSkaitymas(VisiMokiniai, genFile_name);
        }
        else {
            vector<string> Antraste;
            try
            {
                buferioSkaitymas(VisiMokiniai, "mokiniai.txt");
            }
            catch (const std::exception&)
            {
                cout << "ivesties txt failas mokiniai nerastas" << endl;
            }

        }

        galutinisMedVid(VisiMokiniai);

        std::sort(VisiMokiniai.begin(), VisiMokiniai.end(), [](mokinys& a, mokinys& b) {return a.vardas < b.vardas;  });

        auto sortStart = hrClock::now();
        vector<mokinys> kietekai;
        vector<mokinys> vargsai;
        MokiniuSortiravimas(kietekai, vargsai, VisiMokiniai);
        cout << "Mokinius padalinti i dvi grupes uztruko: " << durationDouble(hrClock::now() - sortStart).count() << " sek." << endl;

        auto newWrite = hrClock::now();
        vectoriusToFile("kietekai.txt", kietekai);
        vectoriusToFile("vargsai.txt", vargsai);
        cout << "Surusiuotu mokini? isvedimas i naujus failus uztruko: " << durationDouble(hrClock::now() - newWrite).count() << " sek." << endl;



    }
    else
    {


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
                mokinys data;
                ivestis(data, kurimas);
                VisiMokiniai.push_back(data);
                cout << "Ar norite irasyti dar viena mokini? (taip/ne) ";  mok = atsakymoTikrinimas();
                if (mok == "ne")
                    break;

            }

        }

        galutinisMedVid(VisiMokiniai);
        std::sort(VisiMokiniai.begin(), VisiMokiniai.end(), [](mokinys& a, mokinys& b) {return a.vardas < b.vardas; });
        buferioRasymas(VisiMokiniai);
    }


    cout << "Programa veike: " << durationDouble(hrClock::now() - programStart).count() << " sek." << endl;
    cout << "==============================" << endl;



}