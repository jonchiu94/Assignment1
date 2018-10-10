//
// Created by User on 10/10/2018.
//
#include <iostream>
#pragma once

class matrix {
private:
    int row;
    int column;
public:
    matrix();
    matrix(int size);
    matrix(int r, int c);
    matrix(double array[]);
    void set_value(int row, int column, double value);
    void get_value(int row, int column);
    void clear();
    ~matrix();
    friend std::ostream &operator<< (std::ostream &os, const matrix &matrix);


};



