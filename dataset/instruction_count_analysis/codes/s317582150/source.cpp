// #define _GLIBCXX_DEBUG // for STL debug (optional)

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <string>

#include <cstring>

#include <deque>

#include <list>

#include <queue>

#include <stack>

#include <vector>

#include <utility>

#include <algorithm>

#include <map>

#include <set>

#include <complex>

#include <cmath>

#include <limits>

#include <cfloat>

#include <climits>

#include <ctime>

#include <cassert>

#include <numeric>

#include <fstream>

#include <functional>

#include <bitset>

using namespace std;

using ll = long long int;

using int64 = long long int;

 

template<typename T> void chmax(T &a, T b) {a = max(a, b);}

template<typename T> void chmin(T &a, T b) {a = min(a, b);}

template<typename T> void chadd(T &a, T b) {a = a + b;}

 

int dx[] = {0, 0, 1, -1};

int dy[] = {1, -1, 0, 0};

const int INF = 1LL << 29;

const ll LONGINF = 1LL << 60;

const ll MOD = 1000000007LL;



struct Elem {

    int cur, vel, f; ll cost;

    Elem(int cu, int v, int f_, ll co) : cur(cu), vel(v), f(f_), cost(co) {}

    bool operator<(const Elem &e) const {

        return cost > e.cost;

    }

};



ll dist[510][55][2];

int main() {

    int N, M; scanf("%d%d", &N, &M);

    vector< vector< pair<ll, ll> > > G(N);

    for(int i=0; i<M; i++) {

        int u, v, t; scanf("%d%d%d", &u, &v, &t);

        u--; v--;

        G[u].emplace_back(v, t);

        G[v].emplace_back(u, t);

    }



    int v0; scanf("%d", &v0);

    int A, B, C; scanf("%d%d%d", &A, &B, &C);

    fill(dist[0][0], dist[N][0], LONGINF);

    dist[0][v0][0] = 0;

    priority_queue<Elem> que;

    que.emplace(0, v0, 0, 0);

    while(que.size()) {

        Elem elem = que.top(); que.pop();

        int cur = elem.cur, v = elem.vel, f = elem.f;

        ll cost = elem.cost;

        if(dist[cur][v][f] < cost) continue;

        for(auto e : G[cur]) {

            ll to, t; tie(to, t) = e;

            ll n_cost = cost + v * t;

            ll n_v = (A*v + B) % C;

            ll n_f = f | (to == N-1);

            if(dist[to][n_v][n_f] > n_cost) {

                dist[to][n_v][n_f] = n_cost;

                que.emplace(to, n_v, n_f, n_cost);

            }

        }

    }



    ll ans = LONGINF;

    for(int i=0; i<C; i++) chmin(ans, dist[0][i][1]);

    printf("%lld\n", ans);

    return 0;

}


