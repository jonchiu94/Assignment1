//
// Created by User on 10/19/2018.
//

#include "qmatrix.hpp"
#include "matrix.hpp"
#include <math.h>
using namespace std;
constexpr double RANDOM_WALK {0.85};
qmatrix::qmatrix(int size): matrix(sqrt(size)){
    change_matrix();
    scalar_multiply(1.0-RANDOM_WALK);
}
void qmatrix::change_matrix() {
    for(int i = 0; i < getRow(); i++){
        for(int j=0; j < getColumn(); j++){
            set_value(i,j, 1.0/getColumn());
        }
    }
}