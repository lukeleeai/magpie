#include <iostream>

#include <vector>

#include <array>

using namespace std;



#define rep(i, n) for (int i = 0; i < (int)(n); i++)



//////////////// //////////////// //////////////// //////////////// ////////////////

//////////////// //////////////// //////////////// //////////////// ////////////////



constexpr int max_n = 200'000 + 5;



int n, q;

int cnts[max_n];



int hd[max_n]; // n : 頂点数

int nxt[2*max_n], to[2*max_n]; // 2*(n-1)+1 : 辺の個数+1

int edge_cnt;

inline void add_edge(const int u, const int v) { // u to v

    edge_cnt++; // 辺が1つ増える

    to[edge_cnt] = v; // edge_cnt本目の辺の行き先はv

    nxt[edge_cnt] = hd[u]; // edge_cnt本目の辺の次に見る(uから出る)辺は、はじめに見ていた(uから出る)辺であるhd[u]本目の辺

    hd[u] = edge_cnt; // 新しくはじめに見る(uから出る)辺はedge_cnt本目の辺

}



void dfs(const int cur = 0, const int parent = -1, const int cnt = 0)

{

    cnts[cur] += cnt;

    for (int e = hd[cur]; e > 0; e = nxt[e]) {

       const int child = to[e];

       if (child == parent) { continue; }

       dfs(child, cur, cnts[cur]);

   }

}



int main()

{

    // 入出力

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);



    cin >> n >> q;

    rep(i, n - 1)

    {

        int a, b;

        cin >> a >> b;

        a--;

        b--;

        add_edge(a,b);

        add_edge(b,a);

    }

    rep(j, q)

    {

        int p,x;

        cin >> p >> x;

        p--;

        cnts[p] += x;

    }



    dfs();



    rep(i, n)

    {

        cout << cnts[i] << '\n';

    }



    return 0;

}
