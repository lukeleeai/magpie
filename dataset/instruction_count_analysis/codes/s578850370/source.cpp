#include "stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, j, n) for (int i = j; i < n; i++)

#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>

#define pll pair<ll, ll>

#define vc vector

#define a first

#define b second

#define pb push_back

#define INF (1000000000)

#define MOD (1000000007)

#define MAX (5000000)



/////////////////////////////////////////////////////////



class XY{

public:

  ll x, y;

  XY() {x = y = 0;}

  XY(ll u, ll v) {x = u; y = v;}

};



template<typename T1, typename T2>

void chmin(T1 &a, T2 b) {if(a > b) a = b;}

template<typename T1, typename T2>

void chmax(T1 &a, T2 b) {if(a < b) a = b;}



template<typename T1, typename T2>

ll mypow(T1 a, T2 n){

  if(n == 0) return 1;

  if(n == 1) return a;

  if(n % 2) return a * mypow(a, n - 1);

  ll tmp = mypow(a, n / 2);

  return tmp * tmp;

}



template<typename T>

int BS(vector<T> &V, int left, int right, T key){

  int mid = (left + right) / 2;

  if(V[mid] <= key) left = mid;

  else right = mid;

  if(right - mid == 1) return left;

  else return BS(V, left, right, key);

}



ll comb(ll n, ll r){

	ll res = 1;

  rep(i, 0, r){

    res *= n - i;

    res /= i + 1;

  }

  return res;

}



template<typename T>

T euclid(T a, T b){

  if(b == 0) return a;

  else return euclid(b, a % b);

}



/////////////////////////////////////////////////////////



//MOD of Combination

/*

vector<ll> fact(MAX, 0), fact_inv(MAX, 0);



ll pow_mod(ll a, ll b){

	ll res = 1;

	while(b > 0){

		if(b & 1) res = res * a % MOD;

		a = a * a % MOD;

		b >>= 1;

	}

	return res;

}



void prepare_comb_mod(ll n){

	fact[0] = 1LL;

	for(ll i = 0; i < n; i++) fact[i+1] = fact[i] * (i + 1) % MOD;

	fact_inv[n] = pow_mod(fact[n], MOD - 2);

	for(ll i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD;

}



ll comb_mod(ll n, ll r){

	return (fact[n] * fact_inv[r]) % MOD * fact_inv[n - r] % MOD;

}

*/

/////////////////////////////////////////////////////////



//Union-Find Tree



template<class T> struct UFT{

  vector<int> par;

  vector<int> rank;

  vector<T> diff_weight;



  UFT(int n = 1, T w = 0) {

    init(n, w);

  }



  void init(int n = 1, T w = 0) {

    par.resize(n);

    rank.resize(n);

    diff_weight.resize(n);

    rep(i, 0, n){

      par[i] = i;

      rank[i] = 0;

      diff_weight[i] = w;

    }

  }



  int root(int x){

    if(par[x] == x){

      return x;

    }else{

      int r = root(par[x]);

      diff_weight[x] += diff_weight[par[x]];

      return par[x] = r;

    }

  }



  bool unite(int x, int y, int w = 0){

    w += weight(x); w -= weight(y);

    x = root(x);

    y = root(y);

    if(x == y) return false;

    if(rank[x] < rank[y]){

      par[x] = y;

      diff_weight[x] = -w;

    }else{

      par[y] = x;

      diff_weight[y] = w;

      if(rank[x] == rank[y]) rank[x]++;

    }

    return true;

  }



  bool same(int x, int y){

    return root(x) == root(y);

  }



  T weight(int x) {

    root(x);

    return diff_weight[x];

  }



  T diff(int x, int y) {

    return weight(y) - weight(x);

  }

};



/////////////////////////////////////////////////////////



ll digit(ll N){

    return log10(N)+1;

}



/////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////



void Main () {

  int H, W; cin >> H >> W;

  int N; cin >> N;

  vc<int> A(N);

  rep(i, 0, N) cin >> A[i];

  vc<vc<int>> C(H, vc<int>(W, 0));

  int cur = 0;

  rep(i, 0, H){

    rep(j, 0, W){

      int j_ = j;

      if(i % 2 == 1) j_ = W - j - 1;

      C[i][j_] = cur + 1;

      A[cur]--;

      if(A[cur] == 0) cur++;

    }

  }

  rep(i, 0, H){

    rep(j, 0, W){

      cout << C[i][j];

      if(j != W - 1) cout << " ";

    }

    cout << endl;

  }

}



/////////////////////////////////////////////////////////



int main(){

  cin.tie(nullptr);

  ios_base::sync_with_stdio(false);

  cout << std::fixed << std::setprecision(15);



  Main();

}
