#include <iostream>
#include <string>
using namespace std;

class AbstractCommand {
protected:
	string text = "";
	bool isExecuted = false;
public:
	virtual void execute() = 0;
	virtual void parse() = 0;
	string getText() {
		return this->text;
	}
};

class SelectCommand : public AbstractCommand {
protected:
	string targetTable;
public:
	//override parse
	void parse() {
		cout << endl << "Parsing Select command";
	}

	//override execute
	void execute() {
		cout << endl << "Executing Select command";
	}
};


int main() {
	//AbstractCommand command;

	SelectCommand select;

	AbstractCommand* commands[2];
	commands[0] = &select;
	commands[1] = new SelectCommand();

	for(int i = 0; i < 2; i++) {
		commands[i]->execute();
	}
}