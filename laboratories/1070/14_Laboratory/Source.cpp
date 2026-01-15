#include <iostream>
#include <string>

using namespace std;

//the base abstract class
class AbstractProduct {
protected:
	float price = 0;
	string name = "";
public:
	virtual float getFinalPrice() = 0; //virtual pure method
	virtual string getInfo() = 0;
	string getName() {
		return this->name;
	}
	void setPrice(float value) {
		if (value <= 0)
		{
			throw exception("Invalid value for price");
		}
		this->price = value;
	}
};

class ElectronicProduct: public AbstractProduct {
protected:
	int monthsOfWarranty = 24;
public:

	const static float VAT;

	// Implement the virtual pure methods
	float getFinalPrice() {
		//apply a 25% VAT
		return this->price * (1 + ElectronicProduct::VAT);
	}

	string getInfo() {
		string info = "Electronic product with a warranty of ";

		//char buffer[100];
		//_itoa_s(this->monthsOfWarranty, buffer, 10);
		//info = info + string(buffer);
		//info += " months";

		info = info + to_string(this->monthsOfWarranty) + " months";

		return info;
	}

};

const float ElectronicProduct::VAT = 0.25;


class ToyProduct : public AbstractProduct {
protected:
	int minAge = 3;
public:
	float getFinalPrice() {
		//use a 10% discount
		return this->price * 0.9;
	}
	string getInfo() {
		return "It is a toy with name " + this->name;
	}

	//override getName
	string getName() {
		return "Toy: " + this->name;
	}

};

int main() {
	//AbstractProduct product;
	AbstractProduct* pProduct = nullptr;

	ElectronicProduct laptop;

	pProduct = &laptop; //UP-CASTING at pointer level

	cout << endl << laptop.getInfo();
	cout << endl << "Final price: " << laptop.getFinalPrice();
	cout << endl << pProduct->getInfo();

	//an array of products
	AbstractProduct* products[3];
	AbstractProduct* * newProducts = nullptr;
	newProducts = new AbstractProduct* [5];

	delete[] newProducts;

	//products[0] = &laptop;
	//better
	products[0] = new ElectronicProduct(laptop);
	products[1] = new ToyProduct();
	products[2] = new ElectronicProduct();

	cout << endl << "----------------------";

	for (int i = 0; i < 3; i++) {
		cout << endl << products[i]->getInfo(); //LATE-BINDING with virtual methods
	}


	//try-catch
	laptop.setPrice(100);
	cout << endl << laptop.getFinalPrice();

	bool isPriceChanged = false;

	while (!isPriceChanged) {
		cout << endl << "New price for laptop:";
		float newPrice;
		cin >> newPrice;
		try {
			laptop.setPrice(newPrice);
			isPriceChanged = true;
		}
		catch (char* msg) {

		}
		catch (exception err) {
			cout << endl << "Price issue" << err.what();
		}
		catch (...) {
			cout << endl << "You have an issue";
		}
	}



}


