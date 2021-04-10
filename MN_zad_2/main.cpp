#include <iostream>

#include "Macierz.h"
#include "Wiersz.h"

using namespace std;

int main()
{
    Macierz matrix;
    char load_from_file;
    cout << "Wczytac z pliku (t/n):";
    cin >> load_from_file;
    if(load_from_file == 'y' || load_from_file == 'Y' || load_from_file == 't' || load_from_file == 'T')
    {
        matrix.loadFromFile("plik.txt");
    }
    else
    {
        cout << "Rozmiar:\ncol:>";
        int matrix_size_k, matrix_size_w;
        cin >> matrix_size_k;
        cout << "row:>";
        cin >> matrix_size_w;
        matrix.allocateMemory(matrix_size_k, matrix_size_w);

        double tmp_v;
        for(int i=0; i<matrix_size_k; i++)
        {
            for(int j=0; j<matrix_size_w; j++)
            {
                cout << "col:" << i << " - row:" << j << " =:";

                cin >> tmp_v;
                matrix.setValue(j,i,tmp_v);
            }
        }
    }

    std::cout << matrix.toString() << std::endl;
    matrix.showSteps(true);

    Wiersz wynik = matrix.oblicz();
    cout << matrix.statusToString() << endl;
    if(matrix.getStatus() == Status::oznaczony)
        std::cout << wynik.toString() << std::endl;

    std::cout << "\n\nOSTATNIA WERSJA:\n" << matrix.toString() << std::endl;
    return 0;
}
