#include "stdc++.h"

using namespace std;

#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))

using ll = long long;

using P = pair<ll, ll>;

using namespace std;



template<class T> void vin(vector<T>& v, int n) {

    v.resize(n);

    for (int i = 0; i < n; ++i) {

        cin >> v[i];

    }

}



int ans[400*400+1];



struct UnionFind {

    vector<int> v;

    UnionFind(int N) :v(N, -1) {}

    int root(int x) {

        if (v[x] < 0) return x;

        else return v[x] = root(v[x]);

    }

    void unite(int x, int y) {

        x = root(x);

        y = root(y);

        if (x == y) return;

        if (v[x] > v[y]) swap(x, y);

        v[x] += v[y];

        v[y] = x;

    }

    int size(int x) {

        return -v[root(x)];

    }

};



int dx[] = { 1, 0, -1, 0 };

int dy[] = { 0, 1, 0, -1 };



bool ok(int h, int w, int x, int y) {

    return 0 <= x and x < w and 0 <= y and y < h;

}



ll kuro[400*400+2];

ll siro[400*400+2];



int main() {

    int H, W;

    cin >> H >> W;

    string s[500];

    rep(i, H) cin >> s[i];



    UnionFind uf(H*W);

    rep(r, H) rep(c, W) {

        if (s[r][c] == '#') {

            rep(d, 4) {

                int nr = r + dy[d], nc = c + dx[d];

                if (ok(H, W, nc, nr) and s[nr][nc] == '.') uf.unite(r*W+c, nr*W+nc);

            }

        }

    }



    //cout << uf.same(0, 2) << endl;



    rep(r, H) rep(c, W) {

        if (s[r][c] == '.') siro[uf.root(r*W+c)]++;

        else kuro[uf.root(r*W+c)]++;

    }



    ll ret = 0;

    rep(r, H) rep(c, W) {

        ret += siro[r*W+c]*kuro[r*W+c];

    }

    cout << ret << endl;

}
