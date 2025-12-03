//Laboratory test requirements
//Define a class
// with constant attributes
// no magic numbers - use statics
// copy constructor
// destructor
// no dangling pointers
// operator =
// any other operator from: + - / * += -= *= /= == >
// < >= <= ++ -- (post vs pre) ! cast [] () << >>

#include <iostream>
#include <string>

using namespace std;

enum class Genre { POP, ROCK, TECHNO };

class MusicAlbum {
private:
	const int serial;
	string* songs = nullptr;
	int noSongs = 0;
	float price = 0;
	Genre genre = Genre::POP;
public:
	MusicAlbum(int serial, float price, Genre genre)
		:serial(serial), price(price) {
		this->genre = genre;
	}
	MusicAlbum(const MusicAlbum& album)
		: serial(album.serial), 
		price(album.price), genre(album.genre) {

		this->songs = new string[album.noSongs];
		for (int i = 0; i < album.noSongs; i++) {
			this->songs[i] = album.songs[i];
		}
		this->noSongs = album.noSongs;
	}

	~MusicAlbum() {
		delete[] this->songs;
	}

	MusicAlbum operator+(string song) {
		//+ - * / don't change the operands
		//DON'T change this
		MusicAlbum result = *this;
		string* newSongs = new string[result.noSongs + 1];
		for (int i = 0; i < result.noSongs; i++) {
			newSongs[i] = result.songs[i];
		}
		newSongs[result.noSongs] = song;
		result.noSongs += 1;
		delete[] result.songs;
		result.songs = newSongs;

		return result;
	}

	void operator= (const MusicAlbum& album) {
		if (this == &album)
			return;
		this->price = album.price;
		this->noSongs = album.noSongs;
		delete[] this->songs;
		this->songs = new string[album.noSongs];
		for (int i = 0; i < album.noSongs; i++) {
			this->songs[i] = album.songs[i];
		}
	}

	//with the & you can also change values
	string& operator[](int index) {
		if (index >= 0 && index < this->noSongs) {
			return this->songs[index];
		}
		else {
			throw "Wrong index";
		}
	}

	friend void operator <<(ostream& console, MusicAlbum& album);
	friend MusicAlbum operator+(int value, MusicAlbum& album);
};

void operator <<(ostream& console, MusicAlbum& album) {
	console << endl << "Serial: " << album.serial;
	console << endl << "Price:" << album.price;
	//TODO: print the enum as string other types
	if (album.genre == Genre::POP)
		console << endl << "Music type: POP";
	//DON't
	//console << endl << "Songs: " << album.songs;
	if (album.songs != nullptr) {
		console << endl << "Songs:";
		for (int i = 0; i < album.noSongs; i++) {
			console << " " << album.songs[i];
		}
	}
}

MusicAlbum operator+(int value, MusicAlbum& album) {
	MusicAlbum result = album;
	result.price += value;
	return result;
}

int main() {
	MusicAlbum album(1, 120, Genre::ROCK);
	MusicAlbum copy = album;

	{
		MusicAlbum technoAlbum(1, 120, Genre::TECHNO);
	}
	MusicAlbum* tempAlbum = new MusicAlbum(3, 100, Genre::POP);
	delete tempAlbum;

	cout << album;

	album = album + "Hello";
	album = album + "Bye";

	album = 10 + album; //add to price

	cout << album;

	cout << endl << "First song is " << album[0];

	album[0] = "The end";
	cout << album;

}