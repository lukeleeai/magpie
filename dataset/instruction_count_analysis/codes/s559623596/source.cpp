// #pragma GCC optimize ("O3")

// #pragma GCC target ("sse4")



#include "stdc++.h"

using namespace std;

const int INF = 1 << 29;

const int NINF = -1*INF;

const long long LLINF = 1ll << 60;

const long long LLNINF = -1*LLINF;



template <class Ch, class Tr, class Container>

basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {

    os << "{ ";

    for(auto& y : x) os << y << " ";

    return os << "}";

}



template <class X, class Y>

ostream & operator << (ostream & os, pair <X, Y> const& p) {

	return os << "[ " << p.first << ", " << p.second << "]" ;

}



typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

 

typedef pair<int, int> pi;

typedef pair<ll,ll> pll;

typedef pair<ld,ld> pd;



typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<double> vd;

typedef vector<ld> vld;

typedef vector<pi> vpi;

typedef vector<pll> vpll;

typedef vector<vector<int>> vvi;

typedef vector<vll> vvll;

typedef vector<vd> vvd;

typedef vector<vld> vvld;

 

#define mp make_pair

#define pb push_back

#define pf push_front

#define all(x) x.begin(), x.end()

#define revAll(x) x.rbegin(), x.rend()

#define gcd(a, b) __gcd(a, b)

#define popcount(x) __builtin_popcount(x)

#define isize(x) (int)(x.size())

#define rep(i,n) for(int i = 0; i < n; i++)

#define umap unordered_map

#define uset unordered_set

#define pq priority_queue



const ll MOD = 1e9 + 7;



template<class... Args>

auto nvect(size_t n, Args&&... args) {

	if constexpr(sizeof...(args) == 1)

		return vector(n, args...);

	else

		return vector(n, nvect(args...));

}





int main(){

	ios_base::sync_with_stdio(false);cin.tie(0);

	int n; cin >> n;

	auto dp = nvect<ll>(n+1, 2, 2, 0);

	dp[0][0][0] = 1;

	rep(i, n)rep(j, 2)rep(k, 2)rep(d, 10){

		int nj = int(d == 0 or j);

		int nk = int(d == 9 or k);

		dp[i+1][nj][nk] += dp[i][j][k];

		dp[i+1][nj][nk] %= MOD;

	}

	cout << dp[n][1][1];

}