#include "stdc++.h"

using namespace std;

#define MAXN 100000

#define ll long long

#define rint register int

#define gc() getchar()

inline int read(int r=0,int s=0,int c=gc()){for(;c<48||c>57;s=c,c=gc());for(;c>=48&&c<=57;(r*=10)+=c-48,c=gc());return s^'-'?r:-r;}

struct D{int a,b; D(){} D(int _a, int _b){a=_a,b=_b;} inline D operator + (D x){return D(a+x.a,b+x.b);}}w[MAXN+5];

int a[MAXN+5], q[MAXN+5], in[MAXN+5], n, m, k, h, t, S, T; ll Ans; bool book[MAXN+5]; vector<int> e[MAXN+5];

void DFS(int p, int c, int fa){k += c, w[p] = D(0,1-(c<<1)); for(auto v:e[p]) if(v^fa&&(p^S||v^T)&&(p^T||v^S)) DFS(v,c^1,p);}

void DFS_s(int p, int fa){for(auto v:e[p]) if(v^fa&&(p^S||v^T)&&(p^T||v^S)) DFS_s(v,p), w[p] = w[p]+w[v];}

int main()

{

	n = read(); if(n&1) return puts("-1"),0; m = read(); for(rint i = 1, a, b; i <= m; a = read(), b = read(), e[a].push_back(b), e[b].push_back(a), ++in[a], ++in[b], i++);

	if(m==n){for(rint i = 1; i <= n; in[i]<=1?book[q[++t]=i]=true:0, i++); h = 1; for(; h<=t; ) for(auto v:e[q[h++]]) --in[v]==1?book[q[++t]=v]=true:0;} else t = n;

	if(t<n){for(rint i = 1; i <= n; i++) if(!book[i]) for(auto v:e[S=i]) if(!book[v]){T = v; goto out;}} else S = 1; ;out:; DFS(S,0,0); if(m<n&&k^(n-k)) return puts("-1"),0;

	if((n-t)&1) w[S].b -= (n>>1)-k, w[T].b -= (n>>1)-k, Ans += abs((n>>1)-k); if(t<n&&~(n-t)&1){if(k^(n-k)) return puts("-1"),0; --w[S].a, ++w[T].a;}

	DFS_s(S,0); if(m<n||(n-t)&1){for(rint i = 1; i <= n; Ans += abs(w[i].b), i++); return printf("%lld\n",Ans),0;}

	a[k=1] = 0; for(rint i = 1; i <= n; w[i].a ? a[++k] = w[i].a>0?w[i].b:-w[i].b : Ans += abs(w[i].b), i++);

	sort(a+1,a+k+1); for(rint i = 1; i <= k; Ans += abs(a[i]-a[-~k>>1]), i++); return printf("%lld\n",Ans),0;

}