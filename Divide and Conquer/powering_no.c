#include <stdio.h>

long long power(int x, int n)
{
    if (n == 0)
        return 1;

    long long half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;

    else
        return x * half * half;
}

int main()
{
    int x, n;

    printf("Enter number: ");
    scanf("%d", &x);

    printf("Enter power: ");
    scanf("%d", &n);

    printf("Answer = %lld", power(x, n));

    return 0;
}