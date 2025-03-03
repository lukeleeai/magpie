#include "stdc++.h"

#define rep(i,n) for(int i = 0; i < (n); ++i)

#define rrep(i,n) for(int i = 1; i <= (n); ++i)

#define drep(i,n) for(int i = (n)-1; i >= 0; --i)

#define srep(i,s,t) for (int i = s; i < t; ++i)

#define rng(a) a.begin(),a.end()

using namespace std;

typedef long long int ll;

typedef pair<int,int> P;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<ll> vl;

typedef vector<P> vp;

#define dame { puts("-1"); return 0;}

#define yn {puts("Yes");}else{puts("No");}

#define MAX_N 100005



vector<int> pre_G[MAX_N];

vector<int> G[MAX_N];

int par_[MAX_N];

int flag_netsukigi[MAX_N];

void make_netsukigi(int r){

    queue<int> que;

    que.push(r);

    flag_netsukigi[r] = 1;

    par_[r] = -1;



    while(que.size() > 0){

        int x = que.front();

        que.pop();

        flag_netsukigi[x] = 1;

        rep(i,pre_G[x].size()){

            if(flag_netsukigi[pre_G[x][i]] == 0){

                par_[pre_G[x][i]] = x;

                G[x].push_back(pre_G[x][i]);

                que.push(pre_G[x][i]);

            }

        }

    }

}



int x[MAX_N];

int n;

vector<P> v[MAX_N];

int par[MAX_N];



P knapsack(int y){

    int dp[x[y] + 1] = {};

    rep(i, v[y].size()){

        if(i == 0){

            if(v[y][i].first <= x[y]){

                dp[v[y][i].first] = 1;

            }

            if(v[y][i].second <= x[y]){

                dp[v[y][i].second] = 1;

            }

        }else{

            int tmp[x[y] + 1] = {};

            rep(j,x[y] + 1){

                if(dp[j] == 1 && j + v[y][i].first <= x[y]){

                    tmp[j + v[y][i].first] = 1;

                }

            }



            rep(j,x[y] + 1){

                if(dp[j] == 1 && j + v[y][i].second <= x[y]){

                    tmp[j + v[y][i].second] = 1;

                }

            }



            rep(j, x[y] + 1)dp[j] = tmp[j];

        }

    }

    P res;

    res.first = 0;

    drep(i,x[y]+1){

        if(dp[i] == 1){

            res.first = i;

            break;

        }

    }

    int sum = -res.first;

    rep(i,v[y].size()){

        sum += v[y][i].first;

        sum += v[y][i].second;

    }

    res.first = x[y];

    res.second = sum;

    if(res.first > res.second)swap(res.first, res.second);

    return res;

}



int main() {

    cin >> n;



    rep(i,n-1){

        int a = i + 2;

        int b;

        cin >> b;

        a--; b--; // 0-indexにするため.

        par[a] = b;

        pre_G[a].push_back(b);

        pre_G[b].push_back(a);

    }



    make_netsukigi(0);

    par[0] = -1;

    

    rep(i,n)cin >> x[i];

    



    if(n == 1){

        cout << "POSSIBLE" << endl;

        return 0;

    }



    /*

    rep(i,n)cout << par[i] << ' ';

    cout << endl;

    rep(i,n)cout << G[i].size() << ' ';

    cout << endl;

    */



    queue<int> que;

    int use[n] = {};

    rep(i,n){

        if(G[i].size() == 0){

            use[i] = 1;

            v[par[i]].push_back(P(0,x[i]));

            que.push(par[i]);

        }

    }





    while(!que.empty()){

        int y = que.front();

        que.pop();

        if(v[y].size() == G[y].size() && use[y] == 0){

            use[y] = 1;

            int tmp = 0;

            rep(i,v[y].size()){

                tmp += v[y][i].first;

            }

            if(tmp > x[y]){

                cout << "IMPOSSIBLE" << endl;

                return 0;

            }

            if(y == 0)break;

            // ナップザックを書く.

            P p = knapsack(y);

            // cout << y << ' ' << p.first << p.second << endl;

            v[par[y]].push_back(p);

            // cout << y << ' ' << p.first << ' ' << p.second << endl;

            que.push(par[y]);

        }

    }

    rep(i,n){

        if(use[i] == 0)cout << i << ' ';

    }



    cout << "POSSIBLE" << endl;



    return 0;

}

 
