#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef vector<ll> vec;

typedef vector<vec> mat;

typedef pair<ll,ll> pll;

const ll mod=1e9+7;

//const ll mod=998244353;

const ll inf=1LL<<61;

 

int main() {

  ll n,m;

  cin >> n >> m;

  mat G(n),GG(n);

  for(ll i=0;i<m;i++) {

    ll a,b;

    cin >> a >> b;

    a--,b--;

    G[a].push_back(b);

    GG[b].push_back(a);

  }

  ll ans=inf;

  vec ansv(n);

  for(ll i=0;i<n;i++) {

    queue<ll> q;

    ll id=-1;

    vec d(n,-1);

    d[i]=0;

    q.push(i);

    while(q.size()) {

      ll f=q.front();

      ll td=d[f];

      q.pop();

      for(ll t:G[f]) {

        ll nd=td+1;

        if(t==i) {

          id=f;

          break;

        }

        if(d[t]>-1) continue;

        d[t]=nd;

        q.push(t);

      }

      if(id>-1) break;

    }

    if(id>-1) {

      if(ans>d[id]+1) {

        ans=d[id]+1;

        for(ll j=0;j<ans;j++) {

          ansv[j]=id+1;

          for(ll f:GG[id]) {

            if(d[f]+1==d[id]) {

              id=f;

              break;

            }

          }

        }

      }

    }

    while(q.size()) q.pop();

  }

  if(ans==inf) ans=-1;

  cout << ans << endl;

  for(ll i=0;i<ans;i++) {

    cout << ansv[i] << endl;

  }

}