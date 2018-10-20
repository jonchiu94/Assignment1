#include <iostream>
#include <fstream>
#include <vector>
#include "matrix.hpp"
#include "connectivity.hpp"
#include <math.h>

using namespace std;
//Reads connectivity file and creates matrix
void read_file() {
    matrix* matrix_1;
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
        matrix_1 = new connectivity(temp_array, temp.size());

    }
    myFile.close();

}
//Runs the program
int main() {
    read_file();
    return 0;
}