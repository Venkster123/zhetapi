![alt text][logo]

# Zhetapi ℤHΠ

Zhetapi (ℤHΠ) is a C++ computation library that was built in the hopes of
making mathematical computation and algorithmic research more convenient to the
users.

This project is a work in progress.

## Usage

The Zhetapi library comes with many abilities. They are listed below:

### Evaluation of complex expressions

The library can evaluate complex expressions, which have operands of various
types, such as integers, rational numbers, complex numbers, vectors and
matrices.

The framework of library allows the evaluate to be sensetive to certain types of
operations and their corresponding operations. For example, multiplication of
two integers yields and integers, the division of two rational numbers stays
rational, and the product of an matrix with integer compenents with a rational
scalar yields a matrix with rational components.

### Customization of operands

As mentioned in above, the engine is sensetive to overloads of certain
operations. In addition, users can create their own set of operations and
corresponding overloads or add more overloads.

As of right now, however, due to the way in which the engine parses expressions,
one cannot add new symbols for operations.

### Usage and Declaration of Variables

The library provides tools which allow the user to store variables and retrieve
them in the scope of a certain setting space. Users can then refer to these
variables, and their values can be retrieved or changed.

### User Defined Functions

Users can create their own mathematical functions, which can then be used as any
other C++ functor object.

### Linear Algbebra

The library also provides way in which the user can do linear algebra. The
classes `Vector` and `Matrix` come with a variety of methods on their own, which
include performing computation as well as manipulation of their representations.

In addition to these classes, the library provides standard algorithms such Gram
Shmidt and LU Factorization (see below).

### Standard Algorithms

In addition to a collection of classes the library provides, there are also
common standard algorithms which are implemented such as gradient descent and
root finding, as well as Gram Shmidt and LU factorization, a mentioned above.

Below are the currently implemented algorithms.

| Function Name			| Description																						| Header (In `engine`)	|
| :---------------------------:	| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------: |
| `gram_shmidt`			| Performs the Gram Shmidt process on the given set of vectors.																| `algorithm.h`		|
| `gram_shmidt_normalized`	| Same as `gram_shmidt` but returns a basis of normalized vectors.															| `algorithm.h`		|
| `lagrange_interpolate`	| Performs Lagrange interpolation on the given set of poitns. Returns the appropriate polynomial.											| `algorithm.h`		|
| `lu_factorize`		| Returns the LU factorization of a matrix.																		| `algorithm.h`		|
| `solve_linear_equation`	| Solves the linear equation `Ax = b` given `A` and `b`.																| `algorithm.h`		|
| `reduced_polynomial_fitting`	| Returns a polynomial which goes through the given set of points. Differs from `lagrange_interpolate` in that it returns a simplified polynomial.					| `algorithm.h`		|
| `gradient_descent`		| Applies gradient descent to a given function on the given set of data.														| `algorithm.h`		|
| `find_root`			| Uses Newton's method to find the root of the given function.																| `algorithm.h`		|
| `solve_hlde_constant`		| Solves the homogenous linear differential equation with constant coefficients represented by the given polynomial. Returns a list of functions as a basis to the solution space.	| `calculus.h`		|
| `bernoulli_sequence_real`	| Generates the first `n` terms of the Bernoulli sequence.																| `combinatorial.h`	|
| `bernoulli_sequence_rational`	| Generates the first `n` terms of the Bernoulli sequence as rational numbers.														| `combinatorial.h`	|
| `bernoulli_number_real`	| Generates the `n`th Bernoulli number.																			| `combinatorial.h`	|
| `bernoulli_number_rational`	| Generates the `n`th Bernoulli number as a rational number.																| `combinatorial.h`	|

## Overview of Usable Classes

Below are the currently usable classes.

| Class Name	| Description			| Header (In `engine`)	|
| :--------:	| ----------------------------- | :---------------------------: |
| `Vector`	| A vector in linear algebra	| `vector.h`			|
| `Matrix`	| A matrix in linear algebra	| `matrix.h`			|
| `Polynomial`	| A polynomial in algebra	| `polynomial.h`		|


## Modules

The directory structure of the repository is presented below.

```
.
+-- cli
+-- engine
+-- makefile
+-- tests
+-- texifier
+-- web
```

The most significant of these directories is the `engine` directory. This
directory contains all the code that runs the classes and features of the
library. 

## Most Recent Stable Commit

https://github.com/vedavamadathil/zhetapi/tree/2d9112b98cf730239396f125b4f1f0680d5021c0

[logo]: https://github.com/vedavamadathil/zhetapi/blob/master/zhetapi-logo.png
