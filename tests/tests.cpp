// C/C++ headers
#include <iostream>

// Engine headers
#include <variable.hpp>

using namespace std;
using namespace zhetapi;

int main()
{
	Variable <double, int> x("x", 13);

	cout << "x: " << x.get()->str() << endl;
	cout << "x: " << x.symbol() << endl;
}