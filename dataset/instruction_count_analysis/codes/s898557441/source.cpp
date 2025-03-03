#include"stdc++.h"

#define rep(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

typedef pair<int,int> edge;



const int INF = 1e9;



int main(){

  int n,m,k;

  scanf("%d%d%d",&n,&m,&k);

  

  vector< vector<edge> > g(n);

  rep(i,m){

    int a,b,l;

    cin >> a >> b >> l; a--; b--;

    g[a].push_back(edge(l,b));

    g[b].push_back(edge(l,a));

  }



  vector<int> d(n,INF);

  priority_queue< edge, vector<edge>, greater<edge> > q;

  rep(i,k){

    int s; cin >> s; s--;

    d[s] = 0;

    q.push(edge(0,s));

  }



  while(q.size()){

    edge x = q.top(); q.pop();

    int c = x.first, v = x.second;

    

    for(edge e : g[v]){

      int nc = c + e.first;

      int u = e.second;

      

      if(d[u] > nc){

	d[u] = nc;

	q.push( edge(nc, u) );

      }

    }

  }

  

  int ans = 0;

  rep(a,n){

    for(edge e : g[a]){

      int l = e.first, b = e.second;

      

      int A = min(d[a], d[b]), B = max(d[a], d[b]);

      if(A+l < B){

	ans = max(ans, A+l);

      }else{

	ans = max(ans, (A+B+l+1)/2);

      }

    }

  }

  cout << ans << endl;

}