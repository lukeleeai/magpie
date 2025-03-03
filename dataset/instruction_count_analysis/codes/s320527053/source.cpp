#include <stdio.h>



int min(int a, int b)

{

    return a < b? a: b;

}



int main(void)

{

    int q, h, s, d;

    long long n;

    scanf("%d%d%d%d%lld", &q, &h, &s, &d, &n);

    h = min(h, q * 2);

    s = min(s, h * 2);

    d = min(d, s * 2);

    long long ans = n / 2 * d + n % 2 * s;

    printf("%lld\n", ans);

    return 0;

}
