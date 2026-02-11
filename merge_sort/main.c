#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list {
  int* array;
  int length;
} List;

List* createRandomArrayList(
int minLength,
int maxLength,
int minValue,
int maxValue)
{
  List* list = malloc(sizeof(List));
  list->length = minLength + rand() % (maxLength - minLength + 1);
  list->array = malloc(sizeof(list->array[0]) * list->length);
  for (int i = 0; i < list->length; i++) {
    list->array[i] = minValue + rand() % (maxValue-minValue+1);
  }
  return list;
}


void printArrayList(int* array, int length)
{
  printf(" ---\n| Address:\t%p\n| Length:\t%d\n| Array:\t", array, length);
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n ---\n");
}


int main() {
  srand(time(NULL));

  List *list_1 = createRandomArrayList(2, 10, 0, 10);
  List *list_2 = createRandomArrayList(2, 10, 0, 10);

  printArrayList(list_1->array, list_1->length);
  printArrayList(list_2->array, list_2->length);

  return 0;
}