//
// Created by User on 10/14/2018.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "connectivity.hpp"
using namespace std;
connectivity::connectivity(){
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
        for (int i = 0; i < temp.size(); i++) {
            temp_array[i] = temp[i];
        }
        matrix(temp_array, temp.size());
    }
    myFile.close();
}
connectivity::connectivity(int size){

}
//void set_value(int r, int c, double value);
//double get_value(int r, int c) const;
//void clear();
//~transition();
//friend std::ostream &operator<< (std::ostream &os, const matrix &matrix);
//int getRow() const;
//
//int getColumn() const;
//
//int getMatrix_size() const;