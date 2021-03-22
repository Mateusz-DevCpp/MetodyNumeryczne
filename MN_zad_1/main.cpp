#include <iostream>
#include <math.h>
#include <stdio.h>
#include <windows.h>

#include "include/GnuPlot.h"

#include "Define.h"
#include "Funkcje.h"
#include "MetodaSiecznych.h"
#include "MetodaStycznych.h"
#include "Horner.h"

bool mozeWystepowacPierwiastek(fun funkcja, Przedzial p);
bool mozeWystepowacPierwiastek_Horner(std::vector<double> f, Przedzial p);

fun fun_list[8] {wielomian,trygon,wykladnicza,mieszana,wielomian_p,trygon_p,wykladnicza_p,mieszana_p};

int main()
{
    std::vector<double> wsp_f;
    wsp_f.push_back(-12);
    wsp_f.push_back(42);
    wsp_f.push_back(-49);
    wsp_f.push_back(17);
    std::vector<double> wsp_p;
    wsp_p.push_back(-36);
    wsp_p.push_back(84);
    wsp_p.push_back(-49);

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

    double m_zerowe_mt_siecznych = 0, m_zerowe_mt_stycznych = 0;
    if(warunek_stop == 0)
    {
        std::cout << "Podaj wartosc E:" << std::endl;
        std::cin >> stop;
        if(f_id == 0)
        {
            if(mozeWystepowacPierwiastek_Horner(wsp_f, przedzial))
            {
                std::cout << "Metoda siecznych: \n";
                m_zerowe_mt_siecznych = MetodaSiecznych::szukanieMtSiecznych_E_W(wsp_f, przedzial, stop);
                std::cout << "M. zerowe: x =  " << m_zerowe_mt_siecznych << std::endl;
                std::cout << "ilosc iteracji: " << MetodaSiecznych::PodajIloscIteracji() << std::endl;
                std::cout << "wartosc bledu:  " << MetodaSiecznych::PodajWartoscBledu() << std::endl;
                std::cout << std::endl;

                std::cout << "Metoda stycznych: \n";
                m_zerowe_mt_stycznych = MetodaStycznych::szukanieMtStycznych_E_W(wsp_f, wsp_p, przedzial, stop);
                std::cout << "M. zerowe: x =  " << m_zerowe_mt_stycznych << std::endl;
                std::cout << "ilosc iteracji: " << MetodaStycznych::PodajIloscIteracji() << std::endl;
                std::cout << "wartosc bledu:  " << MetodaStycznych::PodajWartoscBledu() << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "W podanym przedziale nie mozna znalesc pierwiastka funkcji" << std::endl;
                return 0;
            }
        }
        else
        {
            if(mozeWystepowacPierwiastek(fun_list[f_id], przedzial))
            {
                std::cout << "Metoda siecznych: \n";
                m_zerowe_mt_siecznych = MetodaSiecznych::szukanieMtSiecznych_E(fun_list[f_id], przedzial, stop);
                std::cout << "M. zerowe: x =  " << m_zerowe_mt_siecznych << std::endl;
                std::cout << "ilosc iteracji: " << MetodaSiecznych::PodajIloscIteracji() << std::endl;
                std::cout << "wartosc bledu:  " << MetodaSiecznych::PodajWartoscBledu() << std::endl;
                std::cout << std::endl;

                std::cout << "Metoda stycznych: \n";
                m_zerowe_mt_stycznych = MetodaStycznych::szukanieMtStycznych_E(fun_list[f_id], fun_list[f_id+4], przedzial, stop);
                std::cout << "M. zerowe: x =  " << m_zerowe_mt_stycznych << std::endl;
                std::cout << "ilosc iteracji: " << MetodaStycznych::PodajIloscIteracji() << std::endl;
                std::cout << "wartosc bledu:  " << MetodaStycznych::PodajWartoscBledu() << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "W podanym przedziale nie mozna znalesc pierwiastka funkcji" << std::endl;
                return 0;
            }
        }
    }
    else
    {
        std::cout << "Podaj ilosc iteracji:" << std::endl;
        std::cin >> stop;
        if(f_id == 0)
        {
            if(mozeWystepowacPierwiastek_Horner(wsp_f, przedzial))
            {
                std::cout << "Metoda siecznych: \n";
                m_zerowe_mt_siecznych = MetodaSiecznych::szukanieMtSiecznych_IT_W(wsp_f, przedzial, stop);
                std::cout << "M. zerowe: x =  " << m_zerowe_mt_siecznych << std::endl;
                std::cout << "ilosc iteracji: " << MetodaSiecznych::PodajIloscIteracji() << std::endl;
                std::cout << "wartosc bledu:  " << MetodaSiecznych::PodajWartoscBledu() << std::endl;
                std::cout << std::endl;

                std::cout << "Metoda stycznych: \n";
                m_zerowe_mt_stycznych = MetodaStycznych::szukanieMtStycznych_IT_W(wsp_f, wsp_p, przedzial, stop);
                std::cout << "M. zerowe: x =  " << m_zerowe_mt_stycznych << std::endl;
                std::cout << "ilosc iteracji: " << MetodaStycznych::PodajIloscIteracji() << std::endl;
                std::cout << "wartosc bledu:  " << MetodaStycznych::PodajWartoscBledu() << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "W podanym przedziale nie mozna znalesc pierwiastka funkcji" << std::endl;
                return 0;
            }
        }
        else
        {
            if(mozeWystepowacPierwiastek(fun_list[f_id], przedzial))
            {
                std::cout << "Metoda siecznych: \n";
                m_zerowe_mt_siecznych = MetodaSiecznych::szukanieMtSiecznych_IT(fun_list[f_id], przedzial, stop);
                std::cout << "M. zerowe: x =  " << m_zerowe_mt_siecznych << std::endl;
                std::cout << "ilosc iteracji: " << MetodaSiecznych::PodajIloscIteracji() << std::endl;
                std::cout << "wartosc bledu:  " << MetodaSiecznych::PodajWartoscBledu() << std::endl;
                std::cout << std::endl;

                std::cout << "Metoda stycznych: \n";
                m_zerowe_mt_stycznych = MetodaStycznych::szukanieMtStycznych_IT(fun_list[f_id], fun_list[f_id+4], przedzial, stop);
                std::cout << "M. zerowe: x =  " << m_zerowe_mt_stycznych << std::endl;
                std::cout << "ilosc iteracji: " << MetodaStycznych::PodajIloscIteracji() << std::endl;
                std::cout << "wartosc bledu:  " << MetodaStycznych::PodajWartoscBledu() << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "W podanym przedziale nie mozna znalesc pierwiastka funkcji" << std::endl;
                return 0;
            }
        }
    }

    GnuPlot::Clear();
    GnuPlot::SetLegend("disable");
    GnuPlot::EnableAxis();
    GnuPlot::SetSize(przedzial);
    GnuPlot::AddPoint(m_zerowe_mt_stycznych,0,"1");
    GnuPlot::AddPoint(m_zerowe_mt_siecznych,0,"2");
    if(f_id == 0)
    {
        GnuPlot::AddCommand_main_cmd(f_o_wielomianowa);
    }
    else if(f_id == 1)
    {
        GnuPlot::AddCommand_main_cmd(f_o_trygonometryczna);
    }
    else if(f_id == 2)
    {
        GnuPlot::AddCommand_main_cmd(f_o_wykladnicza);
    }
    else if(f_id == 3)
    {
        GnuPlot::AddCommand_main_cmd(f_o_mieszana);
    }
    GnuPlot::Draw();

    return 0;
}

bool mozeWystepowacPierwiastek(fun f, Przedzial p)
{
    if(f(p.begin) * f(p.end) < 0) return true;
    else return false;
}

bool mozeWystepowacPierwiastek_Horner(std::vector<double> f, Przedzial p)
{
    if(Horner::wartoscWielomianuHorner(p.begin, f) * Horner::wartoscWielomianuHorner(p.end, f) < 0) return true;
    else return false;
}
