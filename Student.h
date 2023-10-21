#pragma once
/**
	Date: 10/20/2023
	By: Justin Su
	Purpose: Student.h for Project #1
**/
// Student class
#include "string"
using namespace std;

// Student class
class Student
{
	// Private member variables
	private:
		int id;
		string name;
		int score;
	public:
		/**
			Purpose: Default constructor.
			Precondition: Student object is instantiated
			Result: Private member variable id is set to 0
					Private member variable name is set to ""
					Private member variable score is set to 0
		**/
		Student();

		/**
			Purpose: Constructor with 3 arguments.
			Input: newId as new value for private member variable id as int
				   newName as new value for private member variable name as string
				   newScore as new value for private member variable score as int
			Precondition: Student object should be instantiated
			Result: Private member variable id is set to newId
					Private member variable name is set to newName
					Private member variable score is set to newScore
		**/
		Student(int newId, string newName, int newScore);

		/**
			Purpose: Setter function for private member variable id.
			Input: newId as new value for private member variable id as int
			Precondition: Student object is instantiated
			Result: The Student calling object has its private mmeber variable id set to given newId
		**/
		void setId(int newId);

		/**
			Purpose: Setter function for private member variable name
			Input: newName as new value for private member variable name as string
			Precondition: Student object is instantiated
			Result: The Student calling object has its private member variable name set to given newName
		**/
		void setName(string newName);

		/**
			Purpose: Setter function for private member variable score.
			Input: newScore as new value for private member variable score as int
			Precondition: Student object is instantiated
			Result: The Student calling object has its private mmeber variable score set to given newScore
		**/
		void setScore(int newScore);
		
		/**
			Purpose: Getter function for private member variable id.
			Precondition: Student object is instantiated
			Result: Private member variable id is returned
		**/
		int getId() const;

		/**
			Purpose: Getter function for private member variable name.
			Precondition: Student object is instantiated
			Result: Private member variable name is returned
		**/
		string getName() const;

		/**
			Purpose: Getter function for private member variable score.
			Precondition: Student object is instantiated
			Result: Private member variable name is returned
		**/
		int getScore() const;
};

