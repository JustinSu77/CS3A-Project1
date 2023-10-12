/**
	Date: 10/1/2023
	By: Justin Su
	Purpose: main.cpp for Project #1
**/
#include "Student.h"
 
// Structure to store data of a course
struct Course
{
	string title;
	int number_of_students;
	Student* list;
};
// Text files

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
	Result: Function showMenu is run and one of the 5 main operations 
			of this program is run based on the choice of the user
**/
void run(struct Course* array, int arraySize);

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


// List all students who take all 3 courses


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



// List of students who take only take 2 courses
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
	Purpose: Function to be called when user chooses option 2: List of students who take two courses.
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


/**
	Purpose: Function to be called when user chooses the option of List of students who take two courses.
	Input: courseArray is array of struct Course variables
	Input requirements: Given courseArray is filled with struct Course variables with data from given text files
	Result: Outputs the number of id that exists in all 3 courses.
			Outputs the id, name, and score of the Student object with the id that 
			exists in the Student list of all courses for every course pair
**/
void listOfStudentsWhoTakeTwoCourses(struct Course* courseArray);


// Print out top three students for each course
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
void printOutTopNStudentsForEachCourse(struct Course* courseArray, int arraySize,int n);

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
	run(courseArray, ARRAY_SIZE);
	
	// Deallocate string dynamic array
	delete[] filesToOpen;
	// Deallocate the student dynamic array in each course element of courseArray
	deallocateStudentListInCourseArray(courseArray, ARRAY_SIZE);
	
	return 0;
}

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
		// Declare and initialize variable to store current element
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

void fillCourseArrayFromFiles(struct Course* courseArray, string* filesToOpen, int arraySize)
{
	// Declare ifstream object to read file
	ifstream inputFile;
	// Loop through given courseArray
	for (int i = 0; i < arraySize; i++)
	{
		// Declare and initialize variable for file name at current index of fileToOpen array
		string fileName = filesToOpen[i];
		// Open the file 
		inputFile.open(fileName);
		// Declare variables used to store the data from first line of text file
		int numberOfStudents = 0;
		string title = "";
		// Read in the data
		inputFile >> title >> numberOfStudents;
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

void showMenu(char& userChoice)
{
	// Prompt user for the 5 tasks to run to this program
	cout << "================= Menu =====================" << endl;
	cout << "  1. Show all course lists (sorting)" << endl;
	cout << "  2. List of students who take all courses" << endl;
	cout << "  3. List of students who take two courses" << endl;
	cout << "  4. Print out top three scores for each course" << endl;
	cout << "  5. Exit" << endl;
	cout << "  ----> Select : ";
	// Save user choice as int reference to be passed to the run function
	cin >> userChoice;

}

void run(struct Course* array, int arraySize)
{
	// Declare and initialize variable to store the user choice
	char userChoice = ' ';
	// Prompt user for the 5 options to run
	showMenu(userChoice);
	int userChoiceAsInt = static_cast<int>(userChoice);
	// If user enters an invalid choice
	if (userChoiceAsInt < 1 || userChoiceAsInt > 5)
	{
		// Skip a line in terminal for readability
		cout << endl;
		// Notify
		cout << "Invalid option! Exiting program!" << endl;
		return;
	}
	// Run the functions corresponding to the user choice
	switch (userChoiceAsInt)
	{
	case 1:
		// Run function that shows the student lists in all 3 courses sorted by id in ascending order
		showAllCourseLists(array, arraySize);
		// Prevent fall through and exit switch when function is done
		break;
	case 2:
		// Run function to output all the Students who are in all three courses
		listOfStudentsWhoTakeAllThreeCourses(array);
		// Prevent fall through and exit switch when function is done
		break;
	case 3:
		// Run function to output all the Students who take 2 courses but is not in the third course
		listOfStudentsWhoTakeTwoCourses(array);
		// Prevent fall through and exit switch when function is done
		break;
	case 4:
		// Run function to output the 3 Students from each course with the highest score
		printOutTopNStudentsForEachCourse(array, arraySize, 3);
		// Prevent fall through and exit switch when function is done
		break;
	default:
		// If 5 is chosen, exit program
		cout << "  Exiting....";
		cout << endl;
	}
}


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
		cout << "    " << student.getId() << setw(10) << student.getName() 
			<< setw(4) << student.getScore() << endl;
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

int totalStudentsWhoTakeAllThreeCourses(struct Course courseOne, struct Course courseTwo, struct Course courseThree)
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
				// If the id of Student object  in courseOne is equal to ids of the Student object in courseTwo and courseThree
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

void outputStudentsWhoTakeAllThreeCourses(Course courseOne, Course courseTwo, Course courseThree)
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
				// If the id of Student object in courseOne is equal to ids of the Student object in courseTwo and courseThree
				if (fromCourseOne.getId() == fromCourseTwo.getId()
					&& fromCourseOne.getId() == fromCourseThree.getId())
				{
					// Output the id, name of Student, title of courseOne, score in course one, 
					// title of courseTwo, score in courseTwo, title of courseThree, and score in courseThree neatly formatted
					cout << "  " << fromCourseOne.getId() << setw(10) << fromCourseOne.getName()
						<< " " << courseOneTitle << "(" << fromCourseOne.getScore() << ")"
						<< "  " << courseTwoTitle << "(" << fromCourseTwo.getScore() << ")" << "  "
						<< courseThreeTitle << "(" << fromCourseThree.getScore() << ")  " << endl;

				}
			}
		}
	}

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
	int students = totalStudentsWhoTakeAllThreeCourses(courseOne, courseTwo, courseThree);
	// Output new line for readability in terminal
	cout << endl;
	// Output how many studentts take all 3 courses
	cout << "    There are " << students << " students who take 3 courses      " << endl;
	cout << "=================================================" << endl;
	// Output the id, name, and grade in each course of students who take all 3 courses 
	outputStudentsWhoTakeAllThreeCourses(courseOne, courseTwo, courseThree);
}

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


