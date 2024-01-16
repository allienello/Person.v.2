/**************************************
 * Program 02
 * Written by Allie Ianello 
 **************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Person.h"

/**************************************
 * null constructor()
 **************************************/
person::person()
{
	id = 0;
	last = "";
	first = "";
	age = 0;
}

/**************************************
 * get()
 **************************************/
bool person::get(istream& in)
{
	in >> id;
	in >> first;
	in >> last;
	in >> age;
	return in.good();
}

/**************************************
 * put()
 **************************************/
void person::put(ostream& out)
{
	out << left;
	out << setw(6) << id;
	out << setw(16) << last;
	out << setw(10) << first;
	out << setw(3) << age;
	out << endl;
}

/**********************************
 * equals operator
 **********************************/
bool person::operator == (const person& b)
{
	if (id == b.id && first == b.first && last == b.last && age == b.age)
		return true;
	else
		return false;
}

/**********************************
 * lesser operator
 **********************************/
bool person::operator < (const person& b)
{
	if (last < b.last)
		return true;
	if (last == b.last)
	{
		if (first < b.first)
			return true;
		if (first == b.first)
		{
			if (id < b.id)
			{
				if (age < b.age)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

/**********************************
 * greater operator
 **********************************/
bool person::operator > (const person& b)
{
	if (last > b.last)
		return true;
	if (last == b.last)
	{
		if (first > b.first)
			return true;
		if (first == b.first)
		{
			if (id > b.id)
			{
				if (age > b.age)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}


