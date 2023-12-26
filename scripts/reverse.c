#include <stdio.h>
#define MAX 100

int main(void)
{
  char c;
  char temp[MAX];
  int i = 0;
  while ((c = getchar()) != EOF)
  {
    if (c != '\n') {
      temp[i] = c;
      i++;
    } else {
      for (int j = i; j >= 0; j--)
      {
        printf("%c", temp[j]);
      }
      for (int j = i; j >= 0; j--)
      {
        temp[j] = '\0';
      }
      i = 0;
      printf("\n");
    }
  }
}
