#include <stdio.h>

void printchars(int start, int range)
{
  for (int i = start; i < range; i++)
  {
    if (i >= 32 && i <= 126) {
        printf("%c", i);
    } else {
      printf(".");
    }
  }
  printf("\n");
}

int main(void)
{
  printchars(32, 126);
  return 0;
}
