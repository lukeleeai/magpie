#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

struct ll

{

	int x,y;

	long long v;

}b[600000];

long long ans=0,n,q,a[300000],t=0,f[300000];

int cmp(ll a,ll b)

{

	return a.v<b.v;

}

int find(int x)

{

	if (x==f[x])

	return x;

	return f[x]=find(f[x]);

}

void un(int x,int y)

{

	int fx=find(x),fy=find(y);

	f[fx]=fy;

}

void add(int x,int y,int v)

{

	b[++t].x=x;

	b[t].y=y;

	b[t].v=v;

}

int main()

{

    scanf("%d%d",&n,&q);

	int x,y;

	long long v;

	for (int i=0;i<=n;++i)

	a[i]=1e17;

	for (int i=1;i<=q;++i)

	{

		scanf("%d%d%lld",&x,&y,&v);

	    add(x,y,v);

	    a[x]=min(a[x],v+1);

		a[y]=min(a[y],v+2); 

	}	

	for (int i=1;i<=2;++i)

	for (int j=1;j<=n;++j)

	a[(j%n)]=min(a[(j%n)],a[j-1]+2);

	for (int i=0;i<n;++i)

	add(i,(i+1)%n,a[i]);

	sort(b+1,b+t+1,cmp);

	for (int i=0;i<n;++i)

	f[i]=i;

	for (int i=1;i<=t;++i)

	if (find(b[i].x)!=find(b[i].y))

	{

		un(b[i].x,b[i].y);

		ans+=b[i].v;

		if (t==n-1)

		break;

	}

	printf("%lld\n",ans);

} 