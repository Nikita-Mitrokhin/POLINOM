#include "Rational.h"

int NOD(const int& a1, const int& b1)
{
	int a = abs(a1), b = abs(b1);
	while(a != 0 && b != 0){
		if (a >= b)
			a = a % b;
		else
			b = b % a;
	}
	return a + b;
}

Rational::Rational() : num(0), den(1)
{

}

Rational::Rational(const int& a, const int& b)
{
	if (b < 0)
		exit(1);
	num = a;
	if (b)
		den = b;
	else
		exit(1);
	reduce();
}

Rational::Rational(const Rational& Copy)
{
	num = Copy.num;
	den = Copy.den;
}

const Rational& Rational::operator= (const Rational& Copy)
{
	num = Copy.num;
	den = Copy.den;
	return *this;
}

Rational Rational::operator+ (const Rational& Ratio)
{
	int Tmp = NOK(Ratio);
	Rational t;
	int c1 = Tmp / den, c2 = Tmp / Ratio.den;
	t.num = num * c1 + Ratio.num * c2;
	t.den = Tmp;
	t.reduce();
	return t;
}

Rational Rational::operator- (const Rational& Ratio)
{
	int Tmp = NOK(Ratio);
	Rational t;
	int c1 = Tmp / den, c2 = Tmp / Ratio.den;
	t.num = num * c1 - Ratio.num * c2;
	t.den = Tmp;
	t.reduce();
	return t;
}

bool Rational::operator == (Rational& sr)
{
	sr.reduce();
	if (den == sr.den && num == sr.num)
		return true;
	else 
		return false;
}

unsigned int Rational::NOK(const Rational& Ratio)
{
	return Ratio.den * den / NOD(Ratio.den, den);
}

void Rational::reduce()
{
	int nod = NOD(num,den);
	num = num / nod;
	den = den / nod;
}

ostream& operator<< (ostream& ostr, const Rational& b)
{
	if (b.den == 1 || b.num == 0)
		ostr << b.num;
	else 
		ostr << b.num << '/' << b.den;
	return ostr;
}

int Rational::GetNum(void) const
{
	return num;
}

istream& operator>> (istream& istr, Rational& b){
	char* str = new char [1024];
	cin.getline(str, 1024);
	int i = 0;
	unsigned int bt = 0;
	bool flag = false;
l1:
	int len = strlen(str)-1;
	while (str[len]==' '){
		str[len] = NULL;
		goto l1;
	}
	if (strlen(str)==0)
		exit(1);
	while (str[i]==' ')
		++i;
	if (str[i]=='-'){
		flag = true;
		++i;
	}
	while (str[i]!='.' && str[i]!='/' && i<strlen(str)){
		bt = (str[i] - '0') + bt*10;
		++i;
	}
	++i;
	switch (str[i-1]){
		case '.': {
			int j = 0;
			while (i<(int)strlen(str)){
				bt = (str[i] - '0') + bt*10;
				++i, ++j;
			}			
			b.den = int(pow(10.0,j));
			break;
		}
		case '/': {
			b.den = 0;
			while (i<(int)strlen(str)){
				b.den = (str[i]-'0') + b.den*10;
				++i;
			}
			break;
		}
	}
	b.num = flag ? -int(bt) : bt;
	b.reduce();
	return istr;
}
