#include <core/node_differential.hpp>

#include <core/node_differential.hpp>

namespace zhetapi {

node_differential::node_differential(Token *tptr) : _ref(tptr) {}

node_differential::~node_differential()
{
	if (_ref)
		delete _ref;
}

Token *node_differential::get() const
{
	return _ref;
}

Token::type node_differential::caller() const
{
	return Token::ndd;
}

Token *node_differential::copy() const
{
	return new node_differential(_ref->copy());
}

std::string node_differential::dbg_str() const
{
	return "differential: " + _ref->dbg_str();
}

bool node_differential::operator==(Token *tptr) const
{
	node_differential *ndd = dynamic_cast <node_differential *> (tptr);

	if (ndd == nullptr)
		return false;

	return (*_ref == ndd->_ref);
}

}

