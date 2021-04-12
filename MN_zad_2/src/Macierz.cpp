#include "Macierz.h"

Macierz::Macierz()
{
    resetKonfig();
}

Macierz::Macierz(uint kolumny, uint wiersze)
{
    resetKonfig();
    allocateMemory(kolumny,wiersze);
}

Macierz::Macierz(std::string nazwa_pliku)
{
    resetKonfig();
    loadFromFile(nazwa_pliku);
}

Macierz::~Macierz()
{
    Clear();
}

void Macierz::resetKonfig()
{
    show_steps = false;
    raport.reset();
}

void Macierz::Clear()
{
    for(uint i=0; i<wiersze.size(); i++)
        delete wiersze[i];
}

void Macierz::loadFromFile(std::string nazwa_pliku)
{
    int ilosc_wierszy = 0, ilosc_kolumn = 1;
    std::string tmp;
    double tmp_v;

    std::ifstream plik(nazwa_pliku);
    while(!plik.eof())
    {
        ilosc_wierszy++;
        getline(plik, tmp);
    }
    for(uint i=0; i<tmp.length(); i++)
    {
        if(tmp[i] == ' ')
            ilosc_kolumn++;
    }
    plik.close();

    allocateMemory(ilosc_kolumn, ilosc_wierszy);

    plik.open(nazwa_pliku);
    for(int y=0; y<ilosc_wierszy; y++)
    {
        for(int x=0; x<ilosc_kolumn; x++)
        {
            plik >> tmp_v;
            setValue(y,x,tmp_v);
        }
    }

    plik.close();
}

void Macierz::allocateMemory(uint n, uint m)
{
    for(uint i=0; i<m; i++)
        wiersze.push_back(new Wiersz(n));
}

int Macierz::getSizeC()
{
    return wiersze[0]->getSize();
}

int Macierz::getSizeR()
{
    return wiersze.size();
}

std::string Macierz::toString()
{
    std::string txt;

    for(uint i=0; i<wiersze.size(); i++)
        txt += wiersze[i]->toString() + "\n";

    return txt;
}

double Macierz::getValue(uint wiersz, uint kolumna)
{
    return wiersze[wiersz]->getValue(kolumna);
}

bool Macierz::setValue(uint wiersz, uint kolumna, double v)
{
    if(wiersz >= wiersze.size())
        return false;

    if(kolumna >= wiersze[0]->getSize())
        return false;

    wiersze[wiersz]->setValue(kolumna, v);
    return true;
}

Status Macierz::getStatus()
{
    return status;
}

Wiersz Macierz::oblicz()
{
    init();
    status = oznaczony;
    Wiersz wyniki(wiersze.size());
    double mnoznik_wiersza = 0;
    if(show_steps)
    {
        std::cout << toString() << std::endl;
    }

    for(int i=0; i<getSizeR(); i++)
    {
        for(int j=0; j<getSizeR(); j++)
        {
            raport.ilosc_iteracji++;
            if(i != j)
            {
                double v1 = getValue(j,i);
                double v2 = getValue(i,i);
                if(v2 != 0)
                {
                    mnoznik_wiersza =  v1/v2;
                    *wiersze[j] = *wiersze[j] - *wiersze[i]*mnoznik_wiersza;

                    raport.ilosc_iteracji_z_dzialaniami++;

                    if(show_steps)
                    {
                        std::cout << toString() << std::endl;
                    }
                }
            }
            raport.dodajHistorie(raport.ilosc_iteracji, iloscZer());
        }
    }

    for(int i=0; i<getSizeR(); i++)
    {
        *wiersze[i] = *wiersze[i] / wiersze[i]->getFirstNonZeroValue();
        if(wiersze[i]->getFirstNonZeroValue() == 0)
        {
            status = nieoznaczony;
        }
        else if(wiersze[i]->getFirstNonZeroValueID() == getSizeR())
        {
            status = sprzeczny;
        }
    }

    prepare();

    for(unsigned short int i=0; i<wiersze.size(); i++)
    {
        wyniki.setValue(i, wiersze[i]->getValue(wiersze[0]->getSize()-1));
    }

    return wyniki;
}

std::string Macierz::statusToString()
{
    if(status == oznaczony) return "Oznaczony";
    else if(status == nieoznaczony) return "Nieoznaczony";
    else if(status == sprzeczny) return "Sprzeczny";
    return "NULL";
}

void Macierz::showSteps(bool type)
{
    show_steps = type;
}


void Macierz::init()
{
    if(fmod(wiersze[0]->getValue(0), 2) == 0)
        return;

    for(int i=0; i<getSizeR(); i++)
    {
        if(abs(wiersze[i]->getValue(0)) == 1 || fmod(wiersze[i]->getValue(0), 2) == 0)
        {
            std::swap(wiersze[0], wiersze[i]);
            return;
        }
    }
}

void Macierz::prepare()
{
    for(int i=0; i<getSizeC(); i++)
    {
        for(int j=0; j<getSizeR(); j++)
        {
            double tmp = getValue(j,i);
            if(tmp > -0.0000001 && tmp < 0.0000001)
                setValue(j,i,0);
        }
    }

    if(status == oznaczony)
    {
        for(int i=0; i<getSizeR(); i++)
        {
            std::swap(wiersze[i], wiersze[wiersze[i]->getFirstNonZeroValueID()]);
        }
    }
}

Raport Macierz::getRaport()
{
    return raport;
}

int Macierz::iloscZer()
{
    int ilosc = 0;
    for(int i=0; i<getSizeC(); i++)
    {
        for(int j=0; j<getSizeR(); j++)
        {
            double tmp = getValue(j,i);
            if(tmp == 0)
            {
                ilosc++;
            }
            else if(tmp > -0.0000001 && tmp < 0.0000001)
            {
                setValue(j,i,0);
                ilosc++;
            }
        }
    }
    return ilosc;
}
