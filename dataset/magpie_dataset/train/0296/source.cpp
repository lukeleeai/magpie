#include <iostream>

#include <vector>

#include <algorithm>

#include <queue>

#include <iomanip>

using namespace std;

const int inf = 1e9;



struct info{

    char curr;

    char prev;

    char v;

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

        vector<vector<int> > dist(n+1, vector<int>(n+1, inf));

        vector<vector<int> > limit(n+1, vector<int>(n+1, 0));

        vector<info> map[31][31][31];

        

        for(int i=0; i<m; i++){

            int x,y,d,c;

            cin >> x >> y >> d >> c;

            dist[x][y] = dist[y][x] = d;

            limit[x][y] = limit[y][x] = c;

        }



        for(int i=1; i<=n; i++){ //curr

            for(int j=1; j<=n; j++){ //prev

                for(int k=1; k<=n; k++){ //next

                    if(k==j || dist[i][k]==inf) continue;

                    for(int v=1; v<=30; v++){ //speed

                        for(int r=-1; r<=1; r++){

                            if(v+r>0 && v+r <= limit[i][k]){

                                map[i][j][v].push_back(info(k, i, v+r, (double)dist[i][k]/(v+r)));

                            }

                        }

                    }

                }

            }

        }

        for(int i=1; i<=n; i++){

            if(dist[s][i] != inf){

                map[s][0][1].push_back(info(i, s, 1, dist[s][i]));

            }

        }



        priority_queue<info> pq;

        pq.push(info(s, 0, 1, 0));

        vector<vector<vector<double> > > mincost(n+1, vector<vector<double> >(n+1, vector<double>(31, inf)));

        mincost[s][0][1] = 0;

        while(!pq.empty()){

            int curr = pq.top().curr;

            int prev = pq.top().prev;

            int v = pq.top().v;

            double cost = pq.top().t;

            pq.pop();

            if(cost > mincost[curr][prev][v]) continue;

            if(curr==g && v==1) break;

            for(int i=0; i<(int)map[curr][prev][v].size(); i++){

                info next = map[curr][prev][v][i];

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

            cout << setprecision(10);

            cout << ans << endl;

        }

    }

    return 0;

}