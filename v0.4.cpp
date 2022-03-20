#include "data.h"
#include "tikrinimas.h"
#include "IvestisIsvestis.h"
#include "atsSk.h"

bool egzaminas;
bool pazymys;
bool rezultatas;
bool manual;

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



    vector<mokinys> VisiMokiniai;
    vector<string> length;
    std::ofstream fout("atsakymai.txt");

    cout << "Ar norite vesti pazymius ranka (taip), kitaip (ne) pazymiai bus nuskaityti is failo" << endl;
    failoNuskaitymas = atsakymoTikrinimas();


    if (failoNuskaitymas == "ne")
    {
        try
        {
            std::ifstream fin("mokiniai.txt");
            skaitymas(fin, length, VisiMokiniai);
        }
        catch (const std::exception&)
        {
            cout << "ivesties txt failas mokiniai nerastas" << endl;
        }


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
