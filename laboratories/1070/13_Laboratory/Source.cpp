#include <iostream>
#include <string>

using namespace std;

class Vehicle {
	string registratioNumber = "";
	float km = 0;
public:
	virtual void getDescription() {
		cout << endl << "It's a vehicle";
	}
};

class ElectricVehicle : public Vehicle {
	float batteryCapacity = 0;
public:
	void getElectricVehicleDescription() {
		cout << endl << "It's an electric vehicle";
	}

	void getDescription() {
		//call the Vehicle version
		this->Vehicle::getDescription();
		cout << endl << "It's an electric vehicle";
	}
};

class InternalCombustionVehicle : public Vehicle {
	int engineCapacity = 0;
	float litersPerKm = 0;
public:
	//override 
	void getDescription() {
		cout << endl << "It's a classic vehicle";
	}
};

int main() {
	Vehicle v;
	v.getDescription();
	ElectricVehicle ev;
	ev.getDescription();
	InternalCombustionVehicle icv;
	icv.getDescription();

	v = ev; //UP CASTING at object level
	v.getDescription();
	//ev = v; //DOWN CASTING

	//Vehicle vehicles[3]; //an array of objects
	//vehicles[0] = v;
	//vehicles[1] = ev;
	//vehicles[2] = icv;

	Vehicle* vehicles[3];
	vehicles[0] = &v; //Up CASTING at pointer level
	vehicles[1] = &ev;
	vehicles[2] = &icv;

	cout << endl << "--------------------";
	for (int i = 0; i < 3; i++) {
		vehicles[i]->getDescription();
	}
}