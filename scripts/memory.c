#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n = 4;
  int *x = malloc(n * sizeof(int));
  
  x[0] = 1;
  x[1] = 2;
  x[2] = 3;
  x[3] = 4;
  x[4] = 5;

  for (int i = 0; i < n+1; i++)
  {
    printf("%i\n", x[i]);
  }
  free(x);
  return 0;

}
