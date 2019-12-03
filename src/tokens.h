#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace tokens {
	/* Default data/info type to
	 * use for calculations */
	typedef double def_t;

	/* Token Class:
	 *
	 * Acts as a dummy class for
	 * use of generic pointer in
	 * other modules */
	class token {
	public:
		/* Enumerations:
		 * [type] - new data type to allow function
		 * caller inspection */
		enum type {NONE, OPERAND, OPERATION,
			VARIABLE, FUNCTION, MODULE};

		/* Virtuals:
		 * [type] [caller]() - insepctor function passed
		 * on to all derived classes */
		virtual type caller() = 0;
	};
	
	/* Exception Class:
	 *
	 * Represents the generic error that
	 * is thrown whenever an error occurs
	 * when trying to compute with the
	 * operands */
	class exception {
	protected:
		/* std::string [msg] - what the
		 * error is about */
		std::string msg;
	public:
		/* Constructors:
		 * exception() - default constructor
		 *   that sets the private member [msg]
		 *   to an empty string
		 * exception(std::string) - sets the
		 *   private member variable [msg] to
		 *   whatever string is passed */
		exception();
		exception(std::string);

		/* Virtualized Member Functions:
		 * void [set](std::string) - sets the
		 *   private member variable [msg] to
		 *   whatever string is passed
		 * std::string [what]() - returns a constant
		 *   (unchangable) reference to the contents
		 *   of the private member varaible [msg] */
		virtual void set(std::string);
		
		virtual const std::string &what();
	};

	/* Exception Class Member Functions
	 *
	 * See class declaration for a
	 * description of each function
	 *
	 * Constructors: */
	template <class oper_t>
	operation <oper_t> ::exception::exception() : msg("") {}

	template <class oper_t>
	operation <oper_t> ::exception::exception(std::string str) : msg(str) {}

	/* Virtualized member functions:
	 * setter and getters */
	template <class oper_t>
	void operation <oper_t> ::exception::set(std::string str) {msg = str;}

	template <class oper_t>
	std::string operation <oper_t> ::exception::what() {return msg;}

	/* Operand Class:
	 * 
	 * Represents an operand in mathematics
	 * by using data_t as the numerical data
	 * type or value */
	template <typename data_t>
	class operand : public token {
		/* data_t [val] - the only member of operand
		 * which represents its value */
		data_t val;
	public:
		/* Constructors:
		 * operand() - sets the private member variable
		 *   [val] to the default value of data_t
		 * operand(data_t) - sets the private member variable
		 *   [val] to whatever value is passed */
		operand();
		operand(data_t);
		operand(const operand &);

		/* Virtualized Member Functions:
		 * void [set](data_t) - sets the private member variable
		 *   to whatever value is passed
		 * void operator[](data_t) - sets the private member
		 *   variable to whatever value is passed
		 * data_t &[get]() - returns a reference to the private
		 *   member variable
		 * const data_t &[get]() - returns a constant (unchangable)
		 *   reference to the prviate member variable
		 * data_t &operator*() - returns a reference to the private
		 *   member variable
		 * const data_t &operator*() - returns a constant (unchangable)
		 *   reference to the private member variable */
		virtual void set(data_t);
		virtual void operator[](data_t);
		
		virtual data_t &get();
		virtual const data_t &get() const;

		virtual data_t &operator*();
		virtual const data_t &operator*() const;

		virtual operand &operator=(const operand &);

		/* Friends:
		 * std::ostream &operator<<(std::ostream &, const operand
		 *   <data_t> &) - outputs the value of val onto the stream
		 *   pointed to by the passed ostream object
		 * std::istream &operator>>(std::istream &, operand &) - reads
		 *   input from the stream passed in and sets the value
		 *   of the val in the passed operand object to the read data_t
		 *   value */
		template <typename type>
		friend std::ostream &operator<<(std::ostream &os, const
		        operand <data_t> &);

		template <typename type>
		friend std::istream &operator>>(std::istream &is, operand
		        <data_t> &);

		/* Comparison Operators: */
		template <typename type>
		friend bool &operator==(const operand &, const operand &);
		
		template <typename type>
		friend bool &operator!=(const operand &, const operand &);
		
		template <typename type>
		friend bool &operator>(const operand &, const operand &);
		
		template <typename type>
		friend bool &operator<(const operand &, const operand &);
		
		template <typename type>
		friend bool &operator=>(const operand &, const operand &);
		
		template <typename type>
		friend bool &operator=<(const operand &, const operand &);
	};

	/* Default operand specification
	 * using the default data/info type */
	typedef operand <def_t> num_t;

	/* Operand Class Member Functions
	 * 
	 * See class declaration to see a
	 * description of each function
	 *
	 * Constructors: */
	template <typename data_t>
	operand <data_t> ::operand () : val(data_t()) {}

	template <typename data_t>
	operand <data_t> ::operand(data_t nval) {val = nval;}
	
	template <typename data_t>
	operand <data_t> ::operand(const operand &other) {val = other.val;}
	
	/* Virtualized member functions:
	 * setters, getter and operators */
	template <typename data_t>
	void operand <data_t> ::set(data_t nval) {val = nval;}

	template <typename data_t>
	void operand <data_t> ::operator[](data_t nval) {val = nval;}

	template <typename data_t>
	data_t &operand <data_t> ::get() {return val;}

	template <typename data_t>
	const data_t &operand <data_t> ::get() const {return val;}

	template <typename data_t>
	data_t &operand <data_t> ::operator*() {return val;}

	template <typename data_t>
	const data_t &operand <data_t> ::operator*() const {return val;}
	
	template <typename data_t>
	const data_t &operand <data_t> ::operator=(const operand &other) const
	{
		val = other.val;
		return *this;
	}

	/* Friend functions: istream and ostream utilities */
	template <typename data_t>
	std::ostream &operator<< (std::ostream &os, const operand <data_t>
	        &right)
	{
		os << right.get();
		return os;
	}

	template <typename data_t>
	std::istream &operator>> (std::istream &is, operand <data_t> &right)
	{
		data_t temp;
		is >> temp;
		right.set(temp);
		return is;
	}

	/* Cmoparison functions: */
	template <typename data_t>

	/* Token class derived functions: */
	template <typename data_t>
	token::type operand <data_t> ::caller() {return OPERAND;}

	/* Operation Class:
	 *
	 * Represents an operation in mathematics
	 * that bases computations on the oper_t
	 * operand class, which can check whether
	 * the operand class supports the computations
	 * and makes sure that the class passed in
	 * is an operand class or its derived class */
	template <class oper_t>
	class operation : public token {
	public:
		/* Argset_Exception Class:
		 *
		 * An error class derived from
		 * operation::exception that represents
		 * an error resulting from receiving an
		 * inappropriate number of operands
		 * in the compute method */
		class argset_exception : public exception {
		public:
			/* Constructors:
			 * argset_exception() - default constuctor
			 *   that sets the private member variable
			 *   [msg] to an empty string 
			 * argset_exception(std::string) - constructor
			 *   that sets the private member variabele [msg]
			 *   to whatever string is passed 
			 * argset_exception(std::string, int,
			 *   int) - constructor that creates a message
			 *   using the name of the operation, number of
			 *   operands required and the number of operands
			 *   received
			 * argset_exception(int, const operation
			 *   <oper_t> &) - constructor that creates
			 *   the message using the number of operands
			 *   (passed) and the operation it is called
			 *   from (passed) */
			argset_exception();
			argset_exception(std::string);
			argset_exception(std::string, int, int);
			argset_exception(int, const operation <oper_t> &);

			/* Virtualized Member Functions:
			 * void [set](std::string, int, int) - setter
			 *   method that does the same thing as
			 *   the corresponding constructor
			 * void [set](int, const operation <oper_t> &) - setter
			 *   method that does the same thing as
			 *   the corresponding constructor */
			virtual void set(std::string, int, int);
			virtual void set(int, const operation <oper_t> &);
		};

		/* Computation_Exception Class:
		 *
		 * Represents an error derived from trying
		 * to compute something using the operand
		 * class */
		class computation_exception : public exception {};
		
		/* Typedef oper_t (*[function])(const std::vector
		 * <oper_t> &) - a type alias for conveneince for
		 * the type of function used for computation */
		typedef oper_t (*function)(const std::vector <oper_t> &);

		/* Constructors:
		 * operation() - sets the private member function
		 *   [func] to a null pointer, [opers] to -1,
		 *   [symbols] and [name] to null pointer as well
		 * operation(std::string, function, int, const
		 *   std::vector> &) - sets the private member variables
		 *   to the corresponding parameters passed */
		operation();
		operation(std::string, function, int, const std::vector
		        <std::string> &);

		/* Virtualized Member Functions:
		 * void [set](std::string, function, int, const std::vector
		 *   <std::string> &) - sets the private member variables to
		 *   the corresponding parameters passed
		 * void [function][get] const - returns a pointer to the
		 *   computer function used by the object
		 * void [function]operator*() const - returns a poinbter to
		 *   the computer function used by the object
		 * void oper_t [compute](const std::vector <oper_t> &) - returns
		 *   the result of the operation given a list of operands, and
		 *   throws [argset_exception] if there are not exactly [opers]
		 *   operands
		 * void oper_t operator()(const std::vector <oper_t> &) - does
		 *   the same thing as compute but is supported by the function
		 *   operator */
		virtual void set(std::string, function, int, const
			std::vector <std::string> &);

		virtual function get() const;
		virtual function operator*() const;

		virtual oper_t compute(const std::vector <oper_t> &) const
			noexcept(false);
		virtual oper_t operator()(const std::vector <oper_t> &) const
			noexcept(false);
		
		/* Friend Functions:
		 * std::ostream &operator<<(std::ostream &, const operation
		 *   <oper_t> &) - outputs information about the passed
		 *   operation
		 *   object into the stream pointed to by the passed ostream */
		template <class oper_t>
		friend std::ostream &operator<<(std::ostream &, const operation
		        <oper_t> &);
	private:
		/* [functio][func] - the function used by the operation */
		function func;

		/* std::string [name] - the name of the operation */
		std::string name;

		/* std::size_t [opers] - the number of operands expected
		 * by the operation's function */
		std::size_t opers;

		/* std::vector <std::string> [symbols] - the list of
		 * symbols of the operation that are used in parsing */
		std::vector <std::string> symbols;
	};

	/* Default operation specification using
	 * the default operand type/class */
	typedef operation <num_t> opn_t;

	/* Operation Class Member Functions
	 *
	 * See declaration to see a
	 * description of each function
	 *
	 * Constructors: */
	template <class oper_t>
	operation <oper_t> ::operation() {func = nullptr;}

	template <class oper_t>
	operation <oper_t> ::operation(std::string str, function nfunc,
		int nopers, const std::vector <std::string> &nsymbols)
	{
		name = str;
		func = nfunc;
		opers = nopers;
		symbols = nsymbols;
	}

	template <class oper_t>
	void operation <oper_t> ::set(std::string str, function nfunc,
		int nopers, const std::vector <std::string> &nsymbols)
	{
		name = str;
		func = nfunc;
		opers = nopers;
		symbols = nsymbols;
	}

	/* Virtualized Member Functions: */
	template <class oper_t>
	typename operation <oper_t>::function operation <oper_t> ::get()
		const {return func;}

	template <class oper_t>
	typename operation <oper_t>::function operation <oper_t> ::operator*()
		const {return func;}

	template <class oper_t>
	oper_t operation <oper_t> ::compute(const std::vector <oper_t> &inputs)
		const noexcept(false)
	{
		if (inputs.size() != opers)
			throw argset_exception(inputs.size(), *this);
		return (*func)(inputs);
	}

	template <class oper_t>
	oper_t operation <oper_t> ::operator()(const std::vector <oper_t> &inputs)
		const noexcept(false)
	{
		if (inputs.size() != opers)
			throw argset_exception(inputs.size(), *this);
		return (*func)(inputs);
	}

	/* Friend Functions: ostream utilities */
	template <class oper_t>
	std::ostream &operator<<(std::ostream &os, const operation <oper_t>
	        &opn)
	{
		os << opn.name << " - " << opn.opers << " operands, ";
		os << opn.symbols;
		return os;
	}

	/* Token class derived functions: */
	template <class oper_t>
	token::type operation <oper_t> ::caller() {return OPERATION;}

	/* Argset Exception Class Member Functions
	 *
	 * See class declaration for a description
	 * of each member function
	 *
	 * Constructors */
	template <class oper_t>
	operation <oper_t> ::argset_exception::argset_exception()
		: operation <oper_t> ::exception() {}

	template <class oper_t>
	operation <oper_t> ::argset_exception::argset_exception(int actual, const operation <oper_t> &obj)
	{
		using std::to_string;
		exception::msg = obj.name + ": Expected " + to_string(obj.opers);
		exception::msg += " operands, received " + to_string(actual) + " instead.";
	}

	template <class oper_t>
	operation <oper_t> ::argset_exception::argset_exception(std::string str)
		: operation <oper_t> ::exception(str) {}

	template <class oper_t>
	operation <oper_t> ::argset_exception::argset_exception(std::string str, int expected, int actual)
	{
		using std::to_string;
		exception::msg = str + ": Expected " + to_string(expected);
		exception::msg += " operands, received " + to_string(actual) + "instead.";
	}

	/* Virtualized member functions:
	 * setters only - getters are inherited */
	template <class oper_t>
	void operation <oper_t> ::argset_exception::set(int actual, const operation <oper_t> &obj)
	{
		using std::to_string;
		exception::msg = obj.name + ": Expected " + to_string(obj.opers);
		exception::msg += " operands, received " + to_string(actual) + " instead.";
	}

	template <class oper_t>
	void operation <oper_t> ::argset_exception::set(std::string str) {exception::msg = str;}

	template <class oper_t>
	void operation <oper_t> ::argset_exception::set(std::string str, int expected, int actual)
	{
		using std::to_string;
		exception::msg = str + ": Expected " + to_string(expected);
		exception::msg += " operands, received " + to_string(actual) + "instead.";
	}

	/* Variable Class:
	 *
	 * Represents a variable in mathematics
	 * which can be used as a dummy variable
	 * for custom functions and has the safe
	 * ability to read and write the value
	 * is stores */
	template <typename data_t>
	class variable : public token {
		/* std::string [name] - the name of the
		 * variable that will be taken into account
		 * when creating custom functions and using
		 * them later on */
		std::string name;

		/* data_t [val] - the value stored by the
		 * object which serves the same purpose as
		 * the val member in the operand class */
		data_t val;

		/* bool [param] - a boolean variable that
		 * represents whether or not the current
		 * variable object is being used a parameter
		 * (dummy) or to hold information */
		bool param;
	public:
		class bypass_attempt_exception : exception {};

		/* Constructors:
		 * variable() - creates a new variable object
		 *   that is by default a dummy parameter
		 * variable(std::string, boolean, data_t) - creates
		 *   a new variable object with corresponding
		 *   members with respect to the passed parameters,
		 *   private member variable [val] is defaulted
		 *   to the defalt value of data_t */
		variable();
		variable(std::string str, bool par, data_t data = data_t());

		/* Virtualized Member Functions:
		 * void [set](bool) - changes whether or not the
		 *   current variable object acts as a dummy
		 *   or as a value
		 * void [set](data_t) - sets the private member
		 *   variable [val] to the value that is passed
		 * void [set](std::string) - sets the private
		 *   member variable [name] to the string
		 *   that is passed
		 * void [set](data_t, std::string) - sets
		 *   the name, [name], and value, [val], of
		 *   the current variable object
		 * void operator[](bool) - does the same thing
		 *   as void [set](bool)
		 * void operator[](data_t) - does the same thing
		 *   as void [set](data_t)
		 * void operator[](std::string) - does the same
		 *   thing as void [set](std::string)
		 * void operator[](data_t, std::string) - does the
		 *   same thing as void [set](data_t, std::string)
		 * data_t &[get]() - returns a reference to the
		 *   value of the object or throws a bypass attempt
		 *   exception
		 * const data_t &[get]() const - returns a constant
		 *   (unchangable) reference to the value of the
		 *   object or throws a bypass attempt exception
		 * const std::string &[get]() const - returns the name
		 *   of the current variable object
		 * const std::pair <data_t, std::string> &[get]()
		 *   const - returns a tuple of the value and name of
		 *   the current variable object, or throws a bypass
		 *   attempt exception if the object is a dummy
		 * data_t &operator() - does the same thing as
		 *   data_t &[get]()
		 * const data_t &operator() const- does the same
		 *   thing as const data_t &[get](); 
		 * const std::string &operator() const - does the
		 *   same thing as const std::string &[get]()
		 * const std::pair <data_t, std::string> &operator()
		 *   const - does the same thing as const std::pair
		 *   <data_t, std::string> &[get]() const */
		virtual void set(bool);
		virtual void set(data_t);
		virtual void set(std::string);
		virtual void set(data_t, std::string);
		
		virtual void operator[](bool);
		virtual void operator[](data_t);
		virtual void operator[](std::string);
		virtual void operator[](data_t, std::string);

		virtual data_t &get() noexcept(false);
		virtual const data_t &get() const noexcept(false);
		virtual const std::string &get() const noexcept(false);
		virtual const std::pair <data_t, std::string>
			&get() const noexcept(false);

		virtual data_t &operator*() noexcept(false);
		virtual const data_t &operator*() const noexcept(false);
		virtual const std::string &operator*() const noexcept(false);
		virtual const std::pair <data_t, std::string>
			&operator*() const noexcept(false);
		
		/* Friends:
		 * std::ostream &operator<<(std::ostream &, const variable
		 *   <data_t> &) - outputs the name of the passed variable
		 *   object, its value, and whether or not it is a dummy
		 * std::istream &operator>>(std::istream &, variale &) - reads
		 *   information from the passed istream object, and modifies
		 *   the passed variable object appropriately */
		template <typename type>
		friend std::ostream &operator<<(std::ostream &os, const
		        variable <data_t> &);

		template <typename type>
		friend std::istream &operator>>(std::istream &is, variable
		        <data_t> &);
	};

	/* Default variable specification using
	 * the default numerical type/info structure */
	typedef variable <def_t> var_t;

	/* Variable Class Member Functions
	 *
	 * See class declaration for a
	 * description of each function
	 *
	 * Constructors: */
	template <typename data_t>
	variable <data_t> ::variable() : val(data_t()), name("x"),
		param(false) {}

	template <typename data_t>
	variable <data_t> ::variable(std::string str, bool bl, data_t vl)
		: val(vl), name(str), param(bl) {}

	/* Virtualized member functions:
	 * setters, getters and operators */
	template <typename data_t>
	void variable <data_t> ::set(bool bl) {param = bl;}

	template <typename data_t>
	void variable <data_t> ::set(data_t vl) {val = vl;}
	
	template <typename data_t>
	void variable <data_t> ::set(bool bl) {param = bl;}

	template <typename data_t>
	void variable <data_t> ::set(bool bl) {param = bl;}

	// Beginning of the function class
	template <class oper_t>
	class function : public operation {
	public:
		typedef oper_t (*function)(const std::vector <varible> &);

		function();
		function(std::string, function, opers);

		/* Use these functions to
		* save space in the function
		* stack class - instead
		* of creating new objects
		* and using space, modify
		* old ones (if the program
		* is sure they wont be used
		* again)
		*/
		void set(std::string);
		void set(function, opers);
		void set(std::string, function, opers);

		function get() const;
		function operator~() const;
	private:
		function func;
		std::string name;
		std::size_t opers;
	};

	typedef function <num_t> func_t;	

	// Beginning of the module class
	template <class oper_t>
	class module : public operation {
	private:
		/* The following are the initializations
		 * of the lambda member functions */
		operation <oper_t> add_op = operation <oper_t>
		("add_op",[](const std::vector <oper_t> &inputs) {
			return oper_t(inputs[0].get() + inputs[1].get());
		}, 2, {"+", "plus", "add"});

		operation <oper_t> sub_op = operation <oper_t>
		("sub_op", [](const std::vector <oper_t> &inputs) {
			return oper_t(inputs[0].get() - inputs[1].get());
		}, 2, {"-", "minus", "subtract"});

		operation <oper_t> mult_op = operation <oper_t>
		("mult_op", [](const std::vector <oper_t> &inputs) {
			return oper_t(inputs[0].get() * inputs[1].get());
		}, 2, {"*", "mult", "times"});
		
		operation <oper_t> div_op = operation <oper_t>
		("div_op", [](const std::vector <oper_t> &inputs) {
			return oper_t(inputs[0].get() / inputs[1].get());
		}, 2, {"/", "divided by"});
	public:
		/* The following are static member functions that
		 * give purpose to the tokens
		 *
		 * const token &get_next( std::string, std::size_t):
		 *   returns the next valid token in the passed
		 *   string from the specified index, or throws an
		 *   error if no token was detected
		 */
		static const token &get_next(std::string, std::size_t) noexcept(false);
		static vector <token *> *get_tokens(std::string);
		
		/* The following is the array containing
		 * all the default operations */
		static const int NOPERS = 0x4;
		static const operation <oper_t> opers {
		   add_op, sub_op, mult_op, div_op,
		};
	};

	typedef module <num_t> module_t;
}

#include "types.cpp"

#endif

