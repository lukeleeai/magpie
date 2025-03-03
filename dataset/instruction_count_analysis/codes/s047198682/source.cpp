#include "stdc++.h"

using namespace std;

typedef long long LL;

const int N=400005;

struct Gragh{

	int cnt,y[N],z[N],nxt[N],fst[N];

	void clear(){

		cnt=0;

		memset(fst,0,sizeof fst);

	}

	void add(int a,int b,int c){

		y[++cnt]=b,z[cnt]=c,nxt[cnt]=fst[a],fst[a]=cnt;

	}

}g;

int n,m;

int q[N],head,tail;

LL dis[N];

LL INF=10000000000000000LL;

void out0(){

	puts("0");

	exit(0);

}

void SPFA(int S){

	for (int i=1;i<=n*2;i++)

		dis[i]=INF;

	head=tail=0;

	q[++tail]=S;

	dis[S]=0;

	while (head!=tail){

		int x=q[++head],y;

		for (int i=g.fst[x];i;i=g.nxt[i]){

			int y=g.y[i];

			if (dis[y]!=dis[x]+g.z[i]){

				if (dis[y]!=INF)

					out0();

				dis[y]=dis[x]+g.z[i];

				q[++tail]=y;

			}

		}

	}

}

int main(){

	scanf("%d%d",&n,&m);

	g.clear();

	for (int i=1;i<=m;i++){

		int a,b,c;

		scanf("%d%d%d",&a,&b,&c);

		g.add(a,b+n,-c);

		g.add(b+n,a,c);

		g.add(b,a+n,-c);

		g.add(a+n,b,c);

	}

	SPFA(1);

	LL v=INF;

	for (int i=1;i<=n;i++)

		if (dis[i]!=INF&&dis[i+n]!=INF){

			LL A=dis[i],B=dis[i+n];

			if ((A+B)%2LL)

				out0();

			LL x=-(A+B)/2LL;

			if (x!=v)

				if (v==INF)

					v=x;

				else

					out0();

		}

	if (v!=INF){

		int f=1;

		for (int i=1;i<=n;i++){

			if (dis[i]!=INF)

				if (v+dis[i]<=0)

					f=0;

			if (dis[i+n]!=INF)

				if (v+dis[i+n]>=0)

					f=0;

		}

		printf("%d",f);

		return 0;

	}

	LL MIN=1,MAX=INF;

	for (int i=1;i<=n;i++)

		if (dis[i]!=INF)

			MIN=max(MIN,-dis[i]+1);

		else

			MAX=min(MAX,-dis[i+n]-1);

	printf("%lld",max(MAX-MIN+1,0LL));

	return 0;

}