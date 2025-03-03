#include<cstdio>

#include<algorithm>

using namespace std;

#define LL long long

#define MAXN 100010

LL sum[MAXN],posi[MAXN],ans;

int n,k;

int main()

{

	scanf("%d%d",&n,&k);

	for(int i=1;i<=n;i++)

	{

		posi[i]=posi[i-1];

		scanf("%lld",&sum[i]);

		if(sum[i]>0) posi[i]+=sum[i];

		sum[i]+=sum[i-1];

	}

	for(int i=1;i+k-1<=n;i++)

	{

		LL tmp=posi[n]-posi[i+k-1]+posi[i-1]+max(0LL,sum[i+k-1]-sum[i-1]);

		ans=max(ans,tmp);

	}

	printf("%lld\n",ans);

}