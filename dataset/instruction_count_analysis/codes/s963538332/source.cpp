#include <iostream>

#include <vector>

#include <algorithm>

#include <set>

#include <string>

#include <cmath>

#include <map>

#include <cstring>



#define REP(i, n) for (int i = 0; i < (n); i++)

#define FOR(i, init, n) for(int i = init; i < (n); i++)

#define ALL(obj) (obj).begin(), (obj).end()

#define RALL(obj) (obj).rbegin(), (obj).rend()

#define Cout(obj) cout << obj << endl

#define Size(obj) (int)(obj).size()

#define fcout cout << fixed << setprecision(10)

#define fi first

#define se second



using namespace std;

using ll = long long int;

using P = pair<int, int>;

using T = tuple<int, int, int>;

using edge = struct

{

    int to, cap, rev;

};



const int MOD = 1e9 + 7;

const int iINF = 1e9;

const long long int llINF = 1e18;

const double PI = acos(-1.0);



const int dx[4] = {1, 0, -1, 0};

const int dy[4] = {0, 1, 0, -1};



const int MaxV = 100000;



vector<edge> graph[MaxV];

bool used[MaxV];



void addEdge(int from, int to, int cap)

{

    graph[from].push_back({to, cap, Size(graph[to])});

    graph[to].push_back({from, 0, Size(graph[from]) - 1});

}



int dfs(int v, int t, int f)

{

    if(v == t) return f;

    used[v] = true;



    for(auto &e : graph[v])

    {

        if(!used[e.to] && e.cap > 0)

        {

            int d = dfs(e.to, t, min(f, e.cap));



            if(d > 0)

            {

                e.cap -= d;

                graph[e.to][e.rev].cap += d;

                return d;

            }

        }

    }



    return 0;

}



int maxFlow(int s, int t)

{

    int flow = 0;

    for(;;)

    {

        memset(used, false, sizeof(used));



        int f = dfs(s, t, iINF);



        if(f == 0) return flow;



        flow += f;

    }

}



int main()

{

    cin.tie(0);

    ios::sync_with_stdio(false);



    int V, E;

    cin >> V >> E;

    REP(i, E)

    {

        int s, t, c;

        cin >> s >> t >> c;



        addEdge(s, t, c);

    }



    cout << maxFlow(0, V - 1) << endl;



    return 0;

}
