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
    double *matrix_array;
public:
    matrix();
    matrix(int size);
    matrix(int r, int c);
    matrix(double input[], int size);
    void set_value(int r, int c, double value);
    double get_value(int r, int c) const;
    void clear();
    matrix(const matrix& c);
    ~matrix();
    char nth_letter(int n) const;
    friend std::ostream &operator<< (std::ostream &os, const matrix &matrix);
    friend bool operator== (const matrix &left_matrix, const matrix &right_matrix);
    friend bool operator!= (const matrix &left_matrix, const matrix &right_matrix);
    matrix& operator++();
    matrix operator++(int);
    matrix& operator--();
    matrix operator--(int);
    void swap(matrix& first, matrix& second);
    matrix& operator= (matrix& right);
    matrix& operator+= (const matrix& right);
    friend matrix operator+ (matrix left, const matrix& right);
    matrix& operator-= (const matrix& right);
    friend matrix operator- (matrix left, const matrix& right);
    matrix& operator*= (const matrix& right);
    friend matrix* operator* (matrix left, matrix right);
    void importance();
    matrix& scalar_multiply (double random_walk);
    void change_matrix();
    void percentage();
    int getRow() const;

    int getColumn() const;

    int getMatrix_size() const;
};



