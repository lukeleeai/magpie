#include <cstdio>

#include <algorithm>

#include <cmath>

#include <cstring>



using std::min;

using std::abs;



const int MAXN=1005,MAXW=5005;

int n;

int he[MAXN],w[MAXN],blk[MAXN],wht[MAXN];



struct line{

	int to,nex;

	line(int to=0,int nex=0):to(to),nex(nex){}

}ed[MAXN];



inline void addE(int u,int v){

	static int cnt=0;

	ed[++cnt]=line(v,he[u]);

	he[u]=cnt;

}



bool treeDP(int u){

	static int tmp[MAXN];

	static bool can[MAXW];

	for(int i=he[u];i;i=ed[i].nex){

		if(!treeDP(ed[i].to)) return false;

	}

	if(!he[u]){

		blk[u]=w[u];

		return true;

	}

	int need=w[u],sum=0;

	tmp[0]=0;

	for(int i=he[u],v;i;i=ed[i].nex){

		v=ed[i].to;

		need-=min(blk[v],wht[v]);

		if(need<0) return false;

		tmp[++tmp[0]]=abs(blk[v]-wht[v]);

		sum+=blk[v]+wht[v];

	}

	memset(can,false,sizeof(can));

	can[0]=true;

	for(int i=1;i<=tmp[0];++i){

		for(int j=MAXW-1;j>=tmp[i];--j)

			can[j]|=can[j-tmp[i]];

	}

	for(int i=need;i>=0;--i){

		if(can[i]){

			need-=i;

			break;

		}

	}

	blk[u]=w[u],wht[u]=sum-blk[u]+need;

	return true;

}



int main(){

	scanf("%d",&n);

	for(int i=2,fa;i<=n;++i){

		scanf("%d",&fa);

		addE(fa,i);

	}

	for(int i=1;i<=n;++i)

 		scanf("%d",&w[i]);

	if(treeDP(1)) printf("POSSIBLE");

	else printf("IMPOSSIBLE");

	return 0;

}