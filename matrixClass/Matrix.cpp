//
//  Matrix.cpp
//  matrixClass
//
//  Created by xitowzys on 06.11.2020.
//
#include "Matrix.hpp"

// ************************************** //

// -------------------------------------- //
//              Конструкторы              //
// -------------------------------------- //

// Конструктор
template <class T>
Matrix<T>::Matrix()
{
    n = 0;
    m = 0;
    ptr = nullptr;
}

// Конструктор с двумя параметрами
template <class T>
Matrix<T>::Matrix(const unsigned int n, const unsigned int m)
{
    this->n = n;
    this->m = m;

    ptr = new T*[m];

    for (int i = 0; i < m; i++)
        ptr[i] = new T[n];

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        ptr[i][j] = 0;
}

// Конструктор копирование
template <class T>
Matrix<T>::Matrix(const Matrix<T>& matrix)
{
    n = matrix.n; m = matrix.m;

    ptr = new T * [n];
    for (unsigned int i = 0; i < n; i++)
        ptr[i] = new T[m];

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++)
            ptr[i][j] = matrix.ptr[i][j];
    }
}

// Деструктор
template <class T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < n; i++)
        delete[] ptr[i];
    delete[] ptr;
}

// ************************************** //

// -------------------------------------- //
//          Перегрузка операторов         //
// -------------------------------------- //

// Присваивание
template <class T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T>& matrix)
{
    
    // Если один и тот же адрес
    if (this == &matrix) return *this;
    
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
            ptr[i][j] = matrix.ptr[i][j];
    }
    
    return *this;
}

// Сложение
template <class T>
Matrix<T>& Matrix<T>::operator +=(const Matrix<T> &matrix)
{
    if (m == matrix.getRows() && n == matrix.getColumns()){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ptr[i][j] += matrix.getElem(i, j);
    } else {
        throw MatrixException();
    }
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator +=(int number)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ptr[i][j] += number;
    
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator +(const Matrix<T> &matrix)
{
    return *this += matrix;
}

template <class T>
Matrix<T>& Matrix<T>::operator +(const int number)
{
    return *this += number;
}

// Вычитание
template <class T>
Matrix<T>& Matrix<T>::operator -=(const Matrix<T> &matrix)
{
    if (m == matrix.getRows() && n == matrix.getColumns())
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ptr[i][j] -= matrix.getElem(i, j);
    }
    else
    {
        throw MatrixException();
    }
    
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator -=(int number)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ptr[i][j] -= number;
    
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator -(const Matrix<T> &matrix){
    return *this -= matrix;
}

template <class T>
Matrix<T>& Matrix<T>::operator -(const int number) {
    return *this -= number;
}

// Умножение
template <class T>
Matrix<T>& Matrix<T>::operator *=(const Matrix<T> &matrix)
{
    T temps = 0;
    T** results = new T*[m];

    for (int i = 0; i < m; i++)
        results[i] = new T[n];
    
    if (m == matrix.getRows() && n == matrix.getColumns())
    {
        
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < m; j++)
            {
                for (unsigned int k = 0; k < m; k++)
                {
                    temps += ptr[i][k] * matrix.ptr[k][j];
                }
                
                results[i][j] = temps;
                temps = 0;
            }
        }
        
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < m; j++)
            {
                ptr[i][j] = results[i][j];
            }
            delete[] results[i];
        }
        
        delete[] results;
        results = nullptr;
    }
    else
    {
        throw MatrixException();
    }
    
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator *(const Matrix<T> &matrix)
{
    return *this *= matrix;
}

// Индексация
template<class T>
T* Matrix<T>::operator[](int index) {
    return ptr[index];
}

// ************************************** //

// -------------------------------------- //
//          Операции над матрицой         //
// -------------------------------------- //

// Количество столбцов матрицы
template <class T>
unsigned int Matrix<T>::getColumns() const
{
    return n;
}

// Количество строк матрицы
template <class T>
unsigned int Matrix<T>::getRows() const
{
    return m;
}

// Получить элемент
template <class T>
T Matrix<T>::getElem(const unsigned int n,const unsigned int m) const
{
    return ptr[n][m];
}

// Вставка значений
template <class T>
void Matrix<T>::insert(T value, const unsigned int n, const unsigned int m) const
{
    ptr[n][m] = value;
}

// Транспонирования
template<class T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> trans(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            trans[j][i] = ptr[i][j];
    
    return trans;
}

// Обратная матрица
template<class T>
Matrix<T> Matrix<T>::reverse() const {
    if (m == n) {
        T det = determinant();
        if (det) {
            Matrix<T> M(m, n);
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    M[i][j] = minor(i, j) * ((i + j) % 2 ? -1 : 1);
            return M.transpose();
        }
        else throw MatrixException();
    }
    else throw MatrixException();
}

// Определитель
template<class T>
T Matrix<T>::determinant() const {
    if (m == n) {
        T det = 0;
        if (m == 1) return ptr[0][0];
        
        if (m == 2)
            return ptr[0][0] * ptr[1][1] - ptr[0][1] * ptr[1][0];
        
        for (int i = 0; i < m; i++) {
            T temp_det = ptr[i][0] * minor(i, 0);
            temp_det *= (i % 2 ? -1 : 1);
            det += temp_det;
        }
        
        return det;
    }
    else throw MatrixException();
}

// Минор
template<class T>
T Matrix<T>::minor(int x, int y) const {
    if (m == n && m > 1) {
        if (m == 2)
            for (int i = 0; i < m; i++)
                if (i != x)
                    for (int j = 0; j < m; j++)
                        if (j != y) return ptr[i][j];
            
        Matrix<T> M(m - 1, n - 1);
        for (int i = 0, x_offset = 0; i < m; i++)
            if (i != x) {
                x_offset = i > x;
                for (int j = 0, y_offset = 0; j < m; j++) {
                    y_offset = j > y;
                    if (j != y) M[i - x_offset][j - y_offset] = ptr[i][j];
                }
            }

        return M.determinant();
    }
    else throw MatrixException();
}

// ************************************** //

// -------------------------------------- //
//         Перегрузка ввод/вывода         //
// -------------------------------------- //

// Вывод матрицы
template <class Type>
std::ostream& operator << (std::ostream& out, const Matrix<Type>& matrix)
{
    out << "----------------------" << std::endl;
    for (int i = 0; i < matrix.m; i++)
    {
        for (int j = 0; j < matrix.n; j++)
            out << matrix.ptr[i][j] << "\t";
        out << std::endl;
    }
    out << "----------------------" << std::endl;

    return out;
}
