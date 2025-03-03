#include"stdc++.h"

using namespace std;

const int mod=1e9+7;

#define llong long long

int Q;

llong f[110];

llong n,m;

llong a,b;

void calc(int i)

{

	if(!i)return;

	llong ta=a*f[i]+b*f[i-1];

	llong tb=a*f[i+1]+b*f[i];

	a=ta;b=tb;

}

int main()

{

//	freopen("fibo.in","r",stdin);

//	freopen("fibo.out","w",stdout);

	f[0]=f[1]=1;

	for(int i=2;i<=88;++i)f[i]=f[i-1]+f[i-2];

	scanf("%d",&Q);

	int ans;

while(Q--)

{

	scanf("%lld%lld",&n,&m);

	if(n>m)swap(n,m);

	if(n==1)

	{

		printf("%d %lld\n",1,m%mod);

		continue;

	}

	if(n==2&&m==2)

	{

		puts("1 4");

		continue;

	}

	for(int k=87;k>=0;--k)

		if(m>=f[k+1]&&n>=f[k])

		{

			ans=k;

			break;

		}

	printf("%d ",ans);

	llong res=0;

	for(int i=1;i<=ans;++i)

	{

		a=f[i],b=f[i+1];

		calc(ans-i);

		if(a<=n&&b<=m)

		{

			res+=(m-b)/a+1;

			res%=mod;

			if(b<=n)res+=(m-a)/b+1;

			res%=mod;

		}

	}

	printf("%lld\n",res);

}

	return 0;

}
