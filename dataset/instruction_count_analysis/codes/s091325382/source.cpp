#include "stdc++.h"

#define ALL(a)  (a).begin(),(a).end()

#define sz(x) int(x.size())

using namespace std;

typedef long long ll;

typedef pair<int, int> P;

typedef pair<long long, long long> Pll;

typedef vector<int> vi;

typedef vector<vector<int>> vvi;

typedef vector<long long> vll;

typedef vector<vector<long long>> vvll;

template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

const int INT_INF = 1 << 30;

const double PI = acos(-1.0);

#define MOD 1000000009LL

#define endl "\n"



struct COM{

  ll modpow(ll x, ll nn){

    ll res = 1;

    while(nn > 0){

      if(nn & 1) res = res * x % MOD;

      x = x * x % MOD;

      nn >>= 1;

    }

    return res;

  }

  vll fact, ifact;

  COM(ll n): fact(n+1), ifact(n+1){

    assert(n < MOD);

    fact[0] = 1LL;

    for(ll i = 1; i <= n; i++) fact[i] = fact[i-1]*i%MOD;

    ifact[n] = modpow(fact[n], MOD-2);

    for(ll i = n; i >= 1; i--) ifact[i-1] = ifact[i]*i%MOD;

  }

  ll operator()(int n, int k){

    if(k < 0 || k > n) return 0;

    return fact[n]*ifact[k]%MOD*ifact[n-k]%MOD;

  }

};



int main(){

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  srand((unsigned)time(NULL));

  COM c(200010);

  string S;

  cin >> S;

  ll N = S.size();

  vll count(2019, 0LL);

  ll num = 0LL;

  ll keta = 1LL;

  for(int i = N-1; i >= 0; i--){

    num += keta * (S.at(i)-'0') % 2019;

    num %= 2019;

    count.at(num)++;

    keta *= 10;

    keta %= 2019;

  }

  count.at(0)++;

  ll ans = 0;

  for(int i = 0; i < 2019; i++){

    ans += c(count.at(i), 2);

  }

  cout <<ans << endl;

}