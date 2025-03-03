//#define _GLIBCXX_DEBUG

#include "stdc++.h"

#include <x86intrin.h>

using namespace std;

using ll = long long;

using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)

#define all(v) v.begin(), v.end()

#define allr(v) v.rbegin(), v.rend()

#define V vector

template <typename T> bool chmin(T &a, const T &b) {if(a > b){a = b; return true;} return false;}

template <typename T> bool chmax(T &a, const T &b) {if(a < b){a = b; return true;} return false;}

template<typename A, size_t N, typename T> void Fill (A (&array)[N], const T & val) {fill ((T*)array, (T*)(array+N), val);}

V<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};

V<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};



V<V<int>> to(1e5+1);

map<P, int> d;

V<int> p(1e5+1, 0);

V<bool> saw(1e5+1, false);

bool flag = true;



void dfs (int par, int x) {

    if (saw[x]) return;

    saw[x] = true;

    for (int nx : to[x]) {

        if (nx == par) continue;

        if (saw[nx] && p[nx] != p[x] + d[{x, nx}]) {

            flag = false;

        }

        p[nx] = p[x] + d[{x, nx}];

        dfs(x, nx);

    }

}



int main () {

    int n, m; cin >> n >> m;

    rep(i, m) {

        int l, r, D; cin >> l >> r >> D; l--; r--;

        to[l].emplace_back(r); d[{l, r}] = D;

        to[r].emplace_back(l); d[{r, l}] = -D;

    }

    rep(i, n) dfs(-1, i);

    if (flag) puts("Yes");

    else puts("No");



    return 0;

}