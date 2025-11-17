#include <iostream>
#include <string>

using namespace std;

// LAST WEEK
// - copy constructor
// - static variables and static const
// - static methods

// TODAY
// - overloading operators

class Util {
	int value;
public:
	static string* copyStrings(string* values, int noValues) {
		string* copy = new string[noValues];
		for (int i = 0; i < noValues; i++) {
			copy[i] = values[i];
		}
		return copy;
	}
};


class Student {
	string* courses = nullptr;
	int noCourses = 0;
	const string code = "";
	string name = "";
public:
	void setCourses(string* values, int noValues) {
		//release the old array of courses
		//avoid the memory leak
		delete[] this->courses;

		this->courses = Util::copyStrings(values, noValues);
		this->noCourses = noValues;
	}

	string* getCourses() {
		//DON't
		//return this->courses;
		return Util::copyStrings(this->courses, this->noCourses);
	}

	int getNoCourses() {
		return this->noCourses;
	}

	//destructor
	~Student() {
		delete[] this->courses;
	}

	void print() {
		cout << endl << "Student: " << this->name << " - " << this->code;
		cout << endl << "Courses: ";
		for (int i = 0; i < this->noCourses; i++) {
			cout << " " << this->courses[i];
		}
	}

	//copy ctor
	Student(Student& stud): code(stud.code) {
		//stud.name = this->name;
		this->name = stud.name;
		this->courses = Util::copyStrings(stud.courses, stud.noCourses);
		this->noCourses = stud.noCourses;
		//this->code = stud.code;
	}

	Student(string name, string code): code(code), name(name) {
		//this->name = name;
	}

	//Student(string name, string code, string* courses, int no) 
	//	: code(code), name(name), noCourses(no) {
	//	this->courses = Util::copyStrings(courses, no);
	//}

	//Student(string name, string code = "", string* courses = nullptr, int no = 0)
	//	: code(code), name(name), noCourses(no) {
	//	this->courses = Util::copyStrings(courses, no);
	//}

	Student() {

	}

	//overloading =
	void operator=(Student stud) {

		if (this == &stud) {
			return;
		}

		this->name = stud.name;
		delete[] this->courses;
		this->courses = Util::copyStrings(stud.courses, stud.noCourses);
		this->noCourses = stud.noCourses;

		//NEVER
		//this->code = stud.code;

	}

};

class StudentUtil {
public:
	//you need the copy ctor
	static void printStudent(Student s) {

	}

	//you need the copy ctor - because you return by value
	static Student createStudent() {
		Student temp;
		return temp;
	}


};


//overloading add
int add(int a, int b) {
	return a + b;
}

int add(int a, int b, int c) {
	return a + b + c;
}

int add(Student s, int grade) {

}

int main() {

	string extraCourses[3] = { "AI", "Robotics", "Data Structures" };

	string name = "John";
	Student john(name, "ASE01");
	john.setCourses(extraCourses, 3);
	john.print();

	//you need the copy ctor
	//clone John
	Student johnClone = john;
	johnClone.print();


	StudentUtil::printStudent(john);

	Student temp;
	temp = john; //operator=(Student a, Student b)
	temp = john;

	//temp = temp;

	int vb = 10; //operator=(int a, int b)
	vb = vb + 5; //  operator+(int a, int b)
	vb += 1; //operator+=(int a, int b)

	
	//Student alice("Alice");

}