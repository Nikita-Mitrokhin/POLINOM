#ifndef _Polynomial
#define _Polynomial

#include "List.h"
#include "Rational.h"

static int BASE = 100;
#define n 3	

class Polynomial
{
	List MonomList;									  // ������ ������������� ��������;
	int* GetDegree(void);							  // �������� ������� �� ������;

public:
	void AddMonom(const int&, const Rational&);       // �������� �����;
	Polynomial operator+ (Polynomial);				  // �������� +;
	const Polynomial& operator= (Polynomial);
	Polynomial(Polynomial&);
	Polynomial(void);

	friend ostream& operator<< (ostream& os, Polynomial Buffer);
};

#endif
