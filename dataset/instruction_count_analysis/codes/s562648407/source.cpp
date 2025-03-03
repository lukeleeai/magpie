#include "stdc++.h"

#define PREP(i, s, x) for(ll (i) = (s); (i) < (x); (i) ++)

#define REP(i, x) PREP(i, 0, x)

#define MREP(i, s, x) for(ll (i) = (s); (i) >= (x); (i) --)

#define MOD7 (1000000007LL)

#define MOD9 998244353LL

#define INF (1LL<<60)

typedef long long ll;

using namespace std;

using P = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



ll dx[4] = {0, 1, 0, -1};

ll dy[4] = {1, 0, -1, 0};



ll dfs(vector<string> &field, vector<vector<bool>> &seen, ll x, ll y, ll gx, ll gy, ll kai, ll h, ll w){

    seen[x][y] = true;

    cout << x << " " << y;

    cout << " " << kai << endl;



    ll res = INF;

    if(x == gx && y == gy) return kai;

    REP(dd, 4){

        ll next_x = x+dx[dd], next_y = y+dy[dd];

        cout << " " << next_x << " " << next_y << endl;



        if(next_x < 0 || next_x >= h) continue;

        if(next_y < 0 || next_y >= w) continue;

        if(seen[x+dx[dd]][y+dy[dd]] == true) continue;

        if(field[next_x][next_y] == '#') continue;

        cout << " " << "yap" << endl;

        ll hoge = dfs(field, seen, next_x, next_y, gx, gy, kai+1, h, w);

        chmin(res, hoge);

    }

    return res;

}



int main(){

    ll h, w;

    cin >> h >> w;

    vector<string> field(h);

    REP(i, h){

        cin >> field[i];

    }



    ll ans = 0;



    PREP(sx, 0, h){ // O(h)

        PREP(sy, 0, w){ // O(w)

            if(field[sx][sy] == '#') continue;

            vector<vector<ll>> seen(h, vector<ll>(w, -1));

            ll this_ans  = 0;

            queue<pair<pair<ll, ll>, ll>> que;

            que.push(make_pair(make_pair(sx, sy), 0));

            

            while(!que.empty()){ // O(HW)

                ll x = que.front().first.first;

                ll y = que.front().first.second;

                ll kai = que.front().second;

                que.pop();

                if(seen[x][y] != -1) continue;

                seen[x][y] = kai;

                chmax(ans, kai);



                REP(d, 4){

                    ll next_x = x + dx[d], next_y = y + dy[d];

                    

                    if(next_x < 0 || next_x >= h) continue;

                    if(next_y < 0 || next_y >= w) continue;

                    if(seen[next_x][next_y] != -1) continue;

                    if(field[next_x][next_y] == '#') continue;



                    que.push(make_pair(make_pair(next_x, next_y), kai+1));

                }

            }

        }

    }



    cout << ans << endl;





    return 0;

}
