#include <iostream>
#include <string>
#include "Methods.h"
using namespace std;

class Course {
private:
public:
	char profName[100] = "";
private:
	string name = "";
public:
	int noActivities = 0;
	string* activitiesNames = nullptr;
	double* activitiesPoints = nullptr;

// class public interface
public:
	string getName() {
		return this->name;
	 }

	void setName(string newName) {
		//validate the input
		//at least 3 characters
		//shoud NOT contain @

		if (newName.length() < 3 || newName.find("@") != string::npos) {
			throw "Invalid name";
		}

		this->name = newName;
	}

	char* getProfName() {
		//DON'T return the address of the array
		//return this->profName;
		return copyCharArray(this->profName);
	}

	void setProfName(const char* newName){
		//not less than 2 chars && more than 99
		if (strlen(newName) < 2 || strlen(newName) > 99) {
			throw "Name is too short";
		}
		strcpy_s(this->profName, newName);
	}
};

int main()
{
	Course course;
	//cout << endl << "Course name: " << course.name;
	strcpy_s(course.profName, "John");
	cout << endl << "Prof. name: " << course.profName;
	cout << endl << "Course name:" << course.getName();
	course.setName("OOP");
	cout << endl << "Course name:" << course.getName();
	//course.setName("12@OOP");

	cout << endl << "Prof name: " << course.getProfName();
	char* profName = course.getProfName();
	profName[0] = 'X';
	cout << endl << "Prof name: " << course.getProfName();

	//NOT NICE
	//char* newName;
	//newName = new char[strlen("Bob") + 1];
	//strcpy_s(newName, strlen("Bob") + 1, "Bob");
	//course.setProfName(newName);

	course.setProfName("Bob");

	cout << endl << "Prof name: " << course.getProfName();

}