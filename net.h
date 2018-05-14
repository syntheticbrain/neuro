//
// Created by adronov on 11.05.18.
//

#ifndef NEURO_NET_H
#define NEURO_NET_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>

#define ONE 1
#define THREE 3

using namespace boost::numeric::ublas;


class Net {
public:
    Net();

    matrix<float> INPUTS;
    matrix<float> WEIGHTS_INPUTS;
    matrix<float> WEIGHTS_OUTPUT;
    matrix<float> HIDDEN_INPUT;
    matrix<float> HIDDEN_OUTPUT;
    matrix<float> OUTPUT;

    void initInputs();

    void initWeights();

    void process();

    float activationFunction(float x);

    float sigmoid(float x);

};


#endif //NEURO_NET_H