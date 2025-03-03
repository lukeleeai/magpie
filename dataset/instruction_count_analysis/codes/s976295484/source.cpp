#include "stdc++.h"

const int INF = 1e9;

const int MOD = 1e9+7;

const long long LINF = 1e18;

#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define rep(i,n) for(int i=0;i<(n);++i)

#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

typedef long long ll;

using namespace std;

typedef pair<ll, ll> P;



int main(int argc, char const *argv[]) {

    int n,m;cin>>n>>m;

    vector<vector<int>> x(114514);

    rep(i,n) {

        int a,b;cin>>a>>b;

        x[a].push_back(b);

    }



    priority_queue<ll> pq;

    ll ans = 0;



    for (int i = 1; i <= m; ++i) {

        for (auto &&e: x[i]) pq.push(e);

        if (!pq.empty()) ans += pq.top(), pq.pop();

    }



    cout << ans << endl;

    return 0;

}
