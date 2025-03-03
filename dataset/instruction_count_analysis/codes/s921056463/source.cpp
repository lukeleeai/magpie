#include<cstdio>

#include<cstring>

using namespace std;

#define MAXN 100005

#define LL long long

int n,a[MAXN];

int main()

{

	LL ans=0;

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		scanf("%d",&a[i]);

	for(int i=1;i<=n;i++)

	{

		ans+=a[i]/2;

		a[i]%=2;

		if(a[i]==1&&a[i+1]>0) a[i]=0,ans++,a[i+1]--;//尽量把单个的牌放在后面

	}

	printf("%lld\n",ans);

}