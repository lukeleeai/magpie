#include "stdc++.h"

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

#define F first

#define S second

#define pb push_back

#define mp make_pair

#define ALL(a) a.begin(), a.end()

#define SZ(a) ((int)(a).size())



using namespace std;

typedef long long ll;

typedef pair<int, int> PI;



int n;

map<string, int> memo;

vector<string> mstr;

int get(string a){

  if(memo.count(a))

    return memo[a];

  int sz = SZ(memo);

  mstr.pb(a);

  return memo[a] = sz;

}



vector<PI> G[2000];

int vis[2000];

int vcnt;

bool app[2000][2000];



vector<int> cG[2000];



void solve(){

  memo.clear();

  mstr.clear();

  rep(i, n*2) G[i].clear();

  rep(i, n*2) cG[i].clear();

  

  set<PI> input;

  rep(i, n){

    string a, b;

    cin >> a;

    a[a.find('-')] = ' ';

    stringstream ss(a);

    ss >> a >> b;

    int u = get(a);

    int v = get(b);

    G[u].pb(mp(v,1));

    cG[u].pb(v);

    cG[v].pb(u);

    input.insert(mp(u, v));

  }

  

  

  cout << SZ(memo) << endl;

  rep(i, SZ(memo)) rep(j, SZ(memo)) app[i][j] = 0;

  for(auto e : input) app[e.F][e.S] = 1;



  

  // rep(d, SZ(memo)){

  //   sort(ALL(cG[d]));

  //   cG[d].erase(unique(ALL(cG[d])), cG[d].end());



  //   for(auto a : cG[d]) for(auto b : cG[d]){

  //       if(a == b) break;

        

  //       if(app[a][d] && app[d][b]) continue;

  //       if(app[b][d] && app[d][a]) continue;

  //       G[a].pb(mp(b,0));

  //       G[b].pb(mp(a,0));

  //     }

  // }



  rep(i, SZ(memo)) rep(j, i){

    bool ok = false;

    rep(k, SZ(memo))

      if((app[i][k]|app[k][i]) && (app[k][j]|app[j][k])){

        ok = true;

        break;

      }

    if(!ok) continue;

    ok = true;

    rep(k, SZ(memo)) if(app[i][k] && app[k][j]) ok = false;

    rep(k, SZ(memo)) if(app[j][k] && app[k][i]) ok = false;

    if(ok){

      G[i].pb(mp(j,0));

      G[j].pb(mp(i,0));

    }

  }

  

  rep(d, SZ(memo)){

    sort(ALL(G[d]));

    G[d].erase(unique(ALL(G[d])), G[d].end());

  }

  

  // rep(d, SZ(memo)){

  //   cout << mstr[d] << ": ";

  //   for(auto e : G[d])

  //     cout << mstr[e.F] << ",";

  //   cout << endl;

  // }

  

  int q;

  cin >> q;

  rep(i, q){

    string a, b;

    cin >> a;

    a[a.find('-')] = ' ';

    stringstream ss(a);

    ss >> a >> b;

    

    if(!(memo.count(a) && memo.count(b))){

      cout << "NO" << endl;

      continue;

    }

    

    int u = get(a);

    int v = get(b);

    queue<PI> q;

    q.push(mp(u,0));

    

    bool ok = false;

    ++vcnt;

    while(!q.empty()){

      int cv = q.front().F;

      int cc = q.front().S;

      q.pop();

      if(cv == v){

        //cout << "cc " << cc << endl;

        ok = cc & 1;

        break;

      }

      

      if(vis[cv] == vcnt) continue;

      //cout << mstr[cv] << endl;

      vis[cv] = vcnt;

      for(auto e : G[cv])

        if(vis[e.F] != vcnt)

          q.push(mp(e.F, cc + e.S));

    }

    

    if(ok) cout << "YES" << endl;

    else cout << "NO" << endl;

  }

}



int main(int argc, char *argv[])

{

  while(cin >> n && n) solve();

  return 0;

}