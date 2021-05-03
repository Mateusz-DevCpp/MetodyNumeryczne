#include "Hermit.h"

double Hermit::kwadratura[4][5][2];

double Hermit::ObliczINF(funkcja f, int ilosc_wezlow)
{
    ilosc_wezlow -= 2;
    double suma = 0;

    for(int i=0; i<5; i++)
    {
        if(kwadratura[ilosc_wezlow][i][waga] != 0)
        {
            suma += kwadratura[ilosc_wezlow][i][waga] * f(kwadratura[ilosc_wezlow][i][wezel] );
        }
    }
    return suma;
}

void Hermit::wczytajKwadratury()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            kwadratura[i][j][wezel] = 0;
            kwadratura[i][j][waga] = 0;
        }
    }

    kwadratura[0][0][0] = -0.707107;
    kwadratura[0][0][1] = 0.886227;
    kwadratura[0][1][0] = 0.707107;
    kwadratura[0][1][1] = 0.886227;

    kwadratura[1][0][0] = -1.224745;
    kwadratura[1][0][1] = 0.295409;
    kwadratura[1][1][0] = 0.000000;
    kwadratura[1][1][1] = 1.181636;
    kwadratura[1][2][0] = 1.224745;
    kwadratura[1][2][1] = 0.295409;

    kwadratura[2][0][0] = -1.650680;
    kwadratura[2][0][1] = 0.081313;
    kwadratura[2][1][0] = -0.534648;
    kwadratura[2][1][1] = 0.804914;
    kwadratura[2][2][0] = 0.534648;
    kwadratura[2][2][1] = 0.804914;
    kwadratura[2][3][0] = 1.650680;
    kwadratura[2][3][1] = 0.081313;

    kwadratura[3][0][0] = -2.020183;
    kwadratura[3][0][1] = 0.019953;
    kwadratura[3][1][0] = -0.958572;
    kwadratura[3][1][1] = 0.393619;
    kwadratura[3][2][0] = 0.000000;
    kwadratura[3][2][1] = 0.945309;
    kwadratura[3][3][0] = 0.958572;
    kwadratura[3][3][1] = 0.393619;
    kwadratura[3][4][0] = 2.020183;
    kwadratura[3][4][1] = 0.019953;
}
