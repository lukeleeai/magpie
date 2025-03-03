#include<stdio.h>

typedef long long ll;

int main()

{

	ll n,a,b;

	scanf("%lld %lld %lld",&n,&a,&b);

	ll ans=0;

	if(a>b)  ans=0;

	else if(n==1&&a!=b)  ans=0;

	else if(n==1&&a==b)  ans=1;

	else ans=(n-2)*(b-a)+1;

	printf("%lld\n",ans);

	return 0;

 } 