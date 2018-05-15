#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include "net.h"

using namespace std;

int main() {

    Net net(0);

    net.printMatrix(net.OUTPUT);

    return 0;
}