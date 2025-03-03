#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 200010

#define PI 3.1415926535897932384626433832795

struct node

{

	int x,y;

	bool operator < (const node &a)

	{

		return x<a.x;

	}

}e[MAXN];

int sx,sy,ex,ey,n;

void Pre()

{

	bool f=0;

	if(sy>ey) swap(sx,ex),swap(sy,ey);

	if(sy==ey&&sx>ex) swap(sx,ex);

	if(sx>ex) f=1,ex=2*sx-ex;

	ex-=sx,ey-=sy;

	int x,y,m=0;

	for(int i=1;i<=n;i++)

	{

		scanf("%d%d",&x,&y);

		if(f) x=2*sx-x;

		x-=sx,y-=sy;

		if(x<0||x>ex||y<0||y>ey) continue;

		e[++m].x=x,e[m].y=y;

	}

	sx=0,sy=0;

	n=m;

}

int a[MAXN],st[MAXN],r;

void Solve()

{

	for(int i=1;i<=n;i++)

		a[i]=e[i].y;

	st[0]=-1;

	for(int i=1;i<=n;i++)

	{

		if(a[i]>st[r]) st[++r]=a[i];

		else

		{

			int p=upper_bound(st,st+r+1,a[i])-st;

			st[p]=a[i];

		}

	}

}

int main()

{

	scanf("%d%d%d%d%d",&sx,&sy,&ex,&ey,&n);

	Pre();

	sort(e+1,e+1+n);

	Solve();

	int t=min(ex,ey)+1;

	double ans=100LL*(ex+ey);

	if(r==t) ans+=(r-1)*5LL*PI+10LL*PI-20LL*r;

	else ans+=r*5LL*PI-20LL*r;

	printf("%.12lf\n",ans);

}