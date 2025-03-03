#include <stdio.h>

int main ()

{

    int n, a, b, c, d;

    scanf("%d", &n);

    a = n % 10;

    n /= 10;

    b = n % 10;

    n /= 10;

    c = n % 10;

    n /= 10;

    d = n;

    if (a == b && b == c)

        printf("Yes");

    else if (d == c && c == b)

        printf("Yes");

    else

        printf("No");



    return 0;

}
