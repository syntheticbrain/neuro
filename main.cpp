#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include "net.h"

using namespace std;

int main() {

    srand(time(0));

    Net net(0.1);

    //net.predict();

    net.train();



    return 0;
}