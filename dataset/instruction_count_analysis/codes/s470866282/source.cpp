#include<cstdio>

#define maxn 200005

#define LL long long

int n,a[maxn],l[maxn],r[maxn],st[maxn],tp;

LL ans;

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++) scanf("%d",&a[i]);

	for(int i=1;i<=n;i++)

	{

		while(tp&&a[st[tp]]>=a[i]) tp--;

		l[i]=st[tp]; st[++tp]=i;

	}

	tp=0; st[0]=n+1;

	for(int i=n;i;i--)

	{

		while(tp&&a[st[tp]]>=a[i]) tp--;

		r[i]=st[tp]; st[++tp]=i;

	}

	for(int i=1;i<=n;i++) ans+=1ll*a[i]*(i-l[i])*(r[i]-i);

	printf("%lld\n",ans);

}