#include <iostream>

#include <algorithm>

#include <vector>

#include <queue>

#include <set>

#include <map>

#include <unordered_map>

#include <stack>

#include <cassert>

#include <string>

#include <cmath>

#include <iomanip>



using namespace std;

using ll = long long;

using ld = long double;



#define st first

#define nd second



const int MAXN = 2e5 + 5, inf = 1e9;

const ll INF = 1e18, mod = 1e9 + 7;

const ld PI = 3.1415926535897932384626433832795;



int cnt[MAXN], n;

ll dp[MAXN], h[MAXN], a[MAXN];

bool vis[MAXN], used[MAXN];



vector<int> G[MAXN];

vector<ll> V;

set<ll> S;

map<ll, int> M;

stack<ll> St;

queue<ll> Q;



ll Tree[2 * 1024 * 1024], Base = 1;



void chTree(int node, ll v) {

    node += Base;

    Tree[node] = v;

    while (node /= 2) {

        Tree[node] = max(Tree[2 * node], Tree[2 * node + 1]);

    }

}



ll read(int node, int lo, int hi, int l, int r) {

    if (r < lo or hi < l) {

        return 0;

    }

    if (l <= lo and hi <= r) {

        return Tree[node];

    }



    int mid = (lo + hi) / 2;

    return max(read(2 * node, lo, mid, l, r), read(2 * node + 1, mid + 1, hi, l, r));

}



ll f(ll j,  ll i) {

    return dp[j] + (h[i] - h[j]) * (h[i] - h[j]);

}



ld g(ll i, ll j) {

    return (ld) (h[j] * h[j] + dp[j] - h[i] * h[i] - dp[i]) / ((ld)(2 * h[j] - 2 * h[i]));

}



int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout << setprecision(13) << fixed;



    //////////////////////////////////////////

    //////////////////////////////////////////



    ll C;

    cin >> n >> C;

    for (int i = 1; i<= n; i++) {

        cin >> h[i];

    }

    h[n + 1] = h[n] + 1;



    dp[1] = 0;

    deque<int> Q = {1};

    for (int i = 2; i <= n; i++) {

        while (Q.size() > 1 and f(Q[1], i) < f(Q[0], i)) {

            Q.pop_front();

        }



        dp[i] = f(Q[0], i) + C;



        while (Q.size() > 1 and g(Q[Q.size() - 2], i) <= g(Q[Q.size() - 2], Q.back())) {

            Q.pop_back();

        }

        Q.push_back(i);

    }



    cout << dp[n] << "\n";

}
