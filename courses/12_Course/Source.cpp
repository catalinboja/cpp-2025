#include <iostream>
#include <string>

//relations between classes
// 1. has-a Composition
// 2. is-a Inheritance/Extension

using namespace std;

class PersonalInformation {
public:
	string address;
	string country;
	int postalCode;
	string phone;
	int age;

	PersonalInformation(string address, string country)
		:address(address), country(country)
	{

	}
};

class Student {
public:
	string name;
	const int id = 0;

	


	//string address;
	//string country;
	//int postalCode;
	//string phone;
	//int age;

	//has-a (1:1)
	PersonalInformation personalInformation;

	//Student() : id(0), personalInformation("Piata Romana", "Romania") {

	//}

	Student(int id) 
		: id(id), personalInformation("Piata Romana", "Romania") {
		//this->id = 1;
		this->name = "John";
		//you change the value
		//this->personalInformation = 
		//	PersonalInformation("Piata Romana","Romania");
	}

	Student(int id, string name, string address, string country)
		:id(id), personalInformation(address, country)
	{

	}

};

//is-a relation
class BachelorStudent : public Student {
	float bachelorExamAverage = 0.0;

public:
	BachelorStudent(): Student(1, "Bob","Bucharest", "Ro") {
	}
};

class Group {
public:
	int number;

	//many students
	//has-a (1:M)
	//Student students[100];
	//Student* students = nullptr;
	Student** students = nullptr;
	int noStudents;

	Group() {

	}

	void initStudents(Student* students, int noStudents) {
		delete[] this->students;
		this->students = new Student*[noStudents];
		for (int i = 0; i < noStudents; i++) {
			this->students[i] = &students[i];
		}
		this->noStudents = noStudents;
	}

	void addStudent(int idStudent) {
		Student* newStudent = new Student(idStudent);
		Student** newStudents = new Student * [this->noStudents + 1];
		for (int i = 0; i < this->noStudents; i++) {
			newStudents[i] = this->students[i];
		}
		newStudents[this->noStudents] = newStudent;
		delete[] this->students;
		this->students = newStudents;
		this->noStudents += 1;
	}
};

int main() {
	//Student student;
	Student alice(2, "Alice", "Bucharest", "Romania");
	//student.personalInformation.country = "Romania";
	Group g1070;
	//the country of the 2nd student
	//g1070.students[1].personalInformation.country = "Romania";
	g1070.students[1]->personalInformation.country = "Romania";


	BachelorStudent stud;
	stud.name = "Bob";
	stud.personalInformation.country = "Romania";
}