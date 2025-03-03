#include "stdc++.h"

using namespace std;



#define ll long long

#define endl "\n"



vector<ll> adj[100005];

ll vis[100005];

ll n, m;



void add(ll x, ll y) {

  adj[x].push_back(y);

  adj[y].push_back(x);

}



void solve() {

  ll a, b, c, d;

  cin >> a >> b >> c >> d;

  ll ans1 = max(a, b) * min(c, d);

  ll ans2 = min(a, b) * max(c, d);

  ll ans3 = max(a, b) * max(c, d);

  ll ans4 = min(a, b) * min(c, d);

  ll ans5 = max(max(ans1, ans2), max(ans3, ans4));

  cout << ans5 << endl;

}



int main() {

  ll t;

  // cin >> t;

  t = 1;

  while (t--)

    solve();

  return 0;

}