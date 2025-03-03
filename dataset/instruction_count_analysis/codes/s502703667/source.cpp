#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 300010

#define LL long long

int lazy[MAXN*4],col[MAXN*4];

int a[MAXN*2],n,K,tot;

void PushDown(int i)

{

	if(lazy[i])

	{

		col[i<<1]=col[i<<1|1]=lazy[i<<1]=lazy[i<<1|1]=lazy[i];

		lazy[i]=0;

	}

}

void Change(int i,int l,int r,int L,int R,int k)

{

	if(L>R) return;

	if(L<=l&&r<=R)

	{

		col[i]=lazy[i]=k;

		return;

	}

	PushDown(i);

	int mid=(l+r)/2;

	if(L<=mid) Change(i<<1,l,mid,L,R,k);

	if(R>mid) Change(i<<1|1,mid+1,r,L,R,k);

}

int Query(int i,int l,int r,int k)

{

	if(l==r) return col[i];

	PushDown(i);

	int mid=(l+r)>>1;

	if(k<=mid) return Query(i<<1,l,mid,k);

	return Query(i<<1|1,mid+1,r,k);

}

int l[MAXN],r[MAXN];

LL f[MAXN];

LL Ask(int k)

{

	int pos=Query(1,1,tot,k);

	return pos?(f[pos]+(a[l[pos]]-a[k]+K)%K):0;

}

LL sum[MAXN];

int main()

{

	int typ;

	scanf("%d%d",&n,&K);

	for(int i=1;i<=n;i++)

	{

		scanf("%d%d",&sum[i],&typ);

		sum[i]+=sum[i-1];

		if(typ==2) l[i]=0,r[i]=K-1;

		else l[i]=(K-2*sum[i-1]%K)%K,r[i]=(K-2*sum[i]%K)%K;

		if(typ==1&&2*(sum[i]-sum[i-1])>K)

		{

			printf("-1\n");

			return 0;

		}

		a[++tot]=l[i],a[++tot]=r[i];

	}

	sort(a+1,a+1+tot);

	tot=unique(a+1,a+1+tot)-a-1;

	for(int i=1;i<=n;i++)

	{

		l[i]=lower_bound(a+1,a+1+tot,l[i])-a;

		r[i]=lower_bound(a+1,a+1+tot,r[i])-a;

	}

	for(int i=n;i;i--)

	{

		f[i]=Ask(l[i]);

		if(l[i]>r[i]) Change(1,1,tot,r[i]+1,l[i]-1,i);

		else Change(1,1,tot,1,l[i]-1,i),Change(1,1,tot,r[i]+1,tot,i);

	}

	LL ans=f[1];

	for(int i=tot;i;i--)

		ans=min(ans,Ask(i));

	printf("%lld\n",ans+2*sum[n]);

}