#include <stdio.h>

int main(void) {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 0;
  step = 0;

  fahr = lower;
  while (fahr <= upper)
  {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr += step;
  }
  return 0;
}
