#include "stdc++.h"

using namespace std;

typedef long long ll;

#define rg register



template <typename _Tp> inline _Tp read(_Tp&x){

	char c11=getchar();x=0;while(!isdigit(c11))c11=getchar();

	while(isdigit(c11))x=x*10+c11-'0',c11=getchar();return x;

}



const int N=101000,ae=20;

struct Edge{int v,nxt;}a[N*ae*2];

int qx[N*ae],qy[N*ae],dad[N];

int head[N],_,sz[N];

int n,he=1,ta=0;



inline int find(int x){return dad[x]?dad[x]=find(dad[x]):x;}



inline void ins(int u,int v){++sz[u],a[++_].v=v,a[_].nxt=head[u],head[u]=_;}



map <ll,int> cnt;



#define h(x,y) (x+1ll*n*y)

inline void add(int x,int y){

	if(x>y)swap(x,y);

	ins(x,y),ins(y,x);

	if((++cnt[h(x,y)])==2)

		++ta,qx[ta]=x,qy[ta]=y;

}



int main(){

	read(n);int x,y,p;

	for(rg int i=n-2+n;i;--i)read(x),read(y),add(x,y);

	for(rg int i=1;i<n;++i){

		do	x=qx[he],y=qy[he],++he;

		while(find(x)==find(y)&&he<=ta);

		x=find(x),y=find(y);

		if(x==y){puts("NO");return 0;}

		if(sz[x]>sz[y])swap(x,y);

		--sz[y];cnt.erase(x<y?h(x,y):h(y,x));

		for(rg int j=head[x];j;j=a[j].nxt){

			p=find(a[j].v);

			if(p^y)if(p!=find(x))add(p,y);

		}

		dad[x]=y;

	}puts("YES");

}