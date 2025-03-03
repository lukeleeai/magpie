#include<stdio.h>

#include<string.h>

#include<math.h>

#include<algorithm>

#include<stdlib.h>

using namespace std;

typedef long long ll;

const int mod=1e9+7;

int main()

{

	ll n,m;

	scanf("%lld%lld",&n,&m);

	ll a,b;

	ll sum=0;

	if(n*2<=m)

	{

		sum+=n;

		a=m-n*2;

		sum+=a/4;

	}

	else

	{

		sum=m/2;

		

	}

	printf("%lld\n",sum);

	return 0;

}