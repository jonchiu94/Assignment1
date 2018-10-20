#include <iostream>
#include <fstream>
#include <vector>
#include "matrix.hpp"
#include "connectivity.hpp"
#include "qmatrix.hpp"

using namespace std;

void read_file() {
    matrix* matrix_1;
    matrix* matrix_2;
    ifstream myFile{"../connectivity.txt"};
    if (!myFile) {
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
        for (int i = 0; i < temp.size(); i++) {
            temp_array[i] = temp[i];
        }
        matrix_1 = new matrix(temp_array, temp.size());
        matrix_2 = new matrix(temp.size());
        *matrix_1 += *matrix_2;
        matrix_2 = new matrix(matrix_1->getColumn(),1);
        cout<<*matrix_1<<endl;
    }
    myFile.close();

}

int main() {
    read_file();
//    *matrix_1 += *matrix_2;

    return 0;
}