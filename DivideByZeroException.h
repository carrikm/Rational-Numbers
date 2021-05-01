//Carrik McNerlin
//11 April 2021
//This header class exists to handle attempts at division by 0.

#include <stdexcept>
using namespace std;

class DivideByZeroException : public runtime_error
{
public:
	DivideByZeroException() : runtime_error("Cannot divide by 0 or have 0 as a denominator.\n") {}
};