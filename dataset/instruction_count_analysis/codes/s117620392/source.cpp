#include <iostream>

#include <iomanip>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <array>

#include <tuple>

#include <string>

#include <algorithm>

#include <functional> // greater など

#include <cmath>      // abs など

#include <numeric>    // accumulate, gcd など

#include <cassert>    // assert

#include <stdexcept>

#include <bitset>

using namespace std;



// #include <boost/multiprecision/cpp_int.hpp>

// using namespace boost::multiprecision;



#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

// typedef int128_t ll;

// typedef cpp_int ll;



// GCC, 配列のアクセスなど

#define _GLIBCXX_DEBUG

// Clang, 配列のアクセスなど

#define _LIBCPP_DEBUG 0



// #define NDEBUG 1

// debug用出力 https://trap.jp/post/998/

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>

void debug_out(Head H, Tail... T)

{

    cerr << H << " ";

    debug_out(T...);

}

#ifdef NDEBUG

#define debug(...)

#else

#define debug(...) debug_out(__VA_ARGS__)

#endif



//////////////// //////////////// //////////////// //////////////// ////////////////

//////////////// //////////////// //////////////// //////////////// ////////////////



// 22:00ぐらい？

// アイデアは22:08



// constexpr inline ll mod = 1'000'000'007;

constexpr int max_n = 200'000 + 5;



int n,q;

vector<vector<int>> edges(max_n);

vector<int> p(max_n), x(max_n);

vector<int> cnts(max_n);



void dfs(int u = 0, int parent = -1) {

    for (int v : edges[u]) {

        if (v == parent) {

            continue;

        }

        cnts[v] += cnts[u];

        dfs(v, u);

    }

}



int main()

{

    // 入出力

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout << setprecision(10); // 浮動小数の表示の精度



    cin>>n>>q;

    edges.resize(n);

    p.resize(q);

    x.resize(q);

    cnts.resize(n);

    rep(i, n - 1)

    {

        int a,b; cin>>a>>b;

        a--;b--;

        edges[a].push_back(b);

        edges[b].push_back(a);

    }

    rep(j,q){

        cin>>p[j]>>x[j];

        p[j]--;

    }



    // q回足す

    rep(j, q) {

        cnts[p[j]] += x[j];

    }



    // 集計

    dfs();



    rep(i,n){

        cout<<cnts[i]<<endl;

    }



    return 0;

}
