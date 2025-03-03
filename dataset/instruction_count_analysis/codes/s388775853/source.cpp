#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

 

using namespace std;

using namespace __gnu_pbds;

 

#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define fbo find_by_order

#define ook order_of_key

 

typedef long long ll;

typedef pair<ll,ll> ii;

typedef vector<int> vi;

typedef long double ld; 

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

typedef set<int>::iterator sit;

typedef map<int,int>::iterator mit;

typedef vector<int>::iterator vit;

 

int par[100001];

vi adj[100001];

int dp[100001];

 

void dfs(int u)

{

	vi vec;

	for(int i = 0; i < adj[u].size(); i++)

	{

		int v = adj[u][i];

		dfs(v);

		vec.pb(dp[v]);

	}

	sort(vec.begin(),vec.end());

	dp[u] = 0;

	for(int i = 0; i < vec.size(); i++)

	{

		int t = vec[i];

		if(dp[u]<t+1) dp[u]=t+1;

		else

		{

			dp[u]++;

		}

	}

	//cerr<<u<<' '<<dp[u]<<'\n';

}

 

int main()

{

	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin>>n;

	for(int i = 1; i < n; i++) 

	{

		cin>>par[i];

		par[i]--;

		adj[par[i]].pb(i);

	}

	dfs(0);

	cout<<dp[0]<<'\n';

}