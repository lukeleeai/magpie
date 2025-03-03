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



// UnionFind

// coding: https://youtu.be/TdR816rqc3s?t=726

// comment: https://youtu.be/TdR816rqc3s?t=6822

template<class Abel> struct WeightedUnionFind {

    vector<int> par;

    vector<Abel> diff_weight;

    /*

    WeightedUnionFind(int n=0, Abel SUM_UNITY=0) {init(n, SUM_UNITY);}

    void init(int n=0, Abel SUM_UNITY=0) {

        par.resize(n); diff_weight.resize(n);

        for(int i=0; i<n; i++) par[i]=-1, diff_weight[i]=SUM_UNITY;

    }

    */

    

    

    WeightedUnionFind(int n=0, Abel SUM_UNITY = 0): par(n,-1), diff_weight(n) {

        for (int i = 0; i < n; i++) diff_weight[i] = SUM_UNITY;

    }

    

    int root(int x) {

        if (par[x] < 0) return x;

        int r = root(par[x]);

        diff_weight[x] += diff_weight[par[x]];

        return par[x] = r;//根につなぐ

    }

    bool merge(int x, int y, Abel w) {

        w += weight(x); w -= weight(y);

        x = root(x); y = root(y);

        if (x == y) return false;

        if (par[x] > par[y]) swap(x,y), w = -w;

        par[x] += par[y];

        par[y] = x;

        diff_weight[y] = w;

        return true;

    }

    bool same(int x, int y) { return root(x) == root(y);}

    int size(int x) { return -par[root(x)];}

    Abel weight(int x) {

        root(x);

        return diff_weight[x];

    }

    Abel diff(int x, int y) {

        return weight(y) - weight(x);

    }

};



int main () {

    int n, m; cin >> n >> m;

    WeightedUnionFind<int> uf(n);

    rep(i, m) {

        int l, r, d; cin >> l >> r >> d; l--; r--;

        if (uf.same(l, r)) {

            int diff = uf.diff(l, r);

            if (diff != d) {

                puts("No");

                return 0;

            }

        }

        else {

            uf.merge(l, r, d);

            //printf("d[%d][%d]=%d\n", l, r, uf.diff(l, r));

        }

    }

    puts("Yes");

    return 0;

}