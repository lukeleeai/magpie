#include<stdio.h>

#define ll long long

#define fup(i,a,b) for(int i=a;i<=b;++i)



void Main()

{

    ll n,m;

    scanf("%lld%lld",&n,&m);

    ll s;

    if(n>1&&m>1)s=m+m+n+n-4;

    else if(m==1&&n==1)s=0;

    else s=2;

    printf("%lld",n*m-s);

}

int main()

{

Main();

return 0;

}