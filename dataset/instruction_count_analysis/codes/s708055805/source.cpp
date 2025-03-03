#include<cstdio>

#include<vector>

#include<queue>

#include<algorithm>

using namespace std;



typedef long long LL;

const int MaxN=1e5+10;

int rmq[MaxN][20];

int dis[MaxN];

vector<int> mp[MaxN];

int n;



void dfs(int u,int pre){

	dis[u]=dis[pre]+1;

	if(pre)	rmq[u][0]=pre;

	else rmq[u][0]=u;

	for(int i=1;i<20;i++)

		if(u==1)	rmq[u][i]=u;

		else rmq[u][i]=rmq[rmq[u][i-1]][i-1];

	sort(mp[u].begin(),mp[u].end());

	for(int v:mp[u])

		dfs(v,u);

	}



queue<int> q;

vector<int> path;



void bfs(int u){

	q.push(u);

	while(!q.empty()){

		u=q.front();

		q.pop();

		for(int v:mp[u]){

			path.push_back(v);

			q.push(v);

			}

		}

	}



int getlca(int u,int v){

	if(dis[u]<dis[v])	swap(u,v);

	for(int i=19;i>=0;i--)

		if(dis[rmq[u][i]]>=dis[v])	u=rmq[u][i];

	if(u==v)	return u;

	for(int i=19;i>=0;i--){

		if(rmq[u][i]!=rmq[v][i]){

			u=rmq[u][i];

			v=rmq[v][i];

			}

		}

	return rmq[u][0];

	}



int main(){

	int p,u;

	scanf("%d",&n);

	for(int i=2;i<=n;i++){

		scanf("%d",&p);

		mp[p].push_back(i);

		}

	dfs(1,0);

	bfs(1);

	u=1;

	LL res=0;

	for(int v:path){

		res+=dis[u]+dis[v]-dis[getlca(u,v)]*2;

		u=v;

		}

	printf("%lld\n",res);

	return 0;

	}