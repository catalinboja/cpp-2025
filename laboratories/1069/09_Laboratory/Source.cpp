#include <iostream>
#include <string>

using namespace std;

enum class DeliveryType {EASYBOX, PERSONAL, PRIORITY};

class Delivery {
	char* address = nullptr;
	DeliveryType type = DeliveryType::EASYBOX;
	float price = 0;
	const int id = 0;

public:
	Delivery(const char* _address, DeliveryType _type,
		float _price, int _id) : id(_id), price(_price), type(_type)
	{
		//this->price = _price;
		this->address = new char[strlen(_address) + 1];
		strcpy_s(this->address, strlen(_address) + 1, _address);
	}

	~Delivery() {
		delete[]  this->address;
	}

	Delivery(const Delivery& delivery) 
		:id(delivery.id), price(delivery.price) 
	{
		this->type = delivery.type;
		if (delivery.address == nullptr) {
			this->address = nullptr;
		}
		else {
			int addressLength = strlen(delivery.address);
			this->address = new char[addressLength + 1];
			strcpy_s(this->address, addressLength + 1, delivery.address);
		}
	}

	//overload operator =
	void operator=(const Delivery& delivery) {

		if (this == &delivery) {
			return;
		}

		//this->id = delivery.id;
		this->price = delivery.price;
		this->type = delivery.type;

		delete[] this->address;

		if (delivery.address == nullptr) {
			this->address = nullptr;
		}
		else {
			int addressLength = strlen(delivery.address);
			this->address = new char[addressLength + 1];
			strcpy_s(this->address, addressLength + 1, delivery.address);
		}
	}

	void operator+=(int value) {
		this->price += value;
	}

	bool operator!() {
		if (this->type == DeliveryType::PERSONAL)
			return false;
		else
			return true;
	}

	friend void operator<<(ostream& console, Delivery& d);

}; //end of Delivery

void operator<<(ostream& console, Delivery& d) {
	console << endl << "Address: " << d.address;
	console << endl << "Price: " << d.price;
	//skip the type
	console << endl << "Id:" << d.id;
}


int main() {
	Delivery delivery("Piata Romana", DeliveryType::PERSONAL, 120, 1);

	//test the destructor
	Delivery* newDelivery = new Delivery("", DeliveryType::EASYBOX, 0, 0);
	delete newDelivery;

	{
		Delivery delivery2("Piata Romana", DeliveryType::PERSONAL, 120, 1);
	}

	Delivery deliveryCopy = delivery;

	deliveryCopy = delivery;
	delivery = delivery;

	cout << delivery;

	delivery += 10; //add the value to price

	cout << delivery;

	if (!delivery) {
		cout << endl << "Is not a PERSONAL delivery";
	}
	else {
		cout << endl << "Is a PERSONAL delivery";
	}
}