#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef vector<ll> vec;

typedef vector<vec> mat;

typedef pair<ll,ll> pll;

const ll mod=1e9+7;

//const ll mod=998244353;

const ll inf=1LL<<61;



typedef pair<ll,pll> ppll;



int main() {

  ll n,m,s;

  cin >> n >> m >> s;

  vector<map<ll,pll>> G(n);

  for(ll i=0;i<m;i++) {

    ll u,v,a,b;

    cin >> u >> v >> a >> b;

    u--,v--;

    G[u][v]={a,b};

    G[v][u]={a,b};

  }

  vec mai(n),mnu(n);

  for(ll i=0;i<n;i++) {

    cin >> mai[i] >> mnu[i];

  }

  mat d(n,vec(50*(n-1)+1,-1));

  vec ans(n,-1);

  vec mins(n,-1);

  priority_queue<ppll,vector<ppll>,greater<ppll>> q;

  s=min(s,50*(n-1));

  q.push({0,{0,s}});

  while(q.size()) {

    ll td=q.top().first;

    ll f=q.top().second.first;

    ll s=q.top().second.second;

    q.pop();

    ll flag=0;

    if(ans[f]<0) ans[f]=td;

    if(d[f][s]>-1) continue;

    d[f][s]=td;

    mins[f]=s;

    for(auto p:G[f]) {

      ll t=p.first;

      ll co=p.second.first;

      ll v=p.second.second;

      if(s-co>=0&&d[t][s-co]==-1) {

        q.push({td+v,{t,s-co}});

      }

    }

    ll ns=min(s+mai[f],50*(n-1));

    ll nd=td+mnu[f];

    if(d[f][ns]==-1) q.push({nd,{f,ns}});

  }

  for(ll i=1;i<n;i++) {

    cout << ans[i] << endl;

  }

}