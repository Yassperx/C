#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x);

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <integer>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  int b = bitcount(x);

  printf("x\t: %i\n", x);
  printf("b\t: %i\n", b);
  return 0;
}

int bitcount(unsigned x)
{
  int b;
  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}
