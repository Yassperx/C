#include <stdio.h>
#include <stdlib.h>

void brick(int height) {
  char brick_texture = '#';
  int n = 1;
  while (n < height + 1) {
    for (int i = 0; i < n; i++) {
      printf("%c", brick_texture);
    }
    printf("\n");
    n++;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <height>\n", argv[0]);
    return 1;
  }

  int height = atoi(argv[1]);

  if (height <= 0) {
    return 1;
  }

  brick(height);

  return 0;
}
