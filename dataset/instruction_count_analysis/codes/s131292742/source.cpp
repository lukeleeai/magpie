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



UnionFind fore(100005);

vector<vector<int>> block(100005);

vector<vector<int>> fg(100005);



llong n, m, k;



int main() {

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {

        llong a, b;

        cin >> a >> b;

        

        fore.unite(a, b);

        fg[a].push_back(b);

        fg[b].push_back(a);

    }



    for (int i = 0; i < k; i++) {

        llong a, b;

        cin >> a >> b;

        block[a].push_back(b);

        block[b].push_back(a);

    }



    for (int i = 1; i <= n; i++) {

        llong ans = fore.size(i);

        ans -= fg[i].size();



        for (auto a:block[i]) {

            if (fore.same(a, i)) {

                ans--;

            }

        }



        ans--;

        cout << ans << ' ';

    }

    cout << endl;



    return 0;

}
