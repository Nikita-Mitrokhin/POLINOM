#include "Link.h"
#include <lmcons.h>


Link::Link(void)
{
	next = NULL;
	DegreeCollection = 0;
	Value = Rational(0, 1);
}

Link::Link(const int& IntValue, const Rational& RationalValue)
{
	DegreeCollection = IntValue;
	Value = RationalValue;
	next = NULL;
}
