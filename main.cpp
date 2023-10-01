/**
	Date: 10/1/2023
	By: Justin Su
	Purpose: Project #1
**/
#include "Student.h"
struct Course
{
	string title;
	int number_of_students;
	Student* list;
};

int main()
{
	const int NUMBER_OF_FILES = 3;
	const int ARRAY_SIZE = NUMBER_OF_FILES;
	string* filesToOpen = new string[ARRAY_SIZE];


	delete[] filesToOpen;
	return 0;
}