//
//  Rational.cpp
//  RationalCopyAssignmentExample
//
//  Created by David M. Reed on 9/29/21.
//

#include "Rational.hpp"

// note that methods written inline are not written again in the .cpp file

// methods implementatations require class to be specified
// after the return type as part of the method name with :: separating
// the class name and the rest of the method signature

// constructor does not have a return type
// and default parameters are not specified with implementation
Rational::Rational(int n, int d) {
    // calls method in class (note: unlike Python do not need self.)
    // can use this->set(n, d);
    set(n, d);
}

bool Rational::set(int n, int d) {
    if (d != 0) {
        _num = n;
        _den = d;
        return true;
    }
    else {
        return false;
    }
}

// note since these are not part of the class (standalone functions),
// we do not use Rational:: in front of the names of the functions

Rational operator*(const Rational &r1, const Rational &r2) {
    int n = r1.num() * r2.num();
    int d = r1.den() * r2.den();
    return Rational(n, d);
}

std::istream& operator>>(std::istream &is, Rational &r) {
    // for storing the / as we read in 2/3
    char c;

    // since it is a friend, it can directly access the private data
    is >> r._num >> c >> r._den;

    // other option would be to write:
    // int n, d;
    // is >> n >> c >> d;
    // r.set(n, d);

    // must return the stream passed in for chaining together multiple inputs
    return is;
}

std::ostream& operator<<(std::ostream &os, const Rational &r) {
    // since a friend can either directly access _num and _den or use accessor methods
    os << r.num() << "/" << r.den();

    // must return the stream passed in for chaining together multiple outputs
    return os;
}
