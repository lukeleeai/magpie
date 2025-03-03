#include "stdc++.h"



using namespace std;



#define endl "\n"

#define fi first

#define se second

#define pb push_back

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define fastio { ios_base::sync_with_stdio(false), cin.tie(NULL); }

#define forn(i, n) for(int i = 0; i < (int)(n); i++)

#define for1(i, n) for(int i = 1; i <= (int)(n); i++)

#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)

#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)



#ifdef RICARDO

//Header here

	#include "E:\\Code\\dbg.h"

#else

	#define bug(...) "RICARDO MILOS"

#endif





template<class T> bool mini(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T> bool maxi(T &a, T b) { return a < b ? (a = b, true) : false; }



typedef pair<int, int> pii;

typedef vector<int> vi;

typedef vector<pii> vpi;

typedef vector<vi> vvi;

typedef long long i64;

typedef vector<i64> vi64;

typedef vector<vi64> vvi64;

typedef pair<i64, i64> pi64;

typedef double ld;



//=================================================CODE=================================================//

const int N = 1000;

const i64 mod = 1e9 + 7;

vvi64 F(N + 1, vi64(N + 1, 0));

vi64 fac(N + 1);



i64 pw(i64 a, i64 b) {

	i64 RES = 1;

	for(; b; b >>= 1, a = a * a % mod) if(b & 1)

		RES = (RES * a) % mod;

	return RES;

}



map<i64, i64> dp;

i64 inv(i64 x) {

	if(x == 1) return 1;

	if(dp.count(x)) return dp[x];

	return dp[x] = (mod - mod / x * inv(mod % x) % mod ) % mod;

}



i64 C(i64 n, i64 k) {

	return fac[n] * inv(fac[n - k]) % mod * inv(fac[k]) % mod;

}



signed main()

{	

	fastio;

	cout.precision(10);

	cout << fixed;

#ifdef RICARDO		

	freopen("i", "r", stdin);

#endif

	fac[0] = 1;

	for1(i, N) fac[i] = (fac[i - 1] * i) % mod;



	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;

	int cnt = 0;

	F[a - 1][0] = 1;

	fore(i, a, b) forn(j, n + 1) {

		F[i][j] = F[i - 1][j];

		fore(k, c, d) {

			if(i * k > j) break;

			i64 temp = C(j, i * k) * fac[i * k] % mod * inv(pw(fac[i], k)) % mod * inv(fac[k]) % mod;

			F[i][j] = (F[i][j] + F[i - 1][j - i * k] * temp % mod) % mod;                  

		}

	}



	cout << F[b][n] << endl;

#ifdef RICARDO

	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

#endif

}