//
//  main.cpp
//  matrixClass
//
//  Created by xitowzys on 06.11.2020.
//

#include <iostream>
#include <ctime>

#include "Matrix.hpp"
#include "Matrix.cpp"

int main(int argc, const char * argv[]) {
    using namespace std;
    
    srand(time(0));
    
    // Частный случай 3x3 матрицы
    Matrix<int> matr(3, 3);
    Matrix<int> matr2(3, 3);
    Matrix<int> matr3(3, 3);
    
    Matrix<double> matrDouble(2, 2);
    matrDouble[0][0] = 2;
    matrDouble[0][1] = 3;
    
    matrDouble[1][0] = -1;
    matrDouble[1][1] = 1;

    
    // Заполнение рандомными значениями matr и matr2
    for(int i = 0; i < matr.getColumns(); i++)
    {
        for (int j = 0; j < matr.getRows(); j++) {
            matr.insert(1 + i, i, j); // rand() % 5
            matr2.insert(2 + i, i, j);
        }
    }

    // Тестирование
    cout << "matr" << endl;
    cout << matr;
    cout << endl;

    cout << "matr2" << endl;
    cout << matr2;
    cout << endl;
    
    cout << "matr2 +=" << endl;
    matr = matr * matr2;
    cout << matr;
    cout << endl;
    
    cout << "Transpose" << endl;
    matr = matr.transpose();
    cout <<  matrDouble.reverse() << endl;
    
    return 0;
}
