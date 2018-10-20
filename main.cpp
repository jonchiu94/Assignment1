#include <iostream>
#include <fstream>
#include <vector>
#include "matrix.hpp"
#include "connectivity.hpp"
using namespace std;
matrix* matrix_1;
matrix* matrix_2;
void read_file() {
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
int main() {
    read_file();
    cout<<*matrix_1<<endl;
    return 0;
}