#include <token.hpp>

#include <core/types.hpp>

namespace zhetapi {

Token::Token() {}

// attrs
Token::Token(const std::vector <std::pair <std::string, method>> &attrs)
{
	for (auto attr_pr : attrs)
		this->_methods[attr_pr.first] = attr_pr.second;
}

Token::~Token() {}

Token *Token::attr(const std::string &id, const std::vector <Token *> &args)
{
	// Priorotize attributes
	if (_attributes.find(id) != _attributes.end())
		return _attributes[id];
	
	if (_methods.find(id) != _methods.end())
		return _methods[id](this, args);
	
	throw unknown_attribute(typeid(*this), id);

	return nullptr;
}

bool Token::operator!=(Token *tptr) const
{
	return !(*this == tptr); 
}

bool tokcmp(Token *a, Token *b)
{
	return *a == b;
}

void Token::list_attributes(std::ostream &os) const
{
	os << "Methods:" << std::endl;
	for (const auto &m : _methods)
		os << "\t" << m.first << std::endl;
	
	os << "Attributes:" << std::endl;
	for (const auto &a : _attributes)
		os << "\t" << a.first << " = " << a.second->dbg_str() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const std::vector <Token *> &toks)
{
	os << "{";

	size_t n = toks.size();
	for (size_t i = 0; i < n; i++) {
		os << toks[i]->dbg_str();

		if (i < n - 1)
			os << ", ";
	}

	os << "}";

	return os;
}

// Unknown attribute exception
 std::string Token::unknown_attribute::what() const
 {
	// TODO: use the actual name instead of mangled
	// TODO: use id() instead of typeid
	return "<" + type_name(_ti) + ">"
		+ " has no attribute \""
		+ _msg + "\"";
}

uint8_t Token::id() const
{
	return 0;
}

Token::type Token::caller() const
{
	return undefined;
}

std::string Token::dbg_str() const
{
	return "[?]";
}

void Token::write(std::ostream &os) const
{
	throw empty_io();
}

}
