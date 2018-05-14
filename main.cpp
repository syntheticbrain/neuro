#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include "net.h"
#include <math.h>

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

float sigmoid(float x) {

    float exp_value;
    float return_value;

    exp_value = exp((double) -x);

    return_value = 1 / (1 + exp_value);

    return return_value;
}


float activationFunction(float x) {

    return sigmoid(x);
}


int main() {

/*    float vodka = 1.0;
    float rain = 1.0;
    float bFriend = 0.0;

    boost::numeric::ublas::matrix<float> INPUTS(1, 3);

    INPUTS(0, 0) = vodka;
    INPUTS(0, 1) = rain;
    INPUTS(0, 2) = bFriend;

    boost::numeric::ublas::matrix<float> WEIGHTS_INPUTS(3, 2);

    WEIGHTS_INPUTS(0, 0) = 0.79;
    WEIGHTS_INPUTS(0, 1) = 0.85;
    WEIGHTS_INPUTS(1, 0) = 0.44;
    WEIGHTS_INPUTS(1, 1) = 0.43;
    WEIGHTS_INPUTS(2, 0) = 0.43;
    WEIGHTS_INPUTS(2, 1) = 0.29;

    boost::numeric::ublas::matrix<float> WEIGHTS_OUTPUT(2, 1);

    WEIGHTS_OUTPUT(0, 0) = 0.5;
    WEIGHTS_OUTPUT(1, 0) = 0.52;

    boost::numeric::ublas::matrix<float> HIDDEN_INPUT = prod(INPUTS, WEIGHTS_INPUTS);

    boost::numeric::ublas::matrix<float> HIDDEN_OUTPUT(1,2);

    for (boost::numeric::ublas::matrix<float>::iterator1 it1 = HIDDEN_INPUT.begin1(); it1 != HIDDEN_INPUT.end1(); ++it1) {
        for (boost::numeric::ublas::matrix<float>::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2) {
            HIDDEN_OUTPUT(it2.index1(),it2.index2()) =  activationFunction(*it2);
        }
    }


    boost::numeric::ublas::matrix<float> OUTPUT = prod(HIDDEN_OUTPUT, WEIGHTS_OUTPUT);

    for (boost::numeric::ublas::matrix<float>::iterator1 it1 = OUTPUT.begin1(); it1 != OUTPUT.end1(); ++it1) {
        for (boost::numeric::ublas::matrix<float>::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2) {
            OUTPUT(it2.index1(),it2.index2()) =  activationFunction(*it2);
        }
    }

    printMatrix(OUTPUT);*/

    Net net(0);

    printMatrix(net.OUTPUT);

    //net.printVector(net.inputs);
    //net.printVector(net.inputWeights);

    return 0;
}