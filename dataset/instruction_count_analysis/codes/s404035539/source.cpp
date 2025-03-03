#include "stdc++.h"

using namespace std;

using ll = long long;

constexpr ll MOD = 1e9 + 7;

//constexpr ll MOD = 998244353;

//constexpr ll MOD = ;

ll mod(ll A, ll M) {return (A % M + M) % M;}

constexpr ll INF = 1LL << 60;

template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}

ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}

#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)



int main()

{

  ll N, Q;

  cin >> N >> Q;

  vector<vector<ll>> G(N);

  for (ll i = 0; i < N - 1; i++)

  {

    ll a, b;

    cin >> a >> b;

    a--, b--;

    G.at(a).push_back(b);

    G.at(b).push_back(a);

  }



  vector<ll> cnt(N);

  for (ll i = 0; i < Q; i++)

  {

    ll p, x;

    cin >> p >> x;

    p--;

    cnt.at(p) += x;

  }



  vector<bool> visited(N, false);

  vector<ll> st;

  visited.at(0) = true;

  st.push_back(0);

  while (!st.empty())

  {

    ll v = st.back();

    st.pop_back();



    for (auto nv : G.at(v))

    {

      if (visited.at(nv))

        continue;



      cnt.at(nv) += cnt.at(v);

      visited.at(nv) = true;

      st.push_back(nv);

    }

  }



  for (ll i = 0; i < N; i++)

  {

    cout << cnt.at(i) << ((i == N - 1) ? '\n' : ' ');

  }

}