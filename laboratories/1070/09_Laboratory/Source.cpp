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

	VideoGame(const VideoGame& game) 
		:name(game.name), price(game.price) {
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
	void operator=(VideoGame& game) {

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

	friend void operator<<(ostream& console, VideoGame game);
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

int main() {
	VideoGame fifa("Fifa 2026", 250);
	VideoGame fifaCopy = fifa;

	//operator =
	fifaCopy = fifa; //fifaCopy.operator=(fifa) 
	
	////stream operators
	cout << fifa;
	//cin >> fifa;

	////mathematical operators
	//// with 1 parameter
	//fifa++; //similar with -- post
	//++fifa; //similar woth -- pre

	////with 2 parameters
	////same for +,-,*,/
	//VideoGame newGame = fifa + 23;
	//newGame = 10 + fifa;
	//fifa = fifa + "A new game for 2026";

	////same for *=,/=,-=,+=
	//fifa *= 1.5; //multiply the price by 1.5 times

	////logic operators
	//// !,>,<,==,>=,<=
	//if (!fifa) {
	//	cout << endl << "Price is less than 500";
	//}
	//else {
	//	cout << endl << "It's an expensive game";
	//}
	//if (fifa == newGame) {
	//	cout << endl << "Same game by name and price"
	//}
	//else {
	//	cout << endl << "Different games";
	//}

	////cast operator
	//float price = (float)fifa;

	////function operator
	//bool priceIsInRange = fifa(100, 500);

	////index operator
	//char descriptionCharacter = fifa[2]; //gets the 3rd char in the description
	//fifa[2] = 'X';

}