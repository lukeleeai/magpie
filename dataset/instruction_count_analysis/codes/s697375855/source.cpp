#include "stdc++.h"

using namespace std;



# define REP(i,n) for (int i=0;i<(n);++i)

# define PER(i,n) for (int i=(N-1);i>=0;--i)

# define rep(i,a,b) for(int i=a;i<(b);++i)

# define p(s) std::cout << s ;

# define pl(s)  std::cout << s << endl;

# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;

# define YES(j) cout << (j ? "YES" : "NO") << endl;

# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;

# define yes(j) std::cout << (j ? "yes" : "no") << endl;

# define all(v) v.begin(),v.end()

# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")

template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}

template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}

typedef long long int ll;

typedef pair<ll,ll> P_ii;

typedef pair<double,double> P_dd;



template<class T>

vector<T> make_vec(size_t a){

    return vector<T>(a);

}



template<class T, class... Ts>

auto make_vec(size_t a, Ts... ts){

  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));

}



template<typename T,typename V>

typename enable_if<is_class<T>::value==0>::type

fill_v(T &t,const V &v){t=v;}



template<typename T,typename V>

typename enable_if<is_class<T>::value!=0>::type

fill_v(T &t,const V &v){

  for(auto &e:t) fill_v(e,v);

}





const int MOD = 1000000007;

const int inf=1e9+7;

const ll longinf=1LL<<60 ;



void addM(long long &a, long long b) {

    a += b;

    if (a >= MOD) a -= MOD;

}



void mulM(long long &a, long long b) {

    a = ((a%MOD)*(b%MOD))%MOD ;

}



const int MAX = 510000;

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



vector<pair<long long, long long> > prime_factorize(long long n) {

    vector<pair<long long, long long> > res;

    for (long long p = 2; p * p <= n; ++p) {

        if (n % p != 0) continue;

        int num = 0;

        while (n % p == 0) { ++num; n /= p; }

        res.push_back(make_pair(p, num));

    }

    if (n != 1) res.push_back(make_pair(n, 1));

    return res;

}



vector<int> g[200005];

vector<ll> val(200005, 0);

vector<ll> ans(200005, 0);



void dfs(int v, int p){

    ans[v] = val[v] + (p != -1 ? ans[p] : 0);

    for(auto&& s : g[v]) {

        if(s == p) continue;

        dfs(s, v);

    }

}



int main() {

    ll N;

    cin >> N;



    cout << N * (N-1) / 2 << endl;



    return 0;

}