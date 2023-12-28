#include <stdio.h>

int get_line(char s[], int lim)
{
  int c, i, j;

  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n' ; ++i )
    if (i < lim-2) {
      s[j] = c;
      j++;
    }

    if (c == '\n')
    {
      s[j] = c;
      ++j;
      ++i;
    }

    s[j] = '\0';
    return i;

}
