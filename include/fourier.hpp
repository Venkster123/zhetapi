#ifndef FOURIER_H_
#define FOURIER_H_

// Engine headers
#include "vector.hpp"

namespace zhetapi {

template <class T>
class FourierSeries {
	Vector <T>	_a;	// Cosine coefficients
	Vector <T>	_b;	// Sine coefficients

	size_t		_asize;
	size_t		_bsize;
public:
	FourierSeries(const Vector <T> &);
	FourierSeries(const Vector <T> &, const Vector <T> &);

	T evaluate(const T &) const;
	T operator()(const T &) const;
};

// TODO: Fix indices
//
// a0, a1, b1, a2, b2, ...
template <class T>
FourierSeries <T> ::FourierSeries(const Vector <T> &coeffs)
{
	// Remove vector middle operation
	std::vector <T> a;
	std::vector <T> b;

	size_t n = coeffs.size();

	size_t i = 0;

	a.push_back(coeffs[i++]);	
	while(i < n) {
		a.push_back(coeffs[i]);
		b.push_back(coeffs[i + 1]);

		i += 2;
	}

	_asize = a.size();
	_bsize = b.size();

	_a = Vector <T> (a);
	_b = Vector <T> (b);
}

template <class T>
FourierSeries <T> ::FourierSeries(const Vector <T> &a, const Vector <T> &b)
		: _a(a), _b(b), _asize(a.size()), _bsize(b.size()) {}

template <class T>
T FourierSeries <T> ::evaluate(const T &x) const
{
	// Make more efficient construction kernels for vectors
	// (maybe dont even create a vector: a custom kernel
	// for modified inner products)
	Vector <T> k_cos(_asize,
		[&](size_t i) {
			if (i == 0)
				return T(0.5);
			
			return std::cos(i * x);
		}
	);

	Vector <T> k_sin(_bsize,
		[&](size_t i) {
			return std::cos((i + 1) * x);
		}
	);

	return inner(_a, k_cos) + inner(_b, k_sin);
}

template <class T>
T FourierSeries <T> ::operator()(const T &x) const
{
	return evaluate(x);
}

}

#endif
