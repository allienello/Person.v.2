/**************************************
 * Headers - People.h
 * Written by Allie Ianello
 **************************************/
#include "Person.h"
#define PEOPLE_SIZE 20

class people
{
public:
	people();						// Null Constructor()
	~people();						// Deconstructor()
	bool insert(person arg);		// Insert into array
	void display(ostream& out);		// Display data & average
	bool find(int id);				// Find person
	void remove(int arg);			// Remove from array
private:
	int len;						// Length of array
	person *map;					// Person data
};
