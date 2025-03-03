#include <iostream>

#include <iomanip>

#include <vector>

#include <set>

#include <unordered_set>

#include <map>

#include <unordered_map>

#include <queue>

#include <deque>

#include <stack>

#include <algorithm>

#include <numeric>

#include <string>

#include <sstream>

#include <cmath>

#include <cstring>

#include <assert.h>

#include <utility>

#include <tuple>

#include <array>

#include <bitset>



using int64 = long long;



struct Edge {

    using Weight = int;



    int end1_, end2_, from_, to_;

    Weight weight_;



    Edge() = default;

    Edge(int end1, int end2, Weight w):

        end1_{end1}, end2_{end2}, from_{end1}, to_{end2}, weight_{w} {}

    

    bool operator<(const Edge& e) const {

        return weight_ < e.weight_;

    }

};



struct UndirectedGraph {

    int num_nodes_;

    std::vector<std::vector<Edge>> adjacent_list_;

    std::vector<Edge> edges_;



    UndirectedGraph() = default;

    UndirectedGraph(int num_node): num_nodes_{num_node}, adjacent_list_(num_node) {}



    const std::vector<Edge>& operator[](int u) const { return adjacent_list_[u]; }

    std::vector<Edge>& operator[](int u) { return adjacent_list_[u]; }



    void addEdge(int end1, int end2, Edge::Weight weight) {

        adjacent_list_[end1].emplace_back(end1, end2, weight);

        adjacent_list_[end2].emplace_back(end2, end1, weight);

        edges_.emplace_back(end1, end2, weight);

    }

};



using Tree = UndirectedGraph;



int64 dfs(const Tree& tree, std::vector<int64>& A, int u, int par) {

    if (tree[u].size() == 1) {

        return A[u];

    }



    std::vector<int64> sub_results;



    for (const Edge& e : tree[u]) {

        if (e.to_ == par) continue;



        int64 sub_res = dfs(tree, A, e.to_, u);



        if (sub_res > 0) {

            sub_results.push_back(sub_res);

        }

    }



    std::sort(sub_results.begin(), sub_results.end());



    int64 sum = 0,

          x = 0;

    for (int i = 0; i < sub_results.size(); i++) {

        if (i == sub_results.size() - 1) {

            x = (sum <= sub_results[i]) ? sum : ((sum + sub_results[i]) / 2);

        }

        sum += sub_results[i];

    }

    A[u] -= sum;

    x = std::max(0LL, std::min(-A[u], x));

    A[u] += x;

    sum -= 2 * x;



    if (A[u] != 0) {

        std::cout << "NO" << std::endl;

        std::exit(0);

    }

    return sum;

}



int main() {

    std::cin.tie(nullptr);

    std::ios::sync_with_stdio(false);



    int N;

    std::cin >> N;



    std::vector<int64> A(N);

    for (int i = 0; i < N; i++) {

        std::cin >> A[i];

    }



    Tree tree(N);



    for (int i = 0; i < N - 1; i++) {

        int a, b;

        std::cin >> a >> b;

        a--;

        b--;



        tree.addEdge(a, b, 0);

    }



    if (N == 2) {

        std::cout << ((A[0] == A[1]) ? "YES" : "NO") << std::endl;

        return 0;

    }



    int root = -1;

    for (int u = 0; u < N; u++) {

        if (tree[u].size() > 1) {

            root = u;

        }

    }



    std::cout << ((dfs(tree, A, root, -1) == 0) ? "YES" : "NO") << std::endl;



    return 0;

}
