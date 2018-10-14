//
// Created by User on 10/10/2018.
//

#include "matrix.hpp"
#include <math.h>
#include <iostream>
#include <sstream>
using namespace std;

matrix::matrix(){
    matrix_array[1]={0.0};
    this->matrix_size = 1;
}
matrix::matrix(int size){
    if(size <= 0){
        throw "Size cannot be 0 or negative";
    }
    this->matrix_array[size*size];
    clear();
    this->matrix_size = size*size;
}
matrix::matrix(int r, int c){
    this->matrix_array[r*c]={0.0};
    this->row = r;
    this->column = c;
    this->matrix_size = r*c;
}
matrix::matrix(double input[], int size){
    this->matrix_size = size;
    double sr = sqrt(matrix_size);
    if((sr-floor(sr))!=0){
        throw "size of array is not a perfect square";
    }
    for (int i = 0; i < matrix_size; i++){
        matrix_array[i] = input[i];
    }
    this->row = sqrt(matrix_size);
    this->column = sqrt(matrix_size);
}
void matrix::set_value(int r, int c, double value){
    matrix_array[row * c + r] = value;
}
double matrix::get_value(int r, int c) const{
    double temp = matrix_array[row * c + r];
    return temp;
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

    ostringstream output;
    int n =1;
    for(int i = 0; i < matrix.getRow(); i++){
        cout << "Page " << matrix.nth_letter(n)<< ": ";
        for(int j=0; j < matrix.getColumn(); j++){
            cout << matrix.get_value(i,j);
        }
        n++;
        cout << "\r\n";
    }


}
char matrix::nth_letter(int n) const
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(n >= 1 && n <= 26)
    return alpha[n-1];
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



matrix operator++(matrix){

}
matrix& matrix::operator--(){

}
matrix operator--(matrix){

}
matrix& matrix::operator= (matrix right){
    this-> row = right.getRow();
    this->column = right.getColumn();
    this->matrix_size = right.getMatrix_size();
    for(int i = 0; i < getRow(); i++){
        for(int j=0; j < getColumn(); j++){
            set_value(i,j,right.get_value(i,j));
        }

    }

}
matrix& matrix::operator+= (const matrix& right){
    for(int i = 0; i < getRow(); i++){
        for(int j=0; j < getColumn(); j++){
            set_value(i,j,get_value(i,j)+ right.get_value(i,j));
        }

    }
}
matrix operator+ (matrix left, const matrix& right){
    left += right;
    return left;
}
matrix& matrix::operator-= (const matrix& right){
    for(int i = 0; i < getRow(); i++){
        for(int j=0; j < getColumn(); j++){
            set_value(i,j,get_value(i,j)- right.get_value(i,j));
        }

    }
}
matrix operator- (matrix left, const matrix& right){
    left -= right;
    return left;
}
matrix& matrix::operator*= (const matrix& right){
    double temp = 0;
    for(int i = 0; i < getRow(); i++){
        for(int j=0; j < getColumn(); j++){
            temp += get_value(i,j)* right.get_value(j,0);
        }

    }
}
matrix operator* (matrix left, matrix right){
    left *= right;
    return left;
}
int matrix::getRow() const {
    return row;
}

int matrix::getColumn() const {
    return column;
}

int matrix::getMatrix_size() const {
    return matrix_size;
}


