//
// Created by User on 10/10/2018.
//

#include "matrix.hpp"
#include <math.h>
#include <iostream>
#include <sstream>
using namespace std;
constexpr double RANDOM_WALK {0.85};
constexpr double EPSILON = 0.001;
constexpr double PERCENTAGE = 100;
//matrix default constructor
// creates array of 1 and sets it to 0.0
matrix::matrix(){
    row = 1;
    column = 1;
    matrix_array = new double[1]{};
    clear();
    matrix_size = 1;
}
//matrix constructor that takes an int size
//creates matrix of size, size * size
matrix::matrix(int size){
    if(size <= 0){
        throw ("Size cannot be 0 or negative");
    }
    matrix_array= new double[size*size]{};
    matrix_size = size*size;
    row = size;
    column = size;


}
//matrix constructor that takes two int for row and column size
//initializes array to all 1s
matrix::matrix(int r, int c){
    row = r;
    column = c;
    matrix_size = r*c;
    matrix_array = new double[r*c]{};
    for (int i = 0; i < matrix_size; i++){
        matrix_array[i] = 1;
    }

}
//matrix constructor that takes an array of double and an int of size
//throws exception if size is not a perfect square
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
//Sets the value inside of matrix in specified row and column to specified value
void matrix::set_value(int r, int c, double value){
    matrix_array[row * r + c] = value;
}
//Gets the value inside of matrix in specified row and column
//returns a double
double matrix::get_value(int r, int c) const{
     return matrix_array[row * r + c];

}
//Sets all rows and columns to 0
void matrix::clear(){
    for (int i = 0; i < matrix_size; i++){
        matrix_array[i]={0.0};
    }
}
//Matrix copy constructor
matrix::matrix(const matrix& c) :matrix_size(c.matrix_size), matrix_array(c.matrix_array), row(c.row),column(c.column){
    cout<<"Matrix copied"<<"\r\n";
};
//matrix destructor
matrix::~matrix(){
    cout<<"Matrix destroyed"<<"\r\n";
}
//Overloaded insertion operator that prints all values of matrix
ostream &operator<< (std::ostream &os, const matrix &matrix){
    ostringstream output;
    int n =1;
    for(int i = 0; i < matrix.getRow(); i++){
        cout << "Page " << matrix.nth_letter(n)<< ": ";
        for(int j=0; j < matrix.getColumn(); j++){
            cout << matrix.get_value(j,i) << "% ";
        }
        n++;
        cout << "\r\n";
    }


}
//Nth letter returns the letter in alphabet according to the int passed in
char matrix::nth_letter(int n) const
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(n >= 1 && n <= 26)
    return alpha[n-1];
}
//overloaded == operator that checks if elements in matrices are within tolerance of each other
bool operator== (const matrix &left_matrix, const matrix &right_matrix){
    if(left_matrix.getMatrix_size()!= right_matrix.getMatrix_size()){
        return false;
    }
    for(int i =0; i < left_matrix.getRow(); i++){
        for(int j = 0; j < left_matrix.getColumn(); j++){
            if(fabs(left_matrix.get_value(i, j) - right_matrix.get_value(i, j)) > (EPSILON * fabs(left_matrix.matrix_array[i]))){
                return false;
            }
        }

    }
    return true;
}
//overloaded != operator that checks if two matrices are not equal
bool operator!= (const matrix &left_matrix, const matrix &right_matrix){
    return !(left_matrix==right_matrix);
}
//Overloaded pre-increment operator that increments all elements in matrix by 1
matrix& matrix::operator++(){
    for(int i = 0; i < matrix_size; i++){
        matrix_array[i] = matrix_array[i] + 1.0;
    }
    return *this;
}
//overloaded post-increment operator that increments all elements in matrix by 1
matrix matrix::operator++(int){
    matrix(*this);
    operator++();
    return *this;
}
//overloaded pre-decrement operator that decrements all elements in matrix by 1
matrix& matrix::operator--(){
    for(int i = 0; i < matrix_size; i++){
        matrix_array[i] = matrix_array[i] - 1.0;
    }
    return *this;
}
//overloaded post-decrement operator that decrements all elements in matrix by 1
matrix matrix::operator--(int){
    matrix(*this);
    operator--();
    return *this;
}
//Swap function that uses std::swap to swap variables
void matrix::swap(matrix& first, matrix& second){
    using std::swap;
    swap(first.matrix_size, second.matrix_size);
    swap(first.matrix_array, second.matrix_array);
    swap(first.row, second.row);
    swap(first.column, second.column);
}
//overloaded assignment operator
//using swap function
matrix& matrix::operator= (matrix& right){
    swap(*this, right);
    return *this;

}
//overloaded += operator that adds another matrix to itself
matrix& matrix::operator+= (const matrix& right){
    for(int i = 0; i < getRow(); i++){
        for(int j=0; j < getColumn(); j++){
            set_value(i,j,get_value(i,j)+ right.get_value(i,j));
        }

    }
}
//overloaded + operator that adds two matrices
matrix operator+ (matrix left, const matrix& right){
    left += right;
    return left;
}
//overloaded -= operator that subtracts another matrix to itself
matrix& matrix::operator-= (const matrix& right){
    for(int i = 0; i < getRow(); i++){
        for(int j=0; j < getColumn(); j++){
            set_value(i,j,get_value(i,j)- right.get_value(i,j));
        }

    }
}
//overloaded - operator that subtracts two matrices
matrix operator- (matrix left, const matrix& right){
    left -= right;
    return left;
}
//overloaded *= operator that multiples another matrix to itself
matrix& matrix::operator*= (const matrix& right){
    if(row!= right.getRow()){
        throw "Number of rows in second matrix must match number of columns in first matrix";
    }
    auto * temp_matrix = new double[row*right.getColumn()];
    for(int i = 0; i < getRow(); ++i){
        for(int j=0; j < right.getColumn(); ++j){
            for(int k = 0; k < getColumn(); ++k){
                temp_matrix[row * i + j] += (get_value(i,k)* right.get_value(k,j));
            }
        }
    }
    delete[] matrix_array;
    matrix_array = new double[row*right.getColumn()];
    row = right.getRow();
    copy(temp_matrix, temp_matrix + (row*right.getColumn()), matrix_array);
    delete[] temp_matrix;
    return *this;

}
//overloaded * operator that multiplies two matrices
matrix* operator* (matrix left, matrix right){
    left *= right;
    return &left;
}
//Divides every 1 in column of matrix by the total 1s in column
//Divides entire column by 1/column if column contains only 0
void matrix::importance(){
    int* temp = new int[column]{0};
    int count{0};
    for(int i = 0; i < column; i++){
        for (int j = 0; j < row; j++){
            if(matrix_array[row*j + i] == 1){
                temp[j] = row*j + i;
                count++;
            }
        }
        if(count == 0){
            for (int k = 0; k < column; k++) {
                matrix_array[row * k + i] = (1.0 / column);
            }
        }else {
            for (int k = 0; k < column; k++) {
                if (matrix_array[temp[k]] == 1) {
                    matrix_array[temp[k]] = matrix_array[temp[k]] / count;
                }
            }
        }
        count= 0;
    }
}
//Multiples every element in matrix by a double
matrix& matrix::scalar_multiply (double random_walk) {
    for(int i = 0; i < matrix_size; i++){
        matrix_array[i] *= random_walk;
    }
}
//Changes every element in matrix to 1/column
void matrix::change_matrix() {
    for(int i = 0; i < getRow(); i++){
        for(int j=0; j < getColumn(); j++){
            set_value(i,j, 1.0/getColumn());
        }
    }
}
//converts every element in matrix to a percentage
void matrix::percentage() {
    for (int i = 0; i < getRow(); ++i) {
        for (int j = 0; j < getColumn(); ++j) {
            double temp = get_value(j, i) * PERCENTAGE;
            float percent = (float) temp * PERCENTAGE;
            temp = roundf(percent) / PERCENTAGE;
            set_value(i, j, temp);
        }
    }
}
//Divides the element in column by the sum of the column
void matrix::markov() {
    for (int i = 0; i < getColumn(); ++i) {
        double sum = 0;
        for (int j = 0; j < getRow(); ++j) {
            sum += get_value(j, i);
        }
        if (sum == 0) {
            for (int j = 0; j < getColumn(); ++j) {
                double temp = 1.0 / getColumn();
                set_value(j, i, temp);
            }
        } else {
            for (int j = 0; j < getColumn(); ++j) {
                double temp = get_value(j, i);
                if (temp == 0) {
                    set_value(j, i, 0.0);
                } else {
                    set_value(j, i, temp / sum);
                }
            }
        }
    }
}
//Returns the variable row
int matrix::getRow() const {
    return row;
}
//Returns the variable column
int matrix::getColumn() const {
    return column;
}
//Returns the variable matrix size
int matrix::getMatrix_size() const {
    return matrix_size;
}


