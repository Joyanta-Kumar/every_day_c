#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
const char consonants[21] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };

bool isVowel(char letter)
{
  for (int i = 0; i < 5; i++)
  {
    if (letter == vowels[i]) return true;
  }
  return false;
}

char getRandomVowel()
{
  char randomVowel = vowels[rand() % 5];
  return randomVowel;
}

char getRandomConsonant()
{
  char randomConsonant = consonants[rand() % 21];
  return randomConsonant;
}

char getRandomLetter() {
  if (rand() % 2 == 1) {
    return getRandomVowel();
  }
  else {
    return getRandomConsonant();
  }
}


char* getRandomName(int length)
{
  char* randomName = calloc(length+1, sizeof(char));

  for (int i = 0; i < length; i++) {
    randomName[i] = getRandomLetter();
  }

  return randomName;
}


int main()
{
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    printf("%s\n", getRandomName(3 + rand() % 5));
  }
  printf("\n");
  return 0;
}