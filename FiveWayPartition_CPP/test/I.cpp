#include <iostream>
#include "I.h"

I::I(const I &i)
{
	this->value = i.value;
}
I::I(double val)
{
	this->value = val;
}
I::I() {}
I::~I() {}

bool I::operator>(const I &right) const
{
	return (value > right.value);
}

bool I::operator<(const I &right) const
{
	return (value < right.value);
}

bool I::operator>=(const I &right) const
{
	return (value >= right.value);
}

bool I::operator<=(const I &right) const
{
	return (value <= right.value);
}

bool I::operator==(const I &right) const
{
	return (value == right.value);
}

bool I::operator!=(const I &right) const
{
	return (value != right.value);
}

I &I::operator=(const I &right)
{
	this->value = right.value;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const I &obj)
{
	os << obj.getValue();
	return os;
}
double I::getValue() const
{
	return this->value;
}
