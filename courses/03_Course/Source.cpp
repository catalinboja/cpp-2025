#include <iostream>
using namespace std;

// course objective
// pointers
// dynamic arrays
// functions and passing values to functions

void printValue(int value) {
	int temp;
}

//NO GLOBALS
//int value1, int value2;

void interchange(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void interchange2(int* pa, int* pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void interchange3(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}



int main() {

	//pointer definition
	int variable = 10;
	int noStudents = 1000;

	int* pointer = (int*)10;
	//pointer = (int*)20;

	//read that is at address 10 in RAM
	cout << endl << "The number in memory at address 10 is "
		<< pointer;
	//cout << endl << "The number in memory at address 10 is "
	//	<< *pointer;
	cout << endl << "The number in memory at address 10 is "
		<< &pointer;
	cout << endl << "The variable is "
		<< variable;
	cout << endl << "The variable is "
		<< &variable;

	pointer = &noStudents;
	cout << endl << "No of students: " << noStudents;
	cout << endl << "No of students: " << pointer;
	cout << endl << "No of students: " << *pointer;

	noStudents = 2000;
	*pointer = 3000;
	cout << endl << "No of students: " << noStudents;

	printValue(variable);


	int value1 = 10;
	int value2 = 20;

	cout << endl << "v1 = " << value1 << " v2 = " << value2;

	int temp = value1;
	value1 = value2;
	value2 = temp;

	cout << endl << "v1 = " << value1 << " v2 = " << value2;

	interchange(value1, value2);
	cout << endl << "v1 = " << value1 << " v2 = " << value2;


	interchange2(&value1, &value2);
	cout << endl << "v1 = " << value1 << " v2 = " << value2;

	interchange3(value1, value2);
	cout << endl << "v1 = " << value1 << " v2 = " << value2;

}