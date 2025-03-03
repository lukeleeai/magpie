#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



// グラフ

using Graph = vector<vector<int> >;

 

// 探索

vector<bool> seen, finished;

 

// サイクル復元のための情報

int pos = -1; // サイクル中に含まれる頂点 pos

vector<int> hist; // 訪問履歴

 

void dfs(const Graph &G, int v) {

    seen[v] = true;

    hist.push_back(v);

    for (auto nv : G[v]) {

        // 完全終了した頂点はスルー

        if (finished[nv]) continue;

 

        // サイクルを検出

        if (seen[nv] && !finished[nv]) {

            pos = nv;

            return;

        }

 

        // 再帰的に探索

        dfs(G, nv);

 

        // サイクル検出したならば真っ直ぐに抜けていく

        if (pos != -1) return;

    }

    hist.pop_back();

    finished[v] = true;

}



int main() {

    int N, M; cin >> N >> M;

    Graph G(N);

    for (int i = 0; i < M; ++i) {

        int a, b; cin >> a >> b; --a, --b;

        G[a].push_back(b);

    }



    // 探索

    seen.assign(N, false), finished.assign(N, false);

    pos = -1;

    for (int v = 0; v < N; ++v) {

        pos = -1;

        dfs(G, v);

        if (pos != -1) break;

    }



    // 有向サイクルなし

    if (pos == -1) {

        cout << -1 << endl;

        return 0;

    }



    // 有向サイクルを復元

    vector<int> cycle;

    while (!hist.empty()) {

        int t = hist.back();

        cycle.push_back(t);

        hist.pop_back();

        if (t == pos) break;

    }

    reverse(cycle.begin(), cycle.end());

    

    // サイクル中に「弦」があったら、小さくする

    while (true) {

        int from = -1, to = -1;

        vector<int> ord(N, -1);

        for (int i = 0; i < cycle.size(); ++i) ord[cycle[i]] = i;

        for (int i = 0; i < cycle.size(); ++i) {

            for (auto nv : G[cycle[i]]) {

                if (nv != cycle[(i+1)%cycle.size()] && ord[nv] != -1) {

                    from = i, to = ord[nv];

                }

            }

        }

        if (from == -1) break; // 弦がなくなって終了



        vector<int> ncycle;

        ncycle.push_back(cycle[from]);

        int id = to;

        while (id != from) {

            ncycle.push_back(cycle[id]);

            id = (id + 1) % cycle.size();

        }

        cycle = ncycle;

        

        //COUT(from); COUT(to); COUT(cycle);

    }

    

    cout << cycle.size() << endl;

    for (auto v : cycle) cout << v + 1 << endl;

}
