#include "stdc++.h"

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

#define rep2(i, x, n) for(int i = x; i <= n; i++)

#define rep3(i, x, n) for(int i = x; i >= n; i--)

#define elif else if

#define sp(x) fixed << setprecision(x)

#define pb(x) push_back(x)

#define all(x) x.begin(), x.end()

using ll = long long;

using ld = long double;

using pii = pair<int, int>;

using pil = pair<int, ll>;

using pli = pair<ll, int>;

using pll = pair<ll, ll>;

const ll MOD = 1e9+7;

//const ll MOD = 998244353;

const int inf = 1e9;

const ll INF = 1e18;

const ld EPS = 1e-10;



struct edge{int to, cost;};



const int MAX_V = 1e5;

vector<edge> es[MAX_V];

vector<int> d(MAX_V, inf);



void add_edge(int from, int to, int cost){

    es[from].emplace_back((edge){to, cost});

}



void dijkstra(int s){

    d[s] = 0;

    queue<pii> que;

    que.push(pii(d[s], s));

    while(!que.empty()){

        pii p = que.front();

        que.pop();

        int i = p.second;

        if(p.first > d[i]) continue;

        for(auto &e: es[i]){

            if(d[e.to] > d[i]+e.cost){

                d[e.to] = d[i]+e.cost;

                que.push(pii(d[e.to], e.to));

            }

        }

    }

}



int main(){

    int K;

    cin >> K;

    rep(i, K){

        add_edge(i, (i+1)%K, 1);

        add_edge(i, (i*10)%K, 0);

    }

    dijkstra(1);

    cout << d[0]+1 << endl;

}