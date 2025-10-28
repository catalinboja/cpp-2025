#include <iostream>
#include <string>
using namespace std;

class Assignment {
private:
	//int*
	//char*
	//string*
	char* requirements = nullptr;
	float points = 0;
	int noSubmissions = 0;
	string students[100]; //students names that submit the solution

	//special methods in a class
	//constructors
	//destructor
	//copy constructor



public:
	//class public interface
	// a collection of public methods that anyone can use

	//define a constructor with parameters
	Assignment(const char* requirements, int noPoints) {
		this->setPoints(points);
		this->setRequirements(requirements);
	}

	////define the default ctor
	//Assignment() {

	//}


	//read access methods - getters
	float getPoints() {
		//return this->points;
		return points;
	}

	//write access methods - setters
	void setPoints(float points) {
		//shadowing
		//points = points;
		//no less than 0 and more than 10
		if (points < 0 || points > 10)
		{
			throw "Invalid points";
		}
		this->points = points;
	}

	char* getRequirements() {
		//DON'T return the pointer
		//return this->requirements;

		if (this->requirements == nullptr)
			return nullptr;

		char* copy = new char[strlen(this->requirements) + 1];
		strcpy_s(copy, strlen(this->requirements) + 1, this->requirements);
		return copy;
	}

	void setRequirements(const char* value) {
		//at least 5 chars
		if (strlen(value) < 5) {
			throw "Invalid string";
		}

		//shallow copy
		//DON'T DO IT
		//this->requirements = value;

		//deep copy
		this->requirements = new char[strlen(value) + 1];
		strcpy_s(this->requirements, strlen(value) + 1, value);
	}
};

int main() {
	//encapsulation
	Assignment assign1("implement something", 10);
	//assign1.points = 10;
	//cout << endl << "points: " << assign1.points;

	cout << endl << "points: " << assign1.getPoints();
	assign1.setPoints(10);
	cout << endl << "points: " << assign1.getPoints();

	if(assign1.getRequirements() != nullptr)
		cout << endl << "Req: " << assign1.getRequirements();
	else
	{
		cout << endl << "No requirements";
	}

	char newRequirements[] = { "Implement a class in C++" };
	//assign1.setRequirements("Implement C++ class");
	assign1.setRequirements(newRequirements);

	if (assign1.getRequirements() != nullptr)
		cout << endl << "Req: " << assign1.getRequirements();
	else
	{
		cout << endl << "No requirements";
	}

	strcpy_s(newRequirements, "Don't do it");
	cout << endl << "Req: " << assign1.getRequirements();

	char* assign1Req = assign1.getRequirements();

	strcpy_s(assign1Req, 20, "Don");

	cout << endl << "Req: " << assign1.getRequirements();

	assign1.setRequirements("Implement C++ Student class");
}