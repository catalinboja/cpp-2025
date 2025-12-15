#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// managing files
// - text files
// - binary files
// - reading from the console

class Student {
	char* name = nullptr;
	int age = 0;
	int* grades = nullptr;
	int noGrades = 0;
public:
	Student(const char* name, int age, int* grades, int noGrades) : age(age) {
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->grades = new int[noGrades];
		for (int i = 0; i < noGrades; i++) {
			this->grades[i] = grades[i];
		}
		this->noGrades = noGrades;
	}

	~Student() {
		delete[] this->name;
		delete[] this->grades;
	}

	//TODO: copy ctor, operator = 


	//function that writes the student into a binary file
	void writeToBinary(ofstream& file) {
		//DON'T write addresses in binary files
		//file.write((char*)this, sizeof(Student));

		//write values
		//write age
		file.write((char*)&this->age, sizeof(int));
		//write the name + the ending \0
		//write the size of the name - you need it later
		int nameSize = strlen(this->name) + 1;
		file.write((char*)&nameSize, sizeof(int));
		file.write(this->name,
			sizeof(char) * strlen(this->name) + 1);

		//write grades
		//start with their number
		file.write((char*)&this->noGrades, sizeof(int));
		for (int i = 0; i < this->noGrades; i++) {
			file.write((char*)&this->grades[i], 
				sizeof(int));
		}
	}

	void readFromBinary(ifstream& file) {
		//file.read((char*)this, sizeof(Student));
		//read the age
		file.read((char*)&this->age, sizeof(int));
		//read the name size
		int nameSize;
		file.read((char*)&nameSize, sizeof(int));

		delete[] this->name;
		this->name = new char[nameSize];
		file.read(this->name, nameSize);

		delete[] this->grades;
		file.read((char*)&this->noGrades, sizeof(int));

		this->grades = new int[this->noGrades];

		for (int i = 0; i < this->noGrades; i++) {
			file.read((char*)&this->grades[i], sizeof(int));
		}

	}

	void print() {
		cout << endl << "Name: " << this->name;
		cout << endl << "Age: " << this->age;
		if (this->noGrades > 0) {
			cout << endl << "Grades: ";
			for (int i = 0; i < this->noGrades; i++)
				cout << " " << this->grades[i];
		}
	}

};


int main() {

	int grades[3] = { 10,10,9 };

	Student john("John", 22, grades, 3);
	john.print();

	//writing into binary files
	ofstream dataFile(
		"backup.bin", ios::binary | ios::ate);

	//int vb = 23;
	//DON't use << for binary files
	//dataFile << vb;
	//dataFile.write((char*)&vb, sizeof(int));

	john.writeToBinary(dataFile);
	dataFile.close();

	Student temp("", 0, grades, 3);

	ifstream inputData("backup.bin", ios::binary);
	temp.readFromBinary(inputData);
	inputData.close();

	temp.print();

	temp = john;

}
