#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>

using namespace std;

int getMatrixSize(string filename) {
    string line;
    ifstream infile;
    infile.open (filename.c_str());
    getline(infile, line);
    return count(line.begin(), line.end(), '\t') + 1;
}

void read(string filename, boost::numeric::ublas::matrix<int> &A, boost::numeric::ublas::matrix<int> &B) {
    string line;
    ifstream infile;
    infile.open (filename.c_str());
    int i=0, j, a;

    while (getline(infile, line) && !line.empty()) {
        istringstream iss(line);
        j = 0;
        while (iss >> a) {
            A(i,j) = a;
            j++;
        }
        i++;
    }

    i = 0;
    while (getline(infile, line)) {
        istringstream iss(line);
        j = 0;
        while (iss >> a) {
            B(i,j) = a;
            j++;
        }
        i++;
    }

    infile.close();
}

void printMatrix(boost::numeric::ublas::matrix<float> matrix) {
    for (unsigned int i=0; i < matrix.size1(); i++) {
        for (unsigned int j=0; j < matrix.size2(); j++) {
            cout << matrix(i, j);
            if(j+1 != matrix.size2()) {
                cout << "\t";
            }
        }
        cout << endl;
    }
}

int main () {

    float vodka = 0.0;
    float  rain = 1.0;
    float bFriend = 0.0;

    boost::numeric::ublas::matrix<float> INPUTS(1,3);

    boost::numeric::ublas::matrix<float> HIDDEN_LAYERS(3,2);



    INPUTS(0,0) = vodka;
    INPUTS(0,1) = rain;
    INPUTS(0,2) = bFriend;


    HIDDEN_LAYERS(0,0) = 0.25;
    HIDDEN_LAYERS(0,1) = 0.5;
    HIDDEN_LAYERS(1,0) = 0.25;
    HIDDEN_LAYERS(1,1) = static_cast<float>(-0.4);
    HIDDEN_LAYERS(2,0) = 0;
    HIDDEN_LAYERS(2,1) = 0.9;

    boost::numeric::ublas::matrix<float> RESULT = prod(INPUTS, HIDDEN_LAYERS);



    printMatrix(RESULT);

    return 0;
}