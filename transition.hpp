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
    double matrix_array[];
public:
    transition();
    void set_value(int r, int c, double value);
    double get_value(int r, int c) const;
    void clear();
    ~transition();
    friend std::ostream &operator<< (std::ostream &os, const matrix &matrix);
    int getRow() const;

    int getColumn() const;

    int getMatrix_size() const;

    const double *getMatrix_array() const;
    void setRow(int row);

    void setColumn(int column);

    void setMatrix_size(int matrix_size);
};


#endif //ASSIGNMENT1_TRANSITION_HPP
