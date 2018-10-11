//
// Created by User on 10/10/2018.
//
#include <iostream>
#pragma once

class matrix {
private:
    int row;
    int column;
    int size;
    double matrix_array[];
public:
    matrix();
    matrix(int size);
    matrix(int r, int c);
    matrix(double input[]);
    void set_value(int row, int column, double value);
    void get_value(int row, int column);
    void clear();
    ~matrix();
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
};



