#include<stdio.h>

int main()

{

    long long int a, b, x, c;

    scanf("%lld %lld %lld", &a, &b, &x);

    c=(b/x)-(a/x);

    if(a%x==0)

        c++;

    printf("%lld\n", c);

}