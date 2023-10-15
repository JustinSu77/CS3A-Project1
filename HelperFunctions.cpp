#include "Structures.h"
#include "HelperFunctions.h"
#include "Student.h"

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
 
// Create Data Structure
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

void runProgram(struct Course* array, int arraySize)
{
	// Declare and initialize variable to store the user choice
	char userChoice = ' ';
	// Prompt user for the 5 options to run
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
		cout << endl;
		cout << "  Exiting....";
		cout << endl;
	}
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


// Task 2: List of Students who take all three courses
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
						<< "    " << courseOneTitle << "(" << fromCourseOne.getScore() << ")"
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
	cout << "               There are " << students << " student(s) who take 3 courses               " << endl;
	cout << "----------------------------------------------------------------------" << endl;
	// Output the id, name, and grade in each course of students who take all 3 courses 
	outputStudentsWhoTakeAllThreeCourses(courseOne, courseTwo, courseThree);
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
				cout << " " << idFromCourseOne << setw(12) << nameFromCourseOne << setw(15) << courseOneTitle << "(" << scoreFromCourseOne << ")" << "    " << courseTwoTitle << "(" << scoreFromCourseTwo << ")" << endl;
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
	cout << "     There are " << studentsOne << " student(s) who take " << courseOne.title << " and " << courseTwo.title << endl;
	cout << "-------------------------------------------------------------------" << endl;
	// Output the Student objects who are in courseOne and courseTwo but not in courseThree
	outputStudentsWhoTakeTwoCourses(courseOne.title, courseOne.list, courseOne.number_of_students, courseTwo.title, courseTwo.list, courseTwo.number_of_students, courseThree.list, courseThree.number_of_students);
	// Skip a line in terminal for readability
	cout << endl;
	// Store number of students who are in courseOne and courseThree but not in courseTwo
	int studentsTwo = totalStudentsWhoTakeTwoCourses(courseOne.list, courseOne.number_of_students, courseThree.list, courseThree.number_of_students, courseTwo.list, courseTwo.number_of_students);
	// Output number of students who are in courseOne and courseThree but not in courseTwo
	cout << "     There are " << studentsTwo << " student(s) who take " << courseOne.title << " and " << courseThree.title << endl;
	cout << "-------------------------------------------------------------------" << endl;

	// Output the Student objects who are in courseOne and courseThree but not in courseTwo
	outputStudentsWhoTakeTwoCourses(courseOne.title, courseOne.list, courseOne.number_of_students, courseThree.title, courseThree.list, courseThree.number_of_students, courseTwo.list, courseTwo.number_of_students);
	// Skip a line in terminal for readability
	cout << endl;
	// Store number of students who are in courseTwo and courseThree but not in courseOne
	int studentsThree = totalStudentsWhoTakeTwoCourses(courseTwo.list, courseTwo.number_of_students, courseThree.list, courseThree.number_of_students, courseOne.list, courseOne.number_of_students);
	// Output number of students who are in courseTwo and courseThree but not in courseTwo
	cout << "     There are " << studentsThree << " student(s) who take " << courseTwo.title << " and " << courseThree.title << endl;
	cout << "-------------------------------------------------------------------" << endl;
	// Output the Student objects who are in courseOne and courseThree but not in courseTwo
	outputStudentsWhoTakeTwoCourses(courseTwo.title, courseTwo.list, courseTwo.number_of_students, courseThree.title, courseThree.list, courseThree.number_of_students, courseOne.list, courseOne.number_of_students);

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
int* getStudentGrades(Student* array, int arraySize)
{
	int* newArray = new int[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		newArray[i] = array[i].getScore();
	}
	return newArray;
}


void deleteDuplicateScoresInGivenArray(int* array, int& arraySize)
{

	int removed = 0;
	for (int i = 0; i < arraySize - 1; i++)
	{
		if (array[i] != array[i + 1])
		{
			array[removed] = array[i];

			removed++;
		}
	}
	array[removed] = array[arraySize - 1];
	arraySize = removed + 1;


}
void printOutTopNStudentsForEachCourse(Course* courseArray, int arraySize, int n)
{
	// Skip a line in terminal for readability
	cout << endl;
	// Loop through 
	int initialN = n;
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

		// Declare and initialize pointer that points to the Student list of current course
		Student* list = course.list;
		// Sort the list by id
		insertionSortById(list, courseSize);
		// Sort the list by score
		insertionSortByScore(list, courseSize);
		int copyOfCourseSize = courseSize;
		int* studentGrades = getStudentGrades(list, copyOfCourseSize);
		deleteDuplicateScoresInGivenArray(studentGrades, copyOfCourseSize);

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

		int scoresSeen = 0;
		int arrayIndex = copyOfCourseSize - 1;
		while (scoresSeen < n)
		{
			int score = studentGrades[arrayIndex];
			cout << scoresSeen + 1 << ". " << score << endl;
			printStudentsWithGivenScore(list, courseSize, score);
			scoresSeen++;
			arrayIndex--;
		}
		// Output newline to terminal for readability
		cout << endl;
		delete[] studentGrades;

		// Reset given to value of n before loop
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
