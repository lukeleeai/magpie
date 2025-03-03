#include "stdc++.h"

#define ll long long

#define ld long double

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

#define Yes() std::cout << "Yes" << std::endl

#define No() std::cout << "No" << std::endl

#define Say(s) std::cout << s << std::endl

const ll MOD = 1000000007;

const ll INF = 1061109567;



int main()

{

    ll n, m;

    std::vector<std::array<ll, 2>> k;

    std::cin >> n >> m;

    rep(i, m)

    {

        ll temp_1, temp_2;

        std::cin >> temp_1 >> temp_2;

        --temp_1;

        --temp_2;

        k.push_back({temp_1, temp_2});

    }

    // そもそもdfsは適用範囲が広く,これは単純なグラフの時にしか使えない

    using Graph = std::vector<std::vector<ll>>;

    auto make_graph = [&](const ll& num_points, const ll& num_sides, const auto& side_pairs) {

        //libproton 1.1.0

        //num_pointsは頂点数,num_sidesは辺数,side_pairsはvector::vector<ll>に相当するものを入力してください。

        //ただし二つ目のvectorは二つの要素しかないことを想定している

        //グラフ型(G[index]に頂点indexから直接行ける点の列挙が入っている)を返す

        //graphのiteratorが1次元の時しか対応していない

        Graph G(num_points);

        for (ll i = 0; i < num_sides; ++i) {

            G[side_pairs.at(i).at(0)].push_back(side_pairs.at(i).at(1));

            G[side_pairs.at(i).at(1)].push_back(side_pairs.at(i).at(0));

        }

        return G;

    };

    ll temp_temp = 0;

    std::vector<bool> graph_seen(n, false);  //100には頂点数を入れる。下のdfsは再帰なので外でdfsを定義する必要あり。

    std::function<void(const Graph&, const ll&, std::vector<bool>&)> dfs_mono = [&](const Graph& dfs_G, const ll& start_point, std::vector<bool>& dfs_seen) {

        //libproton 1.1.0

        //graphのiteratorが1次元の時しか対応していない

        //dfs_GにはGraph型を, start_pointには探索開始点を, dfs_seenには頂点数の大きさを持った全false配列を入れてください。

        //返す値はない。dfs_seenが訪問済みでtrueに切り替わっているはず。やりたい動作は使用時にこのなかに追記してください。

        dfs_seen[start_point] = true;  // start_point を訪問済にする

        ++temp_temp;

        // この部分にやりたい動作を書くと良い



        // start_point から行ける各頂点 next_v について

        for (auto next_v : dfs_G[start_point]) {

            if (dfs_seen[next_v])

                continue;  // next_v が探索済だったらスルー



            // この部分にやりたい動作を書くと良い



            dfs_mono(dfs_G, next_v, dfs_seen);  // 再帰的に探索

        }

        return 0;

    };

    Graph friend_graph = make_graph(n, k.size(), k);

    std::vector<ll> number_menber;

    for (ll i = 0; i < n; ++i) {

        temp_temp = 0;

        if (graph_seen[i] == false) {

            dfs_mono(friend_graph, i, graph_seen);

            number_menber.push_back(temp_temp);

        }

    }

    std::sort(number_menber.begin(), number_menber.end());

    Say(number_menber[number_menber.size() - 1]);

    return 0;

}