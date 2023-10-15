#pragma once
#include <string>
#include "Student.h"
using namespace std;
// Structure to store data of a course
struct Course
{
	string title;
	int number_of_students;
	Student* list;
};

struct AllThreeCoursesData
{
	int id;
	string name;
	string courseOneTitle;
	int courseOneGrade;
	string courseTwoTitle;
	int courseTwoGrade;
	string courseThreeTitle;
	int courseThreeGrade;

};
 