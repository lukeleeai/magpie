#include "stdc++.h"

#define ll long long

using namespace std;



#define N 200000

#define WHITE 0  // 未訪問

#define BLACK 1  // 訪問ずみ



// 連結成分の番号を振る関数

void dfs(int n, int comp[], vector<int> G[])

{

    int i, j, vertex, neighbor, color[N];

    stack<int> S;

    int ans[N] = {};

    // 初期状態

    for (i = 0; i < n; i++)

        color[i] = WHITE;



    for (i = 0; i < n; i++) {

        if (color[i] == WHITE) {

            // dfs

            S.push(i);

            while (!S.empty()) {

                vertex = S.top();

                S.pop();

                color[vertex] = BLACK;  // 訪問済みにする

                comp[vertex] = i;       // 連結成分の番号を振る



                for (j = 0; j < (int)G[vertex].size(); j++) {

                    neighbor = G[vertex][j];  // 隣接している頂点：友人

                    if (color[neighbor] == WHITE)

                        S.push(neighbor);

                }

            }

        }

    }

}



int main()

{

    int i, n, m, s, t;

    int comp[N];       // 連結成分の番号

    vector<int> G[N];  // グラフを表現する隣接リスト



    cin >> n >> m;

    // 隣接リストを作成

    for (i = 0; i < m; i++) {

        cin >> s >> t;

        --s;

        --t;

        G[s].push_back(t);

        G[t].push_back(s);

    }



    // グラフを連結成分に分ける

    dfs(n, comp, G);



    int ans[N] = {};

    int temp = 0;

    for (int j = 0; j < n; j++) {

        //std::cout << j << " " << comp[j] << std::endl;

        ++ans[comp[j]];

    }

    for (auto v : ans) {

        temp = std::max(v, temp);

    }

    std::cout << temp << std::endl;

    return 0;

}