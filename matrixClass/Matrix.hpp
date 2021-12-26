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
    // ************************************** //
    
    // Матрица
    T** ptr;
    // Количество столбцов(n) строк(m)
    unsigned int n, m;
    
    // ************************************** //
    
public:
    // ************************************** //

    // -------------------------------------- //
    //              Конструкторы              //
    // -------------------------------------- //
    
    // Конструктор
    Matrix();
    // Конструктор с двумя параметрами
    Matrix(const unsigned int n, const unsigned int m);
    // Конструктор копирование
    Matrix(const Matrix<T>& matrix);
    // Деструктор
    ~Matrix();
    
    // ************************************** //

    // -------------------------------------- //
    //          Перегрузка операторов         //
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
    
    // Индексация
    T* operator[](int);
    
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
    
    // true/false
    operator bool() const { return ptr != nullptr; }
    
    // ************************************** //

    // -------------------------------------- //
    //          Операции над матрицой         //
    // -------------------------------------- //
    
    // Количество столбцов матрицы (n)
    unsigned int getColumns() const;
    // Количество строк матрица (m)
    unsigned int getRows() const;
    // Получить элемент
    T getElem(const unsigned int n, const unsigned int m) const;
    // Вставка значений
    void insert(T value, const unsigned int n, const unsigned int m) const;
    // Минор
    T minor(int x, int y) const;
    // Определитель
    T determinant() const;
    // Обратная матрица
    Matrix reverse() const;
    // Транспонирования
    Matrix transpose() const;
    
    // ************************************** //

    // -------------------------------------- //
    //         Перегрузка ввод/вывода         //
    // -------------------------------------- //
    
    // Вывод матрицы
    template <class Type>
    friend std::ostream& operator <<(std::ostream& out,const Matrix<Type>& matr);
};


#endif /* Matrix_hpp */
