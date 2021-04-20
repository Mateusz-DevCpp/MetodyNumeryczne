#include "Funkcja.h"

double Funkcja::liniowa(double x)
{
    return 2*x+3;
}
std::string Funkcja::liniowa_str()
{
    return "2x + 3";
}
std::string Funkcja::liniowa_przedzial_str()
{
    return "Sugerowany przedzial (-1;1)";
}

double Funkcja::wartosc_bzw(double x)
{
    return x<0?-x:x;
}
std::string Funkcja::wartosc_bzw_str()
{
    return "|x|";
}
std::string Funkcja::wartosc_bzw_przedzial_str()
{
    return "Sugerowany przedzial (-1;1)";
}

double Funkcja::wielomian(double x)
{
    std::vector<double> wsp;
    wsp.push_back(0.4);
    wsp.push_back(0);
    wsp.push_back(0);
    wsp.push_back(0);
    wsp.push_back(0);
    wsp.push_back(-2);
    wsp.push_back(0);
    wsp.push_back(0.2);
    wsp.push_back(0);
    wsp.push_back(1);

    return Horner::wartoscWielomianu(x, wsp);
}
std::string Funkcja::wielomian_str()
{
    return "0.4x^9 - 2x^4 + 0.2x^2 + 1";
}
std::string Funkcja::wielomian_przedzial_str()
{
    return "Sugerowany przedzial (-1.5;1)";
}

double Funkcja::trygonometryczna(double x)
{
    return 2*cos(2*x)*4*x+4*x*x*x;
}
std::string Funkcja::trygonometryczna_str()
{
    return "2cos(2x)*4x + 4x^3";
}
std::string Funkcja::trygonometryczna_przedzial_str()
{
    return "Sugerowany przedzial (-1.5;1.5)";
}

double Funkcja::zlozona(double x)
{
    return (wartosc_bzw(cos(2*x))-0.5) * 4 * x;
}
std::string Funkcja::zlozona_str()
{
    return "(|cos(2x)|-0.5)*4x";
}
std::string Funkcja::zlozona_przedzial_str()
{
    return "Sugerowany przedzial (-1;1)";
}


double Funkcja::oblicz(char funkcja, double x)
{
    switch(funkcja)
    {
    case 'l':
    {
        return liniowa(x);
    }
    break;
    case 'b':
    {
        return wartosc_bzw(x);
    }
    break;
    case 'w':
    {
        return wielomian(x);
    }
    break;
    case 't':
    {
        return trygonometryczna(x);
    }
    break;
    case 'z':
    {
        return zlozona(x);
    }
    break;
    default:
        std::cout << "Nieznana funkcja" << std::endl;
        return 0;
    }
}

std::vector<Punkt<double>> Funkcja::obliczPunkty(Punkt<double> przedzial, char funkcja, double odleglosc_miedy_punktami)
{
    std::vector<Punkt<double>> wynik;

    for(double x=przedzial.x; x<=przedzial.y; x+=odleglosc_miedy_punktami)
    {
        wynik.push_back(Punkt<double>( x, Funkcja::oblicz(funkcja, x) ));
    }

    return wynik;
}

std::string Funkcja::podajWzor(char funkcja)
{
    switch(funkcja)
    {
    case 'l':
    {
        return liniowa_str();
    }
    break;
    case 'b':
    {
        return wartosc_bzw_str();
    }
    break;
    case 'w':
    {
        return wielomian_str();
    }
    break;
    case 't':
    {
        return trygonometryczna_str();
    }
    case 'z':
    {
        return zlozona_str();
    }
    break;
    default:
        std::cout << "Nieznana funkcja" << std::endl;
        return 0;
    }
}

std::string Funkcja::podajSugerowanyPrzedzial(char funkcja)
{
    switch(funkcja)
    {
    case 'l':
    {
        return liniowa_przedzial_str();
    }
    break;
    case 'b':
    {
        return wartosc_bzw_przedzial_str();
    }
    break;
    case 'w':
    {
        return wielomian_przedzial_str();
    }
    break;
    case 't':
    {
        return trygonometryczna_przedzial_str();
    }
    case 'z':
    {
        return zlozona_przedzial_str();
    }
    break;
    default:
        std::cout << "Nieznana funkcja" << std::endl;
        return 0;
    }
}

char Funkcja::idToFunkcja(int id)
{
    switch(id)
    {
    case 1:
    {
        return 'l';
    }
    break;
    case 2:
    {
        return 'b';
    }
    break;
    case 3:
    {
        return 'w';
    }
    break;
    case 4:
    {
        return 't';
    }
    case 5:
    {
        return 'z';
    }
    break;
    default:
        return 0;
    }
}
