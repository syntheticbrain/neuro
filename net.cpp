#include "net.h"
#include <math.h>

using namespace boost::numeric::ublas;


void Net::initInputs() {

    float vodka = 1.0;
    float rain = 1.0;
    float bFriend = 0.0;

    INPUTS.resize(1,3);

    INPUTS(0, 0) = vodka;
    INPUTS(0, 1) = rain;
    INPUTS(0, 2) = bFriend;
}


void Net::initWeights() {

    WEIGHTS_INPUTS.resize(3,2);

    WEIGHTS_INPUTS(0, 0) = 0.79;
    WEIGHTS_INPUTS(0, 1) = 0.85;
    WEIGHTS_INPUTS(1, 0) = 0.44;
    WEIGHTS_INPUTS(1, 1) = 0.43;
    WEIGHTS_INPUTS(2, 0) = 0.43;
    WEIGHTS_INPUTS(2, 1) = 0.29;

    WEIGHTS_OUTPUT.resize(2,1);

    WEIGHTS_OUTPUT(0, 0) = 0.5;
    WEIGHTS_OUTPUT(1, 0) = 0.52;
}

Net::Net() {
    initInputs();
    initWeights();
    process();
}

float Net::activationFunction(float x) {

    return sigmoid(x);
}

float Net::sigmoid(float x) {

    float exp_value;
    float return_value;

    exp_value = exp((double) -x);

    return_value = 1 / (1 + exp_value);

    return return_value;
}

void Net::process() {

    HIDDEN_INPUT = prod(INPUTS, WEIGHTS_INPUTS);

    HIDDEN_OUTPUT.resize(1,2);

    for (matrix<float>::iterator1 it1 = HIDDEN_INPUT.begin1(); it1 != HIDDEN_INPUT.end1(); ++it1) {
        for (matrix<float>::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2) {
            HIDDEN_OUTPUT(it2.index1(),it2.index2()) =  activationFunction(*it2);
        }
    }

    OUTPUT = prod(HIDDEN_OUTPUT, WEIGHTS_OUTPUT);

    for (matrix<float>::iterator1 it1 = OUTPUT.begin1(); it1 != OUTPUT.end1(); ++it1) {
        for (matrix<float>::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2) {
            OUTPUT(it2.index1(),it2.index2()) =  activationFunction(*it2);
        }
    }
}