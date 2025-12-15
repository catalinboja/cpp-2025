#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class UniversityType {STATE, PRIVATE, FOREIGN};
enum EngineType {GASOLINE, DIESEL, ELECTRIC};

class DeliveryVan {
	EngineType type = EngineType::ELECTRIC;
	string* addresses = nullptr;
	int noAddresses = 0;
	string driver = "";
	float km = 0; 
public:
	DeliveryVan() {
		this->driver = "John Doe";
	}
	DeliveryVan(string driver, float km, EngineType type,
		string* addr, int noAddr)
		:driver(driver),km(km), type(type)
	{
		this->addresses = new string[noAddr];
		for (int i = 0; i < noAddr; i++) {
			this->addresses[i] = addr[i];
		}
		this->noAddresses = noAddr;
	}

	~DeliveryVan() {
		delete[] this->addresses;
	}

	//method for serializing an object into a binary file
	void serialize(ofstream& file) {
		//write the van km
		file.write((char*)&this->km, sizeof(float));
		//write the type
		file.write((char*)&this->type, sizeof(EngineType));
		//write the driver name
		//write the size of name - you need this later when reading from file
		int nameSize = this->driver.size() + 1; //include \0
		file.write((char*)&nameSize, sizeof(int));
		file.write(this->driver.c_str(), sizeof(char) * nameSize);

		//write the addresses number
		file.write((char*)&this->noAddresses, sizeof(int));
		//write the addresses
		for (int i = 0; i < this->noAddresses; i++) {
			int addressSize = this->addresses[i].size() + 1; //include \0
			file.write((char*)&addressSize, sizeof(int));
			file.write(this->addresses[i].c_str(), 
				sizeof(char) * addressSize);
		}
	}


	friend void operator<<(ofstream& file, DeliveryVan& van);
};

void operator<<(ofstream& file, DeliveryVan& van) {
	file << endl << "Van data: engine " << van.type << " km " << van.km;
	file << endl << "Driver: " << van.driver;
	if (van.noAddresses > 0) {
		file << endl << "Addresses: ";
		for (int i = 0; i < van.noAddresses; i++) {
			file << " " << van.addresses[i];
		}
	}
}

int main() {
	UniversityType type = UniversityType::PRIVATE;
	//if (type == 1) {
	//	cout << endl << "It's a private university";
	//}

	//cout << endl << "Type: " << type;

	string destinations[3] = { "Piata Romana",
		"Piata Victoriei", "Piata Unirii" };
	DeliveryVan fan1("John", 1300, EngineType::GASOLINE, destinations, 3);

	//text files
	ofstream reportFile("Vans.txt", ios::app);
	if (!reportFile.is_open()) {
		cout << endl << "*********** ISSUES with the file **********";
	}
	else {
		reportFile << "\n\t\t Vans List:";
		reportFile << fan1;
		reportFile.close();
	}

	//binary files
	ofstream backupFile("backup.van", ios::binary | ios::ate);
	if (backupFile.is_open()) {
		fan1.serialize(backupFile);

		backupFile.close();
	}
	else {
		cout << endl << "Backup file corrupted";
	}
}

