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
	Input: userChoice as int reference
	Input Requirements: Given userChoice is an integer
	Result: The result user entered after being prompted is the value of the given userChoice reference 
**/
void showMenu(int& userChoice);

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
	Purpose: Return whether or not whether a Student object in given Student dynamic array has an id the same as given id.
	Input: list as dynamic array with Student data type
		   listSize as the number of elements in given list
		   id as the id to search for in given list
	Input Requirement: Number of elements in given list should be the same as listSize
					   listSize should be an integer
					   id should be an integer
	Result: If there is a Student object with id private member variable equal to given id return true
		    Otherwise return false
**/
bool idExistsInList(Student* list, int listSize, int id);
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
		   score as target score for Student objects to have to be outputted to terminal
	Input Requirement: array is a dynamic array of Student objects
					   Number of elements in array is equal to given arraySize
					   arraySize is an integer
					   score is an integer
	Result: The id, name, and score of the Student objects that the same score as given score is ouputted to the terminal
**/
void printStudentsWithGivenScore(Student* array, int arraySize, int score);

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


// Test functions
void outputCourseArray(struct Course* courseArray, int arraySize);

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
		struct Course newCourse = {title, numberOfStudents, studentArray};
		// Set current index of courseArray to created course 
		courseArray[i] = newCourse;
		// Close ifstream object
		inputFile.close();
	}
}

void showMenu(int& userChoice)
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
	int userChoice = 0;
	// Prompt user for the 5 options to run
	showMenu(userChoice);
	// If user enters an invalid choice
	if (userChoice < 1 || userChoice > 5)
	{
		// Skip a line in terminal for readability
		cout << endl;
		// Notify
		cout << "Invalid option! Exiting program!" << endl;
		return;
	}
	// Run the functions corresponding to the user choice
	switch (userChoice)
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
	}
}

void insertionSortById(Student* list, int arraySize)
{
	int j = 0;
	for (int i = 1; i < arraySize; i++)
	{
		Student key = list[i];
		j = i - 1;
		while (j >= 0 && list[j].getId() > key.getId())
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
	}
}
void outputStudentList(Student* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		Student student = array[i];
		cout << "    " << student.getId() << setw(10) << student.getName() << setw(4) << student.getScore() << endl;
	}
	cout << endl;
}

void showAllCourseLists(struct Course* array, int arraySize)
{
	cout << endl;

	for (int i = 0; i < arraySize; i++)
	{
		struct Course course = array[i];
		int courseSize = course.number_of_students;
		cout << "==========  " << course.title << "  ==========" << endl;
		Student* list = course.list;
		insertionSortById(list, courseSize);
		cout << endl;
		outputStudentList(list, courseSize);
	}
}


void deallocateStudentListInCourseArray(struct Course* courseArray, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		struct Course course = courseArray[i];
		delete[] course.list;
	}

}



void printOutTopNStudentsForEachCourse(Course* courseArray, int arraySize, int n)
{
	cout << endl;
	for (int i = 0; i < arraySize; i++)
	{
		Course course = courseArray[i];
		string title = course.title;
		int courseSize = course.number_of_students;
		if (courseSize < n)
		{
			n = courseSize;
		}
		Student* list = course.list;
		insertionSortById(list, courseSize);
		insertionSortByScore(list, courseSize);
		cout << "[  " << title << " Top Three Scores  ]" << endl;
		int scoresSeen = 0;
		int index = courseSize - 1;
		bool scoreSeen[101] = {};
		while (scoresSeen < n)
		{
			int score = list[index].getScore();
			if (scoreSeen[score - 1] == false)
			{
				cout << (scoresSeen + 1) << ".  " << score << endl;
				printStudentsWithGivenScore(list, courseSize, score);
				scoreSeen[score - 1] = true;
				scoresSeen++;
			}
			index--;
		}
		cout << endl;
	}

}

