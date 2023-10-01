#include "Student.h"

Student::Student()
{
	id = 0;
	name = "";
	score = 0;
}

Student::Student(int newId, string newName, int newScore)
{
	id = newId;
	name = newName;
	score = newScore;
}

void Student::setId(int newId)
{
	id = newId;
}

void Student::setName(string newName)
{
	name = newName;
}

void Student::setScore(int newScore)
{
	score = newScore;
}

int Student::getId()
{
	return id;
}

string Student::getName()
{
	return name;
}

int Student::getScore()
{
	return score;
}
