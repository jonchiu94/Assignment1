#include <iostream>
#include <fstream>
#include <vector>
#include "matrix.hpp"
#include "connectivity.hpp"
using namespace std;
constexpr double random_walk {0.85};
int main() {
    matrix* matrix_1;
    matrix* matrix_2;
    ifstream myFile{"../connectivity.txt"};
    if (!myFile){
        cerr << "error opening file" << endl;
        exit(1);
    }
    if (myFile.is_open()) {
        vector<double> temp;
        double new_digit;
        while (myFile >> new_digit) {
            temp.push_back(new_digit);
        }
        double temp_array[temp.size()];
        for(int i = 0; i < temp.size(); i++){
            temp_array[i] = temp[i];
        }
        matrix_1 = new matrix(temp_array, temp.size());
        matrix_1->importance();
        matrix_1->scalar_multiply(random_walk);
        cout<<*matrix_1<<endl;
        myFile.close();
    }


    return 0;
}