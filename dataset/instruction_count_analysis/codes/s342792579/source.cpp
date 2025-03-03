// #pragma GCC optimize("Ofast")

// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include "stdc++.h"

#define SIZE 300005

#define MOD 1000000007LL

#define EPS 1e-10

#define INF 2147483647

#define LLINF 9223372036854775807LL

#define REP(i,n) for(int i=0;i<n;i++)

#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define DOWN(i,b,a) for(int i=b;i>=a;i--)

#define SET(a,c) memset(a,c,sizeof a)

#define BIT(i,j) ((i)>>(j))&1

#define ALL(o) (o).begin(), (o).end()

#define ERASE(o) (o).erase(unique((o).begin(),(o).end()), (o).end())

#define SQ(x) ((x)*(x))

using namespace std;

typedef int_fast64_t ll;

typedef pair<ll,ll> Pll;

typedef pair<int, int> Pii;

typedef pair<double, double> Pdd;

typedef complex<double> dcomplex;

template<typename T> inline void priv(vector<T>a){REP(i,a.size()){cerr<<a[i]<<((i==a.size()-1)?"\n":" ");}}

inline void fastio(){cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15);}

ll gcd(ll a,ll b){ll c=max(a,b);ll d=min(a,b);return c==0||d==0?c:gcd(c%d,d);}

ll lcm(ll a,ll b){return a==0||b==0?0:a*b/gcd(a,b);}



template<int N, typename T, T M>

struct ModFact {

    T inv[N+1];

    T fact[N+1];

    T ifact[N+1];

    constexpr ModFact() : fact(), ifact() {

        fact[0] = 1;

        for (int i = 0; i < N; i++)

            fact[i+1] = (fact[i]*(i+1))%M;

        ifact[N] = power(fact[N], M-2);

        for (int i = N-1; i >= 0; i--)

            ifact[i] = (ifact[i+1]*(i+1))%M;

        inv[0] = 0;

        for (int i = 0; i < N; i++)

            inv[i+1] = (fact[i]*ifact[i+1])%M;

    }

    constexpr T power(T a, T b) {

        T r = 1;

        while (b>0) {

            if((b&1)!=0) r = (r*a)%M;

            a = (a*a)%M;

            b >>= 1;

        }

        return r;

    }

    constexpr T comb(T n, T r) {

        return (((fact[n]*ifact[r])%M)*ifact[n-r])%M;

    }

};

 

ModFact<100000, ll, MOD> fact;



ll N;

ll X[100001];



int main() {

    fastio();

    ll N, ans = 0;

    cin >> N;

    REP(i, N) cin >> X[i];

    ll a = 0;

    REP(i, N-1) {

        a = (a + fact.inv[i+1]) % MOD;

        ans = (ans + a * (X[i+1] - X[i])) % MOD;

    }

    cout << (ans * fact.fact[N-1])%MOD << "\n";

	return 0;

}
