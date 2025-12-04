#include <iostream>
#include <string>
using namespace std;

class VideoGame {
	char* description = nullptr;
	float price = 0;
	const string name = "";

public:
	VideoGame(string name, float price)
		:name(name), price(price)
	{
	}

	VideoGame(const VideoGame& game):name(game.name), price(game.price) {
		if (game.description == nullptr) {
			this->description = nullptr;
		}
		else {
			this->description = new char[strlen(game.description) + 1];
			strcpy_s(this->description,
				strlen(game.description) + 1, game.description);
		}
	}

	~VideoGame() {
		delete[] this->description;
	}

	//overload =
	void operator=(VideoGame game) {

		//test if this and game are the same object
		if (this == &game) {
			return;
		}

		//IN = you CAN'T copy the const attributes
		//this->name = game.name;
		this->price = game.price;

		delete[] this->description;

		if (game.description == nullptr) {
			this->description = nullptr;
		}
		else {
			this->description = new char[strlen(game.description) + 1];
			strcpy_s(this->description,
				strlen(game.description) + 1, game.description);
		}

	}

	//overload++

	//post increment
	VideoGame operator++(int) {
		VideoGame copy = *this;
		this->price += 1;
		return copy;
	}

	//int operator++(int) {
	//	int temp = this->price;
	//	this->price += 1;
	//	return temp;
	//}

	//pre increment
	VideoGame operator++(){
		this->price += 1;
		return *this;
	}

	VideoGame operator+(int value) {
		//+ - * and / DON'T CHANGE the operands
		//this->price += value;
		//return *this;

		VideoGame result = *this;
		result.price += value;
		return result;
	}

	void operator*=(float multiplier) {
		this->price *= multiplier;
	}

	bool operator!() {
		//return true if price < 500
		if (this->price < 500)
			return true;
		else
			return false;
	}

	bool operator==(VideoGame game) {
		if (this->price == game.price && this->name == game.name)
			return true;
		else
			return false;
	}

	//overload cast
	explicit operator float() {
		return this -> price;
	}

	//overload function
	bool operator()(int lowerLimit, int upperLimit) {
		if (this->price > lowerLimit && this->price < upperLimit)
			return true;
		else
			return false;
	}

	char operator[](int index) {
		if (index >= 0 && index < strlen(this->description))
			return this->description[index];
		else
			throw "Wrong index";
	}

	friend void operator<<(ostream& console, VideoGame game);
	friend void operator>>(istream& console, VideoGame& game);
	friend VideoGame operator+(int value, VideoGame game);
};

//overload the operator as a global method because 
// the 1st parameter is not the class type
void operator<<(ostream& console, VideoGame game) {
	console << endl << "Game name: " << game.name;
	console << endl << "Game price: " << game.price;
	if (game.description != nullptr) {
		console << endl << "Game description: " << game.description;
	}
}

void operator>>(istream& console, VideoGame& game) {
	cout << endl << "New price: ";
	console >> game.price;
	cout << endl << "New description: ";
	//DON't
	//console >> game.description;
	char buffer[100];
	console >> buffer; //don't use space
	//console.getline(buffer,99); //can read space

	delete[] game.description;
	game.description = new char[strlen(buffer) + 1];
	strcpy_s(game.description, strlen(buffer) + 1, buffer);
}

//overload int + VideoGame
VideoGame operator+(int value, VideoGame game) {
	//because we have the other + and they do the same
	//return game + value;

	VideoGame result = game;
	result.price += value;
	return result;
}

int main() {
	VideoGame fifa("Fifa 2026", 250);
	VideoGame fifaCopy = fifa;

	//operator =
	fifaCopy = fifa; //fifaCopy.operator=(fifa) 

	////stream operators
	cout << fifa;
	cin >> fifa;

	cout << fifa;


	int vb1 = 10;
	//int vb2 = ++vb1; //vb1 = 11 vb2 = 11
	//int vb2 = vb1++; //vb1 = 11 vb2 = 10

	////mathematical operators
	//// with 1 parameter
	VideoGame temp = fifa++; //similar with -- post //increments the price
	temp = ++fifa; //similar woth -- pre  //increments the price

	//int price = fifa++;


	////with 2 parameters
	////same for +,-,*,/
	
	cout << fifa;
	
	VideoGame newGame = fifa + 23; //add the value to the price

	cout << fifa;

	newGame = 10 + fifa;
	//fifa = fifa + "A new game for 2026"; //concatenate to the description

	////same for *=,/=,-=,+=
	fifa *= 1.5; //multiply the price by 1.5 times

	cout << fifa;

	////logic operators
	//// !,>,<,==,>=,<=
	if (!fifa) {
		cout << endl << "Price is less than 500";
	}
	else {
		cout << endl << "It's an expensive game";
	}
	if (fifa == newGame) {
		cout << endl << "Same game by name and price";
	}
	else {
		cout << endl << "Different games";
	}

	////cast operator
	float price = (float)fifa;

	////function operator
	bool priceIsInRange = fifa(100, 500);

	////index operator

	//char descriptionCharacter = fifa.getDescriptionCharAtIndex(2);

	char descriptionCharacter = fifa[2]; //gets the 3rd char in the description
	cout << endl << "Char: " << descriptionCharacter;
	fifa[2] = 'X'; 

	cout << fifa;

}