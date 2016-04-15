#ifndef _Link
#define _Link

#include "Rational.h"

class Link;

typedef Link* PLink;

class Link
{
public:
	Rational Value;
	int DegreeCollection;
	PLink next;
	Link(void);
	Link(const int&, const Rational&);
};
#endif
