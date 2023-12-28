#include <stdio.h>
#include "getline.c"

#define MAXLINE 1000
#define LONGLINE 80 /* Exercice choice */

int main(void)
{
  int len;
  char line[MAXLINE];

  while((len = get_line(line, MAXLINE)) > 0)
  {
    if (len > LONGLINE)
      printf("%s", line);
  }
  return 0;
}
