/**
	Date: 10/1/2023
	By: Justin Su
	Purpose: Student.cpp for Project #1
**/

#include "Student.h"

Student::Student()
{
	// Set private member variabe id to 0
	id = 0;
	// Set private member variable name to empty string
	name = "";
	// Set private member variable score to 0
	score = 0;
}

Student::Student(int newId, string newName, int newScore)
{
	// Set private member variable id to given newId
	id = newId;
	// Set private member variable name to given newName
	name = newName;
	// Set private member varuable score to given newScore
	score = newScore;
}

void Student::setId(int newId)
{
	// Set private member id to given newId
	id = newId;
}

void Student::setName(string newName)
{
	// Set private variable name to given newName
	name = newName;
}

void Student::setScore(int newScore)
{
	// Set private member variable score to given newScore
	score = newScore;
}

int Student::getId()
{
	// Return private member variable id
	return id;
}

string Student::getName()
{
	// Return private member variable name
	return name;
}

int Student::getScore()
{
	// Return private member variable score
	return score;
}