void insertionSortByScore(Student* array, int arraySize)
{
	int j = 0;
	for (int i = 1; i < arraySize; i++)
	{
		Student key = array[i];
		j = i - 1;
		while (j >= 0 && array[j].getScore() > key.getScore())
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}



void printStudentsWithGivenScore(Student* array, int arraySize, int score)
{
	for (int i = 0; i < arraySize; i++)
	{
		Student student = array[i];
		if (student.getScore() == score)
		{
			cout << "    " << student.getId() << setw(10) << student.getName() << endl;
		}
	}
}







void listOfStudentsWhoTakeAllThreeCourses(struct Course* courseArray)
{
	struct Course courseOne = courseArray[0];
	struct Course courseTwo = courseArray[1];
	struct Course courseThree = courseArray[2];
	int students = totalStudentsWhoTakeAllThreeCourses(courseOne, courseTwo, courseThree);
	cout << endl;
	cout << "    There are " << students << " students who take 3 courses      " << endl;
	cout << "=================================================" << endl;
	outputStudentsWhoTakeAllThreeCourses(courseOne, courseTwo, courseThree);
}

int totalStudentsWhoTakeAllThreeCourses(struct Course courseOne, struct Course courseTwo, struct Course courseThree)
{

	int courseOneSize = courseOne.number_of_students;
	int courseTwoSize = courseTwo.number_of_students;
	int courseThreeSize = courseThree.number_of_students;
	Student* courseOneList = courseOne.list;
	Student* courseTwoList = courseTwo.list;
	Student* courseThreeList = courseThree.list;
	int total = 0;
	for (int i = 0; i < courseOneSize; i++)
	{
		for (int j = 0; j < courseTwoSize; j++)
		{
			for (int k = 0; k < courseThreeSize; k++)
			{
				Student courseOneStudent = courseOneList[i];
				Student courseTwoStudent = courseTwoList[j];
				Student courseThreeStudent = courseThreeList[k];
				if (courseOneStudent.getId() == courseTwoStudent.getId()
					&& courseOneStudent.getId() == courseThreeStudent.getId())
				{
					total++;
				}
			}
		}
	}
	return total;
}

void outputStudentsWhoTakeAllThreeCourses(Course courseOne, Course courseTwo, Course courseThree)
{
	int courseOneSize = courseOne.number_of_students;
	int courseTwoSize = courseTwo.number_of_students;
	int courseThreeSize = courseThree.number_of_students;
	Student* courseOneList = courseOne.list;
	Student* courseTwoList = courseTwo.list;
	Student* courseThreeList = courseThree.list;
	string courseOneTitle = courseOne.title;
	string courseTwoTitle = courseTwo.title;
	string courseThreeTitle = courseThree.title;
	for (int i = 0; i < courseOneSize; i++)
	{
		for (int j = 0; j < courseTwoSize; j++)
		{
			for (int k = 0; k < courseThreeSize; k++)
			{
				Student fromCourseOne = courseOneList[i];
				Student fromCourseTwo = courseTwoList[j];
				Student fromCourseThree = courseThreeList[k];
				if (fromCourseOne.getId() == fromCourseTwo.getId()
					&& fromCourseOne.getId() == fromCourseThree.getId())
				{
					cout << "  " << fromCourseOne.getId() << setw(10) << fromCourseOne.getName()
						<< " " << courseOneTitle << "(" << fromCourseOne.getScore() << ")"
						<< "  " << courseTwoTitle << "(" << fromCourseTwo.getScore() << ")" << "  "
						<< courseThreeTitle << "(" << fromCourseThree.getScore() << ")  " << endl;

				}
			}
		}
	}

}

void listOfStudentsWhoTakeTwoCourses(struct Course* courseArray)
{
	struct Course courseOne = courseArray[0];
	struct Course courseTwo = courseArray[1];
	struct Course courseThree = courseArray[2];
	Student* listOne = courseOne.list;
	Student* listTwo = courseTwo.list;
	Student* listThree = courseThree.list;
	string courseOneName = courseOne.title;
	string courseTwoName = courseTwo.title;
	string courseThreeName = courseThree.title;
	int courseOneSize = courseOne.number_of_students;
	int courseTwoSize = courseTwo.number_of_students;
	int courseThreeSize = courseThree.number_of_students;
	// Count students who are in courseOne and courseTwo but no int courseThree
	int studentsOne = totalStudentsWhoTakeTwoCourses(listOne, courseOneSize, listTwo, courseTwoSize, listThree, courseThreeSize);
	cout << endl;
	cout << " There are " << studentsOne << " students who take " << courseOne.title << " and " << courseTwo.title << endl;
	outputStudentsWhoTakeTwoCourses(courseOneName, listOne, courseOneSize, courseTwoName, listTwo, courseTwoSize, listThree, courseThreeSize);
	cout << endl;
	int studentsTwo = totalStudentsWhoTakeTwoCourses(listOne, courseOneSize, listThree, courseThreeSize, listTwo, courseTwoSize);
	cout << " There are " << studentsTwo << " students who take " << courseOne.title << " and " << courseThree.title << endl;

	outputStudentsWhoTakeTwoCourses(courseOneName, listOne, courseOneSize, courseThreeName, listThree, courseThreeSize, listTwo, courseTwoSize);
	cout << endl;
	int studentsThree = totalStudentsWhoTakeTwoCourses(listTwo, courseTwoSize, listThree, courseThreeSize, listOne, courseOneSize);
	cout << " There are " << studentsThree << " students who take " << courseTwo.title << " and " << courseThree.title << endl;
	outputStudentsWhoTakeTwoCourses(courseTwoName, listTwo, courseTwoSize, courseThreeName, listThree, courseThreeSize, listOne, courseOneSize);
}

int totalStudentsWhoTakeTwoCourses(Student* listOne, int listOneSize, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize)
{
	int result = 0;
	for (int i = 0; i < listOneSize; i++)
	{
		for (int j = 0; j < listTwoSize; j++)
		{
			int idFromCourseOne = listOne[i].getId();
			int idFromCourseTwo = listTwo[j].getId();
			if (idFromCourseOne == idFromCourseTwo && (!idExistsInList(listThree, listThreeSize, idFromCourseOne)))
			{
				result++;
			}
		}
	}
	return result;
}

void outputStudentsWhoTakeTwoCourses(string courseOneTitle, Student* listOne, int listOneSize, string courseTwoTitle, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize)
{
	insertionSortById(listOne, listOneSize);
	insertionSortById(listTwo, listTwoSize);
	for (int i = 0; i < listOneSize; i++)
	{
		for (int j = 0; j < listTwoSize; j++)
		{
			int idFromCourseOne = listOne[i].getId();
			int idFromCourseTwo = listTwo[j].getId();
			string nameFromCourseOne = listOne[i].getName();
			string nameFromCourseTwo = listTwo[j].getName();
			int scoreFromCourseOne = listOne[i].getScore();
			int scoreFromCourseTwo = listTwo[j].getScore();
			if (idFromCourseOne == idFromCourseTwo &&
				(!idExistsInList(listThree, listThreeSize, idFromCourseOne)))
			{
				cout << " " << idFromCourseOne << setw(10) << nameFromCourseOne << setw(10) << courseOneTitle << "(" << scoreFromCourseOne << ")" << " " << courseTwoTitle << "(" << scoreFromCourseTwo << ")" << endl;
			}
		}
	}

}

bool idExistsInList(Student* list, int listSize, int id)
{
	for (int i = 0; i < listSize; i++)
	{
		Student student = list[i];
		if (student.getId() == id)
		{
			return true;
		}
	}
	return false;
}




void outputCourseArray(Course* courseArray, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		struct Course course = courseArray[i];
		int courseSize = course.number_of_students;
		cout << course.title << " " << courseSize << endl;
		Student* list = course.list;
		for (int i = 0; i < courseSize; i++)
		{
			Student student = list[i];
			cout << student.getId() << " " << student.getName() << " " << student.getScore() << endl;
		}
		cout << endl;
	}
}




 