#ifndef NEURO_NET_H
#define NEURO_NET_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>

using namespace boost::numeric::ublas;


class Net {
private:

    matrix<float> INPUTS;
    matrix<float> WEIGHTS_0_1;
    matrix<float> WEIGHTS_1_2;
    matrix<float> HIDDEN_INPUT;
    matrix<float> HIDDEN_OUTPUT;
    matrix<float> OUTPUT;

    float learningRate;

    void initInputs();

    void initWeights();

    float activationFunction(float x);

    void sigmoidMapper(matrix<float> &INPUT,matrix<float> &OUTPUT);

    float getRandomNumber();

    void fillWeights(matrix<float> &M);

    matrix<float> getTempMatrix(matrix<float> &M);

public:

    bool predict();

    void train();

    Net(float learningRate);

    void printMatrix(matrix<float> matrix);
};


#endif