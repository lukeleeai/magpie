#include <cstdio>

#include <iostream>

#include <algorithm>

#include <cstring>

#define ll long long

using namespace std;

template <class T>

inline void rd(T &x)

{

	x=0; char c=getchar(); int f=1;

	while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}

	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;

}

const int N=1e5+10;

int fa[N],n,q;

ll m;

struct Que { int x,y,c; }Q[N];

int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }

void FAIL() {

	printf("No");

	exit(0);

}

int main() {

	rd(n),rd(m),rd(q);

	for(int i=1;i<=n;++i) fa[i]=i;

	for(int i=1;i<=q;++i) {

		rd(Q[i].x),rd(Q[i].y),rd(Q[i].c);

		Q[i].x++,Q[i].y++;

		if(Q[i].c==0)

			fa[find(Q[i].x)]=find(Q[i].y);

	}

	int flg=0;

	for(int i=1;i<=q;++i) if(Q[i].c==1) {

		flg=1;

		if(find(Q[i].x)==find(Q[i].y)) FAIL();

	}

	int M=0;

	for(int i=1;i<=n;++i) M+=find(i)==i;

	if(m>M*(ll)(M-1)/2+(n-M)) FAIL();

	if(flg&&m<n) FAIL();

	printf("Yes");

	return 0;

}