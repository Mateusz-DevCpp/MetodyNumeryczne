#include "Newton_Cotes.h"

int Newton_Cotes::ilosc_iteracji=0;

double Newton_Cotes::Oblicz(funkcja f, double pp, double kp, double dokladnosc, double ilosc_przedzialow)
{
	double wynik = 0;

	double tmp_wynik1, tmp_wynik2;
	double h, a, b;

	double krok = (kp-pp)/ilosc_przedzialow;

	do
	{
		tmp_wynik2 = wynik;
		wynik = 0;
		int m = 1;
		do
		{
			tmp_wynik1 = wynik;
			a = pp;
			b = kp;
			wynik = 0;
			h = (b-a)/m;

			for(int i=0; i<m; i++)
			{
			    ilosc_iteracji++;
				b = a + h;
				double mid = (a+b)/2;
				wynik += ((b-a)/6)*(f(a)*f_w(a) + 4*f(mid)*f_w(mid) + f(b)*f_w(b));
				a += h;
			}
			m++;
		}
		while((fabs(tmp_wynik1 - wynik) > dokladnosc) || m == 2);

		if(pp<0)
            pp -= krok;
		else
            kp += krok;
	}
	while(fabs(tmp_wynik2 - wynik) > dokladnosc);

    return wynik;
}


double Newton_Cotes::ObliczINF(funkcja f, double dokladnosc, double krok)
{
	double wynik = 0;

	double tmp_wynik1, tmp_wynik2;
	double h, a, b, pp=-1, kp=1;

	do
	{
		tmp_wynik2 = wynik;
		wynik = 0;
		int m = 1;
		do
		{
			tmp_wynik1 = wynik;
			a = pp;
			b = kp;
			wynik = 0;
			h = (b-a)/m;

			for(int i=0; i<m; i++)
			{
			    ilosc_iteracji++;
				b = a + h;
				double mid = (a+b)/2;
				wynik += ((b-a)/6)*(f(a)*f_w(a) + 4*f(mid)*f_w(mid) + f(b)*f_w(b));
				a += h;
			}
			m++;
		}
		while((fabs(tmp_wynik1 - wynik) > dokladnosc) || m == 2);

        pp -= krok;
        kp += krok;
	}
	while(fabs(tmp_wynik2 - wynik) > dokladnosc);

    return wynik;
}
