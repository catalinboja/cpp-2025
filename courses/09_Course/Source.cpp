#include <iostream>
#include <string>

using namespace std;


class Student {
	int* grades = nullptr;
	int noGrades = 0;
	const string name;
	int age = 0;
public:
	Student(const Student& student)
		:name(student.name), age(student.age) {
		this->noGrades = student.noGrades;
		this->grades = new int[student.noGrades];
		for (int i = 0; i < student.noGrades; i++) {
			this->grades[i] = student.grades[i];
		}
	}

	Student(string name, int age) : name(name), age(age) {

	}

	~Student() {
		delete this->grades;
	}

	void operator=(const Student& s) {

		//avoid self equality
		if (this == &s) {
			//same objects
			return;
		}

		this->age = s.age;
		//DOES NOT WORK for const attrs
		//this->name = s.name;

		this->noGrades = s.noGrades;
		delete[] this->grades;

		this->grades = new int[s.noGrades];
		for (int i = 0; i < s.noGrades; i++) {
			this->grades[i] = s.grades[i];
		}
	}

	//operator Student + int
	Student operator+(int value) {

		Student copy = *this;

		int* newGrades = new int[this->noGrades + 1];
		for (int i = 0; i < this->noGrades; i++) {
			newGrades[i] = this->grades[i];
		}
		newGrades[this->noGrades] = value;
		copy.noGrades += 1;
		copy.grades = newGrades;

		return copy;
	}

	float getAverage() {
		if (this->grades == nullptr)
			return 0;
		float s = 0;
		for (int i = 0; i < this->noGrades; i++) {
			s += this->grades[i];
		}
		return s / this->noGrades;
	}

	bool operator==(Student s) {
		return this->getAverage() == s.getAverage();
	}

	//cast to float
	explicit operator float() {
		return this->getAverage();
	}

	friend void operator<<(ostream& console, Student s);

};

//ALL the operators which have a 1st parameter not your class type
// // only by global methods
//int  + Student
Student operator+(int value, Student s) {
	return s + value;
}

void operator<<(ostream& console, Student s) {
	console << endl << "Student name: " << s.name;
}

int main() {
	Student john("John", 22);
	Student temp("Temp", 0);

	Student johnClone = john; //copy ctr

	//test the destructor
	// option A
	Student* alice = new Student("Alice", 22);
	delete alice;

	//option B
	{
		Student s("", 0);
	}

	//operator =
	temp = john;
	john = john;

	////stream operators
	cout << john;
	//cin >> john;
	//cout << john;

	////math operators
	////+= -= *= /= 
	//john += 23; //add 23 to age
	//john -= 5;

	////+ - / *
	// 
	// DON'T CHANGE THE PARAMTERS
	//john = john.operator+(8);

	temp = john + 8; //add 8 to grades
	john = 9 + john;
	//john = john + "Test";
	//temp = 2.3 + john;

	////++ -- post and pre
	//john++; //increment age (post)
	//++john; //pre

	//// < > == >= <= !
	if (john == johnClone) { //john.operator==(alice)
		cout << endl << "They have the same grades average";
	}
	//if (!john) { //return true if at least 1 grade is < 5
	//	cout << endl << "John has at least 1 failed exam";
	//}

	////cast
	float average = (float)john;

	////function operator
	////returns true if john average is between 5 and 8
	//bool isInRange = john(5, 8); 

	////index operator [] 
	//int firstGrade = john[0];
	//john[0] = 10; //change the grade at index 0


}