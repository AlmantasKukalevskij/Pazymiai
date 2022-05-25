#include "data.h"
#include "tikrinimas.h"
#include "IvestisIsvestis.h"

//int pazymioivedimas();

void ivestis(mokinys& temp)
{
    cout << endl;

    cout << "Veskite varda: "; cin >> temp.vardas;
    cout << "Veskite pavarde: "; cin >> temp.pavarde;

    if (egzaminas)
    {
        cout << "Iveskite egzamino pazimi: ";
        while (true)
        {
            int egzaminas = IntTikrinimas();
            if (PazTikrinimas(egzaminas))
            {
                temp.egzaminas = egzaminas;
                break;
            }
        }
    }
    else
        temp.egzaminas = randomInt(1, 10);
    
    if (pazymys)
        rankinisPazIvedimas(temp);
    else
        atsitiktinioPazKurimas(temp);
    cout << "Pazymiai ivesti" << endl;
}

void rankinisPazIvedimas(mokinys& temp)
{
    cout << "Iveskite pazymius, norit baigti iveskite 0" << endl;

    int t;
    while (true)
    {
        t = IntTikrinimas();
        if (t == 0)
            break;
        else if (PazTikrinimas(t))
            temp.pazymiai.push_back(t);
    }
}




void buferioSkaitymas(vector<mokinys>& mokiniai, string file_name, bool gen, double& fopenTime)
{
    std::string line;
    std::stringstream buffer;

    std::ifstream open_f;
    auto stime = hrClock::now();
    openFile(open_f);
    fopenTime = durationDouble(hrClock::now() - stime).count();

    auto readStart = hrClock::now();
    buffer << open_f.rdbuf();
    open_f.close();
    std::getline(buffer, line);
    
    int counter = 0;
    while (buffer)
    {
        std::getline(buffer, line);
        if (line.length() == 0)
            break;
        mokinys t;
        std::istringstream lineStream(line);
        lineStream >> t.vardas >> t.pavarde;
        int mark;
        while (lineStream >> mark)
        {
            t.pazymiai.push_back(mark);
        }
        t.egzaminas = t.pazymiai.back();
        t.pazymiai.pop_back();
        mokiniai.push_back(t);
    }
    cout << "Failo nuskaitymas uztruko: " << durationDouble(hrClock::now() - readStart).count() << " sek." << endl;
}

void buferioSkaitymas(list<mokinys>& mokiniai, string file_name, bool gen, double& fopenTime)
{
    std::string line;
    std::stringstream buffer;

    std::ifstream open_f;
    auto stime = hrClock::now();
    openFile(open_f);
    fopenTime = durationDouble(hrClock::now() - stime).count();

    auto readStart = hrClock::now();
    buffer << open_f.rdbuf();
    open_f.close();
    std::getline(buffer, line);

    int counter = 0;
    while (buffer)
    {
        std::getline(buffer, line);
        if (line.length() == 0)
            break;
        mokinys t;
        std::istringstream lineStream(line);
        lineStream >> t.vardas >> t.pavarde;
        int mark;
        while (lineStream >> mark)
        {
            t.pazymiai.push_back(mark);
        }
        t.egzaminas = t.pazymiai.back();
        t.pazymiai.pop_back();
        mokiniai.push_back(t);
    }
    cout << "Failo nuskaitymas uztruko: " << durationDouble(hrClock::now() - readStart).count() << " sek." << endl;
}

void buferioSkaitymas(deque<mokinys>& mokiniai, string file_name, bool gen, double& fopenTime)
{
    std::string line;
    std::stringstream buffer;

    std::ifstream open_f;
    auto stime = hrClock::now();
    openFile(open_f);
    fopenTime = durationDouble(hrClock::now() - stime).count();

    auto readStart = hrClock::now();
    buffer << open_f.rdbuf();
    open_f.close();
    std::getline(buffer, line);

    int counter = 0;
    while (buffer)
    {
        std::getline(buffer, line);
        if (line.length() == 0)
            break;
        mokinys t;
        std::istringstream lineStream(line);
        lineStream >> t.vardas >> t.pavarde;
        int mark;
        while (lineStream >> mark)
        {
            t.pazymiai.push_back(mark);
        }
        t.egzaminas = t.pazymiai.back();
        t.pazymiai.pop_back();
        mokiniai.push_back(t);
    }
    cout << "Failo nuskaitymas uztruko: " << durationDouble(hrClock::now() - readStart).count() << " sek." << endl;
}

