#include "data.h"
#include "tikrinimas.h"

int pazymioivedimas();

void ivestis(mokinys& temp, bool kurimas)
{
    cout << endl;

    cout << "Veskite varda: "; cin >> temp.vardas;
    cout << "Veskite pavarde: "; cin >> temp.pavarde;

    cout << "Iveskite namu darbu skaiciu: ";
    temp.pazymiuSk = IntTikrinimas();
    cout << endl;


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
            temp.pazymiai.push_back(pazymioivedimas());
        }
        cout << "Veskite egzamino ivertinima: ";
        temp.egzaminas = pazymioivedimas();
    }

    cout << endl;

}




void buferioSkaitymas(vector<mokinys>& mokiniai, string file_name)
{
    std::string line;
    std::stringstream buffer;

    std::ifstream open_f(file_name);

    buffer << open_f.rdbuf();
    open_f.close();
    std::getline(buffer, line);

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

}

void buferioRasymas(vector<mokinys>& mokiniai)
{
    std::stringstream isvestis;

    isvestis << std::left << std::setw(20) << "Vardas";
    isvestis << std::left << std::setw(20) << "Pavarde";
    isvestis << std::left << std::setw(20) << "Vidurkis";
    isvestis << std::left << std::setw(20) << "Mediana";
    isvestis << endl;

    for (auto& mok : mokiniai)
    {
        isvestis << std::left << std::setw(20) << mok.vardas;
        isvestis << std::left << std::setw(20) << mok.pavarde;
        isvestis << std::left << std::setw(20) << mok.vidurkis;
        isvestis << std::left << std::setw(20) << mok.mediana;
        isvestis << endl;
    }

    mokiniai.clear();
    std::ofstream file_out("rezultatas.txt");
    file_out << isvestis.rdbuf();
    file_out.close();

}
void vectoriusToFile(string file_name, vector<mokinys>& data)
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

int pazymioivedimas()
{
    while (true)
    {
        int pazimys = IntTikrinimas();
        if (PazTikrinimas(pazimys)) return pazimys;
    }
}