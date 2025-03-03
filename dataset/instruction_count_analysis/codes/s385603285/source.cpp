#include"stdc++.h"

#define fi first

#define se second

#define pb push_back

#define SZ(x) ((int)x.size())

#define L(i,u) for (register int i=head[u]; i; i=nxt[i])

#define rep(i,a,b) for (register int i=(a); i<=(b); i++)

#define per(i,a,b) for (register int i=(a); i>=(b); i--)

using namespace std;

typedef long long ll;

typedef unsigned int ui;

typedef pair<int,int> Pii;

typedef vector<int> Vi;

template<class T> inline void read(T &x){

	x=0; char c=getchar(); int f=1;

	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}

	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;

}

template<class T> inline void umin(T &x, T y){x=x<y?x:y;}

template<class T> inline void umax(T &x, T y){x=x>y?x:y;}

inline ui R() {

	static ui seed=416;

	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;

}

const int N = 233333;

int n,m;vector<Pii> e[N];bool vis[N],a[N],b[N];

bool ok,exi;int tote;int cnt[3],col[N];ll res;

void dfs(int u, int x){

	vis[u]=1;col[u]=x;cnt[x]++;exi|=a[u]&&b[u];

	rep(i,0,SZ(e[u])-1){

		tote++;

		if(!vis[e[u][i].fi])dfs(e[u][i].fi,(x+e[u][i].se)%3);

		else ok|=(col[u]+e[u][i].se-col[e[u][i].fi])%3>0;

	}

}

int main() {

	read(n);read(m);

	while(m--){

		int u,v;read(u);read(v);a[u]=1;b[v]=1;

		e[u].pb(Pii(v,1));e[v].pb(Pii(u,2));

	}

	rep(i,1,n)if(!vis[i]){

		ok=0;exi=0;tote=0;rep(j,0,2)cnt[j]=0;

		dfs(i,0);int all=cnt[0]+cnt[1]+cnt[2];

		if(!ok){

			if(exi){

				res+=1LL*all*(all-1)/2;

				rep(j,0,2)res-=1LL*cnt[j]*(cnt[j]-1)/2;

			}

			else res+=tote/2;

		}

		else res+=1LL*all*all;

	}

	cout<<res;

	return 0;

}
