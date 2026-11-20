#include <stdio.h>

int main()
{
    int a, b, c, d;
    int e, f, g, h;

    int p1, p2, p3, p4, p5, p6, p7;

    printf("Enter first matrix:\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    printf("Enter second matrix:\n");
    scanf("%d %d %d %d", &e, &f, &g, &h);

    p1 = a * (f - h);
    p2 = (a + b) * h;
    p3 = (c + d) * e;
    p4 = d * (g - e);
    p5 = (a + d) * (e + h);
    p6 = (b - d) * (g + h);
    p7 = (a - c) * (e + f);

    int c11 = p5 + p4 - p2 + p6;
    int c12 = p1 + p2;
    int c21 = p3 + p4;
    int c22 = p1 + p5 - p3 - p7;

    printf("Result:\n");

    printf("%d %d\n", c11, c12);
    printf("%d %d\n", c21, c22);

    return 0;
}