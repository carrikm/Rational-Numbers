// Carrik McNerlin
// 9 March 2021
// Updated 18 March 2021
// Thank you for not making me write the Rational header file!!!
//
// Update includes adding break statements in switch control (something I definitely should have caught) and simplifying the loop control check
//

#include <iostream>
#include "Rational.h"
#include "DivideByZeroException.h"

using namespace std;

int main() {
	int num1, denom1, num2, denom2; //numerators and denominators
	Rational temp, first, second; //This is how we play with our numbers without destroying the original copies


	bool repeat = true;
	bool goodInput = true;
	while (repeat) {
		//repeat entering of numbers until valid input is received
		do{
			goodInput = true;
			//try entering first number
			try {
				cout << "Please enter the first numerator:";
				cin >> num1;

				cout << "Please enter the first denominator:";
				cin >> denom1;

				first.setValues(num1, denom1);
				cout << "First number: ";
				first.print();
			}
			catch (DivideByZeroException e) {
				goodInput = false;
				cout << "\nSomething went wrong.\n" << endl;
				cout << e.what();
			}
		} while (!goodInput);

		//repeat input request until valid input is received
		do {
			goodInput = true;
			//try entering the second number
			try {
				cout << "Enter another numerator:";
				cin >> num2;

				cout << "Enter the second denominator:";
				cin >> denom2;

				second.setValues(num2, denom2);
				cout << "Second number: ";
				second.print();
			}
			catch (exception e) {
				goodInput = false;
				cout << "Something went wrong." << endl;
				cout << e.what();
			}
		} while (!goodInput);



		//print
		cout << "These are the numbers." << endl;
		cout << "First number: ";
		first.print();
		cout << "Second number: ";
		second.print();
		cout << endl;

		//printf
		cout << "Here are the numbers in decimal form." << endl;
		cout << "First number:";
		first.printf();
		cout << "Second number:";
		second.printf();
		cout << endl;
		
		//+
		first.print();
		cout << " + ";
		second.print();
		cout << " = ";
		temp = first; //our copy for manipulation
		temp.add(second);
		temp.print(); //replaced with the value after operation
		cout << endl;


		//-
		first.print();
		cout << " - ";
		second.print();
		cout << " = ";
		temp = first;
		temp.sub(second);
		temp.print();
		cout << endl;
		

		//*
		first.print();
		cout << " * ";
		second.print();
		cout << " = ";
		temp = first;
		temp.mult(second);
		temp.print();
		cout << endl;


		//div
		first.print();
		cout << " / ";
		second.print();
		cout << " = ";
		try{
			temp = first;
			temp.div(second);
		}
		catch (DivideByZeroException e) {
			cout << "Cannot divide these numbers." << endl;
			cout << e.what();
		}
		temp.print();
		cout << endl;



		//relational fanciness
		if (first.operator==(second)) {
			first.print();
			cout << " is equal to ";
			second.print();
			cout << endl;
		}
		

		if (first.operator!=(second)) {
			first.print();
			cout << " is not equal to ";
			second.print();
			cout << endl;
		}
		
		
		if (first.operator<(second)) {
			first.print();
			cout << " is less than ";
			second.print();
			cout << endl;
		}
		
		if (first.operator>(second)) {
			first.print();
			cout << " is greater than ";
			second.print();
			cout << endl;
		}
	
		if (first.operator<=(second)) {
			first.print();
			cout << " is less than or equal to ";
			second.print();
			cout << endl;
		}
		
		if (first.operator>=(second)) {
			first.print();
			cout << " is greater than or equal to ";
			second.print();
			cout << endl;
		}



		string temp;
		cout << "Would you like to do this again? (yes or no)";
		cin >> temp;

		//check whether answer is yes or no
		repeat = temp[0] == 'y';
	}//end while
}