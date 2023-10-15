/**
	Date: 10/1/2023
	By: Justin Su
	Purpose: main.cpp for Project #1
**/

#include "HelperFunctions.h"
 
int main()
{
	// Declare and initialize struct Course array
	struct Course courseArray[3];
	// Declare and initialize variable for size of courseArray
	const int ARRAY_SIZE = sizeof(courseArray) / sizeof(struct Course);
	// Declare and initialize dynamic string array to store the names of text files to open 
	string* filesToOpen = new string[ARRAY_SIZE];
	//string filesToOpen[] = { "javascript.txt", "architecture.txt", "database.txt" };
	// Call function to get fileNames from user
	getFilesToOpen(filesToOpen, ARRAY_SIZE);
	// Check if each of the given fileName exists
	checkIfFilesExist(filesToOpen, ARRAY_SIZE);
	// Creates the data structure for the program from the given files
	fillCourseArrayFromFiles(courseArray, filesToOpen, ARRAY_SIZE);
	// Skip a line for terminal readability 
	cout << endl;
	// Run the program
	runProgram(courseArray, ARRAY_SIZE);
	
	// Deallocate string dynamic array
	delete[] filesToOpen;
	// Deallocate the student dynamic array in each course element of courseArray
	deallocateStudentListInCourseArray(courseArray, ARRAY_SIZE);
	
	return 0;
}



 