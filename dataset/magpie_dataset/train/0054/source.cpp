#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <iostream>

#include <vector>

#include <string>

#include <sstream>

#include <algorithm>

#include <utility>

#include <set>

#include <map>

#include <stack>

#include <queue>

#include <deque>

#include <functional>



using namespace std;



#define fst first

#define scd second

#define PB push_back

#define MP make_pair

#define chmin(a,b) a=min(a,b)

#define chmax(a,b) a=max(a,b)

#define rep(i,x) for(int i=0;i<(x);++i)

#define rep1(i,x) for(int i=1;i<=(x);++i)

#define rrep(i,x) for(int i=(x)-1;i>=0;--i)

#define rrep1(i,x) for(int i=(x);i>=1;--i)

#define FOR(i,a,x) for(int i=(a);i<(x);++i)

#define all(a) a.begin(),a.end()

#define rall(a) a.rbegin(),a.rend()



template<typename T>T&get(){T a;cin >> a;return a;}

template<typename T>T&rev(T&a){reverse(all(a));return a;}

template<typename T>istream&operator>>(istream&is,vector<T>&vec){rep(i,vec.size())is>>vec[i];return is;}

template<typename T>vector<T>&sort(vector<T>a){sort(all(a));return a;}



typedef long long ll;

typedef vector<int> vi;

typedef pair<int, int> pii;



const int inf = 1e9;

const ll linf = 3e18;



struct edge {

    int to, cost, time;

    edge(int to0,int cost0,int time0) {

        to = to0; cost = cost0; time = time0;

    };

};



int N, M;



vector<edge> G[100];

int d[100];



void dijkstra(int s, int mode)

{

    priority_queue<pii, vector<pii>, greater<pii> > q;



    fill(d, d + M, inf);

    d[s] = 0;



    q.push(MP(0, s));



    while (q.size()) {

        pii p = q.top(); q.pop();

        int v = p.scd;

        rep(u, G[v].size()) {

            edge e = G[v][u];

            int a = mode == 0 ? e.cost : e.time;

            if (d[e.to] > d[v] + a) {

                d[e.to] = d[v] + a;

                q.push(MP(d[e.to], e.to));

            }

        }

    }

}



signed main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);



    while (cin >> N >> M, N || M) {

        rep(i, M) G[i].clear();



        rep(i, N) {

            int a, b, cost, time; cin >> a >> b >> cost >> time; a--; b--;

            G[a].PB(edge(b, cost, time));

            G[b].PB(edge(a, cost, time));

        }



        int K; cin >> K;



        rep(i, K) {

            int p, q, r; cin >> p >> q >> r; p--; q--;

            dijkstra(p, r);

            cout << d[q] << endl;

        }

    }

}