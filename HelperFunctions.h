#pragma once
#include "CourseStruct.h"

// Files
/**
	Purpose: Prompt user for name of file to be opened and save to string dynamic array.
	Input: filesToOpen as string dynamic array
		   arraySize as number of elements that will be in filesToOpen
	Input Requirements: Given array size should be greater than 0
						Number of elements in filesToOpen should be equal to arraySize
	Result: Given string dynamic array filesToOpen is filled with file names from user
**/
void getFilesToOpen(string* filesToOpen, int arraySize);

/**
	Purpose: Open each element in given string dynamic array as a text file and exits program
			 with code 1 if the file opened does fails to open
	Input: filesToOpen as string dynamic array
		   arraySize as number elements in filesToOpen as int
	Input Requirements: Given arraySize shoud be greater than 0
						Number of elements in filesToOpen should be equal to arraySize
						filesToOpen is a dynamic array with type string
						arraySize is greater than 0
						arraySize has type of int
	Result: If file fails to be opened, exit program with code 1
**/
void checkIfFilesExist(string* filesToOpen, int arraySize);


// Create data structure
/**
	Purpose: Fill given courseArray from text files with file names from given filesToOpen.
	Input: courseArray as a array of struct Course
		   fileName as dynamic array of string
		   arraySize as number of elements in both given arrays
	Input Requirements: arraySize should be greater than 0
						courseArray and filesToOpen should have the same number of elements
						courseArray is an array with type struct Course
						fileName has tyoe of string
						arraySize has type of int
	Result: Given courseArray is filled with struct Course variables with
			their title, number_of_students, and list data from given text files
**/
void fillCourseArrayFromFiles(struct Course* courseArray, string* filesToOpen, int arraySize);


// User Interaction
/**
	Purpose: Promp user with a menu with choices numbered 1-5. Store user input to a int reference that can
			 be used in another function to do something with the int reference passed.
	Input: userChoice as char reference
	Input Requirements: Given userChoice is an integer
	Result: The value user entered after being prompted is the value of the given userChoice reference
**/
void showMenu(char& userChoice);

/**
	Purpose: Contains the main operational functions of this program.
	Input: array as struct Course array
		   arraySize as number of elements in array
	Input Requirements: Number of elements in array should be equal to arraySize
						array has type struct Course
						arraySize is greater than 0
						arraySize is an int
	Result: Function showMenu is executed and one of the 5 main operations
			of this program is run based on the choice of the user
			If an invalid option is selected, notify user and exit program
**/
void runProgram(struct Course* array, int arraySize);

//Tasks

/**
	Purpose: Uses Insertion Sort to sort a dynamic array of Student objects
			 based on their id member variable in asecending order.
	Input: array as a dynamic array with type Student
		   arraySize as number of elements in array as int
	Input Requirement: array has type of Student
					   Number of elements in array is equal to arraySize
					   arraySize is greater than 0
					   arraySize is an integer
	Result: The given dynamic array or a pointer to the dynamic array has
			Student objects that is sorted in asecending order based on their id
**/


// Task 1: Show All Course Lists
void insertionSortById(Student* array, int arraySize);
/**
	Purpose: Outputs the id, name, and score of given Student dynamic array to terminal.
	Input: array as dynamic array with type of Student
		   arraySize as number of elements in given array
	Input Requirements: array has type of Student
						Number of elements in given array should be equal to given arraySize
						arraySize is greater than 0
						arraySize has type of int
	Result: The id, name, and score of each Student object
			in given array is outputted with spaces in between to terminal
**/
void outputStudentList(Student* array, int arraySize);

/**
*	Purpose: Function to be called for option of Show all courses lists (sorting).
	Input: array as array with type of struct Course
		   arraySize as number of elements in given array
	Input Requirements: array  has type of Student
						Number of elements in array is equal to arraySize
						arraySize is greater than 0
						arraySize is an int
	Result: The title of each course in given array and the Student list
			of each course sorted in ascending order by id is outputted to terminal

**/
void showAllCourseLists(struct Course* array, int arraySize);


// Task 2: List of students who take all courses
/**
	Purpose: Count and return many times a id value of a Student object appears in the Student list of the given courses.
	Input: courseOne as struct Course variable
		   courseTwo as struct Course variable
		   courseThree as struct Course variable
	Input requirements: struct variables  of given courseOne, courseTwo, and courseThree are initialized
	Result: The number of students whose id exists in the Student list of courseOne, courseTwo, and courseThree
**/
int totalStudentsWhoTakeAllThreeCourses(struct Course courseOne, struct Course courseTwo, struct Course courseThree);

/**
	Purpose: Output the id, name, and score of the Student object whose id exists in the Student lists of the given struct Course		   variables courseOne, courseTwo, and courseThree.
	Input: courseOne as struct Course variable
		   CourseTwo as struct Course variable
		   courseThree as struct Course variable
	Input requirements: struct variables of given courseOne, courseTwo, and courseThree are initialized
	Result: The id, name, and score of Student object that exists in given
			struct Course variables courseOne, courseTwo, courseThree
**/
void outputStudentsWhoTakeAllThreeCourses(struct Course courseOne, struct Course courseTwo, struct Course courseThree);


