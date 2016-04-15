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

	void AddLink(const int&, const Rational&); // добавить звено после текущего;
	void GoNext(void);						   // идем по списку вправо;
	bool DelCurrentLink(void);				   // удаление текущего звена;

	void ResetToFirst(void);				   // переместить в начало списка;
	bool IndexOf(const int&);                  // найти звено по DegreeCollection;

	const List& operator= (List);

	int GetDegreeCollection(void) const;
	Rational GetValue(void) const;
	void SetValue(const Rational&); 
	void print(void);
};
#endif
