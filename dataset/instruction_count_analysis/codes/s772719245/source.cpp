#include "stdc++.h"

using namespace std;

typedef long long ll;



template <typename _tp> inline void read(_tp&x){

	char ch=getchar(),ob=0;x=0;

	while(ch!='-'&&!isdigit(ch))ch=getchar();if(ch=='-')ob=1,ch=getchar();

	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();if(ob)x=-x;

}



const int N = 201000;

struct Edge {int v, nxt;} a[N*4];

int head[N], Head[N], indeg[N];

int sz[N], pr[N];

bool vis[N];

int n, _;



inline void add(int x, int y, int*arr) {

	a[++_].v = y, a[_].nxt = arr[x], arr[x] = _;

}



const int p = 1e9+7;

int fac[N], ifac[N], inv[N];



int st[N], tp;

#define FID(i) for(int id=1,i;i=st[id],id<=tp;++id)



int X, Y;

int et, pt;



void bfs(int x, int las) {

	vis[st[++tp] = x] = true, ++pt;

	for(int i=head[x];i;++et,i=a[i].nxt)

		if(!vis[a[i].v]) bfs(a[i].v, x);

		else if(a[i].v != las) X = x, Y = a[i].v;

}



void tfs(int x, int las) {

	for(int i=head[x];i;i=a[i].nxt)

		if(a[i].v != las and a[i].v != X)

			pr[a[i].v] = x, tfs(a[i].v, x);

}



void dfs(int x, int las) {

	sz[x] = 1;

	for(int i=Head[x];i;i=a[i].nxt)

		if(a[i].v != las)

			dfs(a[i].v, x), sz[x] += sz[a[i].v];

}



int solve() {

	tfs(X, Y);

	pr[X] = Y;

	FID(i) Head[i] = indeg[i] = 0;

	FID(x) for(int i=head[x];i;i=a[i].nxt)

		if(a[i].v < pr[x]) add(x, a[i].v, Head), ++indeg[a[i].v];

	

	FID(i) if(!indeg[i]) dfs(i, i);

	int Ans = fac[pt];

	FID(i) Ans = (ll)Ans * inv[sz[i]]%p;

	return Ans;

}



int main() {

	read(n);

	for(int i=1,x,y;i<=(n<<1);++i) {

		read(x), read(y), y += n;

		add(x, y, head);

		add(y, x, head);

	}

	

	n <<= 1;

	fac[0] = fac[1] = inv[0] = inv[1] = ifac[0] = ifac[1] = 1;

	for(int i=2;i<=n;++i) {

		fac[i] = (ll)fac[i-1] * i%p;

		inv[i] = (ll)(p-p/i) * inv[p%i]%p;

		ifac[i] = (ll)ifac[i-1] * inv[i]%p;

	}

	

	int Ans = fac[n];

	for(int i=1;i<=n;++i)

		if(!vis[i]) {

			tp = pt = et = 0;

			bfs(i, i);

			Ans = (ll)Ans * ifac[pt]%p;

			if((pt << 1) != et) return puts("0"), 0;

			int res = solve();

			swap(X, Y);

			res += solve();

			Ans = (ll)Ans * res%p;

		}

	printf("%d\n", Ans);

	return 0;

}