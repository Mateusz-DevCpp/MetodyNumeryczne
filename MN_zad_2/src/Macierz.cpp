#include "Macierz.h"

Macierz::Macierz(uint n, uint m)
{
    allocateMemory(n,m);
}

Macierz::Macierz(std::string nazwa_pliku)
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

Macierz::~Macierz()
{
    for(uint i=0; i<wiersze.size(); i++)
        delete wiersze[i];
}

void Macierz::allocateMemory(uint n, uint m)
{
    for(uint i=0; i<m; i++)
        wiersze.push_back(new Wiersz(n));
}

int Macierz::getSizeX()
{
    return wiersze[0]->getSize();
}

int Macierz::getSizeY()
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

double Macierz::getValue(uint n, uint m)
{
    return wiersze[n]->getValue(m);
}

bool Macierz::setValue(uint n, uint m, double v)
{
    if(n >= wiersze.size())
        return false;

    if(m >= wiersze[0]->getSize())
        return false;

    wiersze[n]->setValue(m, v);
    return true;
}

Wiersz Macierz::oblicz()
{
    Wiersz wyniki(wiersze.size());



    for(int i=0; i<wiersze.size(); i++)
    {
        wyniki.setValue(i, wiersze[i]->getValue(wiersze[0]->getSize()-1));
    }
    return wyniki;
}
