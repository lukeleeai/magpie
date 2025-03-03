#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

typedef long long ll;

const int maxn=2e5+100;

const int mod=1e9+7;

int a[maxn];

int l[maxn];//记录左边比i要小的数 的个数 

int r[maxn];//记录右边比i要小的数 的个数

int main()

{

	int n,k;

	ll ans;

	ll sam;

	int a[maxn];

	int l[maxn];//记录左边比i要小的数 的个数 

	int r[maxn];//记录右边比i要小的数 的个数

	memset(l,0,sizeof(l));

	memset(r,0,sizeof(r));

	scanf("%d%d",&n,&k); 

	sam=(ll)(k+1)*k/2;//总和时要算右边比i小的次数 

	sam-=k; //总和时要算左边比i小的次数 

	sam=(sam+mod)%mod;

	for(int i=0;i<n;i++)

		scanf("%d",&a[i]);

	for(int i=0;i<n;i++)

	{

		for(int j=0;j<i;j++)

			if(a[j]<a[i])

				l[i]++;

		for(int j=i+1;j<n;j++)

			if(a[j]<a[i])

				r[i]++;		 

	}

	ans=0; 

	for(int i=0;i<n;i++)

	{

		ans+=(l[i]*sam);

		ans%=mod;

		ans+=(r[i]*(sam+k));

		ans%=mod;

	}

	printf("%lld\n",ans);

	return 0;

}