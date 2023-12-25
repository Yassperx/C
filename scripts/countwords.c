#include <stdio.h>
#define OR ||

#define STATS "characters\t: %d\nwords\t: %d\nlines\t: %d\n"

int main(void)
{
    char c;
    int characters = 0;
    int words = 0;
    int lines = 0;
    int inWord = 0;  

    while ((c = getchar()) != EOF)
    {
        characters++;

        if (c == ' ' || c == '\t')
        {
            inWord = 0;
        }
        else if (c == '\n')
        {
            lines++;
            inWord = 0;
        }
        else
        {
            if (!inWord)
            {
                words++;
                inWord = 1;
            }
        }
    }

    printf(STATS, characters, words, lines);
    return 0;
}
