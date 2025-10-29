#include <iostream>
#include <string>
using namespace std;

class DynamicArrays {
	//pointer to an array of chars
	char* text = nullptr;

	//pointer to an array of numbers
	//int, float, double, unsigned int
	int* integers = nullptr;
	//number of values in the array
	int noIntegers = 0;

	float* floatValues = nullptr;
	int noFloatValues = 0;

	//pointer to an array of strings
	string* names = nullptr;
	int noNames = 0;


	//C alternative
	//char** namesInC;
public:

	void initText(const char* value) {
		//1 alocate space
		int textSize = strlen(value) + 1;
		this->text = new char[textSize];
		//2 copy values (DONT' SHALLOW COPY)
		//this->text = value; DONT' SHALLOW COPY

		strcpy_s(this->text, textSize, value);
		//the same
		//strncpy(this->text, value, textSize);
	}

	void setNames(string* values, int noValues) {
		//alocate
		this->names = new string[noValues];

		//copy values
		//this->names = values; //DON'T shallow copy
		for (int i = 0; i < noValues; i++) {
			this->names[i] = values[i];
		}

		//don't forget about the variable that manages the
		// number of elements in the array
		this->noNames = noValues;
	}

	void setIntegers(int* values, int noValues) {
		//as we did for the names
	}

	int getNoNames() {
		return this->noNames;
	}

	//other ops on arrays
	// searching for a value
	// adding a new value
	// do simple math: min / max / avg
};

class StaticArrays {
	char text[100];

	int integers[100];
	int noIntegers = 0;

	float floatValues[100];
	int noFloatValues = 0;

	string names[100];
	int noNames = 0;

public:
	void initText(const char* value) {
		//copy the value
		strcpy_s(this->text, value);
	}

	void setIntegers(int* values, int noValues) {

		if (noValues > 100) {
			throw "Too many values";
		}

		//copy
		for (int i = 0; i < noValues; i++) {
			this->integers[i] = values[i];
		}
		this->noIntegers = noValues;
	}

	//other ops on arrays
	// searching for a value
	// adding a new value
	// do simple math: min / max / avg
};

class TestPointers {
public:
	int value = 0;

	void printValue() {
		cout << endl << "The value is: " << this->value;
	}

	void setValue(int newValue) {
		//no negative values
		if (newValue < 0) {
			throw  "Negative value";
		}

		this->value = newValue;
	}
};

void changeValueToSomething(TestPointers obj, int newValue) {
	obj.value = newValue;
}

void changeValueToSomethingWithPointers(
	TestPointers* pObj, int newValue) {
	pObj->value = newValue;
}

void changeValueToSomethingWithReferences(
	TestPointers& obj, int newValue) {
	obj.value = newValue;
}

class Course {
private:
	string name = "";
	int noStudents = 0;
	const int id; //by default 0xccccccc

public:

	//NEVER for const's
	//void setId(int value) {
	//	this->id = value;
	//}

	int getNoStudents() {
		return this->noStudents;
	}

	string getName() {
		return this->name;
	}

	//if the class has no explicit constructors
	// then you get for free the default one
	Course():id(0) {
		cout << endl << "Course default ctor";
	}

	//if you define a single constructor with params
	// THERE IS NO free default ctor

	//constructor with params - course name
	Course(string name):id(0)  {
		cout << endl << "Course ctor with name param";
		this->name = name;
	}

	//constructor with params - course name & no Students
	Course(string name, int noStudents, int idValue)
		:id(idValue){
		cout << endl << "Course ctor with name and no params";
		this->name = name;
		this->noStudents = noStudents;
	}
};

int main() {
	DynamicArrays obj;
	obj.initText("Hello");

	string values[2] = { "John","Alice" };
	obj.setNames(values, 2);
	cout << endl << "No names: " << obj.getNoNames();

	TestPointers tp;
	tp.printValue();

	changeValueToSomething(tp, 100);
	tp.printValue();

	changeValueToSomethingWithPointers(&tp, 100);
	tp.printValue();

	changeValueToSomethingWithReferences(tp, 50);
	tp.printValue();

	//constructors
	Course oop;
	Course atp;
	Course macroeconomics;
	//TODO: Don't forget to put names in your courses

	cout << endl << "Course name: " << oop.getName();
	cout << endl << "Course name: " << atp.getName();
	cout << endl << "Course name: " << macroeconomics.getName();

	Course realOOP("OOP");
	Course realATP("ATP");

	cout << endl << "Course name: " << realOOP.getName();
	cout << endl << "Course name: " << realATP.getName();

	Course otherOOP("OOP", 100, 643);
	cout << endl << "Course name: " 
		<< otherOOP.getName();
	cout << endl << "Course students: " 
		<< otherOOP.getNoStudents();

	int vb = 10;
	if (vb == 10) {
		cout << endl << "Is 10";
	}
	if (vb == 20) {
		cout << endl << "Is 20";
	}

}

