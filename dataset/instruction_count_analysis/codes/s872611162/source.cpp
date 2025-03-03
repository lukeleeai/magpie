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

    //int node_num;

    Directed_Graph() {}

    Directed_Graph(const int greatest_node_id) {

        //node_num = node_num_in;

        G.resize(greatest_node_id + 1);

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

        dist.resize(G.size(), std::numeric_limits<int64_t>::max());



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

        const int node_num = G.size();

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



    // Bellman_Ford法により、sからの距離を返す。

    std::vector<int128_t> Bellman_Ford(const int s) {

        std::vector<int128_t> dist;

        const int128_t INF = std::numeric_limits<int64_t>::max();

        const int128_t NEG_INF = std::numeric_limits<int64_t>::min();

        const int node_num = G.size();

        dist.resize(node_num, INF);

        dist[s] = 0;

        for (int n = 1; n <= node_num * 2; n++) {

            for (int i = 0; i < node_num; i++) {

                if (dist[i] != INF) {

                    for (auto e : G[i]) {

                        if (dist[i] + e.cost < dist[e.to]) {

                            if (n < node_num) {

                                dist[e.to] = dist[i] + e.cost;

                            } else {

                                dist[e.to] = NEG_INF;

                            }

                        }

                    }

                }

            }

        }

        return dist;

    }



    std::vector<std::vector<int128_t>> Warshall_Floyd() {

        const int128_t INF = std::numeric_limits<int64_t>::max();

        const int node_num = G.size();

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



int128_t imax(const int128_t a, const int128_t b) { return std::max(a, b); } // std::max, std::min は型が違うとエラーになるため、ラッパーを作る。

int128_t imin(const int128_t a, const int128_t b) { return std::min(a, b); }



#define rep(i, begin, end) for(int64_t i = ((int64_t)begin); i <= ((int64_t)end); i++) // (int64_t)end としておくと、end = v.size() - 2 みたいな入力で、v.size()が1でも正常(end = -1になる）に挙動する。

#define rev(i, begin, end) for(int64_t i = ((int64_t)begin); ((int64_t)end) <= i; i--)



#define input1(begin, end, v1) v1.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i]; }

#define input2(begin, end, v1, v2) v1.resize((end)+1); v2.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i]; } 

#define input3(begin, end, v1, v2, v3) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i]; }

#define input4(begin, end, v1, v2, v3, v4) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); v4.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i] >> v4[i]; } 

// input_arrayはbegin = 0のときのみ動作確認。Aの要素の型をテンプレートにして関数にしたほうが丁寧かもしれない。

#define input_array(begin, N, M, A) A.resize((begin)+(N)); for (int i = 0; i < (begin)+(N); i++) { A[i].resize((begin)+(M)); } for (int i = begin; i < (begin)+(N); i++) { for (int j = begin; j < (begin)+(M); j++) { std::cin >> A[i][j]; }}



std::vector<int> irange(const int begin, const int end) {

    std::vector<int> ret; for (int i = begin; i <= end; i++) { ret.push_back(i); }

    return ret;

}



template <typename T>

void printvec(const std::vector<T>& vec) {

    for (int i = 0; i < vec.size(); i++) { std::cout << vec[i] << " "; } std::cout << std::endl;

}



const int MAX_N = 2510;

const int MAX_M = 5010;

int N, M;

//int A[MAX_M], B[MAX_M], C[MAX_M];

std::vector<int> A, B, C;

int128_t P;

//Directed_Graph dg(MAX_N);



const int128_t NEG_INF = std::numeric_limits<int64_t>::min();



int main(int argc, char **argv) {

    std::cin >> N >> M >> P;



    input3(1, M, A, B, C);



    Directed_Graph dg(N);

    rep (i, 1, M) {

        dg.add_directed_edge(A[i], B[i], -(C[i] - P));

    }



    auto dist = dg.Bellman_Ford(1);



    if (dist[N] == NEG_INF) {

        std::cout << -1 << std::endl; 

    } else {

        std::cout << imax(0, -dist[N]) << std::endl;

    }

    

    return 0;

}