#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int parseInt(char* str) {
    int number = 0;
    for (int multiplier = 1, index = 0; str[index] != '\0'; index++, multiplier *= 10) {
        int digit = (int) (str[index] - '0');
        number = number * multiplier + digit;
    }
    return number;
}


int getRandomInt(int btm, int top) {	
	int randomNumber = rand() % (top + 1 - btm);
	return randomNumber;
}


int main(int argc, char** argv) {
	srand(time(NULL));
	int btm = 0;
	int top = RAND_MAX;
	int count = 1;

	for (int i = 1; i < argc; i++) {
		if (btm == 0 && (strcmp("--bottom", argv[i]) == 0 || strcmp("-b", argv[i]) == 0)) {
			btm = parseInt(argv[ i + 1 ]);
		}
		else if (top == RAND_MAX && (strcmp("--top", argv[i]) == 0 || strcmp("-t", argv[i]) == 0)) {
			top = parseInt(argv[ i + 1 ]);
		}
		else if (count == 1 && (strcmp("--count", argv[i]) == 0 || strcmp("-c", argv[i]) == 0)) {
			count = parseInt(argv[ i + 1 ]);
		}
	}

	printf("btm: %d\ttop: %d\tcount: %d\n", btm, top, count);

	for (int i = 0; i < count; i++) {
		int randomNumber = getRandomInt(btm, top);
		printf("%d ", randomNumber);
	}
	return 0;
}
