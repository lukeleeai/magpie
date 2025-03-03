#include<cstdio>

#include<algorithm>

#include<cmath>

#include<cstring>

using namespace std;

#define MAXN 200005

#define INF 0x3f3f3f3f

#define LL long long

int n,m=INF;

LL ans;

int a[MAXN],b[MAXN];

int main()

{

	scanf("%lld",&n);

	bool f=0;

	for(int i=1;i<=n;i++)

	{

		scanf("%d %d",&a[i],&b[i]);

		if(a[i]!=b[i]) f=1;

		ans+=a[i];

		if(a[i]>b[i]) m=min(m,b[i]);

	}

	if(f==0) 

	{

		printf("0\n");

		return 0;

	}

	printf("%lld\n",ans-m);

    return 0;

}
