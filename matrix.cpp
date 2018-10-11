//
// Created by User on 10/10/2018.
//

#include "matrix.hpp"
#include <math.h>
#include <iostream>
using namespace std;

matrix::matrix(){
    matrix_array[1]={0.0};
}
matrix::matrix(int size){
    matrix_array[size*size]={0.0};
}
matrix::matrix(int r, int c){
    matrix_array[r*c]={0.0};
}
matrix::matrix(double input[]){
    size =0;
    while(input[size]){
        size++;
    }
    double sr = sqrt(size);
    if((sr-floor(sr))==0){
        throw "size of array is not a perfect square";
    }
}
void matrix::set_value(int row, int column, double value){

}
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