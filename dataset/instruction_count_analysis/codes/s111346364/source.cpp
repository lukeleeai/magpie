#include "stdc++.h"

using namespace std;

#define INF 0x3f3f3f3f

#define rint register int

#define gc() getchar()

inline int read(int r=0,int s=0,int c=gc()){for(;c<48||c>57;s=c,c=gc());for(;c>=48&&c<=57;(r*=10)+=c-48,c=gc());return s^'-'?r:-r;}

vector<int> e[1025]; int f[1025][5025], X[1025], n;

void DP(int p){for(auto v:e[p]) for(rint i = (DP(v),X[p]); ~i; f[p][i] = min(i>=X[v]?f[p][i-X[v]]+f[v][X[v]]:INF,i>=f[v][X[v]]?f[p][i-f[v][X[v]]]+X[v]:INF), i--);}

int main(){n = read(); for(rint i = 2; i <= n; e[read()].push_back(i), i++); for(rint i = 1; i <= n; X[i++] = read()); DP(1); puts(f[1][X[1]]<INF?"POSSIBLE":"IMPOSSIBLE"); return 0;}