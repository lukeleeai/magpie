#include "stdc++.h"

using namespace std;

#define MAXN 100000

#define rint register int

#define gc() getchar()

inline int read(int r=0,int s=0,int c=gc()){for(;c<48||c>57;s=c,c=gc());for(;c>=48&&c<=57;(r*=10)+=c-48,c=gc());return s^'-'?r:-r;}

vector<int> e[MAXN+5]; int fa[MAXN+5], h[MAXN+5], n, K, Ans;

void DFS(int p){h[p] = 1; for(auto v:e[p]) DFS(v), h[p] = max(h[p],h[v]+1); if(h[p]==K&&fa[p]>1) ++Ans, h[p] = 0;}

int main(){n = read(), K = read(), Ans = read()>1; for(rint i = 2; i <= n; e[fa[i]=read()].push_back(i), i++); DFS(1); printf("%d\n",Ans); return 0;}