#include <stdio.h>

void printchars(int start, int range)
{
  for (int i = start; i < range; i++)
  {
    printf("%c", i);
  }
  printf("\n");
}

int main(void)
{
  printchars(0, 255);
  return 0;
}
