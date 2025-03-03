#include <iostream>

#include <queue>

#include <algorithm>

using namespace std;



#define INF 1000000000



struct edge {

    int to;

    double dis;

    edge(int to, double dis):to(to), dis(dis){}

};



typedef pair< int, int > iP;

typedef pair< double, iP > iiP;



int n, m, p, a, b;

int t[8];

vector< vector< edge > > graph;



double dijkstra() {

    double dist[31][1 << 8];

    priority_queue< iiP, vector< iiP >, greater< iiP > > que;

    fill_n(*dist, 31 * (1 << 8), INF);

    que.push(iiP(0.0, iP(a, (1 << n) - 1)));

    dist[a][1 << n - 1] = 0.0;

    while(!que.empty()) {

        iiP p = que.top(); que.pop();

        int now = p.second.first, tt = p.second.second;

        double dis = p.first;

        if(now == b) return dis;



        for(int i = 0; i < graph[now].size(); i++) {

            edge &e = graph[now][i];

            for(int j = 0; j < n; j++) {

                if(tt & (1 << j)) {

                    int next_bit = tt & ~(1 << j);

                    if(dis + e.dis / t[j] < dist[e.to][next_bit]) {

                        que.push(iiP(dis + e.dis / t[j], iP(e.to, next_bit)));

                        dist[e.to][next_bit] = dis + e.dis / t[j];

                    }

                }

            }

        }

    }

    return -1;

}



int main() {



    while(cin >> n >> m >> p >> a >> b, n) {

        graph.resize(m + 1);

        for(int i = 0; i < n; i++)

            cin >> t[i];

        for(int i = 0; i < p; i++) {

            int x, y; double dis;

            cin >> x >> y >> dis;

            graph[x].push_back(edge(y, dis));

            graph[y].push_back(edge(x, dis));

        }

        double ans = dijkstra();

        if(ans != -1) {

            cout << ans << endl;

        } else {

            cout << "Impossible" << endl;

        }



        for(int i = 0; i <= m; i++) {

            graph[i].clear();

        } graph.clear();

    }

}