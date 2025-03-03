#include <stdio.h>

#include <math.h>

#define min(a,b) ((a) > (b) ? (b) : (a))

int main() {

    long long int x,ans, a, b,n;

    scanf("%lld %lld %lld",&a, &b, &n);



     x = min(n, b-1);

    ans = floor(a*x/b) - a * floor(x/b);

    printf("%lld\n", ans);



}
