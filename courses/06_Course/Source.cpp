#include <iostream>
#include <string>
using namespace std;

//classes and constructors
//memory-leak
//dangling-pointers
//constants and statics
//destructor
// 
// Next time:
//copy-constructor

enum class StudentType { ERASMUS, INTERNAL };

class Student {
private:
	const int id;
	string name = "";
	int* grades = nullptr;
	int noGrades= 0;
	StudentType type = StudentType::INTERNAL;
	bool hasScholarship = false;
public:
	static int MIN_NUMBER_CHARS;
	static int MIN_GRADE;
	static int MAX_GRADE;

	void setName(string value) {
		
		if (value.size() < Student::MIN_NUMBER_CHARS) { //5 is a magic number
			throw "Invalid name";
		}
		this->name = name;
	}

	void addGrade(int value) {
		if (value < Student::MIN_GRADE || value > Student::MAX_GRADE) {
			throw "Invalid grade";
		}

		//you can't add a new value in the existing array
		//1 create an array with size + 1
		int* newGrades = new int[this->noGrades + 1];
		//2 copy existing values
		for (int i = 0; i < this->noGrades; i++) {
			newGrades[i] = this->grades[i];
		}
		//3 add the new value
		newGrades[this->noGrades] = value;

		//4 update the size
		this->noGrades += 1;

		//what happens with the old one
		// a memory leak if you don't delete
		delete[] this->grades;

		//5 keep the new array
		this->grades = newGrades;

		//delete[] this->grades; //dangling pointer
	}

	void print() {
		cout << endl << "Name: " << this->name;
		//cout << endl << "Type: " << this->type;
		switch (this->type) {
		case StudentType::INTERNAL:
			cout << endl << "Type: Internal";
			break;
		case StudentType::ERASMUS:
			cout << endl << "Type: Erasmus";
			break;
		default:
			cout << endl << "Type: Other";
		}
		if (this->hasScholarship) {
			cout << endl << "Scholarship: yes";
		}
		else {
			cout << endl << "Scholarship: no";
		}

		cout << endl << "Grades: ";
		if (this->grades == nullptr) {
			cout << endl << "No grades";
		}
		else {
			for (int i = 0; i < this->noGrades; i++) {
				cout << " " << this->grades[i];
			}
		}
	}

	void setGrades(int* values, int noValues) {

		//do you need the previous values in HEAP
		// if no - delete them
		delete[] this->grades;

		this->grades = new int[noValues];
		for (int i = 0; i < noValues; i++) {
			if (values[i] < MIN_GRADE || values[i] > MAX_GRADE) {
				throw "Invalid grade";
			}
			this->grades[i] = values[i];
		}
		this->noGrades = noValues;
	}

	Student(string name, int* grades, int noGrades): id(0) {
		this->setGrades(grades, noGrades);
		this->setName(name);
	}

	Student(int Id, string name, int* grades, int noGrades) 
		: id(Id) {
		this->setGrades(grades, noGrades);
		this->setName(name);
	}

	Student(): id(0) {
	}

	//NOT needed
	//void cleanAfterMe() {
	//	delete[]this->grades;
	//}

	//class destructor
	~Student() {
		//clean any space you have in HEAP
		delete[] this->grades;
	}

};

int Student::MAX_GRADE = 10;
int Student::MIN_GRADE = 0;
int Student::MIN_NUMBER_CHARS = 5;


int main() {
	Student student;
	cout << endl << "Min number of chars: " <<
		Student::MIN_NUMBER_CHARS;

	student.addGrade(10);
	student.addGrade(10);
	student.addGrade(10);
	student.print();

	Student john;
	int values[4] = { 10,9,8,10 };
	string names[3] = { "John", "Bob", "Alice" };

	john.setGrades(values, 4);
	john.print();

	//for (;;) {
	//	john.setGrades(values, 4);
	//}

	for (;;) {
		Student* pStudent = new Student("Vader", values, 4);
		//pStudent->cleanAfterMe();
		delete pStudent;
	}


}