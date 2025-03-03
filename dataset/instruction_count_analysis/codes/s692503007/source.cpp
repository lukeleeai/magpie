#include "stdc++.h"

#define rep(i, a, n) for(int i = a; i < n; i++)

#define repb(i, a, b) for(int i = a; i >= b; i--)

#define all(a) a.begin(), a.end()

#define o(a) cout << a << endl

#define int long long

using namespace std;

typedef pair<int, int> P;



struct UF{

    vector<int> par;

    vector<int> sz;

    void init(int n){

        par.resize(n);

        sz.resize(n, 1);

        rep(i, 0, n) par[i] = i;

    }

    int find(int x){

        if(x == par[x]) return x;

        return par[x] = find(par[x]);

    }

    void unite(int x, int y){

        x = find(x); y = find(y);

        if(x == y) return;

        if(sz[x] < sz[y]) swap(x, y);

        sz[x] += sz[y];

        par[y] = x;

    }

    bool same(int x, int y){

        return find(x) == find(y);

    }

};



vector<int> lp[100010];//langauge id

vector<int> ls[100010];//person id

int n, m;



signed main(){

    cin >> n >> m;

    rep(i, 0, n){

        int k;

        cin >> k;

        rep(j, 0, k){

            int in;

            cin >> in;

            in--;

            lp[i]. push_back(in);

            ls[in]. push_back(i);

        }

    }

    UF uf;

    uf.init(n);

    rep(i, 0, m){

        if(ls[i].size() == 0) continue;

        rep(j, 1, ls[i].size()){

            uf.unite(ls[i][0], ls[i][j]);

        }

    }

    bool f = true;

    rep(i, 1, n){

        if(!uf.same(0, i)) f = false;

    }

    o((f ? "YES" : "NO"));

}