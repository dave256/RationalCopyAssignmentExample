//
//  Rational.hpp
//  RationalCopyAssignmentExample
//
//  Created by David M. Reed on 9/29/21.
//

#ifndef Rational_hpp
#define Rational_hpp

// needed for definition of ostream and istream classes
#include <iostream>

// note: never put a "using" statement in a header file
// as a result we have to use std::istream, etc.
// instead of putting using namespace std; or using std::istream;

class Rational {

    // declare input and output operators functions as friends
    // to the class so they can directly access the private data
    friend std::istream& operator>>(std::istream& is, Rational &r);
    friend std::ostream& operator<<(std::ostream& os, const Rational &r);

    // most methods are declared public so other code can use them
    // may have some private "helper" methods that are only intended
    // to be called by the public methods
public:
    // constructor has same name as class and does not have a return type
    // default values specified in header file but not implementation
    Rational(int n = 0, int d = 1);

    Rational(const Rational &r);
    Rational& operator=(const Rational &r);

    // mutating method
    bool set(int n, int d);

    // access functions marked const since do not mutate the object

    // to avoid the overhead of a function call, short methods can be written here
    // by replacing the ; with the implementation inside {}
    // in this case instead of calling a function, the compiler replaces calls to
    // the method with the body provided here (without causing issues with private)
    // so it acts just like a function without the overhead of a function
    // note: the compiler may decide the method is too long and still create a function for it
    int num() const { return _num; }
    int den() const { return _den; }

    // returns decimal equivalent (also const since does not mutate)
    double decimal() const;

private:
    // instance variables generally declared private
    int _num, _den; // numerator and denominator
};

// declaration for operator overloading
// the first parameter (r1) is the left operand for the * operator
// the second parameter (r2) is the right operand for the * operator
// example:
// Rational a, b, c;
// a is passed as r1 and b is passed as r2
// c = a * b;
Rational operator*(const Rational &r1, const Rational &r2);

// declare the non-member input/output operator functions
std::istream& operator>>(std::istream &is, Rational &r);
std::ostream& operator<<(std::ostream &os, const Rational &r);


// can also write inline methods after the class declaration but then must prefix
// with the inline keyword to prevent duplicate symbols during the linking phase
// of creating the excutable (that compiles each source file and links the object
// code to create a single executable)
inline double Rational::decimal() const {
    return _num / static_cast<double>(_den);
}

#endif /* Rational_hpp */
