#include <stdio.h>

int main()
{
  int n = 5;
  int x = n++;
  printf("x : %i\n", x);
  
  int m = 5;
  int y = ++m;
  printf("y : %i\n", y);
}