void buferioRasymas(std::string write_vardas, vector<mokinys>& mokiniai, bool manual, bool rez)
{
    std::stringstream isvestis;

    isvestis << left << setw(20) << "Vardas";
    isvestis << left << setw(20) << "Pavarde";
    if (rez || !manual)
    isvestis << std::left << std::setw(20) << "Vidurkis";
    if(!rez || !manual)
    isvestis << std::left << std::setw(20) << "Mediana";
    isvestis << endl;
    if (!manual)
    {
        for (auto& mok : mokiniai)
        {
            isvestis << left << setw(20) << mok.vardas;
            isvestis << left << setw(20) << mok.pavarde;
            isvestis << left << setw(20) << mok.vidurkis;
            isvestis << left << setw(20) << mok.mediana;
            isvestis << endl;
        }
    }
    else if (rez)
    {
        for (auto& mok : mokiniai)
        {
            isvestis << left << setw(20) << mok.vardas;
            isvestis << left << setw(20) << mok.pavarde;
            isvestis << left << setw(20) << mok.vidurkis;
            isvestis << endl;
        }
    }
    else if (!rez)
    {
        for (auto& mok : mokiniai)
        {
            isvestis << left << setw(20) << mok.vardas;
            isvestis << left << setw(20) << mok.pavarde;
            isvestis << left << setw(20) << mok.mediana;
            isvestis << endl;
        }
    }

    mokiniai.clear();
    std::ofstream file_out(write_vardas);
    file_out << isvestis.rdbuf();
    file_out.close();

}

void buferioRasymas(std::string write_vardas, list<mokinys>& mokiniai, bool manual, bool rez)
{
    std::stringstream isvestis;

    isvestis << left << setw(20) << "Vardas";
    isvestis << left << setw(20) << "Pavarde";
    if (rez || !manual)
        isvestis << std::left << std::setw(20) << "Vidurkis";
    if (!rez || !manual)
        isvestis << std::left << std::setw(20) << "Mediana";
    isvestis << endl;
    if (!manual)
    {
        for (auto& mok : mokiniai)
        {
            isvestis << left << setw(20) << mok.vardas;
            isvestis << left << setw(20) << mok.pavarde;
            isvestis << left << setw(20) << mok.vidurkis;
            isvestis << left << setw(20) << mok.mediana;
            isvestis << endl;
        }
    }
    else if (rez)
    {
        for (auto& mok : mokiniai)
        {
            isvestis << left << setw(20) << mok.vardas;
            isvestis << left << setw(20) << mok.pavarde;
            isvestis << left << setw(20) << mok.vidurkis;
            isvestis << endl;
        }
    }
    else if (!rez)
    {
        for (auto& mok : mokiniai)
        {
            isvestis << left << setw(20) << mok.vardas;
            isvestis << left << setw(20) << mok.pavarde;
            isvestis << left << setw(20) << mok.mediana;
            isvestis << endl;
        }
    }

    mokiniai.clear();
    std::ofstream file_out(write_vardas);
    file_out << isvestis.rdbuf();
    file_out.close();

}

