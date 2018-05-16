#include "net.h"
#include <math.h>

using namespace boost::numeric::ublas;

void Net::initInputs() {

    INPUTS.resize(1, 3);

    INPUTS(0, 0) = 1.0;
    INPUTS(0, 1) = 1.0;
    INPUTS(0, 2) = 0.0;
}

void Net::initWeights() {

    WEIGHTS_0_1.resize(3, 2);

    //fillWeights(WEIGHTS_0_1);

    WEIGHTS_0_1(0, 0) = 0.79;
    WEIGHTS_0_1(0, 1) = 0.85;
    WEIGHTS_0_1(1, 0) = 0.44;
    WEIGHTS_0_1(1, 1) = 0.43;
    WEIGHTS_0_1(2, 0) = 0.43;
    WEIGHTS_0_1(2, 1) = 0.29;

    WEIGHTS_1_2.resize(2, 1);

    //fillWeights(WEIGHTS_1_2);

    WEIGHTS_1_2(0, 0) = 0.5;
    WEIGHTS_1_2(1, 0) = 0.52;

    HIDDEN_OUTPUT.resize(1, 2);
}

Net::Net(float learningRate) : learningRate(learningRate) {
    initInputs();
    initWeights();
    predict();
}

float Net::activationFunction(float x) {

    return 1 / (1 + exp(-x));
}

bool Net::predict() {

    HIDDEN_INPUT = prod(INPUTS, WEIGHTS_0_1);

    sigmoidMapper(HIDDEN_INPUT, HIDDEN_OUTPUT);

    OUTPUT = prod(HIDDEN_OUTPUT, WEIGHTS_1_2);

    sigmoidMapper(OUTPUT, OUTPUT);

    return OUTPUT(0, 0) > .5;
}

void Net::printMatrix(matrix<float> matrix) {

    for (boost::numeric::ublas::matrix<float>::iterator1 it1 = matrix.begin1(); it1 != matrix.end1(); ++it1) {
        for (boost::numeric::ublas::matrix<float>::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2) {
            std::cout << "(" << it2.index1() << "," << it2.index2() << ") = " << *it2 << std::endl;
        }
    }
}

float Net::getRandomNumber() {

    return (float) 0.01 * (rand() % 101);
}

void Net::fillWeights(matrix<float> &M) {

    for (matrix<float>::iterator1 it1 = M.begin1(); it1 != M.end1(); ++it1) {
        for (matrix<float>::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2) {
            M(it2.index1(), it2.index2()) = getRandomNumber();
        }
    }
}

void Net::sigmoidMapper(matrix<float> &INPUT, matrix<float> &OUTPUT) {

    for (matrix<float>::iterator1 it1 = INPUT.begin1(); it1 != INPUT.end1(); ++it1) {
        for (matrix<float>::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2) {
            OUTPUT(it2.index1(), it2.index2()) = activationFunction(*it2);
        }
    }
}

void Net::train() {

    float expectedPredict = 0;

    HIDDEN_INPUT = prod(INPUTS, WEIGHTS_0_1);

    sigmoidMapper(HIDDEN_INPUT, HIDDEN_OUTPUT);

    OUTPUT = prod(HIDDEN_OUTPUT, WEIGHTS_1_2);

    sigmoidMapper(OUTPUT, OUTPUT);

    float actualPredict = OUTPUT(0, 0);

    float errorLayer2 = actualPredict - expectedPredict;

    float gradientLayer2 = actualPredict * (1 - actualPredict);

    float weightsDeltaLayer2 = errorLayer2 * gradientLayer2;

    matrix<float> HIDDEN_OUTPUT_RESIZED(2, 1, HIDDEN_OUTPUT.data());

    //printMatrix(NEW_MATRIX);

    WEIGHTS_1_2 -= (HIDDEN_OUTPUT_RESIZED * learningRate * weightsDeltaLayer2);

    printMatrix(WEIGHTS_1_2);

    matrix<float> ERROR_LAYER1 = weightsDeltaLayer2 * WEIGHTS_1_2;

    matrix<float> GRADIENT_LAYER = prod(HIDDEN_OUTPUT,getTempMatrix(HIDDEN_OUTPUT));

    //float weightsDeltaLayer1 = errorLayer2 * gradientLayer2;


    printMatrix(GRADIENT_LAYER);


    //error_layer_1 = weights_delta_layer_2 * self.weights_1_2,

    //gradient_layer_1 = outputs_1 * (1 - outputs_1),

    //weights_delta_layer_1 = error_layer_1 * gradient_layer_1,

    //self.weights_0_1 -= np.dot(inputs.reshape(len(inputs), 1), weights_delta_layer_1).T  * self.learning_rate

}

matrix<float> Net::getTempMatrix(matrix<float> &M) {

    matrix<float> TEMP_MATRIX(M.size1(), M.size2());

    for (matrix<float>::iterator1 it1 = M.begin1(); it1 != M.end1(); ++it1) {
        for (matrix<float>::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2) {
            TEMP_MATRIX(it2.index1(), it2.index2()) = 1 - *it2;
        }
    }

    return TEMP_MATRIX;
}