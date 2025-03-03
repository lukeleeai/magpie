#include "stdc++.h"



using namespace std;

typedef long long ll;

typedef vector<int> VI;

typedef vector<VI> VVI;

typedef vector<ll> VL;

typedef vector<VL> VVL;

typedef pair<int, int> PII;



#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)

#define REP(i, n) FOR(i, 0, n)

#define ALL(x) x.begin(), x.end()

#define MOD 1000000007

#define INF (1LL<<25)     //33554432

#define PI 3.14159265359

#define EPS 1e-12

//#define int ll



VI g[100010];

int h[100010], s[100010], t[100010];

signed main(void)

{

  int v, e;

  cin >> v >> e;

  REP(i, e) {

    cin >> s[i] >> t[i];

    g[s[i]].push_back(t[i]);

  }



  stack<int> st;



  for(auto& i: g)

    for(auto& j: i)

      h[j]++;



  REP(i, v) {

    if(h[i] == 0) st.push(i);

  }



  VI ans;

  while(st.size()) {

    int i = st.top(); st.pop();

    ans.push_back(i);

    for(auto& j: g[i]) {

      h[j]--;

      if(h[j] == 0) st.push(j);

    }

  }



  for(int i: ans) cout << i << endl;



  return 0;

}