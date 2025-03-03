#include"stdc++.h"

#include<iostream>

using namespace std;

long long int a[500000];



int main()

{

    long long int i,n,j,k,l=1000000000000,sm=0;

    scanf("%lld",&n);

    for(i=1; i<=n; i++)

    {

        scanf("%lld",&k);

        a[i]=a[i-1]+k;

        sm+=k;

    }

    if(n==2)

    {

        l=abs(sm-2*a[1]);

    }

    else

    {

        for(i=1; i<n; i++)

        {

            l=min(l,abs(sm-2*a[i]));

        }

    }

    printf("%lld",l);

    return 0;

}
