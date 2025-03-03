#include "stdc++.h"

using namespace std;

#define MAXN 100000

#define ll long long

#define rint register int

inline int read(){int r;int s=0,c;for(;!isdigit(c=getchar());s=c);for(r=c^48;isdigit(c=getchar());(r*=10)+=c^48);return s^45?r:-r;}

vector<int> e[MAXN+5], g[MAXN+5]; int A[MAXN+5], B[MAXN+5], fa[MAXN+5], rk[MAXN+5] ,o[MAXN+5], n, m; ll f[MAXN+5], s[MAXN+5];

inline bool cmp(int i, int j){return A[i]<A[j];} inline int getf(int x){return x^fa[x]?fa[x]=getf(fa[x]):x;}

ll DP(int p){for(auto v:g[p]) f[p] = min(f[p],max((ll)A[o[p]],DP(v))-s[v]), s[p] += s[v]; return f[p] += s[p];}

int main()

{

	n = read(); m = read(); for(rint i = 1; i <= n; A[i] = read(), B[i] = read(), A[i] = max(A[i]-B[i],0), fa[i] = o[i] = i, i++); sort(o+1,o+n+1,cmp);

	for(rint i = 1; i <= n; rk[o[i]] = i, f[i] = A[o[i]], s[i] = B[o[i]], i++); for(rint a, b; m--; a = rk[read()], b = rk[read()], e[a].push_back(b), e[b].push_back(a));

	for(rint u = 1, U, V; u <= n; u++) for(auto v:e[u]) v<u&&(V=getf(v))^(U=getf(u))?g[U].push_back(V),fa[V]=U:0; printf("%lld\n",DP(getf(1))); return 0;

}