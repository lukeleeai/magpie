#include <cstdio>

#include <algorithm>

#include <cmath>

#include <cctype>

#define RI register int

#define Tp template <typename T>

#define y1 DEEP_DARK_FANTACY

#define y2 VAN

using namespace std;

inline char nc(){

	static char buf[100000],*L=buf,*R=buf;

	return L==R&&(R=(L=buf)+fread(buf,1,100000,stdin),L==R)?EOF:*L++;

}

inline void read(int& ret){

	ret=0; int f=1;char ch=nc();

	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=nc();}

	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=nc();

	ret*=f;

}

const int N=2e6+5;

int x1,x2,y1,y2,n,F[N],top,dec;

struct dat{int x,y;}p[N];

double Ans;

inline bool valid(int i){

	return ((p[i].x>=x1&&p[i].x<=x2)||(p[i].x>=x2&&p[i].x<=x1))&&((p[i].y>=y1&&p[i].y<=y2)||(p[i].y>=y2&&p[i].y<=y1));

}

inline bool cmp1(dat A,dat B){return A.x<B.x||(A.x==B.x&&A.y<B.y);}

inline bool cmp2(dat A,dat B){return A.x<B.x||(A.x==B.x&&A.y>B.y);}

int main(){

	read(x1), read(y1), read(x2), read(y2), read(n);

	for (int i=1;i<=n;i++) read(p[i].x), read(p[i].y);

	if (x1>x2) swap(x1,x2), swap(y1,y2);

	F[0]=-2e9;

	if (y1<y2){

		sort(p+1,p+n+1,cmp1);

		for (int i=1;i<=n;i++) if (valid(i))

			if (F[top]<p[i].y) F[++top]=p[i].y; else F[upper_bound(F+1,F+top+1,p[i].y)-F]=p[i].y;

	} else{

		sort(p+1,p+n+1,cmp2);

		for (int i=1;i<=n;i++) if (valid(i))

			if (F[top]<-p[i].y) F[++top]=-p[i].y; else F[upper_bound(F+1,F+top+1,-p[i].y)-F]=-p[i].y;

	}

	double delta=20.0-2.0*M_PI_4*10.0;

	if (top==min(abs(x1-x2),abs(y1-y2))+1) 	Ans=(abs(x2-x1)+abs(y1-y2))*100.0-(top-1)*1.0*delta+(M_PI*10.0-20);

		else Ans=((x2-x1)+abs(y1-y2))*100.0-top*1.0*delta;

	printf("%.11lf\n",Ans);

	return 0;

}