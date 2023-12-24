#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ReadArray(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf(" %i ", arr[i]);
  }
  printf(" ]\n");
}

int Min(int *arr, int size) {
  int min = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
    } else {
      continue;
    }
  }
  return min;
}

int Max(int *arr, int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    } else {
      continue;
    }
  }
  return max;
}

int RandomInt(int range) {
  int randint = (int)rand();
  return randint % range;
}

int *RandomArray(int size, int range) {
  int *arr = (int *)malloc(size * sizeof(int));

  if (arr == NULL) {
    return NULL;
  }

  for (int i = 0; i < size; i++) {
    arr[i] = RandomInt(range);
  }

  return arr;
}

void FreeArray(int *arr) { free(arr); }

int* ReverseArray(int* arr, int size)
{
  int* result = (int*)malloc(size * sizeof(int));
  if (result == NULL) {
    return NULL;
  }

  for (int i = size - 1; i >= 0; i--)
  {
    result[size - 1 - i] = arr[i];
  }
  
  return result;
}

int main(void) {
  srand(time(0));

  int size, range;
  printf("Size : ");
  scanf("%d", &size);

  printf("Range : ");
  scanf("%d", &range);

  int *array = RandomArray(size, range);
  ReadArray(array, size);

  int min = Min(array, size);
  int max = Max(array, size);

  printf("min : %i\n", min);
  printf("max : %i\n", max);

  FreeArray(array);
  return 0;
}
