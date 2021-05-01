//
//  Rational.h
//  Student name: Carrik McNerlin
//  Date modified: Last modification on 21 March 2021
//  Student supplied synopsis of the Rational class:
//
//  Created by L.Rhodes on 3/16/20.
//
//  Most recent change was adding overloads to the operators
//

#ifndef Rational_h
#define Rational_h
class Rational {
public:
    Rational();
    Rational(int, int);
    void setValues(int, int);// change the rational number in the object
    int getNumer();
    int getDenom();
    void print();
    void printf();
    void add(Rational); //x.add(y) means x = x + y
    void sub(Rational); // x = x - y
    void mult(Rational);// x = x * y
    void div(Rational); // x = x / y
    void reciprocal();  // x = 1 / x
    void negate(); // x = -x
    //in a later project you will overload operators--don't do it now.

    //it is time. We shall overload them!
    //Add, Subtract, Multiply, and Divide
    //Including adding other rationals and integers
    Rational operator+(Rational);
    Rational operator+(int);
    Rational operator-(Rational);
    Rational operator-(int);
    Rational operator*(Rational);
    Rational operator*(int);
    Rational operator/(Rational);
    Rational operator/(int);
    
    Rational operator-(); //This one is simple negation, not subtraction
    
    bool operator==(Rational);
    bool operator==(int);
    bool operator!=(Rational);
    bool operator!=(int);
    bool operator<(Rational);
    bool operator<(int);
    bool operator>(Rational);
    bool operator>(int);
    bool operator<=(Rational);
    bool operator<=(int);
    bool operator>=(Rational);
    bool operator>=(int);
    

private:
    int num;
    int den;
    int gcd(int, int);
    void reduce(); //local function to care for reducing to simplest terms
                   //and negative sign always in the numerator
};

#endif /* Rational_h */