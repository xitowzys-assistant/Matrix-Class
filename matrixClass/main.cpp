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
//    
//    cout << "matr3 = matr2 + matr" << endl;
//    matr3 = matr2 + matr;
//    cout << matr3;
//    cout << endl;
//    
//    cout << "matr3 = matr2 - matr" << endl;
//    matr3 = matr2 - matr;
//    cout << matr3;
//    cout << endl;
    
    cout << "matr3 = matr2 * matr" << endl;
    matr3 = matr2 * matr;
    cout << matr3;
    cout << endl;
    
    return 0;
}
