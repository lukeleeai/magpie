#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <climits>

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

#define int long long

#define all(a) a.begin(),a.end()

#define rall(a) a.rbegin(),a.rend()

#define omajinai ios::sync_with_stdio(false);cin.tie(0)



typedef long long ll;

typedef long double ld;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef pair<int, int> pii;

typedef vector<pii> vpii;



template<typename T>T& max(T&a,T&b){if(a>=b)return a;return b;}

template<typename T>T& min(T&a,T&b){if(a<b)return a;return b;}

template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}

template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}

template<typename T>T get(){T a;cin>>a;return a;}

template<typename T>T rev(T a){reverse(all(a));return a;}

template<typename T>vector<T>&sort(vector<T>&a){sort(all(a));return a;}



const int inf = 1e9;

const ll linf = 3e18;

const double eps = 1e-9;



struct to {

    int type, x, y;

    to(int type, int y, int x):type(type),y(y),x(x){}

    bool operator<(const to& t) const {

        return type < t.type;

    }

};

struct edge {

    to t; int cost;

    edge(to t, int cost):t(t),cost(cost){}

};



vector<edge> G[2][61][31];

int d[2][61][31];



char fld[62][32];



int dx[9] = {1, 1, 1, 1, 1, 2, 2, 2, 3};

int dy[9] = {-2, -1, 0, 1, 2, -1, 0, 1, 0};



int W, H;



bool inside(int h, int w)

{

    return (0 <= h && h < H && 0 <= w && w < W);

}



void build_graph()

{

    for (int i = 0; i < H; ++i) {

        for (int j = 0; j < W; ++j) {

            if (fld[i][j] == 'T' || fld[i][j] == 'X') continue;



            for (int k = 0; k < 9; ++k) {

                int y = i + dy[k], ax = j + dx[k], bx = j + dx[k] * -1;



                if (inside(y, ax) && fld[y][ax] != 'X') {

                    int cost = (isdigit(fld[y][ax]) ? fld[y][ax] - '0' : 0);

                    G[0][i][j].push_back(edge(to(1, y, ax), cost));

                }

                

                if (inside(y, bx) && fld[y][bx] != 'X') {

                    int cost = (isdigit(fld[y][bx]) ? fld[y][bx] - '0' : 0);

                    G[1][i][j].push_back(edge(to(0, y, bx), cost));

                }

            }

        }

    }

}



void dijkstra(to s)

{

    typedef pair<int, to> P;



    priority_queue<P, vector<P>, greater<P> > q;



    q.push(P(0, to(s.type, s.y, s.x)));



    d[s.type][s.y][s.x] = 0;



    while (q.size()) {

        P p = q.top();

        q.pop();



        to t = p.scd;

        

        if (p.fst > d[t.type][t.y][t.x]) continue;



        for (int i = 0; i < G[t.type][t.y][t.x].size(); ++i) {

            edge e = G[t.type][t.y][t.x][i];



            if (d[e.t.type][e.t.y][e.t.x] > d[t.type][t.y][t.x] + e.cost) {

                d[e.t.type][e.t.y][e.t.x] = d[t.type][t.y][t.x] + e.cost;

                q.push(P(d[e.t.type][e.t.y][e.t.x], e.t));

            }

        }

    }

}

signed main()

{

    while (scanf("%d%d", &W, &H), W) {

        for (int i = 0; i < 2; ++i) for (int j = 0; j < H; ++j) for (int k = 0; k < W; ++k) {

            G[i][j][k].clear();

            d[i][j][k] = inf;

        }





        for (int i = 0; i < H; ++i) {

            for (int j = 0; j < W; ++j) {

                scanf("\n%c", &fld[i][j]);

            }

        }



        build_graph();



        for (int i = 0; i < W; ++i) {

            if (fld[H - 1][i] == 'S') {

                for (int j = 0; j < 2; ++j) {

                    dijkstra(to(j, H - 1, i));

                }

            }

        }



        int mi = inf;



        for (int i = 0; i < W; ++i) {

            if (fld[0][i] == 'T') {

                chmin(mi, min(d[0][0][i], d[1][0][i]));

            }

        }



        printf("%d\n", mi == inf ? -1 : mi);

    }

}