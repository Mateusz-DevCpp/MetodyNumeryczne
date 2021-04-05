#include <iostream>

#include "Macierz.h"
#include "Wiersz.h"

using namespace std;

int main()
{
    /*
    Wiersz *w1 = new Wiersz(3);
    Wiersz *w2 = new Wiersz(3);
    w1->setValue(0,1);
    w1->setValue(1,2);
    w1->setValue(2,3);
    w2->setValue(0,7);
    w2->setValue(1,8);
    w2->setValue(2,9);

    Wiersz w(3);
    w = w1->operator*(3);
    std::cout << w1->toString();
    std::cout << w.toString();
    return 0;
*/

    Macierz ma("plik.txt");

    std::cout << ma.toString() << std::endl;
    std::cout << ma.oblicz().toString() << std::endl << std::endl;
    std::cout << ma.toString() << std::endl;

    return 0;
}
