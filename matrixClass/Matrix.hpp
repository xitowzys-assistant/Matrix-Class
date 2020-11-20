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

class MatrixException{};

template <class T>
class Matrix
{
private:
    // -------------------------------------- //
    
    // Матрица
    T** ptr;
    // Количество столбцов(n) строк(m)
    unsigned int n, m;
    
    // -------------------------------------- //
    
public:
    // -------------------------------------- //
    
    // Конструктор
    Matrix();
    // Конструктор с двумя параметрами
    Matrix(const unsigned int n, const unsigned int m);
    // Конструктор копирование
    Matrix(const Matrix<T>& matrix);
    // Деструктор
    ~Matrix();
    
    // -------------------------------------- //
    
    // Количество столбцов матрицы (n)
    unsigned int getColumns() const;
    // Количество строк матрица (m)
    unsigned int getRows() const;
    // Получить элемент
    T getElem(const unsigned int n, const unsigned int m) const;
    
    // -------------------------------------- //
    
    // Вставка значений
    void insert(T value, const unsigned int n, const unsigned int m) const;
    
    // -------------------------------------- //
    
    // Присваивание
    Matrix& operator =(const Matrix<T> & m);

    // Сложение
    Matrix& operator +=(const Matrix<T>& m);
    Matrix& operator +=(int number);
    Matrix& operator +(const Matrix<T>& m);
    Matrix& operator +(const int number);

    // Вычитание
    Matrix& operator -=(const Matrix& m);
    Matrix& operator -=(const int n);
    Matrix& operator -(const Matrix& m);
    Matrix& operator -(const int n);
    
    // Умножение
    Matrix& operator *=(const Matrix& m);
    Matrix& operator *(const Matrix& m);
    
    T determinant() const;
    Matrix& reverse() const;
    Matrix& transpose() const;
    Matrix& pow(const int power) const;
    
    // -------------------------------------- //
    
    // Вывод матрицы
    template <class Type>
    friend std::ostream& operator <<(std::ostream& out,const Matrix<Type>& matr);
    
//
//    // Сложение матриц
//    template <class Type>
//    friend Matrix operator+(const Matrix &d1, const Matrix &d2);
//
//    // Сложение матриц +=
//    friend Matrix& operator+=(Matrix& left, const Matrix& right);
//
//    // Вычитание матриц
//    template <class Type>
//    friend Matrix operator-(const Matrix &d1, const Matrix &d2);
//
//    // Умножение матриц
//    template <class Type>
//    friend Matrix operator*(const Matrix &d1, const Matrix &d2);
};


#endif /* Matrix_hpp */
