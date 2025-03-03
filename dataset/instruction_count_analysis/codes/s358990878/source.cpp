#include<stdio.h>



int main()

{

    long long int n,k,q;

    long long int p;

    long long int a[100005];

    scanf("%lld%lld%lld",&n,&k,&q);

    for(int i = 1 ; i <= n ; i ++ )

        a[i] = k;

    for(int i = 1 ; i <= q ; i ++ )

    {

        scanf("%lld",&p);

        a[p] ++ ;

    }

    for(int i = 1 ; i <= n ; i ++ )

    {

        a[i] -= q;

    }

    for(int i = 1 ; i <= n ; i ++ )

    {

        if(a[i] <= 0)

            printf("No\n");

        else

            printf("Yes\n");

    }

    return 0;

}