//
//  main.cpp
//  RationalCopyAssignmentExample
//
//  Created by David M. Reed on 9/29/21.
//

#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include "Rational.hpp"

void f1(Rational r) {
    cout << r << endl;
}

Rational f2(Rational &r) {
    cout << r <<endl;
    return r;
}


int main(int argc, const char * argv[]) {

    Rational r1(3, 4);
    Rational r2(r1);

    Rational r3;

    r3 = r1;

    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;

    f1(r1);
    // note because r4 is immediately assigned the return value of f2, it does not first call the constructor for r4 and then call the assignment operator to assign the value returned by f2; instead it just calls the copy constructor with the value returned so r4 is constructed once with the value returned
    Rational r4 = f2(r3);
    cout << r4 << endl;

    Rational r5(1, 2);
    // becuase r5 is constructed above, now the assignment operator would
    // be used for the next line
    r5 = f2(r3);

    return 0;
