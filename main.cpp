/**
	Date: 10/1/2023
	By: Justin Su
	Purpose: Project #1
**/
#include <string>
#include <fstream>
#include <iomanip>
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
void deallocateStudentListInCourseArray(struct Course* courseArray, int arraySize);
 
// Run program
void showMenu(int& userChoice);
void run(struct Course* array, int arraySize);

//Tasks
// Show all course lists (sorting)
void insertionSortById(Student* array, int arraySize);
void showAllCourseLists(struct Course* array, int arraySize);

// List of students who take all courses
void listOfStudentsWhoTakeAllThreeCourses(struct Course* courseArray);
int totalStudentsWhoTakeAllThreeCourses(struct Course courseOne, struct Course courseTwo, struct Course courseThree);
void outputStudentsWhoTakeAllThreeCourses(struct Course courseOne, struct Course courseTwo, struct Course courseThree);

// List of students who take only take 2 courses
void listOfStudentsWhoTakeTwoCourses(struct Course* courseArray);
int totalStudentsWhoTakeTwoCourses(Student* listOne, int listOneSize,Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize);
void outputStudentsWhoTakeTwoCourses(string courseOneTitle, Student* listOne, int listOneSize, string courseTwoTitle, Student* listTwo, int listTwoSize, Student* listThree, int listThreeSize);
bool idExistsInList (Student* list, int listSize, int id);

// Print out top three students for each course
void printOutTopThreeStudentsForEachCourse(struct Course* courseArray, int arraySize);
void insertionSortByScore(Student* array, int arraySize);
void printStudentsWithGivenScore(Student* array, int arraySize, int score);

// Test functions
void outputCourseArray(struct Course* courseArray, int arraySize);
Student* copyStudentList(Student* array, int arraySize);

int main()
{
	// Get files and check if they can be opened
	struct Course courseArray[3];
	int ARRAY_SIZE = sizeof(courseArray) / sizeof(struct Course);
	string* filesToOpen = new string[ARRAY_SIZE];
	getFilesToOpen(filesToOpen, ARRAY_SIZE);
	checkIfFilesExist(filesToOpen, ARRAY_SIZE);
	// Creates the data structure
	
	fillCourseArrayFromFiles(courseArray, filesToOpen, ARRAY_SIZE);
	//outputCourseArray(courseArray, ARRAY_SIZE);
	cout << endl;
	run(courseArray, ARRAY_SIZE);
	
	delete[] filesToOpen;
	deallocateStudentListInCourseArray(courseArray, ARRAY_SIZE);
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

void deallocateStudentListInCourseArray(struct Course* courseArray, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		struct Course course = courseArray[i];
		delete[] course.list;
	}
	 
}

void showMenu(int& userChoice)
{
	
	cout << "================= Menu =====================" << endl;
	cout << "  1. Show all course lists (sorting)" << endl;
	cout << "  2. List of students who take all courses" << endl;
	cout << "  3. List of students who take two courses" << endl;
	cout << "  4. Print out top three scores for each course" << endl;
	cout << "  5. Exit" << endl;
	cout << "  ----> Select : ";
	cin >> userChoice;

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



void insertionSortById(Student* array, int arraySize)
{
	int j = 0;
	for (int i = 1; i < arraySize; i++)
	{
		Student key = array[i];
		j = i - 1;
		while (j >= 0 && array[j].getId() > key.getId())
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}

void showAllCourseLists(struct Course* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		struct Course course = array[i];
		int courseSize = course.number_of_students;
		cout << "==========  " << course.title << "  ==========" << endl;
		cout << endl;
		cout << endl;
		Student* list = course.list;
		insertionSortById(list, courseSize);
		for (int i = 0; i < courseSize; i++)
		{
			Student student = list[i];
			cout << "    " << student.getId() << "    " << student.getName() << "  " << student.getScore() << endl;
		}
	
		cout << endl;
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
					&& courseOneStudent.getId()== courseThreeStudent.getId())
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
	int studentsTwo = totalStudentsWhoTakeTwoCourses(listOne, courseOneSize, listThree,courseThreeSize, listTwo, courseTwoSize);
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
			if (idFromCourseOne == idFromCourseTwo && (!idExistsInList(listThree, listThreeSize, idFromCourseOne)))
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

 

void run(struct Course* array, int arraySize)
{
	int userChoice = 0;
	showMenu(userChoice);
	if (userChoice < 1 || userChoice > 5)
	{
		cout << endl;
		cout << "Invalid option! Exiting program!" << endl;
		exit(1);
	}
	switch (userChoice)
	{
		case 1:
			outputCourseArray(array, arraySize);
			showAllCourseLists(array, arraySize);
			outputCourseArray(array, arraySize);
			break;
		case 2:
			listOfStudentsWhoTakeAllThreeCourses(array);
			break;
		case 3:
			listOfStudentsWhoTakeTwoCourses(array);
			break;
		case 4:
			printOutTopThreeStudentsForEachCourse(array, arraySize);
			break;
		default:
			cout << "  Exiting....";
	}
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

Student* copyStudentList(Student* array, int arraySize)
{
	Student* newArray = new Student[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		newArray[i] = array[i];
	}
	return newArray;
}

 