/**
	Date: 10/1/2023
	By: Justin Su
	Purpose: Project #1
**/
#include <string>
#include "Student.h"
struct Course
{
	string title;
	int number_of_students;
	Student* list;
};
void getFilesToOpen(string* filesToOpen, int arraySize);
int main()
{
	const int NUMBER_OF_FILES = 3;
	const int ARRAY_SIZE = NUMBER_OF_FILES;
	string* filesToOpen = new string[ARRAY_SIZE];
	getFilesToOpen(filesToOpen, ARRAY_SIZE);

	delete[] filesToOpen;
	return 0;
}

void getFilesToOpen(string* filesToOpen, int arraySize)
{
	string fileName = "";
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Enter filename #" << (i + 1) << " : ";
		getline(cin, fileName);
		filesToOpen[i] = fileName;
	}
}
