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
	int courseOneScore;
	string courseTwoTitle;
	int courseTwoScore;
	string courseThreeTitle;
	int courseThreeScore;

};
 