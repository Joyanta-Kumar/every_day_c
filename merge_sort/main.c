#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list {
  int* array;
  int length;
} List;

List* createRandomArray(
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


void printArray(int* array, int length)
{
  printf("Address: %p\nLength: %d\n", array, length);
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}


int main() {
  srand(time(NULL));

  List *list = createRandomArray(2, 15, 0, 100);
  int length = list->length;
  int *array = list->array;

  printArray(array, length);

  return 0;
}