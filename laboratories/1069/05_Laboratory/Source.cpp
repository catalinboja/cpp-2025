#include <iostream>
#include <string>
using namespace std;

//defining a class
//getters and setters (with validation)
//shallow copy vs deep copy
//shadowing
//constructors (default and with params)

class Course {
private:
	float* hoursPerActivity = nullptr;
	int noActivities = 0;
	string name = "";
	int credit = 0;
public:
	string getName() {
		return this->name;
	}

	void setName(string name) {
		//shadowing
		//name = name;
		//the values should have at least 3 chars or 50 at most
		if (name.size() < 3 || name.size() > 50)
			throw "Invalid name";
		this->name = name;
	}

	int getCredit() {
		return this->credit;
	}

	void setCredit(int value) {
		//no negative values
		//maximum 6 credits
		if (value < 0 || value > 6) {
			throw "Invalid credit points";
		}
		credit = value;
	}

	void setHoursPerActivity(int value) {
		this->hoursPerActivity = new float[1];
		this->hoursPerActivity[0] = value; 
		this->noActivities = 1;
	}

	void setHoursPerActivity(
		float* values, int noActivities) {

		if (values == nullptr || noActivities <= 0) {
			throw "Invalid input values";
		}
		//deep copy
		this->hoursPerActivity = new float[noActivities];
		for (int i = 0; i < noActivities; i++) {
			this->hoursPerActivity[i] = values[i];
		}
		this->noActivities = noActivities;

		//shallow copy
		//this->hoursPerActivity = values;
	}

	int getNoActivities() {
		return this->noActivities;
	}

	float* getHoursPerActivity() {
		//shallow copy
		//return this->hoursPerActivity;

		//return a copy
		float* copy = new float[this->noActivities];
		for (int i = 0; i < this->noActivities; i++) {
			copy[i] = this->hoursPerActivity[i];
		}
		return copy;
	}
};

int main() {
	Course oopCourse;
	cout << endl << "Course name: "
		<< oopCourse.getName();
	oopCourse.setName("OOP");
	cout << endl << "Course name: "
		<< oopCourse.getName();

	cout << endl << "Course credits: "
		<< oopCourse.getCredit();
	oopCourse.setCredit(5);
	cout << endl << "Course credits: "
		<< oopCourse.getCredit();

	//test hours array setter
	float hours[3] = { 1.2, 4, 5.3 };

	oopCourse.setHoursPerActivity(hours, 3);

	int noActivities = oopCourse.getNoActivities();
	float* hoursPerActivity = oopCourse.getHoursPerActivity();
	cout << endl << "Hours: ";
	for (int i = 0; i < noActivities; i++) {
		cout << " | " << hoursPerActivity[i];
	}

}