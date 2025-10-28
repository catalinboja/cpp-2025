#include <iostream>
#include <string>
using namespace std;

const int noActivities = 5;

class Course {
private:
	//the dynamic field
	char* name = nullptr;
	string prof = "";
	float pointsPerActivity[noActivities];
	unsigned int noStudents = 0;
public:
	//public interface
	string getProf() {
		return this->prof;
	}

	void setProf(string value) {
		//not less than 2 charactes and not more then 50
		if (value.size() < 2 || value.size() > 50)
			throw "Wrong name";
		this->prof = value;
	}

	unsigned int getNoStudents() {
		return  this->noStudents;
	}

	void setNoStudents(unsigned int value) {
		if (value > 150) {
			throw "Too many students";
		}
		this->noStudents = value;
	}

	char* getName() {
		//NEVER return the pointer
		//return this->name;

		//RETURN a copy
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy_s(nameCopy, strlen(this->name) + 1, this->name);
		return nameCopy;
	}

	void setName(const char* value) {
		//not less than 3 chars
		if (strlen(value) < 3) {
			throw "Invalid course name";
		}
		//this->name = value;
		this->name = new char[strlen(value) + 1];
		strcpy_s(this->name, strlen(value) + 1, value);
	}

	float* getPoints() {

		//DON'T return the pointer
		//return this->pointsPerActivity;

		//RETURN a copy
		float* copy = new float[noActivities];
		for (int i = 0; i < noActivities; i++) {
			copy[i] = this->pointsPerActivity[i];
		}
		return copy;
	}

};

int main() {
	Course course;
	//cout << endl << "Course prof: "
	//	<< course.prof;
	cout << endl << "Course prof: "
		<< course.getProf();
	//course.setProf("A");
	course.setProf("John");
	cout << endl << "Course prof: "
		<< course.getProf();
	course.setNoStudents(100);
	cout << endl << "No students: " <<
		course.getNoStudents();

	//char* newName = new char[4] {"OOP"};
	//course.setName(newName);

	course.setName("OOP");
	cout << endl << "Course name: " <<
		course.getName();

	char* courseNamePointer = course.getName();
	courseNamePointer[0] = 'X';
	delete[] courseNamePointer;

	cout << endl << "Course name: " <<
		course.getName();

	float* coursePoints = course.getPoints();
	coursePoints[0] = 10;

}