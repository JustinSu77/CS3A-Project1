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
// Create data structure
void fillCourseArrayFromFiles(struct Course* courseArray, string* filesToOpen, int arraySize);

int main()
{
	// Get files and check if they can be opened
	const int NUMBER_OF_FILES = 3;
	const int ARRAY_SIZE = NUMBER_OF_FILES;
	string* filesToOpen = new string[ARRAY_SIZE];
	getFilesToOpen(filesToOpen, ARRAY_SIZE);
	checkIfFilesExist(filesToOpen, ARRAY_SIZE);
	// Creates the data structure
	struct Course* courseArray = new Course[ARRAY_SIZE];
	fillCourseArrayFromFiles(courseArray, filesToOpen, ARRAY_SIZE);
	cout << endl;
	 
	
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

void fillCourseArrayFromFiles(struct Course* courseArray, string* filesToOpen, int arraySize)
{
	ifstream inputFile;
	for (int i = 0; i < arraySize; i++)
	{
		string fileName = filesToOpen[i];
		inputFile.open(fileName);
		int numberOfStudents = 0;
		string title = "";
		inputFile >> title >> numberOfStudents;
		Student* studentArray = new Student[numberOfStudents];
		int index = 0;
		int id = 0;
		string name = "";
		int score = 0;
		while (!inputFile.eof() && index < numberOfStudents)
		{
			inputFile >> id >> name >> score;
			Student student(id, name, score);
			studentArray[index] = student;
			index++;
		}
		struct Course newCourse = { title, numberOfStudents, studentArray };
		courseArray[i] = newCourse;
		inputFile.close();
	}
}

 