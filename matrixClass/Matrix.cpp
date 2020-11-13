//
//  Matrix.cpp
//  matrixClass
//
//  Created by xitowzys on 06.11.2020.
//

#include "Matrix.hpp"

// Конструктор
template <class T>
Matrix<T>::Matrix()
{
    this->n = 0;
    this->m = 0;
    this->matrix = nullptr;
}

// Конструктор с двумя параметрами
template <class T>
Matrix<T>::Matrix(int n, int m)
{
    this->n = n;
    this->m = m;

    this->matrix = (T**) new T*[m];

    for (int i = 0; i < m; i++)
        this->matrix[i] = (T*) new T[n];

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        this->matrix [i][j] = 0;
}

// Вставка значений
template <class T>
void Matrix<T>::insert(int value, int n, int m)
{
    this->matrix[n][m] = value;
}

// Количество столбцов матрицы
template <class T>
int Matrix<T>::getColumns()
{
    return this->n;
}

// Количество столбцов матрицы
template <class T>
int Matrix<T>::getRows()
{
    return this->m;
}

// Получить элемент
template <class T>
T Matrix<T>::getElem(int n, int m)
{
    return this->matrix[n][m];
}

// Вывод матрицы
template <class Type>
std::ostream& operator << (std::ostream& out, const Matrix<Type>& matr)
{
    out << "----------------------" << std::endl;
    for (int i = 0; i < matr.m; i++)
    {
        for (int j = 0; j < matr.n; j++)
            out << matr.matrix[i][j] << "\t";
        out << std::endl;
    }
    out << "----------------------" << std::endl;
    
    return out;
}

template <class T>
Matrix<T>& operator+=(Matrix<T>& left, const Matrix<T>& right) {
    left.value += right.value;
    return left;
}


// Сложение матриц
template <class T>
Matrix<T> operator+(Matrix<T> &d1, Matrix<T> &d2)
{
    Matrix<T> temp(d1.getRows(), d2.getColumns());
//    temp[2][2];
//    
//    for (int i = 0; i < d1.getRows(); i++)
//      for (int j = 0; j < d1.getColumns(); j++)
//        temp.insert(d1.getElem(i, j) + d2.getElem(i, j), i, j);
    
    return temp;
}

// Вычитание матриц
template <class T>
Matrix<T> operator-(Matrix<T> &d1, Matrix<T> &d2)
{
    Matrix<T> temp(d1.getRows(), d2.getColumns());
    
    for (int i = 0; i < d1.getRows(); i++)
      for (int j = 0; j < d1.getColumns(); j++)
        temp.insert(d1.getElem(i, j) - d2.getElem(i, j), i, j);
    
    return temp;
}

// Умножение матриц
template <class T>
Matrix<T> operator*(Matrix<T> &d1, Matrix<T> &d2)
{
    Matrix<T> temp(d1.getRows(), d2.getColumns());
    T temp2 = 0;
    
    for (int i = 0; i < d1.getColumns(); i++)
    {
        for (int j = 0; j < d1.getRows(); j++)
        {
            for (int k = 0; k < d1.getRows(); k++)
            {
                temp2 = temp2 + d1.getElem(i, k) * d2.getElem(k, j);
            }
            
            temp.insert(temp2, i, j);
            temp2 = 0;
        }
    }
    
    
    return temp;
    
//    if (a.M () != b.N ())
//       return matrix ();
//    matrix c = matrix (a.N (), b.M ());
//    for (int i = 0; i < a.N (); ++ i)
//       for (int j = 0; j < b.M (); ++ j)
//          for (int k = 0; k < a.M (); ++ k)
//             c[i][j] += a[i][k] * b[k][j];
//    return c;
}

//template <class T>
//T& Matrix<T>::operator[] (int index)
//{
//    std::cout << index;
//    return this->matrix[index][index];
//}