int totalStudentsWhoTakeTwoCourses(Student* listOne, int listOneSize, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize)
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

void outputStudentsWhoTakeTwoCourses(string courseOneTitle, Student* listOne, int listOneSize, string courseTwoTitle, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize)
{
	// Sort listOne in ascending order by id
	insertionSortById(listOne, listOneSize);
	// Sort listTwo in ascending order by id
	insertionSortById(listTwo, listTwoSize);
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
				// Output the id, name, title of courseOne, score in courseOne, title of CourseTwo, and score in courseTwo of Student object that is in listOne and listTwo but not in listThree neatly formatted
				cout << " " << idFromCourseOne << setw(10) << nameFromCourseOne << setw(8) << courseOneTitle << "(" << scoreFromCourseOne << ")" << setw(8) << courseTwoTitle << "(" << scoreFromCourseTwo << ")" << endl;
			}
		}

	}

}

void listOfStudentsWhoTakeTwoCourses(struct Course* courseArray)
{
	struct Course courseOne = courseArray[0];
	struct Course courseTwo = courseArray[1];
	struct Course courseThree = courseArray[2];
	 
	// Store number of students who are in courseOne and courseTwo but not in courseThree
	int studentsOne = totalStudentsWhoTakeTwoCourses(courseOne.list, courseOne.number_of_students, courseTwo.list, courseTwo.number_of_students, courseThree.list, courseThree.number_of_students);
	cout << endl;
	// Output number of students who are in courseOne and courseTwo but not in courseThree
	cout << "  There are " << studentsOne << " students who take " << courseOne.title << " and " << courseTwo.title << endl;
	cout << "---------------------------------------------" << endl;
	// Output the Student objects who are in courseOne and courseTwo but not in courseThree
	outputStudentsWhoTakeTwoCourses(courseOne.title, courseOne.list, courseOne.number_of_students, courseTwo.title, courseTwo.list, courseTwo.number_of_students, courseThree.list, courseThree.number_of_students);
	// Skip a line in terminal for readability
	cout << endl;
	// Store number of students who are in courseOne and courseThree but not in courseTwo
	int studentsTwo = totalStudentsWhoTakeTwoCourses(courseOne.list, courseOne.number_of_students, courseThree.list, courseThree.number_of_students, courseTwo.list, courseTwo.number_of_students);
	// Output number of students who are in courseOne and courseThree but not in courseTwo
	cout << "  There are " << studentsTwo << " students who take " << courseOne.title << " and " << courseThree.title << endl;
	cout << "---------------------------------------------" << endl;
	// Output the Student objects who are in courseOne and courseThree but not in courseTwo
	outputStudentsWhoTakeTwoCourses(courseOne.title, courseOne.list, courseOne.number_of_students, courseThree.title, courseThree.list, courseThree.number_of_students, courseTwo.list, courseTwo.number_of_students);
	// Skip a line in terminal for readability
	cout << endl;
	// Store number of students who are in courseTwo and courseThree but not in courseOne
	int studentsThree = totalStudentsWhoTakeTwoCourses(courseTwo.list, courseTwo.number_of_students,courseThree.list, courseThree.number_of_students, courseOne.list, courseOne.number_of_students);
	// Output number of students who are in courseTwo and courseThree but not in courseTwo
	cout << "  There are " << studentsThree << " students who take " << courseTwo.title << " and " << courseThree.title << endl;
	cout << "---------------------------------------------" << endl;
	// Output the Student objects who are in courseOne and courseThree but not in courseTwo
	outputStudentsWhoTakeTwoCourses(courseTwo.title, courseTwo.list, courseTwo.number_of_students, courseThree.title, courseThree.list, courseThree.number_of_students, courseOne.list, courseOne.number_of_students);
}

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
			cout << "    " << student.getId() << setw(10) << student.getName() << endl;
		}
	}
}

