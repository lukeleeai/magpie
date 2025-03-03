#include <iostream>

#include <sstream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <ctime>

#include <cstring>

#include <string>

#include <vector>

#include <stack>

#include <queue>

#include <deque>

#include <map>

#include <set>

#include <bitset>

#include <numeric>

#include <utility>

#include <iomanip>

#include <algorithm>

#include <functional>

#include <unordered_map>

using namespace std;



template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



template<class T> vector<T> make_vec(size_t a) { return vector<T>(a); }

template<class T, class... Ts> auto make_vec(size_t a, Ts... ts) {

  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));

}

template<class T, class V>

typename enable_if<is_class<T>::value == 0>::type fill(T &t, const V &v) {

    t = v;

}

template<class T, class V>

typename enable_if<is_class<T>::value != 0>::type fill(T &t, const V &v){

    for (auto &e : t) fill(e, v);

}



#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)

{ return s << '<' << P.first << ", " << P.second << '>'; }

template<class T> ostream& operator << (ostream &s, vector<T> P)

{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]+1; } return s; }

template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)

{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }



#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> ostream& operator << (ostream &s, set<T> P)

{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }

template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)

{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }





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





// グラフの隣接行列

bool gr[1100][1100];



int main() {

    // 頂点数

    int N, M; cin >> N >> M;

    memset(gr, 0, sizeof(gr));

    Graph G(N);

    for (int i = 0; i < M; ++i) {

        int a, b; cin >> a >> b; --a, --b;

        G[a].push_back(b);

        gr[a][b] = true;

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
