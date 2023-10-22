/**
	Date: 10/20/2023
	By: Justin Su
	Purpose: main.cpp for Project #1
**/
#include "Student.h"
#include <iostream>
#include <fstream>
#include <iomanip>
 
// Structure definition for a course
struct Course
{
	// Name of course
	string title;
	// Number of students in the course
	int number_of_students;
	// Dynamic array of Student objects
	Student* list;
};

/*   Structure definition to store data for function
	 that outputs students who take all 3 courses
*/
struct AllThreeCoursesData
{
	// Store id of Student object
	int id;
	// Store name of Student object
	string name;
	// Store title of first course
	string courseOneTitle;
	// Store the score from first course
	int courseOneScore;
	// Store the title of second course 
	string courseTwoTitle;
	// Store the score from second course
	int courseTwoScore;
	// Store the title of third course
	string courseThreeTitle;
	// Store the score from third course
	int courseThreeScore;

};

/*   Structure definition to store data for function
	 that outputs students who take only take 2 courses
*/
struct OnlyTwoCoursesData
{
	// Store id of Student object
	int id;
	// Store name of Student object
	string name;
	// Store the title of first course
	string courseOneTitle;
	// Store the score of first course
	int courseOneScore;
	// Store the title of second course
	string courseTwoTitle;
	// Store the score from second course
	int courseTwoScore;
};
 
// Files
/**
	Purpose: Prompt user for name of file to be opened and store user input to string dynamic array.
	Input: filesToOpen as string dynamic array
		   arraySize as number of elements that will be in filesToOpen as int
	Input Requirements: Number of elements in given filesToOpen should be equal to arraySize
						Given filesToOpen is a dynamic array with type string
						Given arraySize is greater than 0
						Given arraySize has type of int
	Result: Given string dynamic array filesToOpen is filled with file names from user
**/
void getFilesToOpen(string* filesToOpen, int arraySize);

/**
	Purpose: Open each element in given string dynamic array as a text file and exits program
			 with code 1 if the current file opened does fails to open
	Input: filesToOpen as string dynamic array
		   arraySize as number elements in filesToOpen as int
	Input Requirements: Given filesToOpen is a dynamic array with type string
						Number of elements in given filesToOpen should be equal to arraySize
						Given arraySize is greater than 0
						Given arraySize has type of int
	Result: If file fails to be opened, exit program with code 1
**/
void checkIfFilesExist(string* filesToOpen, int arraySize);

// Create data structure
/**
	Purpose: Fill given courseArray from text files with file names from given filesToOpen.
	Input: courseArray as a array of struct Course
		   fileName as dynamic array of string
		   arraySize as number of elements in both given arrays as int
	Input Requirements: Given arraySize should be greater than 0
						Given courseArray and filesToOpen should have the same number of elements
						Given courseArray is an array with type struct Course
						Given filesToOpen is an dynamic array of string
						Given arraySize has type of int
						First value of first line of text file read be a string that is the title of the course
						Second value of first line of text file should be a positive number greater than 0
	Result: Given courseArray is filled with struct Course variables with
			their title, number_of_students, and list data from given text files
			If the second value of first line is <= 0 than notify and exit program
**/
void fillCourseArrayFromFiles(struct Course* courseArray, string* filesToOpen, int arraySize);


// User Interaction
/**
	Purpose: Promp user with a menu with choices numbered 1-5. 
			 Store user input to a int reference that can
			 be used in another function to do something with the int reference passed.
	Input: userChoice as char reference
	Input Requirements: Given userChoice is an 
	Result: The value user entered after being prompted is the value of the given userChoice reference
**/
void showMenu(char& userChoice);


// Task 1: Show All Course Lists
/**
	Purpose: Uses Insertion Sort to sort a dynamic array of Student objects
			 based on their id member variable in asecending order.
			 Helper Function for option 1 showAllCourseLists
	Input: array as a dynamic array with type Student
		   arraySize as number of elements in array as int
	Input Requirement: Given array is a dynamic array of type Student
					   Number of elements in given array is equal to arraySize
					   Given arraySize is greater than 0
					   Given arraySize is an integer
	Result: The given dynamic array or a pointer to the dynamic array contains
			Student objects that is sorted in asecending order based on their id
**/
void insertionSortById(Student* array, int arraySize);

/**
	Purpose: Outputs the id, name, and score of given Student dynamic array to terminal.
			 Helper Function for option 1 showAllCourseLists
	Input: array as dynamic array with type of Student
		   arraySize as number of elements in given array as int
	Input Requirements: Number of elements in given array should be equal to given arraySize 
						Given array is dynamic array of Student objects
						Given arraySize is greater than 0
						Given arraySize has type of int
	Result: The id, name, and score of each Student object
			in given array is outputted with spaces in between to terminal
**/
void outputStudentList(Student* array, int arraySize);

/**
*	Purpose: Function to be called for option of Show all courses lists (sorting).
	Input: array as array with type of struct Course
		   arraySize as number of elements in given array
	Input Requirements: Given array could be a static or dynamic array of struct Course
						Number of elements in given array is equal to arraySize
						Given arraySize is greater than 0
						Given arraySize is an int
	Result: The title of each course in given array and the id, name, and score of each Student object 
			from the Student list of each given course is sorted in ascending order by id is outputted to terminal

**/
void showAllCourseLists(struct Course* array, int arraySize);


// Task 2: List of students who take all courses
/**
	Purpose: Count and return the number of times a id value of a Student object appears in 
			 the Student list of the given courses.
			 Helper function for option 2 listOfStudentsWhoTakeAllThreeCourses.
	Input: Given courseOne as struct Course variable
		   Given courseTwo as struct Course variable
		   Given courseThree as struct Course variable
	Input requirements: Given struct variables of given courseOne, courseTwo, and courseThree are initialized
	Result: The number of students whose id exists in the Student list of 
			courseOne, courseTwo, and courseThree is returned
**/
int getTotalStudentsWhoTakeAllThreeCourses(struct Course courseOne, struct Course courseTwo, struct Course courseThree);

