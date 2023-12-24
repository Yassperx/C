#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define CHAR_LIMIT 10

typedef char *string;

void stringcopy(string s, string t)
{
  for (int i = 0; i < strlen(s); i++)
  {
    t[i] = s[i];
  }
}


int main(void)
{
  char s[CHAR_LIMIT];
  printf("s : ");
  scanf("%[^\n]s",s);

  char t[CHAR_LIMIT];

  stringcopy(s, t);

  t[0] = toupper(t[0]);

  printf("s : %s\n", s);
  printf("t : %s\n", t);

  return 0;
}
