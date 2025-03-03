#include<stdio.h>

#include<vector>

#include<queue>

#include<map>

#include<algorithm>

#define to first

#define cost second

#define INF 1000000000

using namespace std;

typedef pair<int,int> P;

vector<P> e[100000];

vector<P> ge[100000];

vector<P> te[100000];

int d[100000];

int used[100000];

int bfr[100000];

int depth[100000];

int par[20][100000];

int cos[20][100000];

int n,m,k,q;

priority_queue< P,vector<P>,greater<P> > que;

int max(int a,int b){return a>b?a:b;}

int min(int a,int b){return a<b?a:b;}

void swap(int& a,int& b){int p=a;a=b;b=p;}

void dykstra(){

	int i;

	while(!que.empty()){

		P p=que.top();

		que.pop();

		int v=p.second;

		if(p.first>d[v])continue;

		for(i=0;i<e[v].size();i++){

			int u=e[v][i].to;

			int c=e[v][i].cost;

			if(d[u]>d[v]+c){

				d[u]=d[v]+c;

				que.push(P(d[u],u));

			}

		}

	}

}

void mt(){

	int i;

	for(i=0;i<n;i++){

		d[i]=INF;

		used[i]=false;

		bfr[i]=-1;

	}

	d[0]=0;

	que.push(P(0,0));

	while(!que.empty()){

		P p=que.top();

		que.pop();

		int v=p.second;

		if(p.first>d[v])continue;

		used[v]=true;

		if(bfr[v]!=-1){

			te[v].push_back(P(bfr[v],-d[v]));

			te[bfr[v]].push_back(P(v,-d[v]));

		}

		for(i=0;i<ge[v].size();i++){

			int u=ge[v][i].to;

			int c=ge[v][i].cost;

			if(!used[u]&&d[u]>c){

				d[u]=c;

				bfr[u]=v;

				que.push(P(d[u],u));

			}

		}

	}

}

void dfs(int v,int p,int d){

	int i;

	depth[v]=d;

	for(i=0;i<te[v].size();i++){

		if(te[v][i].to==p)continue;

		par[0][te[v][i].to]=v;

		cos[0][te[v][i].to]=te[v][i].cost;

		dfs(te[v][i].to,v,d+1);

	}

}

int lca(int a,int b){		

	if(depth[a]<depth[b])swap(a,b);

	int i;

	int diff=depth[a]-depth[b];

	int ans=INF;

	for(i=0;i<20;i++){

		if(diff>>i&1){

			ans=min(ans,cos[i][a]);

			a=par[i][a];

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

	scanf("%d %d %d %d",&n,&m,&k,&q);

	int i,j;

	for(i=0;i<m;i++){

		int a,b,c;

		scanf("%d %d %d",&a,&b,&c);

		a--;b--;

		e[a].push_back(P(b,c));

		e[b].push_back(P(a,c));

	}

	for(i=0;i<n;i++)d[i]=INF;

	for(i=0;i<k;i++){

		int s;

		scanf("%d",&s);

		d[s-1]=0;

		que.push(P(0,s-1));

	}

	dykstra();

	for(i=0;i<n;i++){

		for(j=0;j<e[i].size();j++){

			ge[i].push_back(P(e[i][j].to,-min(d[i],d[e[i][j].to])));

		}

	}

	mt();

	for(i=0;i<n;i++){

		for(j=0;j<20;j++){

			par[j][i]=-1;

			cos[j][i]=INF;

		}

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

		int s,t;

		scanf("%d %d",&s,&t);

		s--;t--;

		printf("%d\n",lca(s,t));

	}

	return 0;

}