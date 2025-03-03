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

typedef pair<int,int> ii;

typedef vector<int> vi;

typedef long double ld; 

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

typedef set<int>::iterator sit;

typedef map<int,int>::iterator mit;

typedef vector<int>::iterator vit;



int a[100001];

vi adj[100001];

int h[100001];

int ans, k;



void dfs(int u, int p)

{

	h[u] = 1;

	for(int i = 0; i < adj[u].size(); i++)

	{

		int v = adj[u][i];

		dfs(v, u);

		h[u] = max(h[u], h[v] + 1);

	}

	if(u != 1 && p != 1 && h[u] >= k)

	{

		ans++; h[u] = 0;

	}

}



int main()

{

	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n >> k;

	for(int i = 1; i <= n; i++)

	{

		cin >> a[i];

	}

	ans = 0;

	if(a[1] != 1)

	{

		a[1] = 1;

		ans++;

	}

	for(int i = 2; i <= n; i++)

	{

		adj[a[i]].pb(i);

	}

	//now we have a tree

	dfs(1, -1);

	cout << ans;

}	