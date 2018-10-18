//
// Created by User on 10/10/2018.
//

#include "matrix.hpp"
#include <math.h>
#include <iostream>
#include <sstream>
using namespace std;
constexpr double epsilon = 0.000001;
matrix::matrix(){
    row = 1;
    column = 1;
    matrix_array = new double[1]{};
    clear();
    matrix_size = 1;
}
matrix::matrix(int size){
    if(size <= 0){
        throw invalid_argument("Size cannot be 0 or negative");
    }
    matrix_array= new double[size*size]{};
    matrix_size = size*size;
    row = size;
    column = size;
}
matrix::matrix(int r, int c){
    row = r;
    column = c;
    matrix_size = r*c;
    matrix_array = new double[r*c]{};
}
matrix::matrix(double input[], int size){
    matrix_array= new double[size]{};
    matrix_size = size;
    double sr = sqrt(matrix_size);
    if((sr-floor(sr))!=0){
        throw "size of array is not a perfect square";
    }
    for (int i = 0; i < matrix_size; i++){
        matrix_array[i] = input[i];
    }
    row = sqrt(matrix_size);
    column = sqrt(matrix_size);
}
void matrix::set_value(int r, int c, double value){
    matrix_array[row * r + c] = value;
}
double matrix::get_value(int r, int c) const{
     return matrix_array[row * r + c];

}
void matrix::clear(){
    for (int i = 0; i < matrix_size; i++){
        matrix_array[i]={0.0};
    }
}
matrix::matrix(const matrix& c) :matrix_size(c.matrix_size), matrix_array(c.matrix_array), row(c.row),column(c.column){
    cout<<"Matrix copied"<<"\r\n";
};
matrix::~matrix(){
    cout<<"Matrix destroyed"<<"\r\n";
}
ostream &operator<< (std::ostream &os, const matrix &matrix){

    ostringstream output;
//    int n =1;
    for(int i = 0; i < matrix.getRow(); i++){
//        cout << "Page " << matrix.nth_letter(n)<< ": ";
        for(int j=0; j < matrix.getColumn(); j++){
            cout << matrix.get_value(i,j);
        }
//        n++;
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
        if(fabs(left_matrix.matrix_array[i] - right_matrix.matrix_array[i]) > (epsilon * fabs(left_matrix.matrix_array[i]))){
            return false;
        }
    }
    return true;
}
bool operator!= (const matrix &left_matrix, const matrix &right_matrix){
    return !(left_matrix==right_matrix);
}
matrix& matrix::operator++(){
    for(int i = 0; i < matrix_size; i++){
        matrix_array[i] = matrix_array[i] + 1.0;
    }
    return *this;
}

matrix matrix::operator++(int){
    matrix(*this);
    operator++();
    return *this;
}
matrix& matrix::operator--(){
    for(int i = 0; i < matrix_size; i++){
        matrix_array[i] = matrix_array[i] - 1.0;
    }
    return *this;
}
matrix matrix::operator--(int){
    matrix(*this);
    operator--();
    return *this;
}
void matrix::swap(matrix& first, matrix& second){
    using std::swap;
    swap(first.matrix_size, second.matrix_size);
    swap(first.matrix_array, second.matrix_array);
    swap(first.row, second.row);
    swap(first.column, second.column);
}
matrix& matrix::operator= (matrix& right){
    swap(*this, right);
    return *this;

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
    auto * temp_matrix = new double[row*right.getColumn()];
    double temp = 0;
    for(int i = 0; i < getRow(); i++){
        int pos_count =0;
        for(int j=0; j < right.getColumn(); j++){
            temp += get_value(i,j)* right.get_value(j,i);
            pos_count = j;
        }
        temp_matrix[row * i + pos_count] = temp;
    }
    delete[] matrix_array;
    matrix_array = new double[row*right.getColumn()];
    row = right.getRow();
    copy(temp_matrix, temp_matrix + (row*right.getColumn()), matrix_array);
    delete[] temp_matrix;
    return *this;

}
matrix operator* (matrix left, matrix right){
    left *= right;
    return left;
}
void matrix::importance(){
    int* temp = new int[row];
    double count{0.0};
    for(int i = 0; i < column; i++){
        for (int j = 0; j < row; j++){
            if(matrix_array[row*j + i] == 1){
                temp[i] = row*j + i;
                count++;
            }
        }
        for(int k = 0; k < row; k++){
            matrix_array[temp[k]] = matrix_array[temp[k]]/ count;
        }
        count= 0.0;
    }
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


