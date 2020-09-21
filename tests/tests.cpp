// C/C++ headers
#include <ctime>
#include <cmath>
#include <iostream>

#include <dlfcn.h>

// Engine headers
#include <function.hpp>

#define TEST1

using namespace std;


#if defined(TEST1)

	const size_t rounds = 10000;

	time_t startt;
	time_t endt;

	zhetapi::Barn <double, int> barn;

	zhetapi::token *__fx_general(double x)
	{
		zhetapi::token *i1 = new zhetapi::operand <double> (x);

		zhetapi::token *c1 = new zhetapi::operand <double> (54);

		zhetapi::token *int1 = barn.compute("*", {i1, c1});
		zhetapi::token *int2 = barn.compute("ln", {i1});

		return barn.compute("+", {int1, int2});
	}

	inline zhetapi::token *__fx_general_inline(double x)
	{
		// Variables
		zhetapi::token *i1 = new zhetapi::operand <double> (x);

		// Constants
		zhetapi::token *c1 = new zhetapi::operand <double> (54);

		return barn.compute("+", {barn.compute("*", {i1, c1}), barn.compute("ln", {i1})});
	}

	double __fx_in_R_out_R(double x)
	{
		return 54.0 * x + log(x);
	}

	inline double __fx_in_R_out_R_inline(double x)
	{
		return 54.0 * x + log(x);
	}

#endif

int main()
{

#if defined(TEST1)

	zhetapi::Function <double, int> fx = "f(x) = x * 54 + ln(x)";

	/////////////////////////////////////////////////////////////
	cout << "Running with zhetapi::Function:" << endl;

	startt = clock();

	for (size_t i = 0; i < rounds; i++)
		fx(10);

	endt = clock();

	cout << "\tTime: " << (endt - startt)/((double) CLOCKS_PER_SEC) << " seconds" << endl;

	/////////////////////////////////////////////////////////////
	cout << "Running with general function:" << endl;

	startt = clock();

	for (size_t i = 0; i < rounds; i++)
		__fx_general(10);

	endt = clock();

	cout << "\tTime: " << (endt - startt)/((double) CLOCKS_PER_SEC) << " seconds" << endl;

	/////////////////////////////////////////////////////////////
	cout << "Running with inlined general function:" << endl;

	startt = clock();

	for (size_t i = 0; i < rounds; i++)
		__fx_general_inline(10);

	endt = clock();

	cout << "\tTime: " << (endt - startt)/((double) CLOCKS_PER_SEC) << " seconds" << endl;

	/////////////////////////////////////////////////////////////
	cout << "Running with specific function:" << endl;

	startt = clock();

	for (size_t i = 0; i < rounds; i++)
		__fx_in_R_out_R(10);

	endt = clock();

	cout << "\tTime: " << (endt - startt)/((double) CLOCKS_PER_SEC) << " seconds" << endl;

	/////////////////////////////////////////////////////////////
	cout << "Running with inlined specific function:" << endl;

	startt = clock();

	for (size_t i = 0; i < rounds; i++)
		__fx_in_R_out_R_inline(10);

	endt = clock();

	cout << "\tTime: " << (endt - startt)/((double) CLOCKS_PER_SEC) << " seconds" << endl;

#elif defined(TEST2)

	const char file[] = "tests/fctn.so";

	cout << 24 << endl;

	system("g++ tests/fctn.cpp -o tests/fctn.so -shared -fPIC");

	void *handle = dlopen(file, RTLD_NOW);

	typedef double (*fctn)(double);

	fctn f = (fctn) dlsym(handle, "F");

	void *ptr = dlsym(handle, "F");

	cout << "ptr: " << ptr << endl;

	cout << "f: " << f << endl;

	const char *dlsym_error = dlerror();
	
	if (dlsym_error) {
		cerr << "Cannot load symbol 'F': " << dlsym_error << '\n';
		
		dlclose(handle);
		
		return 1;
	}

	cout << (*f)(24) << endl;

	dlclose(handle);

#endif

}
