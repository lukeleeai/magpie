#include "stdc++.h"

using namespace std;



#define DUMP(x) cerr << #x << "=" << x << endl

#define DUMP2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")"<< endl

#define BINARY(x) static_cast<bitset<16> >(x)



#define rep(i,n) for(int i=0;i<(int)(n);i++)

#define REP(i,m,n) for (int i=m;i<(int)(n);i++)



#define in_range(x, y, w, h) (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))

#define ALL(a) (a).begin(),(a).end()



typedef long long ll;

const int INF = 1e9;

typedef pair<int, int> PII;

int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};





class LowLink {

    const int N;

    vector<vector<int>> G;

    set<int> used_v;

    vector<int> ord, low, parent;



    void dfs(int v, int &k)

    {

        used_v.insert(v);

        ord[v] = low[v] = k++;



        for (auto u : G[v]) {

            if (!used_v.count(u)) {

                parent[u] = v;

                dfs(u, k);

                low[v] = min(low[v], low[u]);

            } else if (u != parent[v]) {

                low[v] = min(low[v], ord[u]);

            }

        }

    }



    void calc_lowlink()

    {

        int k = 0;

        dfs(0, k);

    }



public:

    LowLink(int _N) : N(_N), G(_N), ord(_N), low(_N), parent(_N) {}



    vector<int> articulation_point()

    {

        vector<int> res;



        parent[0] = -1;

        calc_lowlink();



        int root_deg = 0;

        for (int i=1; i<N; i++) {

            int p = parent[i];

            if (p == 0) root_deg++;

            else if (ord[p] <= low[i]) {

                res.push_back(p);

            }

        }



        if (root_deg > 1) res.push_back(0);

        sort(res.begin(), res.end());

        res.erase(unique(res.begin(), res.end()), res.end());



        return res;

    }



    vector<PII> bridge()

    {

        vector<PII> res;

        calc_lowlink();

        for (int v=0; v<N; v++) {

            for (auto u : G[v]) {

                if (ord[v] < low[u]) {

                    res.emplace_back(min(v, u), max(v, u));

                }

            }

        }

        return res;

    }



    void add_edge(int u, int v)

    {

        G[u].push_back(v);

        G[v].push_back(u);

    }

};



int main()

{

    int N, M;

    cin >> N >> M;



    LowLink LL(N);



    rep(i, M) {

        int U, V;

        cin >> U >> V;

        LL.add_edge(U, V);

    }



    vector<PII> b = LL.bridge();

    sort(ALL(b));

    for (auto a : b) cout << a.first << " " << a.second << endl;

}