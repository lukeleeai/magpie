#include <stdio.h>

#include <stdlib.h>

#include <assert.h>

#include <fstream>

#include <iostream>

#include <sstream>

#include <iomanip>

#include <algorithm>

#include <bitset>

#include <array>

#include <vector>

#include <queue>

#include <set>

#include <cmath> // 変数名にy1が使えなくなるかも…。

#include <map>

#include <unordered_map>

#include <unordered_set>

#include <limits>

#include <functional>

#include <string>



typedef __int128_t int128_t;

std::istream &operator>>(std::istream& input, int128_t& value) { // int128_tの入力。入力が64bitに収まる前提。

    long long tmp; input >> tmp; value = tmp;

    return input;

}

std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。

    output << (long long)value;

    return output;

}



// 有向グラフのクラス。

// ダイクストラ、ベルマン・フォード、ワーシャルフロイド、最大フローに対応。

// 最大フローを求める問題で、costをint128_tにしたらMLEしたことがあるので、costはint64_tにしておく。

class Directed_Graph {

    public:

    struct Edge { 

        int to; int64_t cost;

    };

    typedef std::vector<std::vector<Edge>> adj_list;

    adj_list G;

    int node_num;

    Directed_Graph() {}

    Directed_Graph(const int node_num_in) {

        node_num = node_num_in;

        G.resize(node_num);

    }

    void add_directed_edge(const int from, const int to, const int64_t cost) {

        Edge edge; edge.to = to; edge.cost = cost;

        G[from].push_back(edge);

    }

    void add_undirected_edge(const int node1, const int node2, const int64_t cost) {

        add_directed_edge(node1, node2, cost);

        add_directed_edge(node2, node1, cost);

    }



    // 点sからの最短距離の配列を返す。

    // 戻りの値としてint128_tを用い、初期値としてint64_tの最大値を用いるのは、dist[v] + edge.costの計算でのオーバーフローを防ぐため。

    // 正しい最短距離がint64_tの最大値を超えるような事態は想定していないので、最終的にdist[v] == std::numeric_limits<int64_t>::max()だった場合、vには到達できないことを意味する。

    std::vector<int128_t> Dijkstra(int s) const {

        std::vector<int128_t> dist;

        dist.resize(node_num, std::numeric_limits<int64_t>::max());



        typedef std::pair<int128_t, int> Pair;

        std::priority_queue <Pair, std::vector<Pair>, std::greater<Pair>> que;

        dist[s] = 0;

        que.push(Pair(0, s));



        while (!que.empty()) {

            Pair pair = que.top(); que.pop();

            int v = pair.second;

            if (dist[v] < pair.first) { continue; }

            for (Edge edge : G[v]) {

                if (dist[v] + edge.cost < dist[edge.to]) {

                    dist[edge.to] = dist[v] + edge.cost;

                    que.push(Pair(dist[edge.to], edge.to));

                }

            }

        }

        return dist;

    }



    // Dijkstra法を行った後に、各点に関する最短経路の1つ前の点を計算する。

    // Dijkstra法の中に組み込む方が自然だが、Dijkstra()を複雑にしないように分離する。

    std::vector<int> Dijkstra_prev(const int s, const std::vector<int128_t>& dist) const {

        std::vector<int> prev; prev.resize(node_num, -1);

        for (int i = 0; i < node_num; i++) {

            for (Edge edge : G[i]) {

                if (dist[i] + edge.cost == dist[edge.to]) { prev[edge.to] = i; }

            }

        }

        return prev;

    }



    // Dijkstra法で、s->t 最短路を求める。{s,...,t}の形式で出力。

    // 到達できない場合は空ベクタ、t==sの場合{s}を返す。

    std::vector<int> Dijkstra_path(const int s, const int t) const {

        std::vector<int128_t> dist = Dijkstra(s);

        std::vector<int> prev = Dijkstra_prev(s, dist);

        std::vector<int> path;

        int tmp = t;

        while (tmp != s && prev[tmp] != -1) {

            path.push_back(tmp);

            tmp = prev[tmp];

        }

        if (tmp == s) { path.push_back(tmp); }

        std::reverse(path.begin(), path.end());

        return path;

    }



    // Bellman_Ford法により、loop_numに頂点数を入れることで、sからの距離を返す。返り値のbool値は負の変数の有無。

    // loop_numを変数にせず、while文で処理する方が一般的だが、「ある頂点に距離-∞の道があるか」答えやすくするため変数にしてある。

    // Bellman_Ford(s, N)とBellman_Ford(s, N*2)の値を比べて、dist[t]が異なれば、tへの距離-∞の道がある。

    std::pair<std::vector<int128_t>, bool> Bellman_Ford(const int s, const int loop_num) {

        std::vector<int128_t> dist;

        const int128_t INF = std::numeric_limits<int64_t>::max();

        dist.resize(node_num, INF);

        dist[s] = 0;

        bool last_updated = false;

        for (int n = 1; n <= loop_num; n++) {

            for (int i = 0; i < node_num; i++) {

                if (dist[i] != INF) {

                    for (auto e : G[i]) {

                        if (dist[i] + e.cost < dist[e.to]) {

                            dist[e.to] = dist[i] + e.cost;

                            if (n == loop_num) { last_updated = true; }

                        }

                    }

                }

            }

        }

        return std::pair<std::vector<int128_t>, bool>({ dist, last_updated });

    }



    std::vector<std::vector<int128_t>> Warshall_Floyd() {

        const int128_t INF = std::numeric_limits<int64_t>::max();

        std::vector<std::vector<int128_t>> dist; dist.resize(node_num);

        for (int i = 0; i < dist.size(); i++) {

            dist[i].resize(node_num, INF);

            dist[i][i] = 0;

            for (auto e : G[i]) {

                dist[i][e.to] = std::min(dist[i][e.to], (int128_t)e.cost);

            }

        }

        for (int k = 0; k < node_num; k++) {

            for (int i = 0; i < node_num; i++) {

                for (int j = 0; j < node_num; j++) {

                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);

                }

            }

        }

        return dist;

    }

};



#define rep(i, begin, end) for(int64_t i = (begin); i <= (end); i++)

#define rev(i, begin, end) for(int64_t i = (begin); (end) <= i; i--)



#define input3(begin, end, v1, v2, v3) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i]; } 



void printvec(const std::vector<int>& vec) {

    for (int i = 0; i < vec.size(); i++) { std::cout << vec[i] << " "; } std::cout << std::endl;

}



const int MAX_N = 2510;

const int MAX_M = 5010;

int N, M;

//int A[MAX_M], B[MAX_M], C[MAX_M];

std::vector<int> A, B, C;

int128_t P;

Directed_Graph dg(MAX_N);



int main(int argc, char **argv) {

    std::cin >> N >> M >> P;



    input3(1, M, A, B, C);



    rep (i, 1, M) {

        dg.add_directed_edge(A[i], B[i], -(C[i] - P));

    }



    auto d1 = dg.Bellman_Ford(1, N);

    auto d2 = dg.Bellman_Ford(1, N*2);



    if (d1.first[N] != d2.first[N]) {

        std::cout << -1 << std::endl; 

    } else {

        std::cout << std::max(0, int(-d1.first[N])) << std::endl;

    }

    

    return 0;

}