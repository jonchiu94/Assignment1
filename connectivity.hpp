//
// Created by User on 10/14/2018.
//

#pragma once
#include "matrix.hpp"

class connectivity : public matrix{
public:
    connectivity();
    connectivity(double matrix_array[], int matrix_size);
    ~connectivity();
    connectivity& operator+= (const connectivity& right);


};


