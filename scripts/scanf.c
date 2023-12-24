#include <stdio.h>
#define CHAR_LIMIT 20

int main(void)
{
    char s[CHAR_LIMIT];
    printf("s : ");
    scanf("%s", s);
    printf("s : %s\n", s);
    return 0;
}
