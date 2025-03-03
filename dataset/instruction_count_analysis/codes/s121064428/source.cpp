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

#define INF 2000000000

#define mod 1000000007

#define INF2 1000000000000000000

#define int long long

int H, W;

string S[1010];

int dx[4] = {1, 0, -1, 0};

int dy[4] = {0, 1, 0, -1};



int d[1010][1010];

bool visited[1010][1010];

int sx, sy, gx, gy;

typedef pair<int, int> P;

typedef pair<int, P> PP;

int dijkstra() {

    rep(i, 1010) rep(j, 1010) d[i][j] = INF;

    priority_queue<PP, vector<PP>, greater<PP>> que, que2;

    d[sx][sy] = 0;

    que.push({0, {sx, sy}});

    que2.push({0, {sx, sy}});

    while(que.size()) {

        while(que.size()) {

            PP p = que.top(); que.pop();

            int x = p.second.first;

            int y = p.second.second;



            int cost0 = p.first;

            if(cost0 > d[x][y]) continue;

            bool search = false;

            

            rep(k, 4) {

                int xx = x + dx[k];

                int yy = y + dy[k];

                if(xx < 0 || xx >= H || yy < 0 || yy >= W) continue;

                if(S[xx][yy] == '#') continue;

                if(d[xx][yy] == INF) {

                    d[xx][yy] = d[x][y];

                    search = true;

                    que.push({d[xx][yy], {xx, yy}});

                    que2.push({d[xx][yy], {xx, yy}});

                }

            }

            if(!search) que2.push({d[x][y], {x, y}});

        }

        while(que2.size()) {

            PP p = que2.top(); que2.pop();

            int x = p.second.first;

            int y = p.second.second;

            

            int cost0 = p.first;

            

            if(cost0 > d[x][y] || (cost0 == d[x][y] && visited[x][y])) continue;

            visited[x][y] = true;

            //cout << x << " " << y << " " << cost0 << " " << d[x][y] << " " << d[gx][gy] << endl;

            rep(k, 25) {

                int xx = x + 2 - k % 5;

                int yy = y + 2 - k / 5;

                if(xx < 0 || xx >= H || yy < 0 || yy >= W) continue;

                if(S[xx][yy] == '#') continue;

                if(d[xx][yy] == INF) {

                    d[xx][yy] = d[x][y] + 1;

                    que.push({d[xx][yy], {xx, yy}});

                }

            }

        }

    }

    return d[gx][gy];

}





signed main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    

    cin >> H >> W;

    cin >> sx >> sy;

    cin >> gx >> gy;

    sx--; sy--; gx--; gy--;

    rep(i, H) cin >> S[i];

    int ans = dijkstra();

    if(ans == INF) {

        ans = -1;

    }

    // rep(i, H) {

    //     rep(j, W) {

    //         cout << d[i][j];

    //     }

    //     cout << endl;

    // }

    cout << ans << endl;



    return 0;

}

// ...##

// ..##..

// .##...