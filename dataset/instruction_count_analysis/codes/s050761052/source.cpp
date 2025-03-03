#include <iostream>

#include <fstream>

#include <set>

#include <map>

#include <string>

#include <vector>

#include <queue>

#include <deque>

#include <stack>

#include <functional>

#include <algorithm>

#include <climits>

#include <cmath>

#include <iomanip>

using namespace std;

#define ll long long int

#define rep(i,n) for( int i = 0; i < n; i++ )

#define rrep(i,n) for( int i = n; i >= 0; i-- )

#define REP(i,s,t) for( int i = s; i <= t; i++ )

#define RREP(i,s,t) for( int i = s; i >= t; i-- )

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define INF 200000000

#define mod 1000000007

#define INF2 1000000000000000000

int H, W;

int sx, sy, gx, gy;

string S[1010];

int d[1010][1010];

typedef pair<int, int> P;

typedef pair<int, P> PP;

int dx[4] = {0, 1, 0, -1};

int dy[4] = {1, 0, -1, 0};

int bfs() {

    priority_queue<PP, vector<PP>, greater<PP>> que;

    queue<P> visited;

    rep(i, 1010) rep(j, 1010) d[i][j] = INF;

    d[sx][sy] = 0;

    que.push({0, {sx, sy}});

    visited.push({sx, sy});

    while(que.size()) {

        while(que.size()) {

            PP pp = que.top(); que.pop();

            int cost = pp.first;

            int x = pp.second.first;

            int y = pp.second.second;

            if(d[x][y] < cost) continue;

            rep(i, 4) {

                int xx = x + dx[i];

                int yy = y + dy[i];

                if(xx < 0 || xx >= H || yy < 0 || yy >= W) continue;

                if (S[xx][yy] == '#') continue;

                if(d[xx][yy] == INF) {

                    visited.push({xx, yy});

                }

                if(d[xx][yy] > cost) {

                    d[xx][yy] = cost;

                    que.push({cost, {xx, yy}});

                }

            }

        }

        queue<P> tmp;

        while(visited.size()) {

            P p = visited.front(); visited.pop();

            int x = p.first;

            int y = p.second;

            rep(i, 25) {

                int xx = x + i % 5 - 2;

                int yy = y + i / 5 - 2;

                if(xx < 0 || xx >= H || yy < 0 || yy >= W) continue;

                

                if (S[xx][yy] == '#') continue;

                if(d[xx][yy] == INF || d[xx][yy] > d[x][y] + 1) {

                    d[xx][yy] = d[x][y] + 1;

                    que.push({d[x][y] + 1, {xx, yy}});

                    tmp.push({xx, yy});

                }

            }

        }

        visited = tmp;

    }

    return d[gx][gy];

}



int main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    

    cin >> H >> W;

    cin >> sx >> sy;

    cin >> gx >> gy;

    sx--; sy--; 

    gx--; gy--;

    rep(i, H) cin >> S[i];

    d[sx][sy] = 0;

    int ans = bfs();

    if(ans == INF) ans = -1;

    cout << ans << endl;

    // rep(i, H) {

    //     rep(j, W) {

    //         if(d[i][j] == INF) {

    //             cout << "∞" << " ";

    //         } else {

    //             cout << d[i][j] << " ";

    //         }

    //     }

    //     cout << endl;

    // }



    return 0;

}
