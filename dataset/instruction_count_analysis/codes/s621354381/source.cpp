#include "bits/stdc++.h"

#include "ext/pb_ds/assoc_container.hpp"

#include "ext/pb_ds/tree_policy.hpp"



using namespace std;

using namespace __gnu_pbds;





#define ll long long int

#define pb push_back

#define mp make_pair

#define ff first

#define ss second

#define all(a) a.begin(),a.end()



typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// order_of_key(val): returns the number of values less than val

// find_by_order(k): returns an iterator to the kth largest element (0-based)

vector<ll> adj[200001];

ll seg[800005], lazy[800005];

ll merge(ll a, ll b)

{

	return a + b;

}

void update(ll pos, ll l, ll r, ll l1, ll r1, ll val)

{

	if(l > r)

		return;

	if(lazy[pos])

	{

		seg[pos] += (r - l + 1) * lazy[pos];

		if(l != r)

		{

			lazy[2*pos+1] += lazy[pos];

			lazy[2*pos+2] += lazy[pos];

		}

		lazy[pos] = 0;

	}

	if(r1 < l || l1 > r)

		return;

	if(l1 <= l && r <= r1)

	{

		seg[pos] += (r - l + 1) * val;

		if(l != r)

		{

			lazy[2*pos+1] += val;

			lazy[2*pos+2] += val;

		}

		return;

	}

	ll mid = (l + r)/2;

	update(2*pos+1, l, mid, l1, r1, val);

	update(2*pos+2, mid+1, r, l1, r1, val);

	seg[pos] = merge(seg[2*pos+1], seg[2*pos+2]);

	return;

}

ll query(ll pos, ll l, ll r, ll l1, ll r1)

{

	if(l > r || r1 < l || l1 > r)

		return 0;

	if(lazy[pos])

	{

		seg[pos] += (r - l + 1) * lazy[pos];

		if(l != r)

		{

			lazy[2*pos+1] += lazy[pos];

			lazy[2*pos+2] += lazy[pos];

		}

		lazy[pos] = 0;

	}

	if(l1 <= l && r <= r1)

		return seg[pos];

	ll mid = (l + r)/2;

	return merge(query(2*pos+1, l, mid, l1, r1), query(2*pos+2, mid+1, r, l1, r1));

}

int main(void)

{

	ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll n, i, a, b, j, k;

    cin >> n;

    ll ans[n], sum = 0;

    for(i = 0; i < n - 1; i++) {

    	cin >> a >> b;

    	a--, b--;

    	if(a < b) {

    		swap(a, b);

    	}

    	adj[a].pb(b);

    }

    for(i = 0; i < n; i++) {

    	ans[i] = 0;

    	sort(all(adj[i]));

    	ll prev = 0;

    	ll s = adj[i].size();

    	for(j = 0; j < s; j++) {

    		ll rem = s - j;

    		ll sub = rem - 1;

    		update(0, 0, n - 1, prev, adj[i][j], -sub);

    		prev = adj[i][j] + 1;

    	}

    	update(0, 0, n - 1, prev, i, 1);

    	sum += query(0, 0, n - 1, 0, i);

    }

    cout << sum << "\n";

}