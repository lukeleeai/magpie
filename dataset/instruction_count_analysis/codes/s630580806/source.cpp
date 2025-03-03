#include <cstdio>

#include <iostream>

#include <algorithm>

#include <cstring>

#include <vector>

#include <queue>

#define PII pair<int,int>

#define MP make_pair

#define fir first

#define sec second

#define PB push_back

#define db long double

#define ll long long

using namespace std;

template <class T>

inline void rd(T &x) {

	x=0; char c=getchar(); int f=1;

	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }

	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;

}

const int N=1010,inf=1e9;

inline int Abs(int x) { return x>0?x:-x; }

int S,T;

namespace Flow {

	const int N=5010;

	int head[N],cur[N],vis[N];

	ll dis[N];

	struct ed { int to,next,f; ll w; };

	vector<ed> e;

	void init() { e.clear(); memset(head,-1,sizeof(head)); }

	void ad(int x,int y,int f,ll w) {

		e.PB((ed){y,head[x],f,w}); head[x]=e.size()-1;

		e.PB((ed){x,head[y],0,-w}); head[y]=e.size()-1;

	}

	queue<int> q;

	bool bfs() {

		memset(dis,-0x3f,sizeof(dis));

		memcpy(cur,head,sizeof(cur));

		dis[S]=0,q.push(S),vis[S]=1;

		while(!q.empty()) {

			int u=q.front(); q.pop(),vis[u]=0;

			for(int k=head[u];~k;k=e[k].next) if(e[k].f) {

				int v=e[k].to;

				if(dis[v]<dis[u]+e[k].w) {

					dis[v]=dis[u]+e[k].w;

					if(!vis[v]) q.push(v),vis[v]=1;

				}

			}

		}

		return dis[T]>-1e16;

	}

	int dfs(int u,int f) {

		if(u==T||!f) return f; int ret=0,tmp;

		vis[u]=1;

		for(int &k=cur[u];~k;k=e[k].next) if(e[k].f) {

			int v=e[k].to;

			if(dis[v]==dis[u]+e[k].w&&!vis[v]&&(tmp=dfs(v,min(f,e[k].f)))) {

				f-=tmp,ret+=tmp;

				e[k].f-=tmp,e[k^1].f+=tmp;

				if(!f) break;

			}

		}

		vis[u]=0;

		return ret;

	}

	ll work() { ll ans=0; while(bfs()) ans+=dis[T]*dfs(S,1e9); return ans; }

}

int rx[N],ry[N],rc[N];

int bx[N],by[N],bc[N];

int n;

int main() {

	rd(n);

	for(int i=1;i<=n;++i) rd(rx[i]),rd(ry[i]),rd(rc[i]);

	for(int i=1;i<=n;++i) rd(bx[i]),rd(by[i]),rd(bc[i]);

	S=2*n+1,T=2*n+2;

	int p[4];

	for(int i=0;i<4;++i) p[i]=2*n+3+i;

	Flow::init();

	for(int i=1;i<=n;++i) {

		Flow::ad(S,i,rc[i],0);

		Flow::ad(i+n,T,bc[i],0);

	}

	for(int i=1;i<=n;++i) {

		Flow::ad(i,p[0],inf,rx[i]+ry[i]);

		Flow::ad(i,p[1],inf,rx[i]-ry[i]);

		Flow::ad(i,p[2],inf,-rx[i]+ry[i]);

		Flow::ad(i,p[3],inf,-rx[i]-ry[i]);

		

		Flow::ad(p[0],i+n,inf,-bx[i]-by[i]);

		Flow::ad(p[1],i+n,inf,-bx[i]+by[i]);

		Flow::ad(p[2],i+n,inf,bx[i]-by[i]);

		Flow::ad(p[3],i+n,inf,bx[i]+by[i]);

	}

	printf("%lld",Flow::work());

	return 0;

}
