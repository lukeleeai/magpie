#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<vector>

#define SF scanf

#define PF printf

#define MAXN 100010

#define INF 0x3FFFFFFF

using namespace std;

typedef long long ll;

int siz[MAXN];

ll ans;

int siz1,d1,d2;

ll dep[MAXN];

vector<int> a[MAXN],w[MAXN];

int n;

void dfs(int x,int fa){

	for(int i=0;i<a[x].size();i++){

		int u=a[x][i];

		if(u==fa)

			continue;

		dfs(u,x);

		siz[x]+=siz[u];	

	}

	siz[x]++;

	int siz2=n-siz[x];

	for(int i=0;i<a[x].size();i++)

		if(a[x][i]!=fa)

			siz2=max(siz2,siz[a[x][i]]);

	if(siz2<siz1||siz1==-1){

		siz1=siz2;

		d1=x;

		d2=0;

	}

	else if(siz1==siz2)

		d2=x;

}

void solve(int x,int fa){

	for(int i=0;i<a[x].size();i++){

		int u=a[x][i];

		if(u==fa)

			continue;

		dep[u]=dep[x]+w[x][i];

		solve(u,x);

	}	

	ans+=dep[x]*2;

}

int main(){

	SF("%d",&n);

	int u,v,val;

	for(int i=1;i<n;i++){

		SF("%d%d%d",&u,&v,&val);

		a[u].push_back(v);

		a[v].push_back(u);	

		w[u].push_back(val);

		w[v].push_back(val);

	}

	siz1=-1;

	dfs(1,0);

	solve(d1,0);

	ll add=-1;

	if(d2==0){

		for(int i=1;i<=n;i++)

			if(i!=d1){

				if(add==-1)

					add=dep[i];

				add=min(add,1ll*dep[i]);	

			}

	}

	else

		add=dep[d2];

	ans-=add;

	PF("%lld",ans);

}