#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <queue>

#include <cstdio>

#include <cstring>

#include <ctime>

#include <string>

#include <vector>

#include <algorithm>

#include <cmath>

#include <sstream>

#include <utility>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef pair<int,int> pii;

#define all(c) (c).begin(), (c).end()

#define loop(i,a,b) for(ll i=a; i<ll(b); i++)

#define rep(i,b) loop(i,0,b)

#define each(e,c) for(auto&e:c)

#define pb push_back

#define eb emplace_back

#define mp make_pair

#define mt make_tuple

#define lb lower_bound

#define ub upper_bound

#ifdef DEBUG

#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<(DUMP(),__VA_ARGS__).str()<<" ["<<__LINE__<<"]"<<endl)

struct DUMP:ostringstream{template<class T>DUMP &operator,(const T&t){if(this->tellp())*this<<", ";*this<<t;return *this;}};

#else

#define dump(...)

#endif



// グラフ用ヘッダ



typedef double Weight;

struct Edge {

    int src, dst;

    Weight weight;

    Edge(int src, int dst, Weight weight) :

        src(src), dst(dst), weight(weight) { }

};

bool operator < (const Edge &e, const Edge &f) {

    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!

        e.src != f.src ? e.src < f.src : e.dst < f.dst;

}

typedef vector<Edge> Edges;

typedef vector<Edges> Graph;



typedef vector<Weight> Array;

typedef vector<Array> Matrix;



int n,a,b;

int t[8]; // size n

Graph g;

double dp[32][1<<9];



double inf = 1e100;



string solve(){

    priority_queue<tuple<double,int,int>> q;

    rep(i,32)rep(j,1<<9) dp[i][j] = inf;

    dp[a][0] = 0;

    // -d,v,use

    q.emplace(0,a,0);

    while(q.size()){

        dump(q.size());

        double d; int v,use;

        tie(d,v,use) = q.top(); q.pop();

        dump(d,v,use);

        d = -d;

        if(v==b){

            char buf[100];

            sprintf(buf, "%.10lf", d);

            return buf;

        }

        if(dp[v][use] > d) continue;

        for(const Edge& e : g[v]){

            rep(i,n){

                if(use>>i & 1) continue;

                double nd = d+e.weight/t[i];

                int nu = use | (1<<i);

                if(dp[e.dst][nu] > nd){

                    dp[e.dst][nu] = nd;

                    q.emplace(-nd, e.dst, nu);

                }

            }

        }

    }

    return "Impossible";

}



int main(){

    while(cin>>n && n){

        int m,p;

        cin>>m>>p>>a>>b;

        rep(i,n) cin >> t[i];

        g.assign(m+1,{});

        rep(i,p){

            int x,y,z; cin >> x >> y >> z;

            g[x].eb(x,y,z);

            g[y].eb(y,x,z);

        }

        cout << solve() << endl;

    }

}