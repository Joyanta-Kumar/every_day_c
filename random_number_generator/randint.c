#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int parseInt(char* str) {
    int number = 0;
    for (int multiplier = 1, index = 0; str[index] != '\0'; index++, multiplier *= 10) {
        int digit = (int) (str[index] - '0');
        number = number * multiplier + digit;
    }
    return number;
}

int getRandomInt(int bottom, int top) {	
	int randomNumber = rand() % (top + 1 - bottom);
	return randomNumber;
}

int main(int argc, char** argv) {

	srand(time(NULL));
	int bottom = parseInt(argv[1]);
	int top = parseInt(argv[2]);

	int randomNumber = getRandomInt(bottom, top);
	printf("%d", randomNumber);

	return 0;
}
