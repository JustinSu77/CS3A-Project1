#pragma once
/**
	Date: 10/1/2023
	By: Justin Su
	Purpose: Student.h for Project #1
**/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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
			Default constructor.
			Precondition: Student object is instantiated.
			Postcondition: Private member variable id is set to 0.
						   Private member variable name is set to empty string.
						   Private member variable score is set to 0.
		**/
		Student();

		/**
			Constructor with 3 arguments.
			Precondition: Student object is instantiated
			Postcondition: Private member variable id is set to given newId.
						   Private member variable name is set to given newName.
						   Private member variable score is set to newScore.
			newId as new value for id as int
			newName as new value for name as int
			newScore as new value for score as int
		**/
		Student(int newId, string newName, int newScore);

		/**
			Setter function for private member variable id.
			Precondition: Student object is instantiated.
			Postcondition: Private member variable id is set to given newid.
				newId as new value for id as int
		**/
		void setId(int newId);

		/**
			Setter function for private member variable name.
			Precondition: Student object is instantiated.
			Postcondition: Private member variable name is set to given newName.
				newName as new value for name as string
		**/
		void setName(string newName);

		/**
			Setter function for private member variable score.
			Precondition: Student object is instantiated.
			Postcondition: Private member variable score is set to given newName.
				newScore as new value for score as int
		**/
		void setScore(int newScore);
		
		/**
			Getter function for private member variable id.
			Precondition: Student object is instantied.
			Postcondition: Private member variable id is returned.
		**/
		int getId();

		/**
			Getter function for private member variable name.
			Precondition: Student object is instantied.
			Postcondition: Private member variable name is returned.
		**/
		string getName();

		/**
			Getter function for private member variable score.
			Precondition: Student object is instantied.
			Postcondition: Private member variable score is returned.
		**/
		int getScore();
};

