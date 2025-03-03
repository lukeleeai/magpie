#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

int a[1000001];

main()

{



    long long n,m,sum,p;

    scanf("%lld %lld",&n,&m);

    if (n*2==m)

    {

        sum=n;

    }

    else if (n*2<m)

    {

        p=m-n*2;

        sum=n+p/4;

    }

    else

    {

        sum=m/2;

    }

    printf("%lld\n",sum);

}
