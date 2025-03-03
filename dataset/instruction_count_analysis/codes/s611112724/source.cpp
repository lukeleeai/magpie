#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <cassert>

#include <functional>

#include <algorithm>

#include <string>

#include <vector>

#include <set>

#include <map>

#include <queue>

#include <stack>

using namespace std;

using llong = long long;



//===

struct UnionFind {

    int n;

    vector<int> parent;



    UnionFind() {}

    UnionFind(int nmemb) {

        init(nmemb);

    };



    void init(int nmemb) {

        parent.clear();

        parent.assign(nmemb, -1);

    };



    int root(int x) {

        if (parent[x] < 0) {

            return x;

        }

        return parent[x] = root(parent[x]);

    };



    void unite(int x, int y) {

        x = root(x);

        y = root(y);



        if (x == y) return;



        if (parent[y] < parent[x]) swap(x, y);



        parent[x] += parent[y];

        parent[y] = x;

        

        return;

    };

    

    bool same(int x, int y) {

        return root(x) == root(y);

    };

    int size(int x) {

        return -(parent[root(x)]);

    };

};

//===



llong n, m, k;

vector<vector<llong>> bl;

vector<vector<llong>> fr;



int main() {

    cin >> n >> m >> k;



    UnionFind uf(n + 1);

    bl.resize(n + 1);

    fr.resize(n + 1);

    for (int i = 0; i < m; i++) {

        llong a, b;

        cin >> a >> b;

        uf.unite(a, b);

        fr[b].push_back(a);

        fr[a].push_back(b);

    }



    for (int i = 0; i < k; i++) {

        llong a, b;

        cin >> a >> b;

        bl[a].push_back(b);

        bl[b].push_back(a);

    }



    for (int i = 1; i <= n; i++) {

        llong ans = uf.size(i) - fr[i].size() - 1;

        for (auto u:bl[i]) {

            if (uf.same(u, i)) ans--;

        }



        cout << ans << ' ';

    }

    cout << endl;



    return 0;

}
