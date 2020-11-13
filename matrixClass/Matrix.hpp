//
//  Matrix.hpp
//  matrixClass
//
//  Created by xitowzys on 06.11.2020.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>
#include <stdio.h>

template <class T>
class Matrix
{
private:
    // Матрица
    T** matrix;
    // Количество столбцов
    int n;
    // Количество строк
    int m;
public:
    // Конструктор
    Matrix();
    // Конструктор с двумя параметрами
    Matrix(int n, int m);
    
    // Количество столбцов матрицы (n)
    int getColumns();
    // Количество строк матрица (m)
    int getRows();
    
    // Получить элемент
    T getElem(int n, int m);
    
    T& operator[] (int index);
    
    // Найти определитель
    T Determinant();
    
    // Вывод матрицы
    template <class Type>
    friend std::ostream& operator <<(std::ostream& out,const Matrix<Type>& matr);
    
    // Вставка значений
    void insert(int value, int n, int m);
    
    // Сложение матриц
    template <class Type>
    friend Matrix operator+(const Matrix &d1, const Matrix &d2);
    // Сложение матриц +=
    friend Matrix& operator+=(Matrix& left, const Matrix& right);
    // Вычитание матриц
    template <class Type>
    friend Matrix operator-(const Matrix &d1, const Matrix &d2);
    // Умножение матриц
    template <class Type>
    friend Matrix operator*(const Matrix &d1, const Matrix &d2);
};


#endif /* Matrix_hpp */
