#include<stdio.h>



int gcd(long long int a,long long int b)

{

    return a ? gcd(b % a,a) : b;

}

int main()

{

    long long int n,a[100000];

    scanf("%lld",&n);

    long long int k;

    for(int i = 1 ; i <= n ; i ++ )

    {

        scanf("%lld",&a[i]);

    }

    k = a[1];

    for(int i = 2 ; i <= n ; i ++ )

    {

        k = gcd(k,a[i]);

    }

    printf("%lld\n",k);

    return 0;

}