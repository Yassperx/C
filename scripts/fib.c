#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000
long long memo[MAX];

long long fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (n < 0)
    {
        printf("n < 0\n");
        return 1;
    }

    for (int i = 0; i < MAX; i++)
    {
        memo[i] = -1;
    }

    printf("%lld\n", fib(n));

    return 0;
}
