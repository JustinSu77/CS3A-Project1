/**
	Date: 10/1/2023
	By: Justin Su
	Purpose: Project #1
**/
#include <string>
#include <fstream>
#include "Student.h"
struct Course
{
	string title;
	int number_of_students;
	Student* list;
};

// Text files
void getFilesToOpen(string* filesToOpen, int arraySize);
void checkIfFilesExist(string* filesToOpen, int arraySize);

int main()
{
	// Get files and check if they can be opened
	const int NUMBER_OF_FILES = 3;
	const int ARRAY_SIZE = NUMBER_OF_FILES;
	string* filesToOpen = new string[ARRAY_SIZE];
	getFilesToOpen(filesToOpen, ARRAY_SIZE);
	checkIfFilesExist(filesToOpen, ARRAY_SIZE);
	// Creates the data structure

	
	
	
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

void checkIfFilesExist(string* filesToOpen, int arraySize)
{
	ifstream inputFile;
	for (int i = 0; i < arraySize; i++)
	{
		string fileName = filesToOpen[i];
		inputFile.open(fileName);
		if (inputFile.fail())
		{
			cout << endl;
			cout << "Failed to open " << fileName << endl;
			exit(1);
		}
		inputFile.close();
	}
}
