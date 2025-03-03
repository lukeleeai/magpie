#include "stdc++.h"

#define LL long long

#define mp make_pair

#define pb push_back

#define INF (1<<29)

using namespace std;

typedef pair<int,int>pii;

int n,m;

vector<pii>G[200010];

int col[200010];

int vis[200010];

bool dfs(int x,int co){

//	cout<<"In:"<<x<<' '<<co<<endl;

	if(vis[x]!=-1)return col[x]==co;

	vis[x]=1;

	col[x]=co;

	for(pii i:G[x]){

		if(dfs(i.first,co+i.second)==0)return false;

//		else{

//			if(vis[i.first]!=co+i.second)return false;

//		}

	}

	return true;

}

int main(){

//	freopen("produce/People.txt","r",stdin);

	cin>>n>>m;

	memset(vis,-1,sizeof(vis));

	if(m==0){

		cout<<"Yes\n";

		return 0;

	}

	for(int i=1;i<=m;i++){

		int l,r,d;

		cin>>l>>r>>d;

		G[l].pb(mp(r,d));

		G[r].pb(mp(l,-d));

	}

	for(int i=1;i<=n;i++){

		if(vis[i]!=-1)continue;

		memset(col,0,sizeof(col));

		if(dfs(i,0)==0){

			cout<<"No\n";

			return 0;

		}

//		cout<<"-----------------------\n";

	}

	cout<<"Yes\n";

	return 0;

}
