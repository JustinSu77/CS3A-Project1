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
	Prompt user for file names for files to be opened.
	Precondition: Given string dynamic array filesToOpen is initialized and has some elements.
	Postcondition: Given string dynamic array filesToOpen is filled with strings by user.
		filesToOpen as string dynamic array
		arraySize as number of elements in given string dynamic array
**/
void getFilesToOpen(string* filesToOpen, int arraySize);

/**
	Open each element of the given string dynamic array filesToOpen as a file.
	Notify and exit program with error code 1 if a file fails to open.
	Precondition: Given string dynamic array filesToOpen has some elements.
	Postcondition: If element of filesToOpen fails to open as a file,
				   notify and exit program with error code 1
	filesToOpen as string dynamic array
	arraySize as number of elements in filesToOpen as int
**/
void checkIfFilesExist(string* filesToOpen, int arraySize);

// Create data structure
/**
	Fill given struct Course dynamic array with data from text files in filesToOpen string dynamic array.
	Loop through the courseArray and filesToOpen array
	Read the data from file and initialize a struct Course variable with the read data.
	Assign the struct to the corresponding index of the courseArray
	Precondition: Given filesToOpen is filled with file names to open.
	Postcondition: Given courseArray is filled with struct Course variables created with data from file.
		courseArray as struct Course dynamic array.
		filesToOpen as string dynamic array
		arraySize as the size of both given dynamic arrays	
**/
void fillCourseArrayFromFiles(struct Course* courseArray, string* filesToOpen, int arraySize);


/**
	Deallocates the dynamic array pointed to by the list member variable 
	of each struct Course variable in given struct Course dynamic array.
	Precondition: Given struct Course* course array has some struct Course variables
	Postcondition: The dynamic array pointed to by Stuent list member variable 
				   of each struct variable is deallocated.
	courseArray as array of struct Course variable
	arraySize as number of elements in given courseArray
**/
void deallocateStudentListInCourseArray(struct Course* courseArray, int arraySize);

// Run program
/**
	Show the user the five task options to run for this program.
	Precondition: User enters a number between 1 and 5
	Postcondition: The user input is saved is passed as reference to the run function.
		userChoice as the option to run as int reference
**/
void showMenu(int& userChoice);

/**
	Show the user the menu and run task corresponding to the given option.
	Precondition: User chooses a option 1 through 5.
	Postcondition: The function corresponding to the chosen option is ran and program exit 0
		array as array of type struct Course
		arraySize as size of given array as int
**/
void run(struct Course* array, int arraySize);

//Tasks
// Show all course lists (sorting)
/**
	Sort object elements in given Student dynamic array in ascending order by id,
	Uses insertion sort.
	Precondition: Given Student dynamic array has some elements.
	Postcondition: Object elements in Student dynamic array are 
				   sorted in ascending order by id.
		array as dynamic array of Student objects
		arraySize as number of elements in dynamic array as int
**/
void insertionSortById(Student* array, int arraySize);

/**
	Output the id, name, and score of the Student objects in given Student 
	dynamic array to terminal.
	Precondition: Given Student dynamic array has some elements.
	Postcondition: The id, name, and score of each Student object in given Studeny dynamic array is 
				   outputted to the terminal
		array as dynamic array of Student objects
		arraySize as the number of elements in given array
**/
void outputStudentList(Student* array, int arraySize);

/**
	Output all the Student lists in each struct Course variable in the given struct Course array
	in ascending order of id.
	Precondition: Given struct Course* array is filled with sruct Course variables.
	Postcondition: The Student list in each course is sorted in ascending order of id.

**/
void showAllCourseLists(struct Course* array, int arraySize);


// List of students who take all courses
void listOfStudentsWhoTakeAllThreeCourses(struct Course* courseArray);
int totalStudentsWhoTakeAllThreeCourses(struct Course courseOne, struct Course courseTwo, struct Course courseThree);
void outputStudentsWhoTakeAllThreeCourses(struct Course courseOne, struct Course courseTwo, struct Course courseThree);

// List of students who take only take 2 courses
void listOfStudentsWhoTakeTwoCourses(struct Course* courseArray);
int totalStudentsWhoTakeTwoCourses(Student* listOne, int listOneSize, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize);
void outputStudentsWhoTakeTwoCourses(string courseOneTitle, Student* listOne, int listOneSize, string courseTwoTitle, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize);
bool idExistsInList(Student* list, int listSize, int id);

// Print out top three students for each course
void printOutTopThreeStudentsForEachCourse(struct Course* courseArray, int arraySize);
void insertionSortByScore(Student* array, int arraySize);
void printStudentsWithGivenScore(Student* array, int arraySize, int score);

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
		printOutTopThreeStudentsForEachCourse(array, arraySize);
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



void printOutTopThreeStudentsForEachCourse(Course* courseArray, int arraySize)
{
	cout << endl;
	for (int i = 0; i < arraySize; i++)
	{
		Course course = courseArray[i];
		string title = course.title;
		int courseSize = course.number_of_students;
		if (courseSize < 3)
		{
			cout << "Student list size has to be greater than 3" << endl;
			return;
		}
		Student* list = course.list;
		insertionSortById(list, courseSize);
		insertionSortByScore(list, courseSize);
		cout << "[  " << title << " Top Three Scores  ]" << endl;
		int scoresSeen = 0;
		int index = courseSize - 1;
		bool scoreSeen[101] = {};
		while (scoresSeen < 3)
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




 