void buferioRasymas(std::string write_vardas, deque<mokinys>& mokiniai, bool manual, bool rez)
{
    std::stringstream isvestis;

    isvestis << left << setw(20) << "Vardas";
    isvestis << left << setw(20) << "Pavarde";
    if (rez || !manual)
        isvestis << std::left << std::setw(20) << "Vidurkis";
    if (!rez || !manual)
        isvestis << std::left << std::setw(20) << "Mediana";
    isvestis << endl;
    if (!manual)
    {
        for (auto& mok : mokiniai)
        {
            isvestis << left << setw(20) << mok.vardas;
            isvestis << left << setw(20) << mok.pavarde;
            isvestis << left << setw(20) << mok.vidurkis;
            isvestis << left << setw(20) << mok.mediana;
            isvestis << endl;
        }
    }
    else if (rez)
    {
        for (auto& mok : mokiniai)
        {
            isvestis << left << setw(20) << mok.vardas;
            isvestis << left << setw(20) << mok.pavarde;
            isvestis << left << setw(20) << mok.vidurkis;
            isvestis << endl;
        }
    }
    else if (!rez)
    {
        for (auto& mok : mokiniai)
        {
            isvestis << left << setw(20) << mok.vardas;
            isvestis << left << setw(20) << mok.pavarde;
            isvestis << left << setw(20) << mok.mediana;
            isvestis << endl;
        }
    }

    mokiniai.clear();
    std::ofstream file_out(write_vardas);
    file_out << isvestis.rdbuf();
    file_out.close();

}

void failoGen(int size, string file_name, int ndSkaicius)
{
    auto genStart = hrClock::now();
    std::stringstream isvestis;
    isvestis << left << setw(20) << "Vardas";
    isvestis << left << setw(20) << "Pavarde";
    for (int i = 1; i <= ndSkaicius; i++)
    {
        isvestis << left << "ND" << setw(5) << i;
    }
    isvestis << left << setw(7) << "Egzaminas" << endl;
    for (int i = 0; i < size; i++)
    {
        isvestis << genMokString(ndSkaicius).str();
    }
    std::ofstream file_out(file_name);
    file_out << isvestis.rdbuf();
    file_out.close();
    cout << size << " Irasu failo generavimo laikas: "<<durationDouble(hrClock::now() - genStart).count() << " sek." << endl;
}

void contToFile(string file_name, vector<mokinys>& data)
{
    std::stringstream isvestis;
    isvestis << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vid." << std::left << std::setw(20) << "Med." << endl;
    for (auto& mok : data)
    {
        isvestis << std::left << std::setw(20) << mok.vardas;
        isvestis << std::left << std::setw(20) << mok.pavarde;
        isvestis << std::left << std::setw(20) << mok.vidurkis;
        isvestis << std::left << std::setw(20) << mok.mediana;
        isvestis << endl;
    }
    std::ofstream file_out(file_name);
    file_out << isvestis.rdbuf();
    file_out.close();
}

void contToFile(string file_name, list<mokinys>& data)
{
    std::stringstream isvestis;
    isvestis << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vid." << std::left << std::setw(20) << "Med." << endl;
    for (auto& mok : data)
    {
        isvestis << std::left << std::setw(20) << mok.vardas;
        isvestis << std::left << std::setw(20) << mok.pavarde;
        isvestis << std::left << std::setw(20) << mok.vidurkis;
        isvestis << std::left << std::setw(20) << mok.mediana;
        isvestis << endl;
    }
    std::ofstream file_out(file_name);
    file_out << isvestis.rdbuf();
    file_out.close();
}

void contToFile(string file_name, deque<mokinys>& data)
{
    std::stringstream isvestis;
    isvestis << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vid." << std::left << std::setw(20) << "Med." << endl;
    for (auto& mok : data)
    {
        isvestis << std::left << std::setw(20) << mok.vardas;
        isvestis << std::left << std::setw(20) << mok.pavarde;
        isvestis << std::left << std::setw(20) << mok.vidurkis;
        isvestis << std::left << std::setw(20) << mok.mediana;
        isvestis << endl;
    }
    std::ofstream file_out(file_name);
    file_out << isvestis.rdbuf();
    file_out.close();
}

void openFile(std::ifstream& open_f)
{
    bool err = true;
    cin.ignore();
    while(err)
    {
        cout << "Iveskite failo pavadinima, kitaip bus mokiniai.txt";
        string file_name;
        getline(cin, file_name);

        if (file_name.empty())
            file_name = "mokiniai.txt";
        try
        {
            open_f.open(file_name);
            if (open_f.fail())
                throw std::invalid_argument("Ivestas neteisingas failo pavadinimas");
            err = false;
        }
        catch (const std::invalid_argument& e)
        {
            cout << e.what() << std::endl;
        }
    }
}