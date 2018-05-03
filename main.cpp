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
    infile.open(filename.c_str());
    getline(infile, line);
    return count(line.begin(), line.end(), '\t') + 1;
}

void read(string filename, boost::numeric::ublas::matrix<int> &A, boost::numeric::ublas::matrix<int> &B) {
    string line;
    ifstream infile;
    infile.open(filename.c_str());
    int i = 0, j, a;

    while (getline(infile, line) && !line.empty()) {
        istringstream iss(line);
        j = 0;
        while (iss >> a) {
            A(i, j) = a;
            j++;
        }
        i++;
    }

    i = 0;
    while (getline(infile, line)) {
        istringstream iss(line);
        j = 0;
        while (iss >> a) {
            B(i, j) = a;
            j++;
        }
        i++;
    }

    infile.close();
}

void printMatrix(boost::numeric::ublas::matrix<float> matrix) {

    for (boost::numeric::ublas::matrix<float>::iterator1 it1 = matrix.begin1(); it1 != matrix.end1(); ++it1) {
        for (boost::numeric::ublas::matrix<float>::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2) {
            std::cout << "(" << it2.index1() << "," << it2.index2() << ") = " << *it2 << endl;
        }
        cout << endl;
    }
}

int activation_function(float x) {

    if (x >= 0.5) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    float vodka = 0.0;
    float rain = 1.0;
    float bFriend = 0.0;

    boost::numeric::ublas::matrix<float> INPUTS(1, 3);

    INPUTS(0, 0) = vodka;
    INPUTS(0, 1) = rain;
    INPUTS(0, 2) = bFriend;

    boost::numeric::ublas::matrix<float> WEIGHTS_INPUT_TO_HIDDEN(3, 2);

    WEIGHTS_INPUT_TO_HIDDEN(0, 0) = 0.25;
    WEIGHTS_INPUT_TO_HIDDEN(0, 1) = 0.5;
    WEIGHTS_INPUT_TO_HIDDEN(1, 0) = 0.25;
    WEIGHTS_INPUT_TO_HIDDEN(1, 1) = -0.4;
    WEIGHTS_INPUT_TO_HIDDEN(2, 0) = 0;
    WEIGHTS_INPUT_TO_HIDDEN(2, 1) = 0.9;

    boost::numeric::ublas::matrix<float> WEIGHTS_OUTPUT_TO_HIDDEN(1, 2);


    WEIGHTS_OUTPUT_TO_HIDDEN(0, 0) = -1.0;
    WEIGHTS_OUTPUT_TO_HIDDEN(0, 1) = 1.0;

    boost::numeric::ublas::matrix<float> HIDDEN_OUTPUT(2,1);


    boost::numeric::ublas::matrix<float> HIDDEN_INPUT = prod(INPUTS, WEIGHTS_INPUT_TO_HIDDEN);

    vector<float> hiddenOutput;

/*    for (boost::numeric::ublas::matrix<float>::iterator1 it1 = HIDDEN_INPUT.begin1();
         it1 != HIDDEN_INPUT.end1(); ++it1) {
        for (boost::numeric::ublas::matrix<float>::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2) {

            HIDDEN_OUTPUT(0,it2.index2()) = activation_function(*it2);
        }
        cout << endl;
    }

    for(vector<float>::const_iterator it = hiddenOutput.begin(); it != hiddenOutput.end(); ++it) {
        cout << *it;
        cout << endl;

    }*/

    printMatrix(HIDDEN_INPUT);

    return 0;
}