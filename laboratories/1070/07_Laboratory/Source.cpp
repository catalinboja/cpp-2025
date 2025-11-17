#include <iostream>
#include <string>
using namespace std;

// - static variables
// - constant static variables
// - static methods
// - costant variables
// - memory leaks
// - destructor
// - copy constructor

class StringUtils {
public:
	static string* copyStringArray(string* values, int noValues) {
		string* copy = new string[noValues];
		for (int i = 0; i < noValues; i++) {
			copy[i] = values[i];
		}
		return copy;
	}
};

class VideoGame {
	string* hallOfFame = nullptr;
	int noPlayers = 0;
	const string name = "";
	float price = 0;
	static float TOTAL_VALUE; //sum of all video games prices

public:
	void setHallOfFame(string* values, int noValues) {
		//DON't shallow copy
		//this->hallOfFame = values;

		//avoid the memory leak
		if (this->hallOfFame != nullptr)
			delete[] this->hallOfFame;

		this->hallOfFame = StringUtils::copyStringArray(values, noValues);
		this->noPlayers = noValues;
	}

	string* getHallOfFame() {
		return StringUtils::copyStringArray(
			this->hallOfFame, this->noPlayers);
	}

	int getNoPlayers() {
		return this->noPlayers;
	}

	void print() {
		cout << endl << "Video game: " << this->name;
		cout << endl << "Hall of Fame: ";
		for (int i = 0; i < this->noPlayers; i++) {
			cout << " " << this->hallOfFame[i];
		}
	}

	~VideoGame() {
		delete[] this->hallOfFame;
	}

	//copy constructor
	VideoGame(const VideoGame& game): name(game.name) {
		//game.price = this->price;
		this->price = game.price;
		this->hallOfFame = StringUtils::copyStringArray(
			game.hallOfFame, game.noPlayers);
		this->noPlayers = game.noPlayers;
		//you can't here beucause is constant
		//this->name = game.name;
	}

	VideoGame(): name("") {

	}
};

float VideoGame::TOTAL_VALUE = 0;

int main() {
	VideoGame wow;
	wow.print();

	string topPlayers[3] = { "John", "Alice", "Bob" };
	wow.setHallOfFame(topPlayers, 3);
	wow.print();

	VideoGame starcraft;
	starcraft.setHallOfFame(topPlayers, 3);
	starcraft.print();
}