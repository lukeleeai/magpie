#include<cstdio>

#include<cstring>

#include<algorithm>

typedef long long LL;

const LL mod=1e9+7;

const int N=1006;

using namespace std;

LL f[N];



LL fun(int n)

{

	LL ans=1;

	memset(f,0,sizeof(f));

	for(int i=2;i<=n;i++)

	{

		int k=i;

		for(int j=2;j<=k;j++)

		{

			while(k%j==0)

			{

				f[j]++;

				k/=j;

			}

		}

		if(k)

			f[k]++;

	}

	for(int i=2;i<=n;i++)

	{

		if(f[i])

			ans=ans*(f[i]+1)%mod;

	}

	return ans%mod;

}

int main()

{

	int n;

	while(~scanf("%d",&n))

	{

		printf("%lld\n",fun(n));

	}

	return 0;

} 