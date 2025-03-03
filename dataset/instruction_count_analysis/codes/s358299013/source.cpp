#include"stdc++.h"

#define inf 0x7fffffff

#define RG register

#define inf 0x7fffffff

#define mkp make_pair

#define maxn 100205

typedef unsigned int U;

using namespace std;

typedef long long ll;

const ll mod = 998244353;

const  double eps = 1e-8;

const double pi = acos(-1);

inline ll read(){

    ll x = 0, f = 1;

    char ch = getchar();

    while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getchar();}

    while(ch >= '0' && ch <= '9'){x = x *10 + ch -'0';ch = getchar();}

    return x * f;

}

int n,m,inde[100005],tot;

struct p{

	int c[4];

	bool operator < (const p & a)const{

		if(c[0]!=a.c[0]) return c[0]<a.c[0];

		if(c[1]!=a.c[1]) return c[1]<a.c[1];

		if(c[2]!=a.c[2]) return c[2]<a.c[2];

		return c[3]<a.c[3];

	}

}col[405];

map<p,int> mp;

void add(p x,int val){

	p now=x,nxt;

	mp[now]+=val;

	for(int j=1;j<=3;j++){

		for(int i=0;i<=3;i++) nxt.c[i]=now.c[(i+1)%4];

		now=nxt;

		mp[now]+=val;

	}

}

int main(){

	int i,j,u,v,e,w;

	//freopen("a.out","r",stdin);

	//freopen("a.ans","w",stdout);

	n=read();

	for(i=1;i<=n;i++)

		col[i].c[0]=read(),col[i].c[1]=read(),col[i].c[2]=read(),col[i].c[3]=read();

	for(i=1;i<=n;i++) 

		add(col[i],1);

	ll ans=0,S;

	for(i=1;i<=n-5;i++){

		add(col[i],-1);

		for(j=i+1;j<=n;j++){

			add(col[j],-1);

			p now,nxt=col[j],pj;

			for(e=1;e<=4;e++){

				now=nxt;

				S=1;

				for(w=0;w<=3;w++) nxt.c[w]=now.c[(w+1)%4];

				for(w=0;w<=3;w++){

					pj=(p){col[i].c[(w+1)%4],col[i].c[w],now.c[3-w],now.c[3-(w+1)%4]};

					S*=mp[pj];

					if(!mp[pj]) break;

					else add(pj,-1);

				}

				w--;

				for(;w>=0;w--){

					pj=(p){col[i].c[(w+1)%4],col[i].c[w],now.c[3-w],now.c[3-(w+1)%4]};

					add(pj,1);

				}

				ans+=S;

			}

			add(col[j],1);

		}

	}

	printf("%lld\n",ans);

	return 0;

}

/*

8

0 0 0 0

0 0 1 1

0 1 0 1

0 1 1 0

1 0 0 1

1 0 1 0

1 1 0 0

1 1 1 1

*/