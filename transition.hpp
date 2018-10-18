//
// Created by User on 10/14/2018.
//

#pragma once
#include "matrix.hpp"

class transition : public matrix{
private:
    int row;
    int column;
    int matrix_size;
    static double transition_array[];
public:
    transition();
    transition(int size);
    void set_value(int r, int c, double value);
    double get_value(int r, int c) const;
    void clear();
    ~transition();
    friend std::ostream &operator<< (std::ostream &os, const matrix &matrix);
    int getRow() const;

    int getColumn() const;

    int getMatrix_size() const;


};


