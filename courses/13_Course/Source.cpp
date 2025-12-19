
//last course
// - has-a as 1:1 or 1:M (static array, dynamic array, dynamic array of pointer to objects) 
// - is-a as 1:1 inheritance (multi-inheritance - why not to use it)

//today course
// - inheritance
// - protected
// - build frameworks of classes
// - upcasting vs downcasting
// - virtual functions
// - overriding 
// - overriding + overloading = polymorphims

#include <string>
#include <iostream>
using namespace std;


class Student {
protected:
	string name;
	int age;
	string faculty;
	string bachelorProgram;
public:
	string getName() {
		return this->name;
	}

	Student(string name, int age) {
		this->name = name;
		this->age = age;
	}

	Student() {

	}

	virtual void getBasicInfo() {
		cout << endl << "It is a student";
	}
};

//MasterStudent inherits/extends Student
class MasterStudent : public Student{
	string masterProgram;
	string masterFaculty;
public:
	void display() {
		cout << endl << "Name: " << this->getName();
		cout << endl << "Age: " << this->age;
		cout << endl << "Faculty: " << this->faculty;
		cout << endl << "Program: " << this->bachelorProgram;
		cout << endl << "Master program: " << masterProgram;
		cout << endl << "Master faculty: " << masterFaculty;

	}

	MasterStudent() : Student("John Doe", 0){

	}

	MasterStudent(string name, int age, string masterProgram)
		:Student(name, age)
	{
		this->masterProgram = masterProgram;
	}

	//NOT OK
	void getBasicInfoMaster() {
		cout << endl << "It is a master student";
	}

	//overriding the method from parent class
	void getBasicInfo() {
		cout << endl << "It is a master student";
	}
};

class PhdStudent : public MasterStudent {
	string phdProgram;
public:
	//NOT OK
	void getBasicInfoPhd() {
		cout << endl << "It is a phd student";
	}

	//overriding the method from parent class
	void getBasicInfo() {
		cout << endl << "It is a phd student";
	}

	void defendThesis() {
		cout << endl << this->phdProgram;
	}
};

class ErasmusStudent : public Student {
	string country;
};



int main() {
	Student john("John", 22);
	//cout << "John age is " << john.age;
	MasterStudent alice("Alice", 22, "Informatics");
	cout << endl << "Alice name is " << alice.getName();
	//cout << endl << "Alice name is " << alice.name;
	alice.display();

	//how do we handle all types of students
	//NOT like this
	//Student students[10];
	//MasterStudent masterStudents[10];
	//PhdStudent phdStudents[10];
	//ErasmusStudent erasmusStudent[10];

	PhdStudent bob;
	bob.getBasicInfo();
	alice.getBasicInfo();
	//alice.getBasicInfoMaster();
	//bob.getBasicInfoMaster();
	//bob.getBasicInfoPhd();

	Student student;
	student = alice; //UP-CASTGIN
	student = bob; //UP-CASTING

	Student students[3];
	students[0] = john;
	students[1] = alice;
	students[2] = bob;

	//PhdStudent newPhd = students[2];

	Student* studentsPointers[3];
	studentsPointers[0] = &john;
	studentsPointers[1] = &alice; //UP-CASTING at pointer level
	studentsPointers[2] = &bob;

	PhdStudent* pPhd = (PhdStudent*)studentsPointers[2]; //DOWN-CASTING
	pPhd->defendThesis();


	//DOWN-CASTING
	// works only if you know that you can do the conversion
	//PhdStudent kevin = (PhdStudent)students[2];

	cout << endl << " ------------------- ";

	for (int i = 0; i < 3; i++) {
		students[i].getBasicInfo();
	}


	cout << endl << " ------------------- ";
	for (int i = 0; i < 3; i++) {
		studentsPointers[i]->getBasicInfo(); 
		//early-binding without virtual
		//late-binding with virtual
		//	studentsPointers[i]->vfptr[0]()
	}
}
