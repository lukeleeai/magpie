#include <iostream>

#include <vector>

#include <algorithm>

#include <queue>

#include <iomanip>

using namespace std;

const int S_MAX = 30;

const double inf = 1e9;



struct info{

    int curr;

    int prev;

    int v;

    double t;

    info(int c, int p, int v, double t):curr(c),prev(p),v(v),t(t){}

};

namespace std{

    bool operator < (const info &a, const info &b){

        return b.t < a.t;

    }

}



int main(){

    while(1){

        int n,m;

        cin >> n >> m;

        if(n==0) break;



        int s,g;

        cin >> s >> g;

        vector<vector<vector<info> > > adj(n+1, vector<vector<info> >(S_MAX+1));

        for(int i=0; i<m; i++){

            int x,y,d,c;

            cin >> x >> y >> d >> c;

            for(int v=1; v<=S_MAX; v++){

                for(int r=-1; r<=1; r++){

                    if(v+r>0 && v+r<=c){

                        adj[x][v].push_back(info(y, x, v+r, (double)d/(v+r)));

                        adj[y][v].push_back(info(x, y, v+r, (double)d/(v+r)));

                    }

                }

            }

        }



        priority_queue<info> pq;

        pq.push(info(s, 0, 1, 0));

        vector<vector<vector<double> > > mincost(n+1, vector<vector<double> >(n+1, vector<double>(S_MAX+1, inf)));

        mincost[s][0][1] = 0;

        while(!pq.empty()){

            int curr = pq.top().curr;

            int prev = pq.top().prev;

            int v = pq.top().v;

            double cost = pq.top().t;

            pq.pop();

            if(cost > mincost[curr][prev][v]) continue;

            if(curr==g && v==1) break;

            for(int i=0; i<(int)adj[curr][v].size(); i++){

                info next = adj[curr][v][i];

                if(next.curr == prev) continue;

                if(prev == 0 && next.v != 1) continue;

                if(cost + next.t < mincost[next.curr][next.prev][next.v]){

                    pq.push(info(next.curr, next.prev, next.v, cost+next.t));

                    mincost[next.curr][next.prev][next.v] = cost + next.t;

                }

            }

        }

        double ans=inf;

        for(int i=1; i<=n; i++){

            ans = min(ans, mincost[g][i][1]);

        }

        if(ans == inf){

            cout << "unreachable" << endl;

        }else{

            cout << fixed;

            cout << setprecision(12);

            cout << ans << endl;

        }

    }

    return 0;

}