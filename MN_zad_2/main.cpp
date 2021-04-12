#include <iostream>

#include "Macierz.h"
#include "Wiersz.h"

int main()
{
    Macierz matrix;
    char load_from_file;
    std::cout << "Wczytac z pliku (t/n):";
    std::cin >> load_from_file;
    if(load_from_file == 'y' || load_from_file == 'Y' || load_from_file == 't' || load_from_file == 'T')
    {
        matrix.loadFromFile("plik.txt");
    }
    else
    {
        std::cout << "Rozmiar:\ncol:>";
        int matrix_size_k, matrix_size_w;
        std::cin >> matrix_size_k;
        std::cout << "row:>";
        std::cin >> matrix_size_w;
        matrix.allocateMemory(matrix_size_k, matrix_size_w);

        double tmp_v;
        for(int i=0; i<matrix_size_k; i++)
        {
            for(int j=0; j<matrix_size_w; j++)
            {
                std::cout << "col:" << i << " - row:" << j << " =:";

                std::cin >> tmp_v;
                matrix.setValue(j,i,tmp_v);
            }
        }
    }

    matrix.showSteps(true);

    std::cout << matrix.toString() << std::endl;
    Wiersz wynik = matrix.oblicz();
    std::cout << "\n\nOSTATNIA WERSJA:\n" << matrix.toString() << std::endl;
    std::cout << matrix.statusToString() << std::endl;
    if(matrix.getStatus() == Status::oznaczony)
        std::cout << "WARTOSCI ARGUMENTOW:\n" << wynik.toString() << std::endl << std::endl;
    std::cout << matrix.getRaport().toString() << std::endl;
    matrix.getRaport().drawRaport();

    return 0;
}
