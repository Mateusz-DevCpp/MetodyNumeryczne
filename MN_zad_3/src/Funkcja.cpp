#include "Funkcja.h"

double Funkcja::liniowa(double x)
{
    return 2*x+3;
}
std::string Funkcja::liniowa_str()
{
    return "2x + 3";
}

double Funkcja::wartosc_bzw(double x)
{
    return x<0?-x:x;
}
std::string Funkcja::wartosc_bzw_str()
{
    return "|x|";
}

double Funkcja::zlozona(double x)
{
    return cos(wartosc_bzw(x)) + 4 * x * x;
}
std::string Funkcja::zlozona_str()
{
    return "cos(|x|)+4x^2";
}

double Funkcja::wielomian(double x)
{
    std::vector<double> wsp;
    wsp.push_back(3);
    wsp.push_back(2);
    wsp.push_back(1);

    return Horner::wartoscWielomianu(x, wsp);
}
std::string Funkcja::wielomian_str()
{
    return "3x^2 + 2x + 1";
}

double Funkcja::trygonometryczna(double x)
{
    return cos(x);
}
std::string Funkcja::trygonometryczna_str()
{
    return "cos(x)";
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
