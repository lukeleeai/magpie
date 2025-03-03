#include "stdc++.h"

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

#define rep2(i, x, n) for(int i = x; i <= n; i++)

#define rep3(i, x, n) for(int i = x; i >= n; i--)

#define elif else if

#define sp(x) fixed << setprecision(x)

#define pb push_back

#define eb emplace_back

#define all(x) x.begin(), x.end()

#define sz(x) (int)x.size()

using ll = long long;

using ld = long double;

using pii = pair<int, int>;

using pil = pair<int, ll>;

using pli = pair<ll, int>;

using pll = pair<ll, ll>;

const ll MOD = 1e9+7;

//const ll MOD = 998244353;

const int inf = (1<<30)-1;

const ll INF = (1LL<<60)-1;

const ld EPS = 1e-10;

template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};

template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};



int main(){

    int K;

    cin >> K;

    vector<int> es[K][2];

    rep(i, K){

        es[i][0].pb((i*10)%K);

        es[i][1].pb((i+1)%K);

    }

    int d[K];

    fill(d, d+K, inf);

    d[1] = 1;

    deque<int> que;

    que.push_back(1);

    while(!que.empty()){

        int i = que.front(); que.pop_front();

        for(auto &e: es[i][0]){

            if(chmin(d[e], d[i])) que.push_front(e);

        }

        for(auto &e: es[i][1]){

            if(chmin(d[e], d[i]+1)) que.push_back(e);

        }

    }

    cout << d[0] << endl;

}