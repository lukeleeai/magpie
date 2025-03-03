#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 200000

using namespace std;

typedef long long LL;

struct node

{

	int tag,col;

}tree[MAXN*4];

int N;

LL K;

LL s[MAXN+5];

LL a[MAXN+5];

int b[MAXN+5];

LL l[MAXN+5],r[MAXN+5];

LL lsh[MAXN+5],lcnt;

LL f[MAXN+5];

void PushDown(int i)

{

	if(tree[i].tag==0)

		return;

	tree[i*2].tag=tree[i].tag;

	tree[i*2].col=tree[i].tag;

	tree[i*2+1].tag=tree[i].tag;

	tree[i*2+1].col=tree[i].tag;

	tree[i].tag=0;

}

int Query(int i,int l,int r,int k)

{

	if(l==r)

		return tree[i].col;

	int mid=(l+r)/2;

	PushDown(i);

	if(k<=mid)

		return Query(i*2,l,mid,k);

	else

		return Query(i*2+1,mid+1,r,k);

}

void Insert(int i,int l,int r,int ql,int qr,int val)

{

	if(qr<l||ql>r)

		return;

	PushDown(i);

	if(ql<=l&&r<=qr)

	{

		tree[i].tag=val;

		tree[i].col=val;

		return;

	}

	int mid=(l+r)/2;

	Insert(i*2,l,mid,ql,qr,val);

	Insert(i*2+1,mid+1,r,ql,qr,val);

}

LL Ask(int k)

{

	int pos=Query(1,1,lcnt,k);

	if(pos!=0)

		return f[pos]+(lsh[l[pos]]-lsh[k]+K)%K;

	return 0;

}

int main()

{

	scanf("%d %lld",&N,&K);

	for(int i=1;i<=N;i++)

	{

		scanf("%lld %d",&a[i],&b[i]);

		s[i]=s[i-1]+a[i];

		if(b[i]==2)

			l[i]=0,r[i]=K-1LL;

		else

			l[i]=(K-2LL*s[i-1]%K)%K,r[i]=(K-2LL*s[i]%K)%K;

		if(b[i]==1&&a[i]*2LL>K)

		{

			printf("-1\n");

			return 0;

		}

		lsh[++lcnt]=l[i],lsh[++lcnt]=r[i];

	}

	sort(lsh+1,lsh+1+lcnt);

	lcnt=unique(lsh+1,lsh+1+lcnt)-lsh-1;

	for(int i=1;i<=N;i++)

	{

		l[i]=lower_bound(lsh+1,lsh+1+lcnt,l[i])-lsh;

		r[i]=lower_bound(lsh+1,lsh+1+lcnt,r[i])-lsh;

	}

	for(int i=N;i>=1;i--)

	{

		f[i]=Ask(l[i]);

		if(l[i]>r[i])

			Insert(1,1,lcnt,r[i]+1,l[i]-1,i);

		else

			Insert(1,1,lcnt,1,l[i]-1,i),Insert(1,1,lcnt,r[i]+1,lcnt,i);

	}

	LL ans=f[1];

	for(int i=1;i<=lcnt;i++)

		ans=min(ans,Ask(i));

	printf("%lld\n",ans+2LL*s[N]);

	return 0;

}