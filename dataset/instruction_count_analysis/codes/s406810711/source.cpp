#include "stdc++.h"

 

const double pi = 3.141592653589793238462643383279;

 

 

using namespace std;

//typedef

//------------------------------------------

typedef vector<int> VI;

typedef vector<VI> VVI;

typedef vector<string> VS;

typedef pair<int, int> PII;

typedef pair<long long, long long> PLL;

typedef pair<int, PII> TIII;

typedef long long LL;

typedef unsigned long long ULL;

typedef vector<LL> VLL;

typedef vector<VLL> VVLL;

 

 

//container util

//------------------------------------------

#define ALL(a)  (a).begin(),(a).end()

#define RALL(a) (a).rbegin(), (a).rend()

#define PB push_back

#define MP make_pair

#define SZ(a) int((a).size())

#define SQ(a) ((a)*(a))

#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define EXIST(s,e) ((s).find(e)!=(s).end())

#define SORT(c) sort((c).begin(),(c).end())

 

 

//repetition

//------------------------------------------

#define FOR(i,s,n) for(int i=s;i<(int)n;++i)

#define REP(i,n) FOR(i,0,n)

#define MOD 1000000007

 

 

#define rep(i, a, b) for(int i = a; i < (b); ++i)

#define trav(a, x) for(auto& a : x)

#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()

 

typedef long long ll;

typedef pair<int, int> pii;

typedef vector<int> vi;

const double EPS = 1E-10;

 

#define chmin(x,y) x=min(x,y)

#define chmax(x,y) x=max(x,y)





//ここから編集

 

const int MAX = 2000010;

long long fac[MAX], finv[MAX], inv[MAX];

 

// テーブルを作る前処理

void COMinit() {

    fac[0] = fac[1] = 1;

    finv[0] = finv[1] = 1;

    inv[1] = 1;

    for (int i = 2; i < MAX; i++){

        fac[i] = fac[i - 1] * i % MOD;

        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;

        finv[i] = finv[i - 1] * inv[i] % MOD;

    }

}

 

// 二項係数計算

long long COM(int n, int k){

    if (n < k) return 0;

    if (n < 0 || k < 0) return 0;

    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;

}



int arr[100010];

int main() {

  cin.tie(0);

  ios::sync_with_stdio(false);

  cout << fixed << setprecision(10);



  int N; cin >> N;



  vector<ll> A(N);

  REP(i,N) cin >> A[i];



  ll ans = 1;

  for(int i=0; i<N; i++){

    if(A[i] == 0){

      ans *= (3-arr[A[i]]);

    }else{

      ans *= arr[A[i]-1] - arr[A[i]];

    }

    arr[A[i]]++;

    ans %= MOD;

  }

  cout << ans << endl;

  return 0;

}