//
// Created by User on 10/14/2018.
//
#include "connectivity.hpp"
using namespace std;
constexpr double RANDOM_WALK {0.85};

connectivity::connectivity(double matrix_array[], int matrix_size) : matrix(matrix_array, matrix_size){
    importance();
    scalar_multiply(RANDOM_WALK);
}
connectivity::~connectivity(){

}
