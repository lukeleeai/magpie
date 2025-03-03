#include<stdio.h>

#include<math.h>

int main()

{

    long long n;

    scanf("%lld", &n);

    long long x=1;

    for(long long i=1;i<=sqrt(n);i++)

    {

        if((n%i==0) && (((n/i)-i)<((n/x)-x)))

            x=i;

    }

    long long a=x, b=(n/x);

    long long moves=(a+b)-2;

    printf("%lld", moves);

    return 0;

}