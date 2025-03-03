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

bool marked[100001];

vector<ii> v[100001];  //adjList



ll prim(int k){

    priority_queue<ii, vector<ii>, greater<ii> > q;

    ll u;

    long long minimumCost = 0;

    ii p;

    q.push(mp(0, k));

    while(!q.empty())

    {

        p = q.top();

        q.pop();

        k = p.second;

        if(marked[k] == true)

            continue;

        minimumCost += p.fi;

        marked[k] = true;

        for(ll i = 0;i < v[k].size();++i)

        {

            u = v[k][i].se;

            if(marked[u] == false)

                q.push(v[k][i]);

        }

    }

    return minimumCost;

}



int main() {

    std::ios::sync_with_stdio(false);

    cin.tie(NULL);

    long long n;

    cin>>n;

    vector<ii> x;

    vector<ii> y;

    for(ll i =0;i<n;i++){

        ll a,b;

        cin>>a>>b;

        x.pb(mp(a,i));

        y.pb(mp(b,i));

    }

    sort(x.begin(),x.end());

    sort(y.begin(),y.end());

    for(ll i=0;i<n-1;i++){

        v[x[i].se].pb(mp(x[i+1].fi-x[i].fi,x[i+1].se));

        v[x[i+1].se].pb(mp(x[i+1].fi-x[i].fi,x[i].se));

        v[y[i].se].pb(mp(y[i+1].fi-y[i].fi,y[i+1].se));

        v[y[i+1].se].pb(mp(y[i+1].fi-y[i].fi,y[i].se));

    }

    ll ans=prim(0);

    cout<<ans;

    return 0;

}
