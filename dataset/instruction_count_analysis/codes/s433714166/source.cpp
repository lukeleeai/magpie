//minamoto

#include"stdc++.h"

#define R register

#define pb push_back

#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)

#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)

#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)

template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}

template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}

using namespace std;

const int N=2e5+5;

vector<int>pos[N];int vis[N];

int n,m,k,res,t,mx;

int main(){

	scanf("%d%d%d",&n,&m,&k);

	for(R int i=1,x,y;i<=k;++i)scanf("%d%d",&x,&y),pos[y].pb(x);

	fp(i,1,m)pos[i].pb(n+1),sort(pos[i].begin(),pos[i].end());

	res=pos[1][0]-1,t=0;

	fp(i,2,m){

		mx=0;

		for(auto v:pos[i]){

			if(v<=i+t||vis[v-1])vis[v]=1,cmax(mx,v);

			else{cmin(res,v-1);break;}

		}

		cmax(t,mx-i+1);

	}

	printf("%d\n",res);

	return 0;

}