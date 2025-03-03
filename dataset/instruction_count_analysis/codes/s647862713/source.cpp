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





const int MAX_V = 1e5;

vector<int> G[MAX_V];



set<int> used_v;

set<PII> used_e;

int ord[MAX_V], lowlink[MAX_V];

int k = 0;



void calc_lowlink(int v)

{

    used_v.insert(v);

    ord[v] = lowlink[v] = k++;



    for (auto u : G[v]) {

        if (!used_v.count(u)) {

            used_e.insert(PII(v, u));

            calc_lowlink(u);

            lowlink[v] = min(lowlink[v], lowlink[u]);

        } else if (!used_e.count(PII(u, v))) {

            // backward edge

            lowlink[v] = min(lowlink[v], ord[u]);

        }

    }

}



vector<PII> calc_bridge(int N)

{

    vector<PII> res;

    for (int v=0; v<N; v++) {

        for (auto u : G[v]) {

            if (ord[v] < lowlink[u]) {

                res.emplace_back(min(v, u), max(v, u));

            }

        }

    }

    return res;

}





int main()

{

    int N, M;

    cin >> N >> M;



    rep(i, M) {

        int U, V;

        cin >> U >> V;

        // U--, V--;

        G[U].push_back(V);

        G[V].push_back(U);

    }



    calc_lowlink(0);

    vector<PII> bridges = calc_bridge(N);

    sort(bridges.begin(), bridges.end());



    for (auto p : bridges) {

        cout << p.first << " " << p.second << endl;

    }



    /*

    rep(i, N) {

        cout << ord[i] << " " <<  lowlink[i] << endl;

    }

    */

}