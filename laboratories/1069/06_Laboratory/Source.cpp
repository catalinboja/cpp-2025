#include <iostream>
#include <string>
using namespace std;

//dynamic fields
//char*
//string*
//int/float/double *

//constant and static attributes
//memory-leaks
//destructor

enum class UniversityType {STATE, PRIVATE, FOREIGN};

class University {
private:
	const int id;
	char* name = nullptr;
	int noStudents = 0;
	UniversityType type = UniversityType::STATE;
	bool isAdmissionOpen = false;
public:

	static int MIN_NAME_LENGTH;
	static int MIN_NO_STUDENTS;

	char* getName() {
		//don't return the pointer
		//return a copy
		if (this->name == nullptr) {
			return nullptr;
		}
		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}

	void setName(const char* value) {
		//name should have at least 3 chars
		if (strlen(value) < University::MIN_NAME_LENGTH) {
			throw "Invalid name";
		}

		//avoid the memory leak
		delete[] this->name;

		this->name = new char[strlen(value) + 1];
		strcpy_s(this->name, strlen(value) + 1, value);
	}

	void setNumberOfStudents(int value) {
		if (value < University::MIN_NO_STUDENTS) {
			throw "Invalid number";
		}
		this->noStudents = value;
	}

	//ctor with all params
	University(int id, const char* name, int noStudents,
		UniversityType type, bool openAdmission) :id(id){
		this->setName(name);
		this->setNumberOfStudents(noStudents);
		this->type = type;
		this->isAdmissionOpen = openAdmission;
	}

	//default ctor
	University(): id(0) {

	}

	University(const char* name, int noStudents, int id)
		:id(id) {
		this->setName(name);
		this->setNumberOfStudents(noStudents);
	}

	//class destructor
	~University() {
		cout << endl << "Class DESTRUCTOR";
		//release the memory in HEAP
		//avoid the memory leak
		delete[] this->name;
	}

	void print() {
		cout << endl << "------------------------";
		cout << endl << "University id: " << this->id;
		cout << endl << "University name: " << this->name;
		cout << endl << "University no students: " 
			<< this->noStudents;
		cout << endl << "Admission Open: " 
			<< this->isAdmissionOpen;
	}


}; //end of class

int University::MIN_NAME_LENGTH = 3;
int University::MIN_NO_STUDENTS = 50;


int main() {
	University ase;
	ase.setName("ASE");
	cout << endl << "University name: " << ase.getName();
	ase.setName("Bucharest Univ. of Economic Studies");
	cout << endl << "University name: " << ase.getName();

	University upb(1, "UPB", 10000, UniversityType::STATE, false);
	University ub("Bucharest University", 15000, 2);

	ase.print();
	upb.print();
	ub.print();

}