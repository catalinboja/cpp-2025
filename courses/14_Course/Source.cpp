#include <iostream>
#include <string>

using namespace std;

//abstract classes and virtual pure methods
//managing exceptions with try-catch

class Student {
protected:
	string name;
public:
	virtual void getInfo() {
		cout << endl << "It's a student";
	}

	virtual void takeExam()  = 0; //virtual pure method
};

class MasterStudent : public Student {
protected:
	string bachelorDiploma;
public:
	//override
	//overriding  + overloading  = polymorphism
	void getInfo() {
		cout << endl << "It's a master student. Graduated " 
			+ this->bachelorDiploma;
	}

	void takeExam() {
		cout << endl << "Take an exam";
	}
};

class PhdStudent : public MasterStudent {
	string masterDiploma;
public:
	void getInfo() {

		//calling getInfo from the parents - if needed
		//this->Student::getInfo();
		//this->MasterStudent::getInfo();

		cout << endl << "It's a PhD student. Graduated "
			+ this->bachelorDiploma + " and the master " + this->masterDiploma;
	}

	void setDiploma(string diploma) {
		if (diploma.size() < 3) {
			//throw "Wrong diploma";
			//throw exception("Wrong diploma");
			throw new exception("Wrong diploma");
		}
		this->masterDiploma = diploma;
	}

};

class ErasmusStudent : public Student {
	string country;
public:
	void takeExam() {
		cout << endl << "Take an exam";
	}
};

int main() {
	Student* students[4];
	//students[0] = new Student();
	students[0] = new ErasmusStudent();
	students[1] = new ErasmusStudent();
	students[2] = new MasterStudent();
	students[3] = new PhdStudent();

	MasterStudent ms;
	ms.getInfo();

	for (int i = 0; i < 4; i++) {
		students[i]->getInfo();
	}


	PhdStudent phd;
	try {
		phd.setDiploma("1");
	}
	catch (exception e) {
		cout << endl << "We have an exception ";
		cout << endl << e.what();
	}
	catch (exception* e) {
		cout << endl << "We have an exception ";
		cout << endl << e->what();
		delete e;
	}
	catch (...) {
		cout << endl << "Houston we have a problem !";
	}
	

}