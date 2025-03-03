#include<cstdio>

#include<algorithm>

using namespace std;

#define N 300060

int n,v[N];

long long su[N],su1,su2;

bool check(long long l)

{

	long long mn=0;

	for(int i=1;i<=n;i+=2)

	if(su[i]-mn>=l)

	{

		if(mn>su[i+1])mn=su[i+1];

		if(i==n)return 1;

	}

	return 0;

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++)scanf("%d",&v[i]);

	if(~n&1)

	{

		long long s1=0,s2=0;

		for(int i=1;i<=n;i+=2)s1+=v[i],s2+=v[i+1];

		printf("%lld %lld\n",max(s1,s2),min(s1,s2));

	}

	else

	{

		for(int i=1;i<=n;i++)su1+=v[i]*(i&1),su[i]=su[i-1]+v[i]*(i&1?1:-1),su2+=v[i]*(~i&1);

		long long lb=0,rb=2e10,as=0;

		while(lb<=rb)

		{

			long long mid=(lb+rb)>>1;

			if(check(mid))as=mid,lb=mid+1;

			else rb=mid-1;

		}

		printf("%lld %lld\n",su2+as,su1-as);

	}

}//orzwkr