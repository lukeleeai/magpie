#include <iostream>

#include <vector>

using namespace std;

using ll=long long;

#define rep(i,a,b) for(ll i=a;i<ll(b);i++)

#define endl "\n"



struct UnionFind {

    // 自身が根: その集合の要素数に-1を掛けたもの

    // 自身が葉: 根のID

    // -> 根であれは負の数、葉であれば正の数

    vector<int> data;



    // 全てを根として初期化

    UnionFind(int size = 0) : data(size, -1) {}



    // 根の検索

    int root(int x) {

        if(data[x] < 0) return x;

        return x = root(data[x]); // 経路圧縮

    }



    // 集合の結合

    bool unite(int x, int y) {

        x = root(x); y = root(y);

        if(x == y) return false;



        // 要素数が小さい方を大きい方に結合する

        if(data[x] > data[y]) swap(x, y); // -data[x] > -data[y] となるようにしたい

        data[x] += data[y]; // 要素数の加算

        data[y] = x; // 集合の結合

        return true;

    }



    // 要素xと要素yが同じ集合に属しているか

    bool same(int x, int y) { return root(x) == root(y); }



    // 要素xが属している集合の大きさ(サイズ)

    int size(int x) { return -data[root(x)]; }

};





int n, m;

int main() {

    cin >> n >> m;



    UnionFind UF(n);



    rep(i, 0, m){

        int a, b; cin >> a >> b;

        a--;b--;

        UF.unite(a, b);

    }



    int ans = 0;

    rep(i, 0, n){

        ans = max(ans, UF.size(i));

    }



    cout << ans << endl;



    return 0;

}
