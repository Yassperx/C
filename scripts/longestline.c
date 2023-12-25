#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[], int size);
void program();
int lenghtchars(char *s);

int main(void)
{
  // program();
  char t[] = "small";
  char s[] = "biiggggg";
  printf("to\t: %s\t\t(size : %i)\nfrom\t: %s\t(size : %i)\n", t, lenghtchars(t), s, lenghtchars(s));
  copy(t, s, 10);
  printf("to\t: %s\t\t(size : %i)\nfrom\t: %s\t(size : %i)\n", t, lenghtchars(t), s, lenghtchars(s));
  return 0;
}

int lenghtchars(char *s)
{
    size_t size = 0;

    while (s[size] != '\0') {
        ++size;
    }

    return size;
}


void copy(char *to, char *from, int size)
{
  size_t size1 = lenghtchars(to);
  size_t size2 = lenghtchars(from);

  if (size1 > size2) 
  {

    for (int i=0; i<size1; i++) {
    to[i] = from[i];
    }
  }
  else if (size1 < size2) 
  {
    char empty[size2];
    to = empty;

    for (int i=0; i<size1; i++) {
    to[i] = from[i];
    }
  }
  else 
  {
    for (int i=0; i<size1; i++) 
    {
      to[i] = from[i];
    }
  }

}

int get_line(char s[], int lim)
{
  int c, size;
  for (int i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[size] = c;
    ++size;
  }
  s[size] = '\0';
  return size;
}

void program()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while((len = get_line(line, MAXLINE)) > 0)
  {
    if (len > max)
    {
      max = len;
      copy(longest, line, len);
    }
  }
  if (max > 0)
  {
    printf("%s", longest);
  }
}
