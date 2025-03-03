#include <stdio.h>

#include <math.h>

#include <stdlib.h>

long long int myfun(long long int a,long long int x);

int main()

{

    long long int n,k,ans;

    scanf("%lld %lld", &n,&k);

    ans=ceil(myfun(n,k));

    printf("%lld", ans+1);

    return 0;

}

long long int myfun(long long int n,long long int k)

{

    return log(n)/log(k);

}
