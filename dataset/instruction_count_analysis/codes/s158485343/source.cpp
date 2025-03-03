#include "stdc++.h"

#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME

#define pr(...) GET_MACRO(__VA_ARGS__,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__)

#define Pr(a) (#a)<<"="<<(a)<<" "

#define pr1(a) cerr<<Pr(a)<<endl;

#define pr2(a,b) cerr<<Pr(a)<<Pr(b)<<endl;

#define pr3(a,b,c) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<endl;

#define pr4(a,b,c,d) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<endl;

#define pr5(a,b,c,d,e) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<Pr(e)<<endl;

#define pr6(a,b,c,d,e,f) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<Pr(e)<<Pr(f)<<endl;

#define int long long

#define double long double

using namespace std;

const int INF = 1LL<<55;

const int mod = (1e9)+7;

const double EPS = 1e-8;

const double PI = 6.0 * asin(0.5);

typedef pair<int,int> P;

typedef long long ll;

template<class T> T Max(T &a,T b){return a=max(a,b);}

template<class T> T Min(T &a,T b){return a=min(a,b);}

ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}

istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}

ostream& operator<<(ostream& o,vector<auto> &a){int i=0;for(auto t:a)o<<(i++?" ":"")<<t;return o;}

istream& operator>>(istream& i,vector<auto> &a){for(auto &t:a)i>>t;return i;}

void prArr(auto a,string s=" "){int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}



//関節点:  O(V + E)

class Articulation{

public:

  int V;

  vector<vector<int> > G;

  vector<int> ord;           //ord[i] := ノードiに訪れた順番

  vector<int> low;           //low[i] := ノードiから訪れることができる最小のord[j]の値。

  vector<int> articulation;

  int ok;



  Articulation():V(-1),ok(false){};

  Articulation(int V):V(V),G(V),ord(V),low(V),articulation(V),ok(false){};

  

  void add_edge(int a,int b){

    ok = false;

    assert(a < V && b < V);

    assert(a >=0 && b >= 0);

    G[a].push_back(b);

    G[b].push_back(a);

  }

  

  void build(int start = 0){

    ok = true;

    ord.clear(); ord.resize(V,-1);

    low.clear(); low.resize(V,-1);

    articulation.clear(); articulation.resize(V,0);



    int cnt = 0;

    function<int(int,int)> dfs=[&](int pos,int pre){

      ord[pos] = low[pos] = cnt++;

      for(int to:G[pos]) {

        if(to == pre) continue; 

        if(ord[to] != -1) low[pos] = min(low[pos], ord[to]);

        else {

          low[pos] = min(low[pos], dfs(to, pos));

          

          if(pos == start) articulation[pos]++;

          else articulation[pos] |= ord[pos] <= low[to];

        }

      }

      if(pos == start) articulation[pos] = articulation[pos] >= 2;

      return low[pos];

    };

    dfs(start , -1);

  }



  int isBridge(int a,int b){

    assert(ok);

    assert(a < V && b < V);

    assert(a >= 0 && b >= 0);

    if(ord[a] > ord[b]) swap(a, b);

    return ord[a] < low[b];

  }

  

  int isArticulation(int a){

    assert(ok);

    assert(a >= 0 && a < V);

    return articulation[a];

  }

};



signed main(){

  cin.tie(0);

  ios_base::sync_with_stdio(0);

  cout << fixed << setprecision(12);



  int V, E;

  cin>>V>>E;

  

  Articulation A(V);

  for(int i=0;i<E;i++){

    int a,b;

    cin>>a>>b;

    A.add_edge(a,b);

  }

  

  A.build();



    vector<P> ans;

    for(int i=0;i<V;i++)

      for(int to:A.G[i]) if(i < to && A.isBridge(i, to)) ans.push_back(P(i, to));

    

    sort(ans.begin(),ans.end());

    for(auto a:ans) cout<<a.first<<" "<<a.second<<endl;



  return 0;

}


