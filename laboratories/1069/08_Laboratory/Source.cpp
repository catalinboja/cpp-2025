#include <string>
#include <iostream>

using namespace std;

// no memory leaks
// no shallow copy
// static variables and constant static variables
// constant attributes
// static methods
// copy constructor && avoiding dangling pointers
// destructor
// overloading methods and operators

class ArraysUtil {
public:
	static float* copyFloatArray(float* values, int noElements) {
		float* copy = new float[noElements];
		for (int i = 0; i < noElements; i++) {
			copy[i] = values[i];
		}
		return copy;
	}
};

class Sensor {
	float* temperaturesPerDay = nullptr;
	int noDays = 0;
	string location = "";
	const float maxTemperature = 0; //the maximum value that the sensor can record

public:

	const static float MIN_TEMP;
	const static float MAX_TEMP;

	void setTemperatures(float* values, int noValues) {
		//validate each value between -30 and +50
		for (int i = 0; i < noValues; i++) {
			if (values[i] < Sensor::MIN_TEMP || values[i] > Sensor::MAX_TEMP)
				throw "Invalid value";
		}
		//copy & avoid memory
		delete[] this->temperaturesPerDay;
		this->temperaturesPerDay = 
			ArraysUtil::copyFloatArray(values, noValues);
		this->noDays = noValues;
	}

	float* getTemperatures() {
		return ArraysUtil::copyFloatArray(
			this->temperaturesPerDay, this->noDays);
	}

	int getNoDays() {
		return this->noDays;
	}

	void print() {
		cout << endl << "Sensor in :" << this->location;
		cout << endl << "Temperatures in last days: ";
		for (int i = 0; i < this->noDays; i++) {
			cout << " " << this->temperaturesPerDay[i];
		}
	}

	//destructor
	~Sensor() {
		delete[] this->temperaturesPerDay;
	}

	//copy constructor
	Sensor(const Sensor& sensor): maxTemperature(sensor.maxTemperature) {
		this->location = sensor.location;
		this->temperaturesPerDay =
			ArraysUtil::copyFloatArray(
				sensor.temperaturesPerDay, sensor.noDays);
		this->noDays = sensor.noDays;
		//this->maxTemperature = sensor.maxTemperature;
	}

	Sensor(): maxTemperature(80) {

	}

	Sensor(string location, float maxTemp,
		float* values, int noValues)
		: maxTemperature(maxTemp), location(location), 
		noDays(noValues) {

		this->temperaturesPerDay = 
			ArraysUtil::copyFloatArray(values, noValues);
	}

	//overloading operator =
	void operator=(Sensor source) {
		//copy values from source into this
		this->location = source.location;
		delete[] this->temperaturesPerDay;
		this->temperaturesPerDay = ArraysUtil::copyFloatArray(
			source.temperaturesPerDay, source.noDays);
		this->noDays = source.noDays;
		//NEVER for consts
		//this->maxTemperature = source.maxTemperature;
	}

};

const float Sensor::MIN_TEMP = -30;
const float Sensor::MAX_TEMP = 50;


int main() {
	Sensor bucharest;
	float values[3] = { 10.5, 11, 8 };
	bucharest.setTemperatures(values, 3);
	bucharest.setTemperatures(values, 3);

	bucharest.print();

	Sensor bucharestCopy = bucharest; //calling the copy ctor

	Sensor giurgiu("Giurgiu", 80, values, 3);
	giurgiu.print();

	giurgiu = bucharest; //operator=(Sensor, Sensor)
}
