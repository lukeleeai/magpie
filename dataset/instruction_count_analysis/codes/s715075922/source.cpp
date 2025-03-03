#include <stdio.h>

#include <math.h>

#include <string.h>

#define N 1005

#define reg register

using namespace std;

typedef long long ll;

int n,S,T,sx,sy,tx,ty;

int x[N],y[N],r[N];

double d[N];char vis[N];

int ne=0,h[N];struct edge{int to,x;double w;}e[1010010];

inline double ss(reg int x) {

	return (double)x*x;

}

inline double dis(reg int x1,reg int y1,reg int x2,reg int y2) {

	return sqrt(ss(x1-x2)+ss(y1-y2));

}

inline void ins(reg int s,reg int t,reg double w) {

	e[++ne].to=t;e[ne].w=w;e[ne].x=h[s];h[s]=ne;

}

inline void dijkstra() {

	reg int i,u,v;reg double w,x;

	for(i=1;i<=n;++i) d[i]=1e99;

	d[S]=0;d[T]=1e99;

	while(true) {

		u=0;x=1e99;

		for(i=1;i<=n+2;++i) if(!vis[i]&&d[i]<x) u=i,x=d[i];

		if(!u) return;

		vis[u]=1;

		for(i=h[u];i;i=e[i].x) {

			v=e[i].to;w=x+e[i].w;

			if(w<d[v]) d[v]=w;

		}

	}

}

int main() {

	reg double t;reg int i,j;

	scanf("%d%d%d%d%d",&sx,&sy,&tx,&ty,&n);

	S=n+1;T=n+2;

	for(i=1;i<=n;++i) {

		scanf("%d%d%d",x+i,y+i,r+i);

		for(j=1;j<i;++j) {

			t=dis(x[i],y[i],x[j],y[j])-r[i]-r[j];

			if(t<0) t=0;

			ins(i,j,t);ins(j,i,t);

		}

	}

	for(i=1;i<=n;++i) {

		t=dis(sx,sy,x[i],y[i])-r[i];

		if(t<0) t=0;

		ins(S,i,t);

		t=dis(tx,ty,x[i],y[i])-r[i];

		if(t<0) t=0;

		ins(i,T,t);

	}

	ins(S,T,dis(sx,sy,tx,ty));

	dijkstra();

	printf("%.12lf",d[T]);

	return 0;

}