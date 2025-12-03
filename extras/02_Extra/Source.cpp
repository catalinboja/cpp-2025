#include <iostream>
#include <string>

using namespace std;

// statics variables - how to define and how to use them
// static  methods


class Util {
public:
	static int* copyArray(int* values, int noValues) {
		//TODO: implement deep copy
		return nullptr;
	}
};
class Student {
	const int id;
	int age = Student::MIN_AGE;
	string name = "";
	bool hasScholarship = false;
	int* grades = nullptr;
	int noGrades;

	static int MIN_AGE;
	static int STUDENTS_WITH_SCHOLARSHIP;
	static int ID_COUNTER;

public:
	//Option B: make the static public and constant
	static const int MAX_AGE;

public:

	Student(): id(++ID_COUNTER) {
		
	}

	Student(string name) :id(++ID_COUNTER), name(name) {

	}

	void setAge(int value) {
		if (value < Student::MIN_AGE || value > Student::MAX_AGE) {
			throw "Invalid value for age";
		}
		else {
			this->age = value;
		}
	}

	bool checkScholarship() {
		return this->hasScholarship;
	}

	void gainsScholarship() {
		if (this->hasScholarship == false) {
			this->hasScholarship = true;
			Student::STUDENTS_WITH_SCHOLARSHIP += 1;
		}
	}

	void losesScholarship() {
		if (this->hasScholarship == true) {
			this->hasScholarship = false;
			Student::STUDENTS_WITH_SCHOLARSHIP -= 1;
		}
	}

	//Option A - provide a public static method for the static attribute
	static int getMinAge() {
		return Student::MIN_AGE;
	}

	static int getNoStudentsWithScholarship() {
		return Student::STUDENTS_WITH_SCHOLARSHIP;
	}

	int getId() {
		return this->id;
	}

	//post version
	Student operator++(int) {
		Student result = *this;
		this->age += 1;
		return result;
	}

	//pre version
	Student operator++() {
		this->age += 1;
		return *this;
	}

	~Student() {
		delete[] this->grades;
	}

	Student(const Student& s):id(s.id) {
		this->name = s.name;
		this->age = s.age;
		this->noGrades = s.noGrades;
		//done by the default version
		//this->grades = s.grades;

		this->grades = new int[s.noGrades];
		for (int i = 0; i < s.noGrades; i++)
			this->grades[i] = s.grades[i];
	}

};

int Student::MIN_AGE = 8;
const int Student::MAX_AGE = 100;
int Student::STUDENTS_WITH_SCHOLARSHIP = 0;
int Student::ID_COUNTER = 0;


void operator<<(ostream& console, Student s) {

}

void operator>>(istream& console, Student& s) {

}

Student operator+(int value, Student s) {

}

void printStudent(Student s) {

}

Student createAStudent(string name) {
	Student temp(name);
	return temp;
}

int main() {
	Student s1;
	Student s2;

	cout << endl << "S1 ID " << s1.getId();
	cout << endl << "S2 ID " << s2.getId();

	//Student::MAX_AGE = 50;

	int newAgeValue = 5;
	if(newAgeValue >= Student::getMinAge() && 
		newAgeValue <= Student::MAX_AGE)
		s2.setAge(5);

	//Question: how many students have scholarship
	//int counter = 0;
	//if (s1.checkScholarship())
	//	counter += 1;
	//if (s2.checkScholarship())
	//	counter += 1;

	s1.gainsScholarship();
	s1.gainsScholarship();


	cout << endl << "Number of students with scholarship "
		<< Student::getNoStudentsWithScholarship();

	Student john("John");
	Student alice("Alice");

	cout << endl << "John ID " << john.getId();
	cout << endl << "Alice ID " << alice.getId();

	Student temp = s1++; //post increment the student age
	Student temp2 = ++s1; //pre

	int vb1 = 10;
	//int vb2 = ++vb; // pre increment will return the vb1 changed value
	int vb2 = vb1++; //post increment will return the initial vb1 value - before the increment

	cout << endl << "vb1 = " << vb1 << " vb2 = " << vb2;

	Student johnClone = john; //we use the copy ctor

	Student aliceClone(alice); //we use the copy ctor

	cout << john;
	Student temp3 = 4 + john;

	cin >> john;

}

