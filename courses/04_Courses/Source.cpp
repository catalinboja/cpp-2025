#include <iostream>
#include <string>
using namespace std;

struct StudentStructure {
	string name = "";
	int grade  = 0;
	char faculty[1000] = "";
};

void printStudentInfo(StudentStructure student) {
	cout << endl << "Name: " << student.name;
	cout << endl << "Grade: " << student.grade;
	cout << endl << "Faculty: " << student.faculty;
}

//void printStudentObjInfo(StudentClass student) {
//	cout << endl << "Name: " << student.name;
//	cout << endl << "Grade: " << student.grade;
//	cout << endl << "Faculty: " << student.faculty;
//}

//the most complex function ever to read and validate the grade
void noOneWillUseIt(StudentStructure& student) {
	/////
	//TODO
}

class StudentClass {
private:
//access specifiers
public:
	string name = "";
	char faculty[1000] = "";
private:
	int grade = 0;

public:
	void printStudentObjInfo(StudentClass student) {
		cout << endl << "Name: " << student.name;
		cout << endl << "Grade: " << student.grade;
		cout << endl << "Faculty: " << student.faculty;
	}

	void printStudentObjInfo() {
		cout << endl << "Name: " << this->name;
		cout << endl << "Grade: " << this->grade;
		cout << endl << "Faculty: " << faculty;
	}


	//class public interface
	int getGrade() {
		return this->grade;
	}

	void setGrade(int newGrade) {
		if (newGrade < 0 || newGrade >10) {
			throw "Wrong value";
		}
		this->grade = newGrade;
	}

	//class constructor
	StudentClass() {

	}

	StudentClass(int grade, string name) {
		this->name = name;
		this->grade = grade;
	}
};


int main() {
	// data
	// in STACK you get 0xCC for each byte
	//char facultyName[1000];
	//char* courseName;

	////in HEAP you get 0xCD for each byte
	//courseName = new char[5];

	////facultyName[5] = '\0';

	// data
	char facultyName[1000] = "Don't know";
	char* courseName = nullptr;
	int noStudents = 0;

	string* names = nullptr;
	int* grades = nullptr;

	cout << endl << facultyName;

	StudentStructure student;
	student.name = "John";
	cout << endl << "Student Struct name "
		<< student.name;

	StudentStructure* students = nullptr;
	printStudentInfo(student);

	cout << endl << "Give me the Student grade:";
	cin >> student.grade;
	printStudentInfo(student);

	StudentClass studentObject;
	cout << endl << "Student Obj name "
		<< studentObject.name;
	//cout << endl << "Student Obj grade "
	//	<< studentObject.grade;
	//studentObject.grade = -6;

	cout << endl << "----------------------";
	studentObject.printStudentObjInfo(studentObject);

	StudentClass alice;
	StudentClass john;

	//alice.printStudentObjInfo(alice);
	//john.printStudentObjInfo(alice);
	alice.printStudentObjInfo();
	john.printStudentObjInfo();

	cout << endl << "Alice grade "
	<< alice.getGrade();

	//alice.setGrade(-6);
	alice.setGrade(9);
	alice.printStudentObjInfo();

	StudentClass bob(8, "Bob");
	bob.printStudentObjInfo();
}