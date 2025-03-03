#include<stdio.h>

#include<vector>

#include<queue>

#include<map>

#define INF 200000000

using namespace std;

typedef pair<int,int> P;

vector<P> e[100000];

vector<P> te[100000];

int d[100000];

bool used[100000];

int bfr[100000];

int dep[100000];

int par[20][100000];

int cos[20][100000];

int n,m,s,q;

priority_queue< P,vector<P>,greater<P> > que;

int max(int a,int b){return a>b?a:b;}

int min(int a,int b){return a<b?a:b;}

void dykstra(){

	int i;

	while(!que.empty()){

		P p=que.top();que.pop();

		int v=p.second;

		if(p.first>d[v])continue;

		for(i=0;i<e[v].size();i++){

			int u=e[v][i].first;

			int cost=e[v][i].second;

			if(d[u]>d[v]+cost){

				d[u]=d[v]+cost;

				que.push(P(d[u],u));

			}

		}

	}

}

void kraskal(){

	int i;

	for(i=0;i<n;i++){

		used[i]=false;

		d[i]=INF;

		bfr[i]=-1;

	}

	d[0]=0;

	que.push(P(0,0));

	while(!que.empty()){

		P p=que.top();que.pop();

		int v=p.second;

		if(p.first>d[v])continue;

		used[v]=true;

		if(bfr[v]!=-1){

			te[v].push_back(P(bfr[v],-d[v]));

			te[bfr[v]].push_back(P(v,-d[v]));

		}

		for(i=0;i<e[v].size();i++){

			int u=e[v][i].first;

			int cost=e[v][i].second;

			if(!used[u]&&d[u]>cost){

				d[u]=cost;

				bfr[u]=v;

				que.push(P(d[u],u));

			}

		}

	}

}

void dfs(int v,int p,int depth){

	dep[v]=depth;

	for(int i=0;i<te[v].size();i++){

		int u=te[v][i].first;

		if(u==p)continue;

		par[0][u]=v;

		cos[0][u]=te[v][i].second;

		dfs(u,v,depth+1);

	}

}

int lca(int a,int b){

	if(dep[a]>dep[b]){int p=a;a=b;b=p;}

	int dif=dep[b]-dep[a];

	int ans=INF;

	int i;

	for(i=0;i<20;i++){

		if(dif>>i&1){

			ans=min(ans,cos[i][b]);

			b=par[i][b];

		}

	}

	if(a==b)return ans;

	for(i=19;i>=0;i--){

		if(par[i][a]!=par[i][b]){

			ans=min(ans,cos[i][a]);

			ans=min(ans,cos[i][b]);

			a=par[i][a];

			b=par[i][b];

		}

	}

	ans=min(ans,cos[0][a]);

	ans=min(ans,cos[0][b]);

	return ans;

}

	

int main(){

	scanf("%d %d %d %d",&n,&m,&s,&q);

	int i,j;

	for(i=0;i<m;i++){

		int a,b,c;

		scanf("%d %d %d",&a,&b,&c);

		a--;b--;

		e[a].push_back(P(b,c));

		e[b].push_back(P(a,c));

	}

	for(i=0;i<n;i++)d[i]=INF;

	for(i=0;i<s;i++){

		int p;

		scanf("%d",&p);

		d[p-1]=0;

		que.push(P(0,p-1));

	}

	dykstra();

	for(i=0;i<n;i++){

		for(j=0;j<e[i].size();j++){

			e[i][j].second=-min(d[i],d[e[i][j].first]);

		}

	}

	kraskal();

	for(i=0;i<20;i++)for(j=0;j<n;j++){

		par[i][j]=-1;

		cos[i][j]=INF;

	}

	dfs(0,-1,0);

	for(i=1;i<20;i++){

		for(j=0;j<n;j++){

			if(par[i-1][j]!=-1){

				par[i][j]=par[i-1][par[i-1][j]];

				cos[i][j]=min(cos[i-1][j],cos[i-1][par[i-1][j]]);

			}

		}

	}

	for(i=0;i<q;i++){

		int a,b;

		scanf("%d %d",&a,&b);

		printf("%d\n",lca(a-1,b-1));

	}

	return 0;

}