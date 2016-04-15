#ifndef _List
#define _List

#include "Link.h"
#include <iostream>

using namespace std;

class List
{
public:
	PLink current;
public:
	List(void);
	List(List&);
	~List(void);

	void AddLink(const int&, const Rational&); // �������� ����� ����� ��������;
	void GoNext(void);						   // ���� �� ������ ������;
	bool DelCurrentLink(void);				   // �������� �������� �����;

	void ResetToFirst(void);				   // ����������� � ������ ������;
	bool IndexOf(const int&);                  // ����� ����� �� DegreeCollection;

	const List& operator= (List);

	int GetDegreeCollection(void) const;
	Rational GetValue(void) const;
	void SetValue(const Rational&); 
	void print(void);
};
#endif