/**
	Purpose: Returns a pointer to a dynamic array of struct AllThreeCoursesData of the Student objects 
	         that exist in all 3 given courseOne, courseTwo, courseThree.
			 Helper function for option 2 listOfStudentsWhoTakeAllThreeCourses.
	Input: totalStudents as the number of students that will be in dynamic array returned as int
		   courseOne as struct variable of type struct Course
		   courseTwo as as struct variable of type struct Course
		   courseThree as struct variable of type struct Course
	Input Requirement: Given totalStudents should be an integer greater than 0
					   Given courseOne, courseTwo, courseThree are initialized
	Result: A pointer to dynamic array filled with data of Student object that exists 
		    in given courseOne, courseTwo, and courseThree is     returned
**/
struct AllThreeCoursesData* getDataOfStudentsWhoTakeAllThreeCourses(int totalStudents, struct Course courseOne, 
	struct Course courseTwo, struct Course courseThree);

/**
	Purpose: Uses Insertion Sort to sort a dynamic array of struct AllThreeCoursesData variables
			 based on the id in ascending order.
			 Helper function for option 2 listOfStudentsWhoTakeAllThreeCourses.
	Input: array as a dynamic array with type of struct AllThreeCoursesData
		   arraySize as number of elements in array as int
	Input Requirement: Given array is a dynamic array of type struct AllThreeCoursesData
					   Number of elements in given array is equal to arraySize
					   Given arraySize is greater than 0
					   Given arraySize is an integer
	Result: The given dynamic array or a pointer to the dynamic array struct AllThreeCoursesData 
			variable that is sorted in asecending order based on their id
**/
void sortAllThreeCoursesDataArrayById(struct AllThreeCoursesData* array, int arraySize);

/**
	Purpose: Outputs the data in each element of given array neatly formatted to terminal.
			 Helper function for option 2 listOfStudentsWhoTakeAllThreeCourses.
	Input: Given array as dynamic array of struct AllThreeCoursesData variables
		   Given arraySize as number of elements in given array
	Input Requirement: Given array is filled with struct AllThreeCoursesData variables with 
	                   data from Student objects that appear in all 3 courses
					   Number of elements in givne array should be equal to given arraySize
					   arraySize should be an integer
					   arraySize should be greater than 0
	Result: The data of each struct AllThreeCourseData variable in the given array is outputted neatly to the terminal
**/
void outputAllThreeCoursesDataArray(struct AllThreeCoursesData* array, int arraySize);

/**
	Purpose: Function to be called for option 2 List of students who take all courses.
	Input: courseArray as an array of struct Course variables
	Input Requirements: struct Course Variables in given courseArray should be initialized
	Result: Outputs the data in the struct AllThreeCoursesData neatly to terminal
**/
void listOfStudentsWhoTakeAllThreeCourses(struct Course* courseArray);


// Task 3: List of students who take only take 2 courses
/**
	Purpose: Return whether or not whether a Student object in given Student dynamic array 
			 has an id the same as given targetId.
			 Helper function for option 3 listOfStudentsWhoTakeTwoCourses.
	Input: list as dynamic array with Student data type
		   listSize as the number of elements in given list
		   targetId as the id to search for in given list
	Input Requirement: Number of elements in given list should be the same as listSize
					   listSize should be an integer
					   targetId should be an integer
	Result: If there is a Student object with id private
			member variable equal to given targetId return true
			Otherwise return false
**/
bool idExistsInList(Student* list, int listSize, int targetId);

/**
	Purpose: Return the number of students who are in given Student dynamic arrays listOne 
			 and listTwo but not in given listThree.
			 Helper function for option 3 listOfStudentsWhoTakeTwoCourses.
	Input: listOne as dynamic array with type Student
		   listOneSize as number of elements in listOne
		   listTwo as dynamic array with type Student
		   listTwoSize as number of elements in listTwo
		   listThree as dynamic array with type Student
		   listThreeSize as number of elements in listThree
	Input Requirements: Number of elements in given listOne should be equal to given listOneSize
						Number of elements in given listTwo should be equal to given listTwoSize
						Number of elements in given listThree should be equal to given listThreeSize
	Result: The number of students that are both in listOne and listTwo but not in listThree is returned.
**/
int getTotalStudentsWhoOnlyTakeTwoCourses(Student* listOne, int listOneSize, Student* listTwo, int listTwoSize, 
	Student* listThree, int listThreeSize);

/**
	Purpose: Return a pointer to a struct OnlyTwoCoursesData dynamic array that has the data of 
	         the Student objects that exists in given listOne and listTwo but not listThree.
			 Helper function for option 3 listOfStudentsWhoTakeTwoCourses.
	Input: totalStudents as number of students that will by in dynamic array to be returned as int
		   courseOneTitle as the title of course One as string
		   listOne as an array of student objects
		   listOneSize as the number of elements in given array as int
		   courseTwoTitle as title of course Two as string
		   listTwo as array of Student objects
		   listTwoSize as number of elements in given listTwo
		   listThree as array of Student objects
		   listThreeSize as number of elements in given listThree
	Input Requirement: Given totalStudents should be greater than 0
					   Given courseOneTitle should be a string
					   Number of elements in given listOne should be equal to given listOneSize
					   Number of elements in given listTwo should be equal to listTwoSize
					   Number of elements in given listThree should be equal to listThreeSize
	Result: A pointer to dynamic array of type struct OnlyTwoCoursesData is returned.
					   
**/
struct OnlyTwoCoursesData* getDataOfStudentsWhoOnlyTakeTwoCourses(int totalStudents, string courseOneTitle, Student* listOne, 
	int listOneSize, string courseTwoTitle, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize);

