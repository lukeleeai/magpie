#include "stdc++.h"

using namespace std;

using ll = long long;

const ll MOD = pow(10, 9) + 7;

//const ll MOD = 998244353;

//const ll MOD = ;

ll mod(ll A, ll M) {return (A % M + M) % M;}

const ll INF = 1LL << 60;

template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}

ll divCeil(ll A, ll B) {return (A + (B - 1)) / B;}

ll myctoi(char C) {return C - '0';}

char myitoc(ll N) {return '0' + N;}

#define FINALANS(A) {cout << (A) << endl; exit(0);}



vector<vector<ll>> G(222222);

vector<ll> cnt(222222, 0);

vector<bool> visited(222222, false);

void dfs(ll V)

{

  if (visited.at(V))

    return;

  visited.at(V) = true;



  //cerr << V << endl;



  for (ll i = 0; i < G.at(V).size(); i++)

  {

    if (!visited.at(G.at(V).at(i)))

      cnt.at(G.at(V).at(i)) += cnt.at(V);

    dfs(G.at(V).at(i));

  }

}



int main()

{

  ll N, Q;

  cin >> N >> Q;

  for (ll i = 0; i < N - 1; i++)

  {

    ll a, b;

    cin >> a >> b;

    a--, b--;

    G.at(a).push_back(b);

    G.at(b).push_back(a);

  }

  for (ll i = 0; i < Q; i++)

  {

    ll p, x;

    cin >> p >> x;

    p--;

    cnt.at(p) += x;

  }



  dfs(0);



  for (ll i = 0; i < N; i++)

  {

    cout << cnt.at(i);

    if (i == N - 1)

      cout << endl;

    else

      cout << " ";

  }

}