void printOutTopNStudentsForEachCourse(Course* courseArray, int arraySize, int n)
{
	// Skip a line in terminal for readability
	cout << endl;
	// Loop through 
	for (int i = 0; i < arraySize; i++)
	{
		// Store course at current index 
		Course course = courseArray[i];
		// Store the title of the current course
		string title = course.title;
		// Store the number of students in current course
		int courseSize = course.number_of_students;
		// Want to make this function more universal and not just for top 3 students
		// For situations when there is not enough students in the course to print out the top n students
		if (courseSize < n)
		{
			// Make n the number of students in the course
			n = courseSize;
		}
		// Declare and initialize pointer that points to the Student list of current course
		Student* list = course.list;
		// Sort the list by id
		insertionSortById(list, courseSize);
		// Sort the list by score
		insertionSortByScore(list, courseSize);
		// If given n is 3
		if (n == 3)
		{
			// Output course title and Top Three Scores
			cout << "[  " << title << " Top Three Scores  ]" << endl;
		}
		// If given n is 1
		else if (n == 1)
		{
			// Output course title and Top Score
			cout << "[  " << title << " Top Score  ]" << endl;
		}
		// Otherwise
		else
		{
			// Output the course title and Top n Scores
			cout << "[  " << title << " Top " << n << " Scores  ]" << endl;
		}
		// Declare and initialize couner variable to keep track of scores seen
		int scoresSeen = 0;
		// Declare and initialize index that to traverse array backwards
		int index = courseSize - 1;
		// Declare and initialize boolean array to keep track of value seen
		bool scoreSeen[101] = {};
		// Keep looping while scoreSeen counter is less than given n
		while (scoresSeen < n)
		{
			// Store the score of the current Student object
			int score = list[index].getScore();
			// If score has not been seen
			if (scoreSeen[score - 1] == false)
			{
				// Output scoreSeen counter and the score
				cout << (scoresSeen + 1) << ".  " << score << endl;
				// Output the students with the score
				printStudentsWithGivenScore(list, courseSize, score);
				// Mark score as seen
				scoreSeen[score - 1] = true;
				// Increment score seen
				scoresSeen++;
			}
			// Decrement index 
			index--;
		}
		// Output newline to terminal for readability
		cout << endl;
	}
}

 