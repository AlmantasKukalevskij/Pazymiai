#include "tikrinimas.h"
#include "IvestisIsvestis.h"
#include "atsSk.h"
#include "generavimas.h"
#include "data.h"

#include <chrono>



bool egzaminas;
bool pazymys;
bool rezultatas;
bool manual;

int main()
{
    auto programStart = hrClock::now();

    cout << "Ar norite sugeneruoti failus (1/0)?" << endl;
    bool gen = validMode(0, 1);
    if (gen)
    {
        string genFile_name;
        cin.ignore();
        cout << "Kaip norite pavadinti faila?(kitaip bus mokiniai.txt)";
        genFile_name.empty() ? genFile_name = "mokiniai.txt" : genFile_name += ".txt";
        cout << "Kiek sugeneruoti mokiniu?" << endl;
        int MokCount;
        MokCount = IntTikrinimas();
        cout << "Kiek namu darbu sugeneruoti?" << endl;
        int ndCount;
        ndCount = IntTikrinimas();
        cout << "=======================" << endl;
        failoGen(MokCount, genFile_name, ndCount);
        return 0;
    }
    else
    {

        cout << "Ar norite vesti pazymius ranka (1), kitaip (0) pazymiai bus nuskaityti is failo" << endl;
        manual = validMode(0, 1);
    }
    if (!manual)
    {
        double fileOpenTime = 0;
        cout << "Pasirinkite tipa: 1 - vectorius, 2 - listas, 3 - deque" << endl;
        int type = validMode(1, 3);
        cout << "Kokia strategija norite naudotis, greitesne kuri naudoja daugiau atmintis - 1, ar 2 - letesne kuri uzima maziau atminties" << endl;
        int strategyType = validMode(1, 2);
        if (type == 1)
        {
            vector<mokinys> mokiniai;
            vector<mokinys> kietekai;
            vector<mokinys> vargsai;

            auto programStart = hrClock::now();

            if (strategyType == 1)
            { 
                buferioSkaitymas(mokiniai, "mokiniai1000.txt", gen, fileOpenTime);
                RezSk(mokiniai, rezultatas, manual);
                MokiniuSortiravimas(kietekai, vargsai, mokiniai);
            }
            else if (strategyType == 2)
            {
                buferioSkaitymas(mokiniai, "mokiniai1000.txt", gen, fileOpenTime);
                RezSk(mokiniai, rezultatas, manual);
                MokiniuSortiravimasV2(kietekai, vargsai);
            }
            std::sort(kietekai.begin(), kietekai.end(), [](mokinys& a, mokinys& b)
                {return a.vardas < b.vardas; });
            std::sort(vargsai.begin(), vargsai.end(), [](mokinys& a, mokinys& b)
                {return a.vardas < b.vardas; });

            auto write = hrClock::now();
            contToFile("kietekai.txt", kietekai);
            contToFile("vargsai.txt", vargsai);
            cout << "Isrusiuotu mokiniu surasymas i atskirus failus uztruko: " << durationDouble(hrClock::now() - write).count() << " sek." << endl;
            
        }
        else if (type == 2)
        {
            list<mokinys> mokiniai;
            list<mokinys> kietekai;
            list<mokinys> vargsai;

            auto programStart = hrClock::now();
            if (strategyType == 1)
            {
                buferioSkaitymas(mokiniai, "mokiniai1000.txt", gen, fileOpenTime);
                RezSk(mokiniai, rezultatas, manual);
                MokiniuSortiravimas(kietekai, vargsai, mokiniai);
            }
            else if (strategyType == 2)
            {
                buferioSkaitymas(mokiniai, "mokiniai1000.txt", gen, fileOpenTime);
                RezSk(mokiniai, rezultatas, manual);
                MokiniuSortiravimasV2(kietekai, vargsai);
            }

            kietekai.sort(lyginimas);
            vargsai.sort(lyginimas);

            auto write = hrClock::now();
            contToFile("kietekai.txt", kietekai);
            contToFile("vargsai.txt", vargsai);
            cout << "Isrusiuotu mokiniu surasymas i atskirus failus uztruko: " << durationDouble(hrClock::now() - write).count() << " sek." << endl;
        }
        else if (type == 3)
        {
            deque<mokinys> mokiniai;
            deque<mokinys> kietekai;
            deque<mokinys> vargsai;

            auto programStart = hrClock::now();
            if (strategyType == 1)
            {
                buferioSkaitymas(mokiniai, "mokiniai1000.txt", gen, fileOpenTime);
                RezSk(mokiniai, rezultatas, manual);
                MokiniuSortiravimas(kietekai, vargsai, mokiniai);
            }
            else if (strategyType == 2)
            {
                buferioSkaitymas(mokiniai, "mokiniai1000.txt", gen, fileOpenTime);
                RezSk(mokiniai, rezultatas, manual);
                MokiniuSortiravimasV2(kietekai, vargsai);
            }
            auto write = hrClock::now();
            std::sort(kietekai.begin(), kietekai.end(), [](mokinys& a, mokinys& b)
                {return a.vardas < b.vardas; });
            std::sort(vargsai.begin(), vargsai.end(), [](mokinys& a, mokinys& b)
                {return a.vardas < b.vardas; });

            contToFile("kietekai.txt", kietekai);
            contToFile("vargsai.txt", vargsai);
            cout << "Isrusiuotu mokiniu surasymas i atskirus failus uztruko: " << durationDouble(hrClock::now() - write).count() << " sek." << endl;
            
        }
        auto programosPabaiga = durationDouble(hrClock::now() - programStart).count() - fileOpenTime;
        cout << "Visos programos veikimo laikas: " << programosPabaiga << " sek." << endl;
        cout << "=======================" << endl;
    }
    else
    {
        vector<mokinys> mokiniai;
        cout << "Jeigu norite skaiciuoti vidurki spauskite 1, jeigu norite gauti mediana - 0" << endl;
        rezultatas = validMode(0, 1);
        cout << "Jeigu norite ivesti egzamino pazimi spauskite 1, jeigu norite automatiskai generuoti - 0" << endl;
        egzaminas = validMode(0, 1);
        cout << "Jeigu norite suvesti pazymius rankomis spauskite 1, jeigu norite automatiskai generuoti - 0" << endl;
        pazymys = validMode(0, 1);

        while (true)
        {
            cout << "Jeigu norite ivesti mokini spauskite 1, jeigu norite baigti - 0" << endl;
            bool run = validMode(0, 1);
            if (!run)
                break;
            else
            {
                mokinys temp;
                ivestis(temp);
                mokiniai.push_back(temp);
            }
        }
        RezSk(mokiniai, rezultatas, manual);
        std::sort(mokiniai.begin(), mokiniai.end(), [](mokinys& a, mokinys& b)
            {return a.vardas < b.vardas; });

        buferioRasymas("rezultatas.txt", mokiniai, manual, rezultatas);
        cout << "Programa veike: " << durationDouble(hrClock::now() - programStart).count() << " sek." << endl;
        cout << "==============================" << endl;
    }

}