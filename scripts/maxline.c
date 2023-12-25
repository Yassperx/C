#include <stdio.h>
#define MAX_LINE 1000

int getmyline(char s[], int lim);
void copy(char from[], char to[]);

int main(void)
{
  int max;
  int len;
  char line[MAX_LINE];
  char longest[MAX_LINE];

  max = 0;
  while((len = getmyline(line, MAX_LINE)) > 0)
    {
      if (len > max)
      {
        max = len;
        copy(longest, line);
      }
        
    }
  if (max > 0)
  {
    printf("%s", longest);
  }
  return 0;
}

int getmyline(char s[], int lim)
{
  int c,i;

  for (int i = 0; (i < lim-1) && ((c=getchar() != EOF) && (c != '\n')); i++)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char from[], char to[])
{
  int i=0;
  while((from[i]=to[i])!='\0')
    ++i;
}
