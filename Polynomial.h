#ifndef _Polynomial
#define _Polynomial

#include "List.h"
#include "Rational.h"

static int BASE = 100;
#define n 3	

class Polynomial
{
	List MonomList;									  // список коэффициентов полинома;
	int* GetDegree(void);							  // получаем степени из набора;

public:
	void AddMonom(const int&, const Rational&);       // добавить звено;
	Polynomial operator+ (Polynomial);				  // оператор +;
	const Polynomial& operator= (Polynomial);
	Polynomial(Polynomial&);
	Polynomial(void);

	friend ostream& operator<< (ostream& os, Polynomial Buffer);
};

#endif
