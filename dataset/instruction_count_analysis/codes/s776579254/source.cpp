#include"stdc++.h"

const int P=998244353;

int n;

struct pos{

	int x,y;

}ps[1007];

int ep=0,f[1007],sz[1007];

int gf(int x){while(x!=f[x])x=f[x]=x[f][f];return x;}

struct edge{

	int a,b;

	int v;

	bool operator<(const edge&e)const{return v<e.v;}

	void cal(){

		int x=gf(a),y=gf(b);

		if(x!=y)f[x]=y,sz[y]+=sz[x];

	}

}es[207*207];

int gcd(int a,int b){

	return b?gcd(b,a%b):a;

}

int pw[1007],ans;

int main(){

	scanf("%d",&n);

	pw[0]=1;

	for(int i=1;i<=n;++i)pw[i]=pw[i-1]*2%P;

	ans=(pw[n]-n-1)%P;

	for(int i=0;i<n;++i)scanf("%d%d",&ps[i].x,&ps[i].y);

	for(int i=0;i<n;++i){

		for(int j=0;j<i;++j){

			int x=ps[i].x-ps[j].x,y=ps[i].y-ps[j].y;

			int g=gcd(x,y);

			x/=g,y/=g;

			if(!x)y=1;

			if(!y)x=1;

			if(x<0)x=-x,y=-y;

			es[ep++]=(edge){i,j,x*30000+y};

		}

	}

	std::sort(es,es+ep);

	for(int i=0,j=0;i<ep;i=j){

		for(int a=0;a<n;++a)sz[f[a]=a]=1;

		for(;j<ep&&es[i].v==es[j].v;es[j++].cal());

		for(int a=0;a<n;++a)if(f[a]==a&&sz[a]>1)ans=(ans-pw[sz[a]]+sz[a]+1)%P;

	}

	printf("%d\n",(ans%P+P)%P);

	return 0;

}