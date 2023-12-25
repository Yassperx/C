#include <stdio.h>

int main(void)
{
  char c;
  printf("%i", EOF);
  printf("%i", EOF);
  while ((c = getchar()) != EOF)
  {
    putchar(c);
  }
}
