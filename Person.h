/**************************************
 * Headers - Person.h
 * Written by Allie Ianello
 **************************************/
class person
{
friend class people; 
public:
	person();					// Constructor()
	bool get(istream& in);		// Input data
	void put(ostream& out);		// Output data
	bool operator == (const person& b);     // Equal to
	bool operator > (const person& b);      // Greater than
	bool operator < (const person& b);      // Less than
private:
	string last;			// Person first name
	string first;			// Person last name
	int age;				// Person age
	int id;					// Person ID
};
