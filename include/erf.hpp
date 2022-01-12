#ifndef ERF_H_
#define ERF_H_

#ifndef __AVR	// Does not support AVR

// C/C++ headers
#include <memory>

#endif		// Does not support AVR

// Engine headers
#ifdef ZHP_CUDA

#include "cuda/vector.cuh"

#else

#include "vector.hpp"

#endif

#include "cuda/essentials.cuh"

namespace zhetapi {

namespace ml {

template <class T>
class Erf {
public:
	// TODO: Replace with a string
	enum erf_type {
		OPT_Default,
		OPT_SE,
		OPT_MSE,
	};

	// TODO: Add a vector <double> constructor for JSON
	__cuda_dual__
	Erf();

	__cuda_dual__
	Vector <T> compute(const Vector <T> &, const Vector <T> &) const;

	__cuda_dual__
	virtual Vector <T> operator()(const Vector <T> &, const Vector <T> &) const;

	__cuda_dual__
	virtual Erf *derivative() const;

	__cuda_dual__
	int get_erf_type() const;

	template <class U>
	__cuda_dual__
	friend Erf <U> *copy(Erf <U> *);

	// Exceptions
	class dimension_mismatch {};
protected:
	static void assert_size(const Vector <T> &, const Vector <T> &);

	erf_type kind;
};

template <class T>
void Erf <T> ::assert_size(const Vector <T> &a, const Vector <T> &b)
{
	if (a.size() != b.size())
		throw dimension_mismatch();
}

#ifndef ZHP_CUDA

template <class T>
Erf <T> ::Erf() : kind(OPT_Default) {}

// TODO: Reverse compute and operator()
template <class T>
Vector <T> Erf <T> ::operator()(const Vector <T> &comp, const Vector <T> &in) const
{
	return {(comp - in).norm()};
}

template <class T>
Vector <T> Erf <T> ::compute(const Vector <T> &comp, const Vector <T> &in) const
{
	return (*this)(comp, in);
}

template <class T>
Erf <T> *Erf <T> ::derivative() const
{
	return new Erf();
}

template <class T>
int Erf <T> ::get_erf_type() const
{
	return kind;
}

#endif

}

}

#endif
