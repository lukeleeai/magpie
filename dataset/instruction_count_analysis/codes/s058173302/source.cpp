#include "stdc++.h"

#define repd(i,a,b) for (int i=(a);i<(b);i++)

#define rep(i,n) repd(i,0,n)

#define int long long

typedef long long ll;

using namespace std;

const int MOD = 1000000007;

const int INF = 1000000000000000000;

const double EPS = 1e-10;

const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 



struct edge { int to, cost; };

vector<edge> g[110000];

int d[110000];

int v,e,s,t;



void dijkstra(int s, int d[], vector<edge> g[]){

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;

  fill(d,d+v+1, INF);d[s] = 0;que.push(pair<int,int>(0,s));

  while(!que.empty()){

    pair<int,int> p = que.top();que.pop();

    int v = p.second;

    if(d[v]<p.first)continue;

    rep(i,g[v].size()){

      edge e = g[v][i];

      if(d[e.to] > d[v] + e.cost){

        d[e.to] = d[v] + e.cost;

        que.push(pair<int,int>(d[e.to], e.to));

      }

    }

  }

}



signed main(){

  int x,y,z,k;cin>>x>>y>>z>>k;

  int a[1100], b[1100], c[1100];rep(i,x)cin>>a[i];rep(i,y)cin>>b[i];rep(i,z)cin>>c[i];

  vector<int> d(x*y);int ind = 0;

  rep(i,x){

    rep(j,y){

      d[ind] = a[i]+b[j];

      ind++;

    }

  }

  sort(d.begin(), d.end(),greater<int>());sort(c,c+z,greater<int>());

  deque<int> q;

  rep(i,z){

    rep(j,min(k,x*y)){

      q.push_back(c[i]+d[j]);

    }

  }

  sort(q.begin(), q.end(), greater<int>());

  rep(i,k){

    cout << q[i] << endl;

  }

}
