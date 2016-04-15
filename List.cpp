#include "List.h"

List::List(void)
{
	current = new Link;
	current->DegreeCollection = -1;
	current->next = current;
}

List::~List(void)
{
	ResetToFirst();
	while(DelCurrentLink())
		;
}

List::List(List& CopyList)
{
	current = new Link;
	current->DegreeCollection = -1;
	current->next = current;
	CopyList.ResetToFirst();
	while(CopyList.GetDegreeCollection() >= 0)
	{
		AddLink(CopyList.GetDegreeCollection(), CopyList.GetValue());
		CopyList.GoNext();
	}
}

void List::AddLink(const int& ValueInt, const Rational& ValueRational)
{
	PLink p = new Link(ValueInt, ValueRational);
	p->next = current->next;
	current->next = p;
	current = p;
}

void List::GoNext(void)
{
	current = current->next;
}

int List::GetDegreeCollection(void) const
{
	return current->DegreeCollection;
}

Rational List::GetValue(void) const
{
	return current->Value;
}

bool List::DelCurrentLink(void)
{
	if (current->next == current)
		return false;
	else
	{
		PLink Tmp;
		Tmp = current;
		ResetToFirst();
		while (current->next != Tmp)
			GoNext();
		current->next = Tmp->next;
		GoNext();
		delete Tmp;
		return true;
	}
}

void List::ResetToFirst(void)
{
	while(current->DegreeCollection >= 0)
		GoNext();
	GoNext();
}

void List::print(void)
{
	ResetToFirst();
	int i = 0;
	while(current->DegreeCollection != -1) 
	{
		cout << ++i << '.' << endl << "Value = " << current->Value	<< endl; 
		cout << "DegreeCollection = " << current->DegreeCollection << endl;
		GoNext();
	}
}

void List::SetValue(const Rational& RationalValue)
{
	current->Value = RationalValue;
}

bool List::IndexOf(const int& BufferValue)
{
	ResetToFirst();
	while(current->DegreeCollection != -1)
	{
		if (current->DegreeCollection == BufferValue)
			return true;
		GoNext();
	}
	return false;
}

const List& List::operator= (List CopyList)
{
	this->~List();
	List();
	CopyList.ResetToFirst();
	while (CopyList.GetDegreeCollection() >= 0)
	{
		AddLink(CopyList.GetDegreeCollection(), CopyList.GetValue());
		CopyList.GoNext();
	}
	return *this;
}
