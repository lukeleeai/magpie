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



int n;

vi adj[100001];

ll a[100001];

ll dp[100001];

ll sumleaf[100001];



ll solve(vector<ll>& vec)

{

	if(vec.empty()) return 0;

	ll mx = 0;

	ll sum = 0;

	int k = vec.size();

	for(int i = 0; i < k; i++)

	{

		mx=max(mx,vec[i]);

		sum+=vec[i];

	}

	if(mx*2>sum)

	{

		return (sum-mx);

	}

	else

	{

		return sum/2;

	}

}



void prep(int u, int p)

{

	bool leaf=1;

	for(int i = 0; i < adj[u].size(); i++)

	{

		int v = adj[u][i];

		if(v==p) continue;

		leaf=0;

		prep(v,u);

		sumleaf[u]+=sumleaf[v];

	}

	if(leaf)

	{

		sumleaf[u]=a[u];

	}

}



ll dfs1(int u, int p)

{

	ll sum = 0;

	for(int i = 0; i < adj[u].size(); i++)

	{

		int v = adj[u][i];

		if(v==p) continue;

		ll val = dfs1(v,u);

		sum+=val;

		a[u] -= val*2;

	}

	sum+=a[u];

	return sum;

}

bool pos;

ll dfs2(int u, int p)

{

	ll sum = 0;

	vector<ll> vec;

	bool leaf=1;

	for(int i = 0; i < adj[u].size(); i++)

	{

		int v = adj[u][i];

		if(v==p) continue;

		leaf=0;

		ll val = dfs2(v,u);

		sum+=val;

		vec.pb(val);

	}

	if(leaf)

	{

		if(a[u]>0)

		{

			pos=0;

			return 0;

		}

		return sumleaf[u];

	}

	ll cnt = solve(vec);

	if(cnt<a[u])

	{

		pos=0;

		return 0;

	}

	//apply a[u] times;

	return (sum - ll(a[u])*2LL);

}



int main()

{

	ios_base::sync_with_stdio(0); cin.tie(0);

	pos=1;

	int n; cin>>n;

	for(int i = 0; i < n; i++)

	{

		cin>>a[i];

	}

	for(int i = 0; i + 1 < n; i++)

	{

		int u, v; cin>>u>>v;

		u--; v--;

		adj[u].pb(v); adj[v].pb(u);

	}

	if(n==2)

	{

		if(a[0]==a[1])

		{

			cout<<"YES\n";

		}

		else

		{

			cout<<"NO\n";

		}

		return 0;

	}

	int rt = 0;

	for(int i = 0; i < n; i++)

	{

		if(adj[i].size()!=1)

		{

			rt=i;

			break;

		}

	}

	prep(rt,-1);

	//cerr<<rt<<'\n';

	for(int i = 0; i < n; i++)

	{

		ll newa = (sumleaf[i] - a[i]);

		//cerr<<i<<' '<<sumleaf[i]<<' '<<a[i]<<' '<<newa<<'\n';

		/*

		if(newa&1)

		{

			cout<<"NO\n";

			return 0;

		}

		*/

		if(newa<0)

		{

			cout<<"NO\n";

			return 0;

		}

		//a[i]=newa/2;

		a[i]=newa;

	}

	dfs1(rt,-1);

	for(int i = 0; i < n; i++)

	{

		if(a[i]<0)

		{

			cout<<"NO\n";

			return 0;

		}

	}

	ll val = dfs2(rt,-1);

	if(pos&&val==0) cout<<"YES\n";

	else cout<<"NO\n";

}
