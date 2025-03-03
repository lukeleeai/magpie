#include<cmath>

#include<cstdio>

#include<cstring>

#include<algorithm>

#define fo(i,a,b) for(int i=a;i<=b;i++)

#define fd(i,b,a) for(int i=b;i>=a;i--)

#define efo(i,v,u) for(int i=last[v],u=to[last[v]];i;i=nxt[i],u=to[i])

#define max(x,y) ((x)>(y)?(x):(y))

#define min(x,y) ((x)<(y)?(x):(y))

#define mset(a,x) memset(a,x,sizeof(a))

using namespace std;

typedef long long ll;

void read(int &n)

{

	int t=0,p=1;char ch;

	for(ch=getchar();!('0'<=ch && ch<='9');ch=getchar())

		if(ch=='-') p=-1;

	for(;'0'<=ch && ch<='9';ch=getchar()) t=t*10+ch-'0';

	n=t*p;

}

const int N=4e5+5,M=7000005;

int n,nn,rtn,tot,ext,b[N][2];

struct node

{

	int x,id;

}a[N];

bool cmp(node a,node b){return a.x<b.x;}

int m,co[N],to[M],nxt[M],last[N],list[N],L[N],R[N];

void link(int u,int v)

{

	to[++m]=v,nxt[m]=last[u],last[u]=m;

}

bool dfs(int v)

{

	if(v<=tot && co[v^1]) return 0;

	if(v<=tot && co[v]) return 1;

	co[v]=1;

	list[++list[0]]=v;

	efo(i,v,u) if(!co[u])

		if(!dfs(u)) return 0;

	return 1;

}

bool check(int lim)

{

	m=0;mset(last,0);

	fo(i,1,n)

	{

		link(b[i+i-1][0],b[i+i][1]),link(b[i+i][1],b[i+i-1][0]);

		link(b[i+i-1][1],b[i+i][0]),link(b[i+i][0],b[i+i-1][1]);

	}

	fo(i,1,rtn)

		fo(j,L[i],R[i]) link(tot+i,b[a[j].id][0]);

	int l=1,r=1;

	fo(i,1,nn)

	{

		while(l<nn && a[i].x-a[l].x>=lim) ++l;

		while(r<nn && a[r+1].x-a[i].x<lim) ++r;

		int ql=min(rtn,(l-1)/rtn+1),qr=min(rtn,(r-1)/rtn+1),qi=min(rtn,(i-1)/rtn+1);

		if(ql==qr)

		{

			fo(j,l,r)

				if(j!=i) link(b[a[i].id][1],b[a[j].id][0]);

		}

		else

		{

			if(ql==qi)

				fo(j,l,i-1) link(b[a[i].id][1],b[a[j].id][0]);

			else

			{

				fo(j,l,R[ql]) link(b[a[i].id][1],b[a[j].id][0]);

				fo(j,ql+1,qi-1) link(b[a[i].id][1],tot+j);

				fo(j,L[qi],i-1) link(b[a[i].id][1],b[a[j].id][0]);

			}

			if(qi==qr)

				fo(j,i+1,r) link(b[a[i].id][1],b[a[j].id][0]);

			else

			{

				fo(j,i+1,R[qi]) link(b[a[i].id][1],b[a[j].id][0]);

				fo(j,qi+1,qr-1) link(b[a[i].id][1],tot+j);

				fo(j,L[qr],r) link(b[a[i].id][1],b[a[j].id][0]);

			}

		}

	}

	mset(co,0);

	fo(i,1,tot)

	{

		int x=i+i-1;

		if(!co[b[x][0]] && !co[b[x][1]])

		{

			list[0]=0;

			if(!dfs(b[x][0]))

			{

				fo(j,1,list[0]) co[list[j]]=0;

				list[0]=0;

				if(!dfs(b[x][1])) return 0;

			}

		}

	}

	return 1;

}

namespace Prog2{

	const int N = 10010;

	int m=0,n;

	int v[N<<1],f[N<<1];

	inline bool ok(int x){

		v[0]=-1e9;

		memset(f,0,sizeof f); f[0]=0;

		int j=1;

		for(int i=1;i<=m;++i){

		//	j=lower_bound(v,v+1+m,v[i]-x)-v;

			while(v[j]<=v[i]-x) ++j;

			if (v[j]>v[i]-x) --j;

			f[i]=max(f[i-1],f[j]+1);

		}

		return f[m]>=n;

	}

}

int main()

{

	int x,y;

	read(n);nn=n+n; Prog2::n=n;

	fo(i,1,n) read(a[i+i-1].x),read(a[i+i].x),Prog2::m+=2;

	tot=1;

	fo(i,1,nn) a[i].id=i,b[i][0]=++tot,b[i][1]=++tot;

	rtn=sqrt(nn);

	fo(i,1,rtn-1) L[i]=1+rtn*(i-1),R[i]=rtn*i;

	L[rtn]=1+rtn*(rtn-1),R[rtn]=nn;

	sort(a+1,a+nn+1,cmp);

	fo(i,1,n+n) Prog2::v[i]=a[i].x;

	int l=0,r=a[nn].x;

	while (l<r-1){

		int M=(l+r)>>1;

		if(Prog2::ok(M)) l=M;

		else r=M;

	}

	l=0;

	while(l<r-1)

	{

		int mid=(l+r)>>1;

		if(check(mid)) l=mid;

		else r=mid;

	}

	printf("%d\n",l);

	return 0;

}