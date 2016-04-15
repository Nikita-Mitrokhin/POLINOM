#include <conio.h>
#include "Rational.h"  
#include "Polynomial.h"

int SetDegreeCollections(int* degree)
{
	int Tmp = degree[0];
	for (int i = 1; i < n; ++i)
			Tmp = degree[i] + (Tmp *= BASE); 
	return Tmp;
}

#define size 2

int main()
{
	BASE = 100; 
	setlocale(LC_ALL, "Russian");
	Polynomial *A = new Polynomial[size];
	Rational Index;
	int degree[n]; 

	cout << "������� ������������ � ������ �������� ������� ��������" << endl;
	for (int j = 0; j < size; ++j)
	{
		while(_getch() != '1')
		{
			cout << "����������� ";
			fflush(stdin);
			cin >> Index;
			cout << "����� �������� ";
			fflush(stdin);
			for (int i = 0; i < n; ++i)
				cin	>> degree[i];
			A[j].AddMonom(SetDegreeCollections(degree), Index);
		}
		cout << "��������� �������" << endl << A[j] <<endl;		
	}

	cout << "�����: " << A[0] + A[1] << endl;
	_getch();
	return 0;
}