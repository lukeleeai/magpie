#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef vector<ll> vec;

typedef vector<vec> mat;

typedef pair<ll,ll> pll;

const ll mod=1e9+7;

//const ll mod=998244353;

const ll inf=1LL<<61;



const ll N=1e3+10;

ll n,m;

vector<set<ll>> G(N),GG(N);



int main() {

  cin >> n >> m;

  for(ll i=0;i<m;i++) {

    ll a,b;

    cin >> a >> b;

    a--,b--;

    G[a].insert(b);

    GG[b].insert(a);

  }

  ll ans=inf;

  vec ansv(n);

  for(ll i=0;i<n;i++) {

    priority_queue<pll> q;

    ll id=-1;

    vec d(n,-1);

    q.push({0,i});

    while(q.size()) {

      ll f=q.top().second;

      ll td=q.top().first;

      q.pop();

      if(d[f]>-1) continue;

      d[f]=td;

      for(ll t:G[f]) {

        ll nd=td+1;

        if(t==i) {

          id=f;

          break;

        }

        q.push({nd,t});

      }

      if(id>-1) break;

    }

    if(id>-1) {

      if(ans>d[id]+1&&d[id]) {

        ans=d[id]+1;

        ll j=0;

        while(1) {

          ansv[j]=id+1;

          j++;

          if(id==i) break;

          for(ll t:GG[id]) {

            if(d[t]+1==d[id]) {

              id=t;

              break;

            }

          }

        }

      }

    }

  }

  if(ans==inf) ans=-1;

  cout << ans << endl;

  for(ll i=0;i<ans;i++) {

    cout << ansv[ans-i-1] << endl;

  }

}