#include <stdio.h>

int main(void)
{
  char c;
  long count = 0;
  while ((c = getchar()) != EOF)
  {
    ++count;
    printf("%ld\n", count);
  }
}
