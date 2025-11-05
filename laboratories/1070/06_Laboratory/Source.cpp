#include <iostream>
#include <string>
using namespace std;

//classes
//constructors
//setters and getters without shallow copy (do deep copy)

//char*
//string*
//int/float/double *

enum class UniversityType {STATE, PRIVATE, FOREIGN};

class University {
private:
	UniversityType type = UniversityType::STATE;
	string* faculties = nullptr;
	string name;
	int noFaculties = 0;
	int noStudents = 0;
public:

	//constructors
	//default ctor
	University() {
		cout << endl << "University default ctor";
	}

	//ctor with all params
	University(
		string name,
		UniversityType type,
		int noStudents,
		string* faculties,
		int noFaculties
	) {
		cout << endl << "Ctor with all params";
		//shadowing
		//name = name;
		this->name = name;
		this->noStudents = noStudents;
		this->type = type;
		this->setFaculties(faculties, noFaculties);
	}

	University(string name, UniversityType type) {
		this->name = name;
		this->type = type;
	}


	void setFaculties(string* values, int noValues) {
		//this->faculties = values; //SHALLOW COPY
		//DEEP COPY
		this->faculties = new string[noValues];
		for (int i = 0; i < noValues; i++) {
			this->faculties[i] = values[i];
		}
		this->noFaculties = noValues;
	}

	//IT's a trap
	// noFaculties must change togheter with the faculties array
	//void setNoFaculties(int value) {
	//	this->noFaculties = value;
	//}

	string* getFaculties() {
		//DON't shallow copy
		//return this->faculties;

		//create and return a copy
		string* copy = new string[this->noFaculties];
		for (int i = 0; i < this->noFaculties; i++) {
			copy[i] = this->faculties[i];
		}
		return copy;
	}

	void print() {

		cout << endl << "-----------------------------------";

		cout << endl << "University: " << this->name;
		cout << endl << "No students: " << this->noStudents;
		switch (this->type) {
		case UniversityType::STATE:
			cout << endl << "Type: " << "State university";
			break;
		case UniversityType::PRIVATE:
			cout << endl << "Type: " << "Private university";
			break;
		case UniversityType::FOREIGN:
			cout << endl << "Type: " << "Foreign university";
			break;
		default:
			cout << endl << "Type: " << "Not covered !!!";
		}

		cout << endl << "Faculties: ";
		if (this->faculties == nullptr) {
			cout << " none ";
		}
		else {
			for (int i = 0; i < this->noFaculties; i++) {
				cout << " " << this->faculties[i];
			}
		}
	}

	void setType(UniversityType type) {
		this->type = type;
	}

	UniversityType getType() {
		return this->type;
	}

	string getTypeAsString() {

		switch (this->type) {
		case UniversityType::STATE:
			return "State";
		case UniversityType::PRIVATE:
			return "Private";
		case UniversityType::FOREIGN:
			return "Foreign";
		default:
			return "Undefined";
		}
	}

};

int main() {
	University ase;
	ase.print();

	string faculties[3] = {"CSIE", "MK", "MAN"};
	int values[3] = { 10,20,30 };
	char name[] = "CSIE";
	char* newName = new char[5] {"CSIE"};

	ase.setFaculties(faculties, 3);
	ase.print();

	University upb("UPB",UniversityType::STATE,10000,faculties, 3);
	upb.print();

	University ub("UB", UniversityType::STATE);
	ub.setType(UniversityType::FOREIGN);
	ub.print();
	cout << endl << "UB type: " << ub.getTypeAsString();


	string test = "test";
	const char* pTest = test.c_str();

}