/**
	Purpose: Uses Insertion Sort to sort a dynamic array of struct OnlyTwoCoursesData variables
			 based on the id in ascending order.
			 Helper function for option 3 listOfStudentsWhoTakeTwoCourses.
	Input: array as a dynamic array with type of struct AllThreeCoursesData
		   arraySize as number of elements in array as int
	Input Requirement: Given array is a dynamic array of type struct AllThreeCoursesData
					   Number of elements in given array is equal to arraySize
					   Given arraySize is greater than 0
					   Given arraySize is an integer
	Result: The given dynamic array or a pointer to the dynamic array struct AllThreeCoursesData 
			variable that is sorted in asecending order based on their id
**/
void sortOnlyTwoCoursesDataArrayById(struct OnlyTwoCoursesData* array, int arraySize);

/**
	Purpose: Outputs the data in each element of given array neatly formatted to terminal.
			 Helper function for option 3 listOfStudentsWhoTakeTwoCourses.
	Input: Given array as dynamic array of struct AllThreeCoursesData variables
		   Given arraySize as number of elements in given array
	Input Requirement: Given array is filled with struct AllThreeCoursesData variables with
					   data from Student objects that appear in all 3 courses
					   Number of elements in givne array should be equal to given arraySize
					   arraySize should be an integer
					   arraySize should be greater than 0
	Result: The data of each struct AllThreeCourseData variable in the given array is outputted neatly to the terminal
**/
void outputOnlyTwoCoursesDataArray(struct OnlyTwoCoursesData* array, int arraySize);

/**
	Purpose: Function to be called when user chooses the option 3 List of students who take two courses.
	Input: courseArray is array of struct Course variables
	Input requirements: Given courseArray is filled with struct Course variables with data from given text files
	Result: Outputs the number of id that exists in all 3 courses.
			Outputs the id, name, and score of the Student object with the id that
			exists in the Student list of all courses for every course pair
**/
void listOfStudentsWhoTakeTwoCourses(struct Course* courseArray);


// Task 4: Print out top three students for each course
/**
	Purpose: Sort elements in given Student object array by their score in ascending order using Insertion Sort.
			 Helper function for option 4 printOutTopNStudentsForEachCourse
	Input: array as a dynamic array of Student objects
		   arraySize as the number of elements in given array
	Input Requirement: array is a dynamic array of Student object
					   Number of elements in array should be equal to arraySize
					   arraySize is an integer
	Result: Given dynamic array of Student objects are sorted in ascending order by their score.
**/
void insertionSortByScore(Student* array, int arraySize);

/**
	Purpose: Return a pointer to dynamic array filled with scores from given Student array.
			 Helper function for option 4 printOutTopNStudentsForEachCourse
	Input: array as dynamic array of type Student
		   arraySize number of elements in given array as int
	Input Requirement: Number of elements in given array should be equal to arraySize
					   arraySize should be >= 0
	Result: Return a pointer to dynamic array filled with scores from given Student array
**/
int* getStudentGrades(Student* array, int arraySize);

/**
	Purpose: Delete duplicate scores in sorted integer dynamic array.
			 Helper function for option 4 printOutTopNStudentsForEachCourse
	Input: array as int dynamic array
		   arraySize as number of elements in given array as int reference
	Input Requirements: Given array is sorted in ascending order
						Number of elements in given array is equal to given arraySize
						arraySize should be >= 0
	Result: Duplicate scores in given array are removed
			arraySize is changed to number of elements removed + 1
**/
void  removeDuplicateScoresInGivenArray(int* array, int& arraySize);

/**
	Purpose: Output the id and score of the Student object that has the given targetScore.
			 Helper function for option 4.
	Input: array as dynamic array of Student objects
		   arraySize as number of elements in given array
		   targetScore as target score for Student objects to have to be outputted to terminal
	Input Requirement: array is a dynamic array of Student objects
					   Number of elements in array is equal to given arraySize
					   arraySize is an integer
					   targetScore is an integer
	Result: The id, name, and score of the Student objects that the same score as given score 
			is ouputted to the terminal
**/
void printStudentsWithGivenScore(Student* array, int arraySize, int targetScore);

/**
	Purpose: Function to run when user chooses option 4: Print out top three scores for each course.
	Input: courseArray as array of struct Course variables
		   arraySize as number of elements in courseArray
		   n as the number of students to print out
	Input Requirement: courseArray should be a array of struct Course variables
					   Number of elemenets in courseArray should be arraySize
					   n should be an integer
	Result: Outputs the title of the course
			Prints out the top 3 score in each Student list and the id and name of each Student object 
			in the Student list of each course
			If the given number of students in a course is less than n, than use that number as n
			Ex: 2 student object in Student list and given n is 3
				Then n will be 2
				So the top 2 score and the id and name ofthe Student objects who have those scores will be printed out
**/
void printOutTopNStudentsForEachCourse(struct Course* courseArray, int arraySize, int n);


// Clean up
/**
	Purpose: Deallocates the dynamic arrays pointed to by the list member variable of
			 each struct variable in given courseArray.
	Input: courseArray as array of type struct Course
		   arraySize as the size of the courseArray as int
``	Input Requirements: Number of elements in courseArray should be same as arraySize
						courseArray has type of struct Course
						arraySize is greater than 0
						arraySize is an int
	Result: The dynamic array pointed to by the list variable of each struct Course variable is deallocated
**/
void deallocateStudentListInCourseArray(struct Course* courseArray, int arraySize);

