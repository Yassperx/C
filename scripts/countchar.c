#include <stdio.h>
#define BACKSPACE '\b'
#define TAB       '\t'
#define NEWLINE   '\n'

int main(void)
{
  char c;
  while ((c = getchar()) != EOF)
  {
    if (c == BACKSPACE) {
      putchar('\\');
      putchar('b');
    } else if (c == TAB) {      
      putchar('\\');
      putchar('t');
    } else if (c == NEWLINE) {      
      putchar('\\');
      putchar('n');
    } else {
      putchar(c);
    }
    printf("\n");
  }
}
