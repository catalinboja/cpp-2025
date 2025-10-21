#include <string.h>

char* copyCharArray(char* input) {
	char* copy = new char[strlen(input) + 1];
	strcpy_s(copy, strlen(input) + 1, input);
	return copy;
}