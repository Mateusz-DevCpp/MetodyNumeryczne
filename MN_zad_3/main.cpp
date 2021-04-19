#include <iostream>

#include "Define.h"
#include "Horner.h"
#include "Czebyszew.h"
#include "Interpolacja.h"

#include "gnuplot_manager/Gnuplot_manager.h"

using namespace std;

int main()
{
    char wybor;
    cout << "Wybierz funkcje:" << endl;
    cout << "l. " << Funkcja::liniowa_str() << endl;
    cout << "b. " << Funkcja::wartosc_bzw_str() << endl;
    cout << "w. " << Funkcja::wielomian_str() << endl;
    cout << "t. " << Funkcja::trygonometryczna_str() << endl;
    cout << "z. " << Funkcja::zlozona_str() << endl;
    cout << "e. exit" << endl;
    cout << ">";
    cin >> wybor;

    if(wybor == 'e')
        return 0;

    double poczatek, koniec;
    cout << "Podaj przedzial:" << endl;
    cout << "poczatek: >";
    cin >> poczatek;
    cout << "koniec:   >";
    cin >> koniec;

    Punkt<double> przedzial(poczatek,koniec);

    int ilosc;
    cout << "Ilosc wezlow:" << endl;
    cout << ">";
    cin >> ilosc;

    vector<Punkt<double>> wezly = Czebyszew::obliczWartosciWezlow(ilosc, przedzial, wybor);
    vector<Punkt<double>> punkty_funkcji = Funkcja::obliczPunkty(przedzial, wybor, 0.01);
    vector<Punkt<double>> punkty_funkcji_interpolowanej_newton =
    Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Newton(przedzial, wezly, 0.01);
    vector<Punkt<double>> punkty_funkcji_interpolowanej_lagrange =
    Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Lagrange(przedzial, wezly, 0.01);

    GnuPlot::Clear();
    GnuPlot::EnablePause();
    GnuPlot::SetLegend("bottom");
    GnuPlot::EnableAxis();
    GnuPlot::AddLines(punkty_funkcji,"3","000000","Funkcja");
    GnuPlot::AddLines(punkty_funkcji_interpolowanej_newton,"2","00FF00","Interpolacja Newtona");
    GnuPlot::AddLines(punkty_funkcji_interpolowanej_lagrange,"1","0000FF","Interpolacja Lagrange'a");
    GnuPlot::AddPoints(wezly,"4","FF0000","Wezly");
    GnuPlot::SetTitle(Funkcja::podajWzor(wybor));
    GnuPlot::Draw();

    return 0;
}

/**


    std::vector<double> wsp_f;
    wsp_f.push_back(-12);
    wsp_f.push_back(42);
    wsp_f.push_back(-49);
    wsp_f.push_back(17);

    int f_id = 0;
    Przedzial przedzial;
    int warunek_stop = 0;
    double stop = 0;

    std::cout << "Wybiez funkcje:" << std::endl;
    std::cout << "0. " << f_o_wielomianowa << std::endl;
    std::cout << "1. " << f_o_trygonometryczna << std::endl;
    std::cout << "2. " << f_o_wykladnicza << std::endl;
    std::cout << "3. " << f_o_mieszana << std::endl;
    std::cin >> f_id;

    std::cout << "Podaj przedzial:" << std::endl;
    std::cout << "poczatek: >";
    std::cin >> przedzial.begin;
    std::cout << "koniec  : >";
    std::cin >> przedzial.end;

    std::cout << "Wybiez warunek stopu:" << std::endl;
    std::cout << "0. spelnienie warunku nalozonego na dokladnosc" << std::endl;
    std::cout << "1. osiagniecie zadanej liczby iteracji" << std::endl;
    std::cin >> warunek_stop;

*/
