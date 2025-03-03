#include<cmath>

#include<queue>

#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#define int long long

using namespace std;



int a,b,n,c[100010],tmp[100010];



int check(int u)

{

	for(int i=1;i<=n;i++)

	{

		tmp[i]=c[i]-u*b;

	}

	int res=0;

	for(int i=1;i<=n;i++)

	{

		if(tmp[i]>0)

		{

			res+=(tmp[i]+a-1)/a;

		}

	}

	return res<=u;

}



signed main()

{

	scanf("%lld%lld%lld",&n,&a,&b);

	a-=b;

	for(int i=1;i<=n;i++)

	{

		scanf("%lld",&c[i]);

	}

	int l=1,r=1e9+1,mid;

	while(l<r)

	{

	    mid=(l+r)>>1;

		if(check(mid))

		{

			r=mid;

		}

		else

		{

			l=mid+1;

		}

	}

	printf("%lld\n",l);

}