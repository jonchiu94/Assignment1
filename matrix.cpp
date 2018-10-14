//
// Created by User on 10/10/2018.
//

#include "matrix.hpp"
#include <math.h>
#include <iostream>
using namespace std;

matrix::matrix(){
    matrix_array[1]={0.0};
    matrix_size = 1;
}
matrix::matrix(int size){
    matrix_array[size*size]={0.0};
    this->matrix_size = size*size;
}
matrix::matrix(int r, int c){
    matrix_array[r*c]={0.0};
    row = r;
    column = c;
    matrix_size = r*c;
}
matrix::matrix(double input[]){
    matrix_size = sizeof(input);
    double sr = sqrt(matrix_size);
    if((sr-floor(sr))==0){
        throw "size of array is not a perfect square";
    }
    for (int i = 0; i < matrix_size; i++){
        matrix_array[i] = input[i];
    }
}
void matrix::set_value(int r, int c, double value){
    matrix_array[row * c + r] = value;
}
double matrix::get_value(int r, int c){
    return matrix_array[row * c + r];
}
void matrix::clear(){
    for (int i = 0; i < matrix_size; i++){
        matrix_array[i]={0.0};
    }
}
matrix::~matrix(){
    cout<<"Matrix destroyed"<<"\r\n";
}
ostream &operator<< (std::ostream &os, const matrix &matrix){
    int row_count = 1;
    while(row_count<matrix.getRow()){
        for(int i = 1; i < matrix.getColumn(); i++){
//            cout<<matrix.get_value(1,i);
        }
    }

}
bool operator== (const matrix &left_matrix, const matrix &right_matrix){
    if(left_matrix.getMatrix_size()!= right_matrix.getMatrix_size()){
        return false;
    }
    for(int i =0; i < left_matrix.getMatrix_size(); i++){
        if(left_matrix.matrix_array[i] != right_matrix.matrix_array[i]){
            return false;
        }
    }
    return true;
}
bool operator!= (const matrix &left_matrix, const matrix &right_matrix){
    return !(left_matrix==right_matrix);
}
matrix& matrix::operator++(){

}



//matrix operator++(int){
//
//}
//matrix& operator--();
//matrix operator--(int);
//matrix& operator= (matrix right);
//matrix& operator+= (const matrix& right);
//friend matrix operator+ (matrix left, const matrix& right);
//matrix& operator-= (const matrix& right);
//friend matrix operator- (matrix left, const matrix& right);
//matrix& operator*= (const matrix& right);
//friend matrix operator* (matrix left, matrix right);
int matrix::getRow() const {
    return row;
}

int matrix::getColumn() const {
    return column;
}

int matrix::getMatrix_size() const {
    return matrix_size;
}

const double *matrix::getMatrix_array() const {
    return matrix_array;
}