///b. replacing integer

#include <stdio.h>

#include <math.h>



long long int diff(long long int a, long long int b)

{

    if(a>=b) return a-b;

    else return b-a;

}

int main()

{

    long long int n,k;

    scanf("%lld %lld",&n,&k);



    if(n<k){

        if(diff(n,k)<n) printf("%lld",diff(n,k));

        else printf("%lld",n);

        return 0;

    }

    if(n%k==0){

        printf("0");

        return 0;

    }

    n=n%k;

    if(n<diff(n,k)) printf("%lld",n);

    else printf("%lld",diff(n,k));



    return 0;

}