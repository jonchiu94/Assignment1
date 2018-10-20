//
// Created by User on 10/14/2018.
//
#include "connectivity.hpp"
using namespace std;
constexpr double RANDOM_WALK {0.85};
//connectivity constructor
//Takes an array of doubles and an int
connectivity::connectivity(double matrix_array[], int matrix_size) : matrix(matrix_array, matrix_size){
    transition();
}
//Connectivity destructor
connectivity::~connectivity(){
    cout<< "destructor called"<<"\r\n";
}
//Creates and converts all matrices into page rank
matrix connectivity::transition(){
    int row = getRow();
    matrix S(*this);
    importance();
    scalar_multiply(RANDOM_WALK);
    matrix Q(row);
    Q.change_matrix();
    Q.scalar_multiply(1.0-RANDOM_WALK);
    matrix M = S + Q;
    matrix rank(getRow(), 1);
    rank = (M * rank);
    rank.percentage();
    cout<< rank << endl;

}



