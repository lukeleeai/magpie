#include "stdc++.h"

using namespace std;

#define rep(i,N) for(int i=0,i##_max=(N);i<i##_max;++i)

#define repp(i,l,r) for(int i=(l),i##_max=(r);i<i##_max;++i)

#define per(i,N) for(int i=(N)-1;i>=0;--i)

#define perr(i,l,r) for(int i=r-1,i##_min(l);i>=i##_min;--i)

#define all(arr) (arr).begin(), (arr).end()

#define SP << " " <<

#define SPF << " "

#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false);

#define MAX_I INT_MAX //1e9

#define MIN_I INT_MIN //-1e9

#define MAX_UI UINT_MAX //1e9

#define MAX_LL LLONG_MAX //1e18

#define MIN_LL LLONG_MIN //-1e18

#define MAX_ULL ULLONG_MAX //1e19

  typedef long long ll;

  typedef pair<int,int> PII;

  typedef pair<char,char> PCC;

  typedef pair<ll,ll> PLL;

  typedef pair<char,int> PCI;

  typedef pair<int,char> PIC;

  typedef pair<ll,int> PLI;

  typedef pair<int,ll> PIL; 

  typedef pair<ll,char> PLC; 

  typedef pair<char,ll> PCL; 



inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}

inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}

inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}



struct edge{int to;ll cost;};

const int VMAX = 1e5+10;

const int MMAX = 1e5+10;

const ll INF = 1e15;

vector<vector<edge> > G(VMAX);

vector<ll> d(VMAX,INF);

int V,M;



void dijkstra(int s){

  priority_queue<PLI, vector<PLI>, greater<PLI> > pque;

  d[s] = 0;

  pque.push(PLI(0,s));

  while(!pque.empty()){

    PLI p = pque.top();pque.pop();

    int v = p.second;

    if(d[v] < p.first)continue;

    for(const edge& e : G[v]){

      if(d[e.to] > d[v] + e.cost){

        d[e.to] = d[v] + e.cost;

        pque.push(PLI(d[e.to],e.to));

      }

    }

  }

}



int main(void){

  SPEEDUP

  cout << setprecision(15);

  cin >> V >> M;

  rep(i,M){

    int f,t;

    ll c;cin >> f >> t >> c;

    G[f].push_back({t,c});

  }

  rep(i,V-1){

    G[i+1].push_back({i,0});

  }

  dijkstra(1);

  if(d[V] == INF)cout << -1 << endl;

  else cout << d[V] << endl;

  return 0;

}
