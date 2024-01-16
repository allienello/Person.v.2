#include <iostream>
#include <iomanip>
using namespace std;

#include "People.h"

/*************************************
 * constructor()
 *************************************/
people::people()
{
	// Initialize

	int cap;
	int i;
	len = cap = 0;

	// Allocate data

	map = new person[PEOPLE_SIZE];

	if (map != NULL) cap = PEOPLE_SIZE;
}

/*************************************
 *destructor()
 *************************************/
people::~people()
{
	if (map != NULL) delete[] map;
}

/*************************************
 * insert()
 *************************************/
bool people::insert(person arg)
{
	int i, n, pos = 0;

	// Check to see if there is room

	if (len >= PEOPLE_SIZE) return false;

	// Finding position

	for (i = 0; i < len; i++)
	{
		if (arg > map[i])
		{
			pos = i + 1;
		}
	}

	// Make room in array to insert

	if (len < PEOPLE_SIZE)
	{
		for (i = len; i > pos; i--)
		{
			map[i] = map[i - 1];
		}

		map[pos] = arg;
		len++;
	}

	return true;

}

/*************************************
 * display()
 *************************************/
void people::display(ostream& out)
{
	int total = 0, average = 0;

	int i;

	// Output header

	cout << "ID    Last            First     Age" << endl;
	cout << "----  --------------  --------  ---" << endl;

	// Loop through data

	for (i = 0; i < len; i++)
	{
		map[i].put(cout);
		total += map[i].age;
	}

	// Calculate total

	if (len > 0)
	{
		average = total / len;
	}

	cout << "----  --------------  --------  ---" << endl;

	// Display average (account for single and double digit number of persons)

	if (i <= 9)
	{
		cout << left << setw(6) << "" << left << i << " Persons       " << "Average   " << average << endl << "\n";
	}
	if (i > 9)
	{
		cout << left << setw(6) << "" << i << " Persons      " << "Average   " << average << endl << "\n";
	}
}

/*************************************
 * find()
 *************************************/
bool people::find(int id)
{
	// Loop through data to find person using id

	for (int i = 0; i < len; i++) {
		if (map[i].id == id) return true;
	}
	return false;
}


/*************************************
 * remove()
 *************************************/
void people::remove(int arg)
{
	int i, n, pos;
	pos = len + 1;

	// Loop through data; if person exists initialize position

	for (i = 0; i < len; i++)
	{
		if (map[i].id == arg)
		{
			pos = i;
		}
	}

	// If person does not exist return 

	if (pos == len + 1) {
		return;
	}

	// Remove person 

	if (len > 0)
	{
		len--;
		for (n = pos; n < len; n++)
		{
			map[n] = map[n + 1];
		}
	}
}