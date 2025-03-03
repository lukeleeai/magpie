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



int main(void)

{

	ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll n, i, a, b, ans = 0;

    cin >> n;

    vector<pair<ll, ll>> edges;

    for(i = 0; i < n - 1; i++) {

    	cin >> a >> b;

    	if(a < b) {

    		swap(a, b);

    	}

    	edges.pb(mp(a, b));

    }

    for(i = 1; i <= n; i++) {

    	ans = ans + i * (n - i + 1);

    }

    for(auto u: edges) {

    	ans = ans - (u.ss * (n - u.ff + 1));

    }

    cout << ans << "\n";

}