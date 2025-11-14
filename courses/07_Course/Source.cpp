#include <iostream>
using namespace std;

//last week
// - constructors
// - constant and static attributes
// - destructor
// - memory leaks and how to avoid them
// - dangling pointers

//this week
// - static and constant attributes
// - copy constructor
// - overloading operators

class StringUtils {
public:
	static char* createDeepCopy(const char* value) {
		if (value == nullptr)
			return nullptr;
		char* copy = new char[strlen(value) + 1];
		strcpy_s(copy, strlen(value) + 1, value);
		return copy;
	}
};

class Course {
	char* name = nullptr;
	unsigned int noStudents = 0;
	bool isOnline = false;

	static int NO_ONLINE_COURSES;

public:

	const static int MAX_NO_STUDENTS;

	void setNoStudents(unsigned int value) {
		if (value > MAX_NO_STUDENTS) {
			throw "Too many students";
		}
		this->noStudents = value;
	}

	unsigned int getNoStudents() {
		return this->noStudents;
	}


	//static methods don't receive 'this'
	static int getNoOnlineCourses() {
		//this->noStudents = 100;
		return Course::NO_ONLINE_COURSES;
	}

	void setName(const char* value) {
		this->name = StringUtils::createDeepCopy(value);
	}

	bool checkIsOnline() {
		return this->isOnline;
	}

	Course() {
		this->isOnline = false;
	}

	Course(const char* name, int noStudents, bool isOnline) {
		this->name = StringUtils::createDeepCopy(name);
		this->setNoStudents(noStudents);
		this->isOnline = isOnline;
		if (this->isOnline) {
			Course::NO_ONLINE_COURSES++;
		}
	}

	void moveItOnline() {
		if(!this->isOnline)
			Course::NO_ONLINE_COURSES++;
		this->isOnline = true;
	}

	void moveItInClass() {
		if(this->isOnline)
			Course::NO_ONLINE_COURSES--;
		this->isOnline = false;
	}

	~Course() {
		delete[] this->name;
		if(this->isOnline)
			Course::NO_ONLINE_COURSES--;
	}

	//copy constructor
	Course(const Course& c) {
		//c.noStudents = this->noStudents;
		this->noStudents = c.noStudents;
		this->name = StringUtils::createDeepCopy(c.name);
		this->isOnline = c.isOnline;
		if (this->isOnline)
			NO_ONLINE_COURSES++;
	}

	void print() {
		cout << endl << "Course name: " << this->name;
		cout << endl << "Course students: " << this->noStudents;
	}
};

const int Course::MAX_NO_STUDENTS = 1000;
int Course::NO_ONLINE_COURSES = 0;

void doSomething(Course c) {

}

Course doSomethingelse() {
	Course c;
	return c;
}

int main() {

	int noOnlineCourse = 0;
	Course c;
	int noStudents = 10000;
	//Course::MAX_NO_STUDENTS = 100000;
	if(noStudents < Course::MAX_NO_STUDENTS)
		c.setNoStudents(noStudents);

	cout << endl << c.getNoStudents();

	Course oop;
	Course atp;

	//cout << endl << "No online courses: " 
	//	<< Course::NO_ONLINE_COURSES;

	atp.moveItOnline();
	atp.moveItOnline();
	atp.moveItOnline();

	cout << endl << "No online courses: " 
		<< Course::getNoOnlineCourses();

	Course oop2("OOP", 150, false);
	oop2.print();

	//create a copy of oop2
	Course newOop = oop2; //copy constructor
	//newOop.print();

	doSomething(oop2);
}

