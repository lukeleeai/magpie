#include <vector>

#include <stdio.h>

#include <string.h>

#include <iostream>

#include <algorithm>

#define R register

typedef long long ll;

inline int read(){

	R int x; R bool f; R char c;

	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');

	for (x=c^'0'; (c=getchar())>='0'&&c<='9'; x=(x<<1)+(x<<3)+(c^'0'));

	return f?-x:x;

}

#define M (1<<18)

#define MN 200005

int T[M<<1],n,q,cost[MN],cnt;

std::vector<int> rang[MN];

inline void rw(int k,int v){for (k+=M; k; k>>=1) if (T[k]<=v) return; else T[k]=v;}

inline int query(int l,int r){

	R int res=0x3f3f3f3f;

	for (l+=M-1,r+=M+1; l^r^1; l>>=1,r>>=1){

		if (~l&1) res=std::min(T[l^1],res);

		if ( r&1) res=std::min(T[r^1],res);

	}return res;

}

int main(){

	n=read();for (R int i=1; i<=n; ++i)

		cost[i]=read()?1:-1,cnt+=(bool)(!(~cost[i]));

	q=read();for (R int i=1,x,y; i<=q; ++i)

		x=read(),y=read(),rang[x].push_back(y);

	memset(T,0x3f,sizeof(T));rw(0,0);

	for (R int i=1; i<=n; ++i){

		for (auto j : rang[i]){

			R int res = T[i+M-1];

			res=std::min(res,query(std::max(i-1,1),j));

			rw(j,res);

		}rw(i,T[i+M-1]+cost[i]);

	}printf("%d\n",T[n+M]+cnt);

	return 0;

}