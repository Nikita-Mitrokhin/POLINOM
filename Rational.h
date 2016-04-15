#ifndef __RATIONAL
#define __RATIONAL

#include <iostream>

using namespace std;

class Rational
{
public:
	Rational ();
	Rational (const int&, const int&);
	Rational (const Rational&);

	const Rational& operator= (const Rational&);
	Rational operator+ (const Rational&);
	Rational operator- (const Rational&);
	bool operator == (Rational&);

	friend ostream& operator<< (ostream& ostr, const Rational&);
	friend istream& operator>> (istream& istr, Rational& b);

	int GetNum(void) const;	

private:
	int num;
	unsigned int den; 

	void reduce();	
	unsigned int NOK(const Rational&);
};
#endif