int main()
{
	// Declare and initialize struct Course array
	struct Course courseArray[3];
	// Declare and initialize variable for size of courseArray
	const int ARRAY_SIZE = sizeof(courseArray) / sizeof(struct Course);
	// Declare and initialize dynamic string array to store the names of text files to open 
	string* filesToOpen = new string[ARRAY_SIZE];
	// Call function to get fileNames from user
	getFilesToOpen(filesToOpen, ARRAY_SIZE);
	// Check if each of the given fileName exists
	checkIfFilesExist(filesToOpen, ARRAY_SIZE);
	// Creates the data structure for the program from the given files
	fillCourseArrayFromFiles(courseArray, filesToOpen, ARRAY_SIZE);
	// Skip a line for terminal readability 
	cout << endl;
	// Run the program
	// Declare and initialize variable to store the user choice
	// Use char to allow user to enter char characters without crashing
	char userChoice = ' ';
	// Show menu to user for the 5 options to run
	showMenu(userChoice);
	// Change userChoice to actual int value instead of char ascii value
	int userChoiceAsInt = static_cast<int>(userChoice) - static_cast<int>('0');
	// If user enters an invalid choice
	if (userChoiceAsInt < 1 || userChoiceAsInt > 5)
	{
		// Skip a line in terminal for readability
		cout << endl;
		// Notify
		cout << "Invalid option! Exiting program!" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Run the functions corresponding to the user choice
	switch (userChoiceAsInt)
	{
	case 1:
		// Run function that shows the student lists in all 3 courses sorted by id in ascending order
		showAllCourseLists(courseArray, ARRAY_SIZE);
		// Prevent fall through and exit switch when function is done
		break;
	case 2:
		// Run function to output all the Students who are in all three courses
		listOfStudentsWhoTakeAllThreeCourses(courseArray);
		// Prevent fall through and exit switch when function is done
		break;
	case 3:
		// Run function to output all the Students who take 2 courses but is not in the third course
		listOfStudentsWhoTakeTwoCourses(courseArray);
		// Prevent fall through and exit switch when function is done
		break;
	case 4:
		// Run function to output the 3 Students from each course with the highest score
		printOutTopNStudentsForEachCourse(courseArray, ARRAY_SIZE, 3);
		// Prevent fall through and exit switch when function is done
		break;
	// If 5 is chosen
	default:
		// Notify program is about to exit
		cout << endl;
		cout << "  Exiting....";
		cout << endl;
	}
	
	// Deallocate string dynamic array
	delete[] filesToOpen;
	// Deallocate the student dynamic array in each course element of courseArray
	deallocateStudentListInCourseArray(courseArray, ARRAY_SIZE);
	
	return 0;
}

// Files
void getFilesToOpen(string* filesToOpen, int arraySize)
{
	// Declare and initialize variable to store fileName
	string fileName = "";
	// Loop through given string dynamic array
	for (int i = 0; i < arraySize; i++)
	{
		// Prompt user for fileName
		cout << "Enter filename #" << (i + 1) << " : ";
		// Save string from user into fileName variable
		getline(cin, fileName);
		// Set current index of dynamic array to given fileName
		filesToOpen[i] = fileName;
	}
}

void checkIfFilesExist(string* filesToOpen, int arraySize)
{
	// Declare ifstream object
	ifstream inputFile;
	// Loop through given string dynamic array filesToOpen
	for (int i = 0; i < arraySize; i++)
	{
		// Declare and initialize variable for file name at 
		// current index of fileToOpen array
		string fileName = filesToOpen[i];
		// Open fileName as file
		inputFile.open(fileName);
		// If file failed to open
		if (inputFile.fail())
		{
			// Skip a line for terminal readability
			cout << endl;
			// notify
			cout << "Failed to open " << fileName << endl;
			// Exit program with error code 1
			exit(1);
		}
		// Close ifstream object
		inputFile.close();
	}
}

// Create Data Structure
void fillCourseArrayFromFiles(struct Course* courseArray, string* filesToOpen, int arraySize)
{
	// Declare ifstream object to read file
	ifstream inputFile;
	// Loop through given courseArray
	for (int i = 0; i < arraySize; i++)
	{
		// Declare and initialize variable for file name at 
		// current index of fileToOpen array
		string fileName = filesToOpen[i];
		// Open the file 
		inputFile.open(fileName);
		// Declare variables used to store the data from first line of text file
		int numberOfStudents = 0;
		string title = "";
		// Read in the data
		inputFile >> title >> numberOfStudents;
		// If after reading in value for numberOfStudents and the value is still 0
		if (numberOfStudents <= 0)
		{
			// Output new line for readability in terminal
			cout << endl;
			// Notify
			cout << fileName << " has no students " << endl;
			// Exit program with error code 1
			exit(1);
		}
		// Declare and initialize the Student dynamic array to store Student objects with the next 3 data
		Student* studentArray = new Student[numberOfStudents];
		// Declare the variables needed for the next 3 data
		int id = 0;
		string name = "";
		int score = 0;
		int index = 0;
		// Keep looping while not end of file
		// ensure index is less than number of students for compiler warning
		while (!inputFile.eof() && index < numberOfStudents)
		{
			// Read the 3 data of Student object
			inputFile >> id >> name >> score;
			// Create Student object with the 3 given data
			Student student(id, name, score);
			// Set currrent index of Student dynamic array to Student object
			studentArray[index] = student;
			// Increment index 
			index++;
		}
		// Create new struct course variable
		struct Course newCourse = { title, numberOfStudents, studentArray };
		// Set current index of courseArray to created course 
		courseArray[i] = newCourse;
		// Close ifstream object
		inputFile.close();
	}
}


// User interaction
void showMenu(char& userChoice)
{
	// Prompt user for the 5 tasks to run to this program
	cout << "=================  Menu  =====================" << endl;
	cout << "  1. Show all course lists (sorting)" << endl;
	cout << "  2. List of students who take all courses" << endl;
	cout << "  3. List of students who take two courses" << endl;
	cout << "  4. Print out top three scores for each course" << endl;
	cout << "  5. Exit" << endl;
	cout << "  ----> Select : ";
	// Save user choice as int reference to be passed to the run function
	cin >> userChoice;
}


// Task 1: Show all course Lists
void insertionSortById(Student* array, int arraySize)
{
	// Declare variables used
	int j;
	// Loop through given array
	for (int i = 1; i < arraySize; i++)
	{
		// Set key to current element
		Student key = array[i];
		// Set j to element before current element
		j = i - 1;
		// Compare the id of the key element to the id of the element before it
		// If id of key element is smaller keep comparing with each of the elements before it
		// Swap the key element with the its previous element if its id is smaller
		while (j >= 0 && array[j].getId() > key.getId())
		{
			// Swap element
			array[j + 1] = array[j];
			// Go to element before
			j--;
		}
		// Insert key element into position where its id is greater than the element before it
		array[j + 1] = key;
	}
}

void outputStudentList(Student* array, int arraySize)
{
	// Loop through given array
	for (int i = 0; i < arraySize; i++)
	{
		// Store Student object at current index
		Student student = array[i];
		// Output the id, name, and score of Student object student neatly formatted
		cout << "    " << student.getId() << " " << setw(10) << student.getName()
			<< " " << student.getScore() << endl;
	}
	// Go to next line for next terminal output
	cout << endl;
}

void showAllCourseLists(struct Course* array, int arraySize)
{
	// Go to next line for readability in terminal
	cout << endl;
	// Loop through given array
	for (int i = 0; i < arraySize; i++)
	{
		// Store struct Course variable at current index
		struct Course course = array[i];
		// Declare initialize variable to store rhe number of students of current course variable
		int courseSize = course.number_of_students;
		// Output the name of current course
		cout << "==========  " << course.title << "  ==========" << endl;
		// Declare and initialize pointer to point to list of current course variable
		Student* list = course.list;
		// Sort the list by id
		insertionSortById(list, courseSize);
		// Go to next line for readability in terminal
		cout << endl;
		// Output the student list
		outputStudentList(list, courseSize);
	}
}


// Task 2: List of Students who take all three courses
int getTotalStudentsWhoTakeAllThreeCourses(struct Course courseOne, struct Course courseTwo, struct Course courseThree)
{
	// Declare and initialize variable to store the number of students in given courseOne
	int courseOneSize = courseOne.number_of_students;
	// Declare and initialize variable to store the number of students in given courseTwo
	int courseTwoSize = courseTwo.number_of_students;
	// Declare and initialize variable to store the number of students in given courseThree
	int courseThreeSize = courseThree.number_of_students;
	// Declare and initialize pointer that points to the list variable of courseOne
	Student* courseOneList = courseOne.list;
	// Declare and initialize pointer that points to the list variable of courseTwo
	Student* courseTwoList = courseTwo.list;
	// Declare and initialize pointer that points to the list variable of courseThree
	Student* courseThreeList = courseThree.list;
	// Declare and initialize variable counter to store number of students who are in all 3 courses
	int total = 0;
	// Loop through courseOne Student list
	for (int i = 0; i < courseOneSize; i++)
	{
		// Loop through courseTwo Student list
		for (int j = 0; j < courseTwoSize; j++)
		{
			// Loop through courseThree Student list
			for (int k = 0; k < courseThreeSize; k++)
			{
				// Store Student object in courseOne list at current i index
				Student fromCourseOne = courseOneList[i];
				// Store Student object in courseOne list at current j index
				Student fromCourseTwo = courseTwoList[j];
				// Store Student object in courseOne list at current k index
				Student fromCourseThree = courseThreeList[k];
				// If the id of Student object  in courseOne is equal to ids of the Student object in 
				// courseTwo and courseThree
				if (fromCourseOne.getId() == fromCourseTwo.getId()
					&& fromCourseOne.getId() == fromCourseThree.getId())
				{
					// Increment total counter
					total++;
				}
			}
		}
	}
	// Return total counter
	return total;
}

struct AllThreeCoursesData* getDataOfStudentsWhoTakeAllThreeCourses(int totalStudents, Course courseOne, 
	Course courseTwo, Course courseThree)
{
	// Declare and initialize variable to store the number of students in courseOne
	int courseOneSize = courseOne.number_of_students;
	// Declare and initialize variable to store the number of students in courseTwo
	int courseTwoSize = courseTwo.number_of_students;
	// Declare and initialize variable to store the number of students in courseThree
	int courseThreeSize = courseThree.number_of_students;
	// Declare and initialize pointer that points to Student list of courseOne
	Student* courseOneList = courseOne.list;
	// Declare and initialize pointer that points to Student list of courseTwo
	Student* courseTwoList = courseTwo.list;
	// Declare and initialize pointer that points to Student list of courseThree
	Student* courseThreeList = courseThree.list;
	// Declare and initialize variable to store the title name of courseOne
	string courseOneTitle = courseOne.title;
	// Declare and initialize variable to store the title name of courseTwo
	string courseTwoTitle = courseTwo.title;
	// Declare and initialize variable to store the title name of courseThree
	string courseThreeTitle = courseThree.title;
	struct AllThreeCoursesData* result = new AllThreeCoursesData[totalStudents]{};
	int resultIndex = 0;
	// Loop through courseOneList
	for (int i = 0; i < courseOneSize; i++)
	{
		// Loop through courseTwoList
		for (int j = 0; j < courseTwoSize; j++)
		{
			// Loop through courseThreeList
			for (int k = 0; k < courseThreeSize; k++)
			{
				// Store Student object in courseOne list at current i index
				Student fromCourseOne = courseOneList[i];
				// Store Student object in courseOne list at current j index
				Student fromCourseTwo = courseTwoList[j];
				// Store Student object in courseOne list at current k index
				Student fromCourseThree = courseThreeList[k];
				// If the id of Student object in courseOne is equal to ids of the Student object in 
				// courseTwo and courseThree
				if (fromCourseOne.getId() == fromCourseTwo.getId()
					&& fromCourseOne.getId() == fromCourseThree.getId())
				{
					// Create a struct AllThreeCoursesData variable
					struct AllThreeCoursesData data = { fromCourseOne.getId(),
						                                fromCourseOne.getName(), 
						                                courseOneTitle, 
						                                fromCourseOne.getScore(), 
						                                courseTwoTitle, 
						                                fromCourseTwo.getScore(), 
						                                courseThreeTitle, 
						                                fromCourseThree.getScore() 
				                                      };
					// Prevents compiler warning
					// If current resultIndex is less than totalStudents
					if (resultIndex < totalStudents)
					{
						// Store created data variable to created 
						// result dynamic array at current resultIndex index
						result[resultIndex] = data;
						// Increment resultIndex
						resultIndex++;
					}
				}
			}
		}
	}
	// Return result dynamic array
	return result;
}

void sortAllThreeCoursesDataArrayById(AllThreeCoursesData* array, int arraySize)
{
	// Declare variables used
	int j;
	// Loop through given array
	for (int i = 1; i < arraySize; i++)
	{
		// Set key to current element
		AllThreeCoursesData key = array[i];
		// Set j to element before current element
		j = i - 1;
		// Compare the id of the key element to the id of the element before it
		// If id of key element is smaller keep comparing with each of the elements before it
		// Swap the key element with the its previous element if its id is smaller
		while (j >= 0 && array[j].id > key.id)
		{
			// Swap element
			array[j + 1] = array[j];
			// Go to element before
			j--;
		}
		// Insert key element into position where its id is greater than the element before it
		array[j + 1] = key;
	}
}

void outputAllThreeCoursesDataArray(AllThreeCoursesData* array, int arraySize)
{
	// Loop through given AllThreeCoursesData dynamic array
	for (int i = 0; i < arraySize; i++)
	{
		// Save struct AllThreeCourseData at current index
		AllThreeCoursesData data = array[i];
		// Output member variables of current AllThreeCoursesData
		// variable neatly to terminal
		cout << "  " << data.id << "  " << setw(10) << data.name
			 << "    " << data.courseOneTitle << "(" << data.courseOneScore << ")"
			 << "  " << data.courseTwoTitle << "(" << data.courseTwoScore << ")" 
			 << "  " << data.courseThreeTitle << "(" << data.courseThreeScore << ")  " << endl;
	}
	// Output newline to terminal for readadbility
	cout << endl;
}

void listOfStudentsWhoTakeAllThreeCourses(struct Course* courseArray)
{
	// Store the first course in given courseArray
	struct Course courseOne = courseArray[0];
	// Store the secound course in given courseArray
	struct Course courseTwo = courseArray[1];
	// Store the third course in given courseArray
	struct Course courseThree = courseArray[2];
	// Declare and initialize variable to store the returned value from function 
	// that counts the number of students that take all 3 courses
	int students = getTotalStudentsWhoTakeAllThreeCourses(courseOne, courseTwo, courseThree);
	// Output new line for readability in terminal
	cout << endl;
	// Output how many studentts take all 3 courses
	cout << "               There are " << students << " students who take 3 courses               " << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	// Output the id, name, and grade in each course of students who take all 3 courses 
	struct AllThreeCoursesData* array = getDataOfStudentsWhoTakeAllThreeCourses(students, courseOne, courseTwo, courseThree);
	sortAllThreeCoursesDataArrayById(array, students);
	outputAllThreeCoursesDataArray(array, students);
	delete[] array;
}


// Task 3: List of students who take 2 courses
bool idExistsInList(Student* list, int listSize, int targetId)
{
	// Loop through given list of Student objects
	for (int i = 0; i < listSize; i++)
	{
		// Set variable to store Student object at current index
		Student student = list[i];
		// If the id of the current student is equal to given targetId
		if (student.getId() == targetId)
		{
			return true;
		}
	}
	// Otherwise return false
	return false;
}

int getTotalStudentsWhoOnlyTakeTwoCourses(Student* listOne, int listOneSize, Student* listTwo, int listTwoSize, 
	Student* listThree, int listThreeSize)
{
	// Declare and Initialize total counter for 
	// number of students who take 2 courses 
	int total = 0;
	// Loop through listOne
	for (int i = 0; i < listOneSize; i++)
	{
		// Loop through listTwo
		for (int j = 0; j < listTwoSize; j++)
		{
			// Save id of current Student object at index i
			int idFromCourseOne = listOne[i].getId();
			// Save id of current Student object at index j
			int idFromCourseTwo = listTwo[j].getId();
			// If the ids are equal and the id does not exist in given listThree
			if (idFromCourseOne == idFromCourseTwo && (!idExistsInList(listThree, listThreeSize, idFromCourseOne)))
			{
				// Increment total counter
				total++;
			}
		}
	}
	// Return total counter
	return total;
}

struct OnlyTwoCoursesData* getDataOfStudentsWhoOnlyTakeTwoCourses(int totalStudents, string courseOneTitle, Student* listOne, 
	  int listOneSize, string courseTwoTitle, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize)
{
	struct OnlyTwoCoursesData* result = new OnlyTwoCoursesData[totalStudents];
	int resultIndex = 0;
	// Loop through listOne
	for (int i = 0; i < listOneSize; i++)
	{
		// Loop through listTwo
		for (int j = 0; j < listTwoSize; j++)
		{
			// Store the id from Student object at current i index of listOne
			int idFromCourseOne = listOne[i].getId();
			// Store the id from Student object at current j index of listTwo
			int idFromCourseTwo = listTwo[j].getId();
			// Store the name from Student object at current i index of listOne
			string nameFromCourseOne = listOne[i].getName();
			// Store the name from Student object at current j index of listTwo
			string nameFromCourseTwo = listTwo[j].getName();
			// Store the score from Student object at current i index of listOne
			int scoreFromCourseOne = listOne[i].getScore();
			// Store the id from Student object at current j index of listTwo
			int scoreFromCourseTwo = listTwo[j].getScore();
			// If the ids are equal and the id does not exist in given listThree
			if (idFromCourseOne == idFromCourseTwo &&
				(!idExistsInList(listThree, listThreeSize, idFromCourseOne)))
			{
				// Create a struct OnlyTwoCoursesData variable
				struct OnlyTwoCoursesData data = { idFromCourseOne, 
					                               nameFromCourseOne, 
					                               courseOneTitle, 
					                               scoreFromCourseOne, 
					                               courseTwoTitle, 
					                               scoreFromCourseTwo 
				                                 };
				// Prevents compiler warning
				// If current resultIndex is less than totalStudents
				if (resultIndex < totalStudents)
				{
					// Store created data variable to created 
					// result dynamic array at current resultIndex index
					result[resultIndex] = data;
					// Increment resultIndex
					resultIndex++;
				}

			}
		}

	}
	// Return result dynamic array
	return result;
}

void sortOnlyTwoCoursesDataArrayById(OnlyTwoCoursesData* array, int arraySize)
{
	// Declare variables used
	int j;
	// Loop through given array
	for (int i = 1; i < arraySize; i++)
	{
		// Set key to current element
		OnlyTwoCoursesData key = array[i];
		// Set j to element before current element
		j = i - 1;
		// Compare the id of the key element to the id of the element before it
		// If id of key element is smaller keep comparing with each of the elements before it
		// Swap the key element with the its previous element if its id is smaller
		while (j >= 0 && array[j].id > key.id)
		{
			// Swap element
			array[j + 1] = array[j];
			// Go to element before
			j--;
		}
		// Insert key element into position where its id is greater than the element before it
		array[j + 1] = key;
	}


}

void outputOnlyTwoCoursesDataArray(OnlyTwoCoursesData* array, int arraySize)
{
	// Loop through OnlyTwoCoursesData dynamic array
	for (int i = 0; i < arraySize; i++)
	{
		// Save OnlyTwoCourseData variable at current index
		OnlyTwoCoursesData data = array[i];
		// Output member variables of current OnlyTwoCoursesData 
		// variable neatly to terminal
		cout << " " << data.id <<  " " << setw(12) << data.name << "    " << data.courseOneTitle << "(" 
			 << data.courseOneScore << ")" << "    " << data.courseTwoTitle << "(" << data.courseTwoScore 
			 << ")" << endl;
	}
	cout << endl;
}

void listOfStudentsWhoTakeTwoCourses(struct Course* courseArray)
{
	// Save the struct Course variables into seperate variables
	struct Course courseOne = courseArray[0];
	struct Course courseTwo = courseArray[1];
	struct Course courseThree = courseArray[2];

	// Get number of students who are in courseOne and courseTwo but not in courseThree
	int studentsOne = getTotalStudentsWhoOnlyTakeTwoCourses(courseOne.list, courseOne.number_of_students, 
		courseTwo.list, courseTwo.number_of_students, courseThree.list, courseThree.number_of_students);
	// Output newline to terminal for readability
	cout << endl;
	// Output number of students who are in courseOne and courseTwo but not in courseThree
	cout << "  There are " << studentsOne << " students who take " << courseOne.title 
		<< " and " << courseTwo.title << endl;
	cout << "-----------------------------------------------------------------" << endl;
	// Get data of the Students objects who are in courseOne and courseTwo but not in courseThree as dynamic array
	struct OnlyTwoCoursesData* data = getDataOfStudentsWhoOnlyTakeTwoCourses(studentsOne, courseOne.title, courseOne.list, 
		courseOne.number_of_students, courseTwo.title, courseTwo.list, courseTwo.number_of_students, 
		courseThree.list, courseThree.number_of_students);
	// Sort the data dynamic array
	sortOnlyTwoCoursesDataArrayById(data, studentsOne);
	// Output the elements in data dynamic array neatly to terminal
	outputOnlyTwoCoursesDataArray(data, studentsOne);
	// Deallocate data dynamic array
	delete[] data;
	 
	// Store number of students who are in courseOne and courseThree but not in courseTwo
	int studentsTwo = getTotalStudentsWhoOnlyTakeTwoCourses(courseOne.list, courseOne.number_of_students, 
		courseThree.list,courseThree.number_of_students, courseTwo.list, courseTwo.number_of_students);
	// Output number of students who are in courseOne and courseThree but not in courseTwo
	cout << "  There are " << studentsTwo << " students who take " << courseOne.title 
		<< " and " << courseThree.title << endl;
	cout << "-----------------------------------------------------------------" << endl;

	// Get data of the Students objects who are in courseOne and courseThree but not in courseTwo as dynamic array
	data = getDataOfStudentsWhoOnlyTakeTwoCourses(studentsTwo, courseOne.title, courseOne.list,
		  courseOne.number_of_students,courseThree.title, courseThree.list, courseThree.number_of_students, 
		courseTwo.list, courseTwo.number_of_students);
	// Sort the data dynamic array
	sortOnlyTwoCoursesDataArrayById(data, studentsTwo);
	// Output the elements from data dynamic array
	outputOnlyTwoCoursesDataArray(data, studentsTwo);
	// Deallocate data dynamic array
	delete[] data;
	 
	// Store number of students who are in courseTwo and courseThree but not in courseOne
	int studentsThree = getTotalStudentsWhoOnlyTakeTwoCourses(courseTwo.list, courseTwo.number_of_students, 
		courseThree.list,courseThree.number_of_students, courseOne.list, courseOne.number_of_students);
	// Output number of students who are in courseTwo and courseThree but not in courseOne
	cout << "  There are " << studentsThree << " students who take " << courseTwo.title 
		<< " and " << courseThree.title << endl;
	cout << "-----------------------------------------------------------------" << endl;
	// Get data of the Students objects who are in courseTwo and courseThree but not in courseOne as dynamic array
	data = getDataOfStudentsWhoOnlyTakeTwoCourses(studentsThree, courseTwo.title, courseTwo.list, 
		courseTwo.number_of_students, courseThree.title, courseThree.list, courseThree.number_of_students, 
		courseOne.list, courseOne.number_of_students);
	// Sort the data dynamic array
	sortOnlyTwoCoursesDataArrayById(data, studentsThree);
	// Output the data dynamic array
	outputOnlyTwoCoursesDataArray(data, studentsThree);
	// Deallocate the data dynamic array
	delete[] data;
}


// Task 4: Print out top scores for each course
void insertionSortByScore(Student* array, int arraySize)
{
	// Declare variables used
	int j;
	// Loop through given array
	for (int i = 1; i < arraySize; i++)
	{
		// Set key to current element
		Student key = array[i];
		// Set j to element before current element
		j = i - 1;
		// Compare the score of the key element to the score of the element before it
		// If score of key element is smaller keep comparing with each of the elements before it
		// Swap the key element with the its previous element if its score is smaller
		while (j >= 0 && array[j].getScore() > key.getScore())
		{
			// Swap element
			array[j + 1] = array[j];
			// Go to element before
			j--;
		}
		// Insert key element into position where its id is greater than the element before it
		array[j + 1] = key;
	}
}

int* getStudentGrades(Student* array, int arraySize)
{
	int* newArray = new int[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		newArray[i] = array[i].getScore();
	}
	return newArray;
}

void removeDuplicateScoresInGivenArray(int* array, int& arraySize)
{
	// Declare and initialize counter to keep 
	// track of number of elements removed
	int removed = 0;
	// Loop through given int dynamic array to second to last element
	for (int i = 0; i < arraySize - 1; i++)
	{
		// If the current element is not equal to adjacent element
		if (array[i] != array[i + 1])
		{
			// Recopy the element into the index of removed
			array[removed] = array[i];
			// Increment removed index
			removed++;
		}
	}
	// Last element of array will always be the same
	array[removed] = array[arraySize - 1];
	// Change arraySize to be elements removed plus 1
	arraySize = removed + 1;
}

void printStudentsWithGivenScore(Student* array, int arraySize, int targetScore)
{
	// Loop through given Student dynamic array
	for (int i = 0; i < arraySize; i++)
	{
		// Store Student object at current index
		Student student = array[i];
		// If the score of current Student object is equal to given score
		if (student.getScore() == targetScore)
		{
			// Output id and name of Student object neatly formatted
			cout << "    " << student.getId() << "  " << setw(10) << student.getName() << endl;
		}
	}
}

void printOutTopNStudentsForEachCourse(Course* courseArray, int arraySize, int n)
{
	// Skip a line in terminal for readability
	cout << endl;
	// Store the value of n as it will change later
	int initialN = n;
	// Looop through given courseArray
	for (int i = 0; i < arraySize; i++)
	{
		// Store course at current index 
		Course course = courseArray[i];
		// Store the title of the current course
		string title = course.title;
		// Store the number of students in current course
		int courseSize = course.number_of_students;
		// Declare and initialize pointer that points to the Student list of current course
		Student* list = course.list;
		// Sort the list by id
		insertionSortById(list, courseSize);
		// Sort the list by score
		insertionSortByScore(list, courseSize);
		// Store initialize courseSize to another variable as it will change later 
		int copyOfCourseSize = courseSize;
		// Get the grades of students as an integer dynamic array
		int* studentGrades = getStudentGrades(list, copyOfCourseSize);
		// Remove the duplicates from the integer dynamic array
		removeDuplicateScoresInGivenArray(studentGrades, copyOfCourseSize);
		// Want to make this function more universal 
		// and not just for top 3 students
		// For situations when there is not enough students in the course 
		// to print out the top n students
		if (n > copyOfCourseSize)
		{
			// Make n the number of students in the course
			n = copyOfCourseSize;
		}

		// If given n is 1
		if (n == 1)
		{
			// Output course title and Top Score
			cout << "[  " << title << " Top Score  ]" << endl;
		}
		else if (n == 3)
		{
			cout << "[  " << title << " Top Three Scores  ]" << endl;
		}
		// Otherwise
		else
		{
			// Output the course title and Top n Scores
			cout << "[  " << title << " Top " << n << " Scores  ]" << endl;
		}
		// Declare and initialize variable to store the scores seen
		int scoresSeen = 0;
		// Store index of last element in integer dynamic array
		// Traverse integer dynamic array backwards
		int arrayIndex = copyOfCourseSize - 1;
		// Keep looping while scoreSeen is less than n
		while (scoresSeen < n)
		{
			// Store current score
			int score = studentGrades[arrayIndex];
			// Output it
			cout << scoresSeen + 1 << ".  " << score << endl;
			// Output the Student objects with the current score
			printStudentsWithGivenScore(list, courseSize, score);
			// Increment scoresSeen
			scoresSeen++;
			// Go to next element
			arrayIndex--;
		}
		// Output newline to terminal for readability
		cout << endl;
		// Deallocate integer dynamic array
		delete[] studentGrades;
		// Reset given to value of n before loop as it would have changed
		n = initialN;
	}
}


// Clean up
void deallocateStudentListInCourseArray(struct Course* courseArray, int arraySize)
{
	// Loop through given courseArray 
	for (int i = 0; i < arraySize; i++)
	{
		// Declare and store current element of courseArray
		struct Course course = courseArray[i];
		// Deallocate thst Student dynamic array pointed by the list of the current course struct
		delete[] course.list;
	}
}