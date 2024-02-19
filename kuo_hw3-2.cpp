#include<iostream>
#include"function.h"
using namespace std;
std::ostream &operator<<(std::ostream &os, const Matrix &m){ //std::ostream &operator<<(std::ostream &os, const Matrix &m){for(int i = 0;i<m.size;i++{for(int j = 0;j<m.size;j++){os<<m.matrix[i][j]; if(j!=m.size-1) os<<' '; os<<std::endl;}return os;}}
    for(int i = 0; i < m.size; i++){
        for(int j = 0; j < m.size; j++){
            os << m.matrix[i][j];
            if(j != m.size-1) os << ' ';
        }
        os << std::endl;
    }
    return os;
}
std::istream &operator>>(std::istream &is, Matrix &m){ //std::istream &operator>>(std::istream &is, Matrix &m){for(int i = 0;i<m.size;i++){for(int j = 0;j<m.size;j++){is>>m.matrix[i][j];}}return is;}
    for(int i = 0; i < m.size; i++){
        for(int j = 0; j < m.size; j++){
            is >> m.matrix[i][j];
        }
    }
    return is;
}

Matrix::Matrix(int s){ //Matrix::Matrix(int s){size = s;buf = new int[s*s];matrix = new int*[s];for(int i = 0;i<s;i++) matrix[x] = i*s+buf;}*******************
    size = s;
    buf = new int[s*s];
    matrix = new int*[s];
    for(int i = 0; i < s; i++) matrix[i] = buf + i * s;
}

Matrix::Matrix(const Matrix &m1):size(m1.size){ //Matrix::Matrix(const Matrix &ml):size(m1.size){buf = new int[size*size]; matrix = new int*[size]; for(int i = 0;i<size;i++){ matrix[i] = buf+i*s;for(int j=0;j<size;j++){matrix[i][j]=m1.matrix[i][j];}}}
    buf = new int[size * size];
    matrix = new int*[size];
    for(int i = 0; i < size; i++) {
        matrix[i] = buf + i * size;
        for(int j = 0; j < size; j++){
            matrix[i][j] = m1.matrix[i][j];
        }
    }
}

Matrix::~Matrix(){ //Matrix::~Matrix(){ delete [] buf;delete [] matrix;}
    delete [] buf;
    delete [] matrix;
}

Matrix &Matrix::operator=(const Matrix &a){ //Matrix &Matrix::operator=(const Matrix &a){return *this};
    // Matrix b(a);
    return *this;
}

Matrix &Matrix::clockwise90(){
    Matrix b(*this);
    for(int j = 0, _i = 0; j < size; j++, _i++){
        for(int i = size-1, _j = 0; i >= 0; i--, _j++){
            matrix[_i][_j] = b.matrix[i][j];
        }
    }
    return *this;
}
/*
3
1 2 3
1 1 1
1 1 2
*/
