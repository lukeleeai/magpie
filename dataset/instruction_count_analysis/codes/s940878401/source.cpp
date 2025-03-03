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



ll v[150001];

int par[150001];

vi adj[150001];



vector<ii> S[150001];



bool cmp2(const ii &a, const ii &b)

{

	if(a.se!=b.se) return a.se<b.se;

	return a.fi<b.fi;

}



void calc(ll mid, int u)

{

	for(int i=0;i<adj[u].size();i++)

	{

		calc(mid,adj[u][i]);

	}

	if(adj[u].empty())

	{

		S[u].pb(mp(0,0)); return ;

	}

	int u1=adj[u][0]; int u2=adj[u][1];

	if(S[u1].size()>S[u2].size()) swap(u1,u2);

	sort(S[u1].begin(),S[u1].end(),cmp2); sort(S[u2].begin(),S[u2].end());

	int ptr2=0;

	ll mind=ll(1e18);

	for(int i = int(S[u1].size()) - 1; i >= 0; i--)

	{

		ll a=S[u1][i].fi; ll b=S[u1][i].se; ll cap=mid-v[u1]-v[u2]-b;

		while(ptr2<S[u2].size()&&S[u2][ptr2].fi<=cap)

		{

			mind=min(mind,S[u2][ptr2].se);

			ptr2++;

		}

		if(mind<ll(1e18))

		{

			S[u].pb(mp(a+v[u1],mind+v[u2]));

		}

	}

	sort(S[u1].begin(),S[u1].end()); sort(S[u2].begin(),S[u2].end(),cmp2);

	ptr2=0;

	mind=ll(1e18);

	for(int i = int(S[u1].size()) - 1; i >= 0; i--)

	{

		ll a=S[u1][i].fi; ll b=S[u1][i].se; ll cap=mid-v[u1]-v[u2]-a;

		while(ptr2<S[u2].size()&&S[u2][ptr2].se<=cap)

		{

			mind=min(mind,S[u2][ptr2].fi);

			ptr2++;

		}

		if(mind<ll(1e18))

		{

			S[u].pb(mp(mind+v[u2],b+v[u1]));

		}

	}

}



int main()

{

	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin>>n;

	for(int i=1;i<n;i++)

	{

		cin>>par[i]>>v[i];

		par[i]--;

		adj[par[i]].pb(i);

	}

	ll lo=0; ll hi=ll(1e11);

	ll ans=0;

	while(lo<=hi)

	{

		ll mid=(lo+hi)>>1;

		calc(mid,0);

		if(S[0].empty())

		{

			lo=mid+1;

		}

		else

		{

			hi=mid-1;

			ans=mid;

		}

		for(int i=0;i<=n;i++) S[i].clear();

	}

	cout<<ans<<'\n';

}
