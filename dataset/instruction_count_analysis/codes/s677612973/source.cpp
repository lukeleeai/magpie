#include "stdc++.h"



using namespace std;

#define _overload3(_1,_2,_3,name,...) name

#define _rep(i,n) repi(i,0,n)

#define repi(i,a,b) for(int i=int(a);i<int(b);++i)

#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)



typedef long long ll;

typedef pair<ll, ll> P;

const ll INF = 1LL<<60;



ll gcd(ll a, ll b) {

  if(b == 0) return a;

  return gcd(b, a % b);

}



template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



ll modpow(ll a, ll n, ll mod) {

  ll res = 1;

  while (n > 0) {

    if (n & 1) res = res * a % mod;

    a = a * a % mod;

    n >>= 1;

  }

  return res;

}



ll K;



ll dfs(int j, vector<ll> a){



  ll n = a.size();

  if(n < K){

    return 0;

  }



  vector<ll> a0, a1;



  rep(i, n){

    if(a[i] & (1LL<<j)){

      a1.push_back(a[i]);

    }else{

      a0.push_back(a[i]);

    }

  }



  if(j == 0){

    if(a1.size() >= K){

      return 1;

    }else{

      return 0;

    }

  }else{



    if(a1.size() >= K){

      ll ans;

      ll ret_a1 = dfs(j-1, a1);

      ans = (1LL << j);

      ans += ret_a1;

      return ans;

    }else{

      return dfs(j-1, a);

    }

  }

}



int main(){

  cin.tie(0);

  ios::sync_with_stdio(false);



  int N;

  cin >> N >> K;



  vector<ll> a(N);

  rep(i, N) cin >> a[i];



  vector<ll> asum;



  for(int i = 0; i < N; i++){

    

    ll sum = a[i];

    asum.push_back(sum);

    for(int j = i+1; j < N; j++){

      sum += a[j];

      asum.push_back(sum);

    }

  }



  ll ans = 0;

  rep(i, 60){

    chmax(ans, dfs(i, asum));

  }



  cout << ans << endl;



  return 0;

}
