#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

#define LL long long

LL n,a[100002],ans;

bool vis[100002];

int main()

{

	scanf("%lld",&n);

	for(int i=1;i<=n;i++)

	{

		scanf("%lld",&a[i]);

		if(a[i])vis[i]=1;

		ans+=a[i]/2;

		a[i]%=2;

	}

	for(int i=2;i<=n;i++)

	{

		if(a[i]+a[i-1]==2)a[i-1]=a[i]=0,ans++;

		if(a[i]==0&&a[i-1]&&vis[i])

			a[i]++,a[i-1]--;

	}

	printf("%lld",ans);

}