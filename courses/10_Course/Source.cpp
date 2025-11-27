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

	//alternative to overloading <<
	void writeToTextFile(ofstream& file) {
		if (this->name != nullptr) {
			file << "Name: " << this->name << endl;
		}
		file << "Age: " << this->age << endl;
		if (this->grades != nullptr) {
			file << "Grades: ";
			for (int i = 0; i < this->noGrades; i++) {
				file << " " << this->grades[i];
			}
			file << endl;
		}
	}

	friend void operator<<(ofstream& file, Student& stud);
	friend void operator>>(ifstream& file, Student& s);
};

void operator<<(ofstream& file, Student& stud) {
	if (stud.name != nullptr) {
		file << "Name: " << stud.name << endl;
	}
	file << "Age: " << stud.age << endl;
	if (stud.grades != nullptr) {
		file << "Grades: ";
		for (int i = 0; i < stud.noGrades; i++) {
			file << " " << stud.grades[i];
		}
		file << endl;
	}
}

void operator>>(ifstream& file, Student& s) {
	char buffer[1000];
	file >> buffer;

	delete[] s.name;
	s.name = new char[strlen(buffer) + 1];
	strcpy_s(s.name, strlen(buffer) + 1, buffer);

	int age;
	file >> age;
	s.age = age;

	//alternative
	//file >> s.age;

	int noGrades;
	file >> noGrades;

	delete[] s.grades;
	s.grades = new int[noGrades];
	s.noGrades = noGrades;

	for (int i = 0; i < noGrades; i++) {
		file >> s.grades[i];
	}

}

int main() {
	//reading from console
	int vb;
	string text;
	string text2;
	string text3;

	//cout << endl << "Give me a number: ";
	//cin >> vb;
	//cout << endl << "Value is: " << vb;


	//space is used as input separator
	//cout << endl << "Give me a text: ";
	//cin >> text;
	//cout << endl << "Text is: " << text;
	//cout << endl << "Give me another text: ";
	//cin >> text2;
	//cout << endl << "Other text is: " << text2;
	//cin >> text3;
	//cout << endl << "Other text is: " << text3;

	//read with space
	//char buffer[1000];
	//cout << endl << "Give me a text with space: ";
	//cin.getline(buffer, 999);
	//cout << endl << "Text with space: " << buffer;
	//text = string(buffer);
	//cout << endl << "Text with space: " << text;

	//text files
	// in C you were using FILE

	//in C++ we use classes from fstream
	fstream file; //generic class
	ofstream fileForWriting; //class for opening files in write mode
	ifstream fileForReading; //class for opening files in read mode

	int grades[3] = { 10,10,9 };
	Student john("John", 22, grades, 3);

	//create a report to store students data
	//by default all files are considered text
	ofstream report("students.txt", ios::ate); //open file in truncate mode
	if (report.is_open()) {
		//write into the text file
		report << "\t\t Students Data Report" << endl;
		report << "\t Current date: Nov 27, 2025" << endl;

		report << john;
		john.writeToTextFile(report);

	}
	else {
		cout << endl << "***** ERROR File not created *******";
	}

	//don't forget to close the file when you are done
	report.close();


	//read from text files
	//create the text file in a standard format that is easy to read
	//other formats: CSV, JSON, XML

	//simple format
	//1. each line has a single value
	//2. before multiple lines that store multiple values (array) 
	// put a line with their number

	//open a text file in read mode
	ifstream inputFile("backup.txt");
	if (inputFile.is_open()) {
		//use the file pattern
		string name;
		char buffer[100];
		//inputFile >> name; //stop on space
		inputFile.getline(buffer, 99);
		cout << endl << "Name from file: " << buffer;
		int age;
		inputFile >> age;
		cout << endl << "Age from file: " << age;
		int noGrades;
		inputFile >> noGrades;
		cout << endl << "No of grades from file: " << noGrades;
		for (int i = 0; i < noGrades; i++) {
			int grade;
			inputFile >> grade;
			cout << endl << "Grade from file: " << grade;
		}
	}
	else
	{
		cout << endl << "***** ERROR Missing file *******";
	}
	inputFile.close();

	//test reading a student
	ifstream backup("backup.txt");
	if (backup.is_open()) {
		backup >> john;
	}
	backup.close();

	ofstream report2("john.txt");
	report2 << john;
	report2.close();

	//binary files
	//343455465 - as text -> 9 bytes
	//			- as binary -> 4 bytes

	vb = 23;

	ofstream binaryFile("students.bin", ios::binary | ios::ate);
	if (binaryFile.is_open()) {
		//write into binary files
		//NEVER use <<
		//binaryFile << vb;


		//little endian
		binaryFile.write((char*)&vb, sizeof(int));
	}
	binaryFile.close();


}
