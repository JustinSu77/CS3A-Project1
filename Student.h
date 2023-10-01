#pragma once
#include <iostream>
using namespace std;

class Student
{
	private:
		int id;
		string name;
		int score;
	public:
		Student();
		Student(int newId, string newName, int newScore);
		void setId(int newId);
		void setName(string newName);
		void setScore(int newScore);
		int getId();
		string getName();
		int getScore();
};

