#include <cstdio>

#include <cstring>

#include <algorithm>

#define MN 262150

using namespace std;

struct node{int x,y;}b[MN];

int t[MN<<1],a[MN];

int MQ,INF,n,m,ans,f0;



inline int read()

{

	int n=0,f=1; char c=getchar();

	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}

	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}

	return n*f;

}



inline void grw(int x,int y) {for (x+=MQ;x;x>>=1) if (t[x]>y) t[x]=y; else return;}

inline int gmn(int x,int y)

{

	int sm=INF;

	for (x+=MQ,y+=MQ;x<=y;x>>=1,y>>=1)

	{

		if ( x&1) sm=min(sm,t[x++]);

		if (~y&1) sm=min(sm,t[y--]);

	}

	return sm;

}

bool cmp(const node& a,const node& b) {return a.x<b.x || a.x==b.x && a.y>b.y;}



int main()

{

	register int i,j;

	n=read(); for (i=1;i<=n;++i) a[i]=read(),ans+=(a[i]==0),a[i]=a[i]?1:-1;

	m=read(); for (i=1;i<=m;++i) b[i].x=read(),b[i].y=read();

	sort(b+1,b+m+1,cmp); memset(t,100,sizeof(t)); INF=t[0]; f0=0;

	for (MQ=1;MQ<n;MQ<<=1); --MQ;

	for (i=j=1;i<=n;f0=min(f0+a[i],t[i+MQ]),++i)

		for (;j<=m&&b[j].x==i;++j)

			grw(b[j].y,min(gmn(i,b[j].y),f0));

	printf("%d",ans+f0);

}