/*
Carrik McNerlin
9 March 2021
Updated 21 March 2021
This file is a collection of functions for the Rational number class.

Update includes removing the check before trying to reduce in setValues and simplifying the add function. 3/18/21

Overloaded operations 3/21/21
*/

#include "Rational.h"
#include "DivideByZeroException.h"
#include <iostream>
using namespace std;

//DECLARATIONS
Rational::Rational(){
	num = 0;
	den = 1; //0 goofs it all up
}

Rational::Rational(int n, int d) {
	//just checking for valid input

	if (d == 0) {
		throw DivideByZeroException();
		return;
	}
	
	num = n;
	den = d;
	reduce();
}

void Rational::setValues(int n, int d) {
	if (d == 0) {
		throw DivideByZeroException();
		return;
	}

	num = n;
	den = d;
	reduce();
	
}



//PRINT FUNCTIONS
void Rational::print() {
	cout << num << '/' << den;
}
void Rational::printf() {

	cout << float(num) / float(den);
}



//return numerator and denominator for the manipulation functions
int Rational::getNumer(){
	return num;
}
int Rational::getDenom(){
	return den;
}



//MANIPULATIONS
// All manipulations will use a temporary copy of the second rational number.
// This is to protect the original copies of these numbers.


//We're getting a little funky here. just making the second number negative and using the addition function
void Rational::sub(Rational fraction2) {
	Rational temp = fraction2;

	temp.negate();
	add(temp);
	
	//reduce if possible
	reduce();
}

void Rational::mult(Rational fraction2) {
	Rational temp = fraction2;

	num = num * temp.getNumer();
	den = den * temp.getDenom();

	//reduce if we can
	reduce();
}

//This one gets funky like the brass monkey, too. Flip second number and multiply.
void Rational::div(Rational fraction2) {
	Rational temp = fraction2;

	temp.reciprocal();

	mult(temp); //also calls reduce in mult()
}

void Rational::add(Rational fraction2) {
	num = num * fraction2.den + den * fraction2.num;
	den = den * fraction2.den;
	reduce();
}



//Some useful functions for the above manipulations
void Rational::negate(){
	num = -num; //only negate the numerator
}
void Rational::reciprocal() {
	//can't flip to a denominator of 0
	if (num == 0) {
		cout << "Invalid input. Denominator can't be 0." << endl;
		return;	
	}
	
	//hold value to swap the variables
	int temp = den;
	den = num;
	num = temp;
}

void Rational::reduce() {
	if (den == 0) {
		throw DivideByZeroException();
		return;
	}

	int greatest = gcd(num, den);

	num = num / greatest;
	den = den / greatest;

	
	if (den < 0) {
		//can't have a negative denominator, but we CAN have a negative numerator
		num = -num;
		den = -den;
	}
}

//recursively reduce until we find greatest common denominator
int Rational::gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}



//Overloaded operations
//We're just implementing the code from above
Rational Rational::operator+(Rational y) {
	Rational z = *this;
	z.add(y);
	return z;
}

Rational Rational::operator+(int y) {
	Rational z = *this;
	Rational w(y, 1); //w is a placeholder that holds the fraction y/1
	z.add(w);
	return z;
}

Rational Rational::operator-(Rational y) {
	Rational z = *this;
	z.sub(y);
	return z;
}

Rational Rational::operator-(int y) {
	Rational z = *this;
	Rational w(y, 1); //w is a placeholder that holds the fraction y/1
	z.sub(w);
	return z;
}

Rational Rational::operator*(Rational y) {
	Rational z = *this;
	z.mult(y);
	return z;
}

Rational Rational::operator*(int y) {
	Rational z = *this;
	Rational w(y, 1); //w is a placeholder that holds the fraction y/1
	z.mult(w);
	return z;
}

Rational Rational::operator/(Rational y) {
	Rational z =  *this;
	z.div(y);
	return z;
}

Rational Rational::operator/(int y) {
	Rational z = *this;
	Rational w(y, 1); //w is a placeholder that holds the fraction y/1
	z.div(w);
	return z;
}

Rational Rational::operator-() {
	Rational z = *this;
	z.negate();
	return z;
}


//RELATIONAL OPS
bool Rational::operator==(Rational y) {
	//a/b == c/d
	// a*d == b*c
	return ((num * y.den) == (den * y.num));
}

bool Rational::operator==(int y) {
	//a/b == c/d
	// a*d == b*c
	Rational w(y, 1);
	return ((num * w.den) == (den * w.num));
}


bool Rational::operator!=(Rational y) {
	Rational x = *this;
	return !(x.operator==(y));
}

bool Rational::operator!=(int y) {
	Rational x = *this;
	Rational w(y, 1);
	return !(x.operator==(w));
}


bool Rational::operator<(Rational y) {
	//a/b < c/d
	// equivalent to
	// a*d < b*c
	return num * y.den < den* y.num;
}

bool Rational::operator<(int y) {
	Rational w(y, 1);
	return num * w.den < den* w.num;
}


bool Rational::operator>(Rational y) {
	//a/b > c/d
	// a*d > b*c
	return num * y.den > den * y.num;
}

bool Rational::operator>(int y) {
	Rational w(y, 1);
	return num * w.den > den* w.num;
}


//complement of <
bool Rational::operator>=(Rational y) {
	Rational x = *this;
	return !(x.operator<(y));
}

bool Rational::operator>=(int y) {
	Rational x = *this;
	Rational w(y, 1);
	return !(x.operator<(w));
}


//complement of >
bool Rational::operator<=(Rational y) {
	Rational x = *this;
	return !(x.operator>(y));
}

bool Rational::operator<=(int y){
	Rational x = *this;
	Rational w(y, 1);
	return !(x.operator>(w));
}