/**
	Purpose: Function to be called when user chooses the option of List of students who take all courses.
	Input: courseArray as array with type of struct Course
	Input requirements: Given courseArray is filled with struct Course variables with data from given text files
	Result: The number of id that exists in the lists of all the courses is outputted to terminal.
			The id, name, and score from all three courses of Student objects
			whose id exists in list of all the courses is outputted	to the terminal in ascending order based on id
**/
void listOfStudentsWhoTakeAllThreeCourses(struct Course* courseArray);



// Task 3: List of students who take only take 2 courses
/**
	Purpose: Return whether or not whether a Student object in given Student dynamic array has an id the same as given targetId.
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
	Purpose: Return the number of students who are in given Student dynamic arrays listOne and listTwo but not in given listThree.
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

int totalStudentsWhoTakeTwoCourses(Student* listOne, int listOneSize, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize);

/**
	Purpose: Function to be called when user chooses option 3: List of students who take two courses.
	Input: courseOneTitle as string
		   listOne as dynamic array of Student objects
		   listOneSize as number of elements in listOne
		   courseTwoTitle as string
		   listTwo as dynamic array of Student objects
		   listTwoSize as number of elements in listTwo
		   listThree as dynamic array of Student objects
		   listThreeSize as dynamic array of Student object
	Input Requirement: courseOneTitle should be a string
					   courseTwoTitle should be a string
					   Number of elements in listOne should be equal to listOneSize
					   Number of elements in listTwo should be equal to listTwoSize
					   Number of elements in listThree should be equal to listThreeSize
					   listOneSize should be an integer
					   listTwoSize should be an integer
					   listThreeSize should be an integer
					   listOne should be a pointer to a string dynamic array
					   listTwo should be a pointer to a string dynamic array
					   listThree should be a pointer to a string dynamic array
	Result: The number of students who take each pairing of courses is outputted.
			For each pairing, the id, name, name of each course and the score of the Student object that exists in listOne and listTwo but not
			listThree is outputted to the screen.
**/
void outputStudentsWhoTakeTwoCourses(string courseOneTitle, Student* listOne, int listOneSize, string courseTwoTitle, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize);


// Task 4: Print out top scores for each course
/**
	Purpose: Function to be called when user chooses the option of List of students who take two courses.
	Input: courseArray is array of struct Course variables
	Input requirements: Given courseArray is filled with struct Course variables with data from given text files
	Result: Outputs the number of id that exists in all 3 courses.
			Outputs the id, name, and score of the Student object with the id that
			exists in the Student list of all courses for every course pair
**/
void listOfStudentsWhoTakeTwoCourses(struct Course* courseArray);


// Task 4: Print out top three students for each course
/**
	Purpose: Helper function for option 4
	Input: array as a dynamic array of Student objects
		   arraySize as the number of elements in given array
	Input Requirement: array is a dynamic array of Student object
					   Number of elements in array should be equal to arraySize
					   arraySize is an integer
	Result: Given dynamic array of Student objects are sorted in ascending order by their score.
**/
void insertionSortByScore(Student* array, int arraySize);
/**
	Purpose: Helper function for option 4.
	Input: array as dynamic array of Student objects
		   arraySize as number of elements in given array
		   targetScore as target score for Student objects to have to be outputted to terminal
	Input Requirement: array is a dynamic array of Student objects
					   Number of elements in array is equal to given arraySize
					   arraySize is an integer
					   targetScore is an integer
	Result: The id, name, and score of the Student objects that the same score as given score is ouputted to the terminal
**/
void printStudentsWithGivenScore(Student* array, int arraySize, int targetScore);

/**
	Purpose: Return a pointer to dynamic array filled with scores from given Student array.
	Input: array as dynamic array of type Student
		   arraySize number of elements in given array as int
	Input Requirement: Number of elements in given array should be equal to arraySize
					   arraySize should be >= 0
	Result: Return a pointer to dynamic array filled with scores from given Student array
**/
int* getStudentGrades(Student* array, int arraySize);


/**
	Purpose: Delete duplicate scores in sorted integer dynamic array.
	Input: array as int dynamic array
		   arraySize as number of elements in given array as int reference
	Input Requirements: Given array is sorted in ascending order
						Number of elements in given array is equal to given arraySize
						arraySize should be >= 0
	Result: Duplicate scores in given array are removed
			arraySize is changed to number of elements removed + 1
**/
void  deleteDuplicateScoresInGivenArray(int* array, int& arraySize);

/**
	Purpose: Function to run when user chooses option 4: Print out top three scores for each course.
	Input: courseArray as array of struct Course variables
		   arraySize as number of elements in courseArray
		   n as the number of students to print out
	Input Requirement: courseArray should be a array of struct Course variables
					   Number of elemenets in courseArray should be arraySize
					   n should be an integer
	Result: Outputs the title of the course
			Prints out the top 3 score in each Student list and the id and name of each Student object in the Student list of each course
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