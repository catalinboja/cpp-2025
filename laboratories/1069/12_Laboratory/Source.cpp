#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Driver {
public:
	string name = "";
	int age = 0;
public:
	Driver(string name, int age) :name(name), age(age) {

	}

	Driver(const Driver& driver)
		: name(driver.name), age(driver.age) {

	}
};

class Box {
public:
	string address = "";
	float weight = 0;
public:

	Box() {

	}

	Box(string address) : address(address) {

	}
};

enum class EngineType { ELECTRIC = 10, GASOLINE, DIESEL  = 30};

class DeliveryVan {
public:
	Driver driver;	//1:1 has-a relation
	//Box boxes[50];
	Box* boxes = nullptr;		//1:M has-a relation
	int noBoxes= 0;
	EngineType engine = EngineType::GASOLINE;
	int maxSpeed = 0;
public:
	DeliveryVan():driver("John Doe", 18) {

	}

	DeliveryVan(const DeliveryVan& van)
		: maxSpeed(van.maxSpeed), engine(van.engine), 
		noBoxes(van.noBoxes), driver(van.driver)
		//we use the Driver copy ctor
	{
		this->boxes = new Box[this->noBoxes];
		for (int i = 0; i < this->noBoxes; i++) {
			this->boxes[i] = van.boxes[i];
		}
	}
	void addBox(Box box) {
		Box* newList = new Box[this->noBoxes + 1];
		for (int i = 0; i < this->noBoxes; i++) {
			newList[i] = this->boxes[i];
		}
		newList[this->noBoxes] = box;
		delete[] this->boxes;
		this->noBoxes += 1;
		this->boxes = newList;
	}
};

int main() {
	EngineType type = EngineType::ELECTRIC;
	if (type == EngineType::ELECTRIC)
		cout << endl << "It's an electric engine";
	//cout << endl << type;

	DeliveryVan fan1;

	Box box1("Piata Romana 7");
	Box box2("Calea Dorobanti 15");

	fan1.addBox(box1);
	fan1.addBox(box2);


	//generate a text report file
	ofstream reportFile("van report.txt", ios::ate);
	if (reportFile.is_open()) {
		reportFile << "\n\t\t Van Info";
		reportFile << "\n\tDriver info:";
		reportFile << "\n Name: " << fan1.driver.name;
		reportFile << "\n Age: " << fan1.driver.age;
		reportFile << "\n\tVan info:";
		reportFile << "\n Max speed:" << fan1.maxSpeed;
		reportFile << "\n\Boxes list:";
		if (fan1.noBoxes > 0) {
			for (int i = 0; i < fan1.noBoxes; i++) {
				reportFile << "\n Address: " << fan1.boxes[i].address <<
					" with weight: " << fan1.boxes[i].weight;
			}
		}
		reportFile.close();	
	}
	else
	{
		cout << endl << "************ Issues with the file";
	}


	ofstream backupFile("backup.bin", ios::binary | ios::ate);
	if (backupFile.is_open()) {
		//write the van max speed
		backupFile.write((char*)&fan1.maxSpeed, sizeof(int));
		//write the driver name
		backupFile.write(fan1.driver.name.c_str(),
			sizeof(char) * fan1.driver.name.size());
		backupFile.close();
	}

}