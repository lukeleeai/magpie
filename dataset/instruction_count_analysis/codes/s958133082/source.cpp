#include <cstdio>

#include <cstring>

#include <algorithm>

#include <cmath>

#define ld long double

#define MN 205

#define eps 1e-9

using namespace std;

const ld pi=acos(-1);

struct vec

{

	ld x,y; int pos;

	friend vec operator-(const vec& a,const vec& b) {return (vec){a.x-b.x,a.y-b.y};}

	friend ld operator/(const vec& a,const vec& b) {return a.x*b.y-a.y*b.x;}

	friend ld operator*(const vec& a,const vec& b) {return a.x*b.x+a.y*b.y;}

	friend ld abs(const vec& a) {return sqrt(a.x*a.x+a.y*a.y);}

}a[MN];

ld ans[MN];

int q[MN];

int n,tp;



inline int read()

{

	int n=0,f=1; char c=getchar();

	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}

	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}

	return n*f;

}



bool cmp1(const vec& a,const vec& b) {return a.x<b.x || a.x==b.x && a.y<b.y;}

bool cmp2(const vec& A,const vec& B)

{

	ld lt=(A-a[1])/(B-a[1]);

	if (fabs(lt)>eps) return lt>0;

	else return abs(A-a[1])<abs(B-a[1]);

}



int main()

{

//	freopen("data.in","r",stdin);

//	freopen("data.out","w",stdout);

	register int i;

	n=read();

//	printf("%d\n",n);	

	for (i=1;i<=n;++i)

		a[i].x=read(),a[i].y=read(),a[i].pos=i;

	if (n==1) return 0*printf("1");

	else if (n==2) return 0*printf("0.5000000\n0.5000000");

	sort(a+1,a+n+1,cmp1);

	sort(a+2,a+n+1,cmp2);

	q[tp=1]=1;

	for (i=2;i<=n;++i)

	{

		while (tp>1&&(a[q[tp]]-a[q[tp-1]])/(a[i]-a[q[tp-1]])<eps) --tp;

		q[++tp]=i;

	}

	q[tp+1]=q[1]; q[0]=q[tp];

//	for (i=1;i<=tp;++i) printf("%lld,%lld\n",a[q[i]].x,a[q[i]].y);	

//	for (i=1;i<=tp;++i) printf("%d ",a[q[i]].pos); puts("");

//	printf("%d\n",tp);

//	printf("%d %d\n",n,tp);

	for (i=1;i<=tp;++i)

	

	{

	

		ans[a[q[i]].pos]=

		(pi-acos((double)(

		((a[q[i-1]]-a[q[i]])*

		(a[q[i+1]]-a[q[i]]))

		/(abs(a[q[i-1]]-a[q[i]])*

		  abs(a[q[i+1]]-a[q[i]])))))/(pi*2);

//	printf("%.5lf\n",acos(

//		((a[q[i-1]]-a[q[i]])*

//		(a[q[i+1]]-a[q[i]]))

//		/(abs(a[q[i-1]]-a[q[i]])*

//		  abs(a[q[i+1]]-a[q[i]]))));

	}

	

	for (i=1;i<=n;++i) printf("%.10lf\n",(double)ans[i]);

}