#include <algorithm>

#include <functional>

#include <cmath>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <string>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <vector>

#include <list>

#include <stack>

#include <queue>

#include <map>

#include <set>

#include <bitset>

#include <climits>



#define all(c) (c).begin(), (c).end()

#define rep(i,n) for(int i=0;i<(n);i++)

#define pb(e) push_back(e)

#define mp(a, b) make_pair(a, b)

#define fr first

#define sc second



const int INF=100000000;

int dx[4]={1,0,-1,0};

int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

typedef long long ll;



template<class T>

bool chmin(T &a, const T &b) {

    if(a>b) {

        a=b;

        return true;

    }

    return false;

}

struct Edge {

    int to,d,c;

    Edge(int to=0,int d=0,int c=0) :

        to(to),d(d),c(c) {}

};



struct State {

    int v,u;

    int spd;

    double t;

    State(int v=0,int u=0,int spd=0,double t=0) :

        v(v),u(u),spd(spd),t(t){}



    bool operator<(const State &rhs) const {

        return t>rhs.t;

    }

};

int s,g;

int n,m;

vector<Edge> G[40];



double dijk() {

    // v,u,spd;

    double d[40][40][40];

    rep(i,40) rep(j,40) rep(k,40) d[i][j][k]=INF;

    //rep(i,40) d[s][i][1]=1;

    d[s][s][0]=0;



    priority_queue<State> que;

    que.push(State(s,s,0));

    while(que.size()) {

        State s=que.top(); que.pop();



        rep(i,G[s.v].size()) {

            Edge e=G[s.v][i];

            if(e.to==s.u) continue;

            for(int k=-1;k<=1;k++) {

                if(!(0<=s.spd+k&&s.spd+k<=e.c)) continue;

                if(s.spd+k<=0) continue;

                if(chmin(d[e.to][s.v][s.spd+k],d[s.v][s.u][s.spd]+1.0*e.d/(s.spd+k))) {

                    que.push(State(e.to,s.v,s.spd+k,d[e.to][s.v][s.spd+k]));

                }

            }

        }

    }

    double ret=INF;

    rep(i,40) chmin(ret,d[g][i][1]);



    return ret;



}



void solve() {

    rep(i,40) G[i].clear();

    cin>>s>>g;

    s--,g--;

    rep(i,m) {

        int x,y,d,c;

        cin>>x>>y>>d>>c;

        x--,y--;

        G[x].push_back(Edge(y,d,c));

        G[y].push_back(Edge(x,d,c));

    }

    double ans=dijk();

    if(ans==INF) cout<<"unreachable"<<endl;

    else printf("%.10f\n",ans);

}



int main() {

    while(cin>>n>>m) {

        if(n==0) break;

        solve();

    }

    return 0;

}