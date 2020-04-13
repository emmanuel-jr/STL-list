


#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct DataType
{
	string lastname;	// Student's Last Name
	string firstname;	// Student's First Name

	string getKey() const
	{
		return lastname;
	}   // Returns the key field
};

//---------Need to add code to overload operator <<
ostream& operator<<(ostream& os, const DataType& p)
{
	os << p.firstname << " " << p.lastname << endl;

	return os;
}


bool operator < (DataType lhs, DataType rhs)
{
	return (lhs.getKey() < rhs.getKey());
}

void main()
{
	ifstream studentFile("input.txt");  // Student file
	list <DataType> students;            // Students
	DataType currStudent;              // One Student (has firstname,lastname)



	// Read each line from input.txt:
	//Store the firstname and the lastname into 
	//the temporary student structure "currStudent".
	for (int i = 0; i < 10; i++)
	{
		studentFile >> currStudent.firstname >> currStudent.lastname;
		// Push the current student into the list ("students") 
		students.push_back(currStudent);
	}

	// Use an iterator to print the unsorted list of students.
		list<DataType>::iterator p = students.begin();
		cout << "Unsorted contents:\n";
		while (p != students.end()) 
		{
			cout << *p;
			p++;
		}

		cout << endl;

	// Sort the list of students.
		students.sort();

	// Use an iterator to print the sorted list of students.
		cout << "Sorted contents:\n";

		for (auto x : students)
			cout << x;

}

