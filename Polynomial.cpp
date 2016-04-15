#include "Polynomial.h"


Polynomial::Polynomial(Polynomial& CopyBuffer)
{
	MonomList = CopyBuffer.MonomList;
}

Polynomial::Polynomial(void)
{

}

int* Polynomial::GetDegree(void)
{
	int *degree = new int[n];
	degree[0] = MonomList.GetDegreeCollection() / (BASE * BASE);
	degree[1] = MonomList.GetDegreeCollection() / BASE % BASE;
	degree[2] = MonomList.GetDegreeCollection() % BASE;

	return degree;
}

void Polynomial::AddMonom(const int& DegreeValue, const Rational& RationalValue)
{
	if (MonomList.IndexOf(DegreeValue))
		if ((MonomList.GetValue() + RationalValue) == Rational(0, 1))
			MonomList.DelCurrentLink();
		else
			MonomList.SetValue(MonomList.GetValue() + RationalValue);
	else
	{
		while(MonomList.current->DegreeCollection >= 0)
			MonomList.GoNext();
		while(DegreeValue < MonomList.current->next->DegreeCollection)		//???
			MonomList.GoNext();
		MonomList.AddLink(DegreeValue, RationalValue);
	}
}

Polynomial Polynomial::operator+ (Polynomial PolynomialBuffer)
{
	Polynomial Tmp;
	MonomList.ResetToFirst();
	Tmp.MonomList = MonomList;
	PolynomialBuffer.MonomList.ResetToFirst();
	while(PolynomialBuffer.MonomList.GetDegreeCollection() >= 0)
	{
		Tmp.AddMonom(PolynomialBuffer.MonomList.GetDegreeCollection(), PolynomialBuffer.MonomList.GetValue());
		PolynomialBuffer.MonomList.GoNext();
	}

	return Tmp;
}


const Polynomial& Polynomial::operator= (Polynomial CopyBuffer)
{
	MonomList = CopyBuffer.MonomList;
	return *this;
}

ostream& operator<< (ostream& os, Polynomial Buffer)
{
	Buffer.MonomList.ResetToFirst();
	char symbol[3] = {'x', 'y', 'z'};
	while(Buffer.MonomList.GetDegreeCollection() >= 0)
	{
		int* degree = Buffer.GetDegree();
		os << Buffer.MonomList.GetValue();
		for (int i = 0; i < n; ++i)
			if (!degree[i])
				continue;
			else
				if (degree[i] == 1)
					os << '*' << symbol[i];
				else
					os << '*' << symbol[i] << '^' << degree[i];

		if (Buffer.MonomList.current->next->DegreeCollection != -1 && Buffer.MonomList.current->next->Value.GetNum() >= 0)
			os << " + ";
		Buffer.MonomList.GoNext();
	}
	return os;
}

