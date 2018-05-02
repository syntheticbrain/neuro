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

void printMatrix(boost::numeric::ublas::matrix<int> matrix) {
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


    int n = 2;
    boost::numeric::ublas::matrix<int> A(n,n), B(n,n);

    A(0,0) = 2;
    A(0,1) = 3;
    A(1,0) = 1;
    A(1,1) = 4;

    B(0,0) = 4;
    B(0,1) = 2;
    B(1,0) = 1;
    B(1,1) = 5;

    boost::numeric::ublas::prod(A, B);

    boost::numeric::ublas::matrix<int> C = prod(A, B);

    printMatrix(C);

    return 0;
}