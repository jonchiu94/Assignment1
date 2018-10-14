//
// Created by User on 10/10/2018.
//
#include <iostream>
#pragma once

class matrix {
private:
    int row;
    int column;
    int matrix_size;
    double matrix_array[];
public:
    matrix();
    matrix(int size);
    matrix(int r, int c);
    matrix(double input[], int size);
    void set_value(int r, int c, double value);
    double get_value(int r, int c) const;
    void clear();
    ~matrix();
    char nth_letter(int n) const;
    friend std::ostream &operator<< (std::ostream &os, const matrix &matrix);
    friend bool operator== (const matrix &left_matrix, const matrix &right_matrix);
    friend bool operator!= (const matrix &left_matrix, const matrix &right_matrix);
    matrix& operator++();
    matrix operator++(int);
    matrix& operator--();
    matrix operator--(int);
    matrix& operator= (matrix right);
    matrix& operator+= (const matrix& right);
    friend matrix operator+ (matrix left, const matrix& right);
    matrix& operator-= (const matrix& right);
    friend matrix operator- (matrix left, const matrix& right);
    matrix& operator*= (const matrix& right);
    friend matrix operator* (matrix left, matrix right);
    int getRow() const;

    int getColumn() const;

    int getMatrix_size() const;

    const double *getMatrix_array() const;
    void setRow(int row);

    void setColumn(int column);

    void setMatrix_size(int matrix_size);
};



