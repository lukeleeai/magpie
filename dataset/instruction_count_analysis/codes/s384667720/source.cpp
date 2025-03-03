#include "stdc++.h"

using namespace std;

typedef long long LL;

const int N=1000005;

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

LL dis[N],Max[N];

LL INF=10000000000000000LL;

bool SPFA(int S){

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

					return 0;

				dis[y]=dis[x]+g.z[i];

				q[++tail]=y;

			}

		}

	}

	return 1;

}

int TS=0;

int main(){

	scanf("%d%d",&n,&m);

	g.clear();

	for (int i=1;i<=n;i++)

		Max[i]=INF;

	for (int i=1;i<=m;i++){

		int a,b,c;

		scanf("%d%d%d",&a,&b,&c);

		g.add(a,b+n,-c);

		g.add(b+n,a,c);

		g.add(b,a+n,-c);

		g.add(a+n,b,c);

		Max[a]=min(Max[a],1LL*c);

		Max[b]=min(Max[b],1LL*c);

	}

	if (!SPFA(1)){

		puts("0");

		return 0;

	}

	LL v=INF;

	for (int i=1;i<=n;i++)

		if (dis[i]!=INF&&dis[i+n]!=INF){

			LL A=dis[i],B=dis[i+n];

			// x+A=-(x+B) => x=-(A+B)/2;

			if ((A+B)%2LL){

				puts("0");

				return 0;

			}

			LL x=-(A+B)/2LL;

			if (x!=v)

				if (v==INF)

					v=x;

				else {

					puts("0");

					return 0;

				}

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

		if (dis[i]!=INF){

			// 0 < x+dis[i] < Max[i]

			MAX=min(MAX,Max[i]-dis[i]-1);

			MIN=max(MIN,-dis[i]+1);

		}

		else {

			// 0 < -(x+dis[i]) < Max[i]

			MAX=min(MAX,-dis[i+n]-1);

			MIN=max(MIN,-Max[i]-dis[i+n]+1);

		}

	printf("%lld",max(MAX-MIN+1,0LL));

	return 0;

}