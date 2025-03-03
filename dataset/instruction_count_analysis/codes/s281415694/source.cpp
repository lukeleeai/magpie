#include "stdc++.h"



using namespace std;

#define FOR(i,n) for(int i = 0; i < (n); i++)

#define sz(c) ((int)c.size())

#define ten(n) ((int)1e##n)

using ll = long long;



template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }

template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }

#define mygc(c) (c)=getchar_unlocked()

#define mypc(c) putchar_unlocked(c)

void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }

void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }

int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }

int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }

template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }

template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }

template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }

void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }

void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }

void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }

void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }

template<class T> void writerLn(T x) { writer(x, '\n'); }

template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }

template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }

template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }

template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }



template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

ll mod_pow(ll a, ll n, ll mod) {

	ll ret = 1;

	ll p = a % mod;

	while (n) {

		if (n & 1) ret = ret * p % mod;

		p = p * p % mod;

		n >>= 1;

	}

	return ret;

}

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }

template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }



using Pii = pair<int, int>;

using Pll = pair<ll, ll>;



const int MOD = ten(9) + 7;

const int N = ten(4);

ll inverse[N];

void init_inverse() {

	inverse[1] = 1;

	for (int i = 2; i < N; i++) inverse[i] = (MOD - MOD / i) * inverse[MOD%i] % MOD;

}



ll fact[N], infact[N];

void init_fast_fact() {

	init_inverse();

	fact[0] = fact[1] = 1;

	for (int i = 2; i < N; i++) fact[i] = fact[i - 1] * i % MOD;

	infact[0] = infact[1] = 1;

	for (int i = 2; i < N; i++) infact[i] = infact[i - 1] * inverse[i] % MOD;

}



ll fast_nCk(int n, int k) {

	if (n < 0 || k < 0) return 0;

	if (k > n) return 0;

	ll ret = fact[n] * infact[k] % MOD * infact[n - k] % MOD;

	return ret;

}





ll pseudo_catalan(int a, int b, int c) {

	if (c == a - 1) b--, c--;

	if (c == b - 1) a--, c--;

	ll ret = fast_nCk(a + b - 2, a - 1) - fast_nCk(a + b - 2, c - 1);

	if (ret < 0) ret += MOD;

	return ret;

}



void add(int& a, int b) {

	a += b;

	if (a >= MOD) a -= MOD;

}



int dp[350][350];

int solve(int n,int m) {

	init_fast_fact();

	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;

	FOR(i, n) FOR(j, n + 1) {

		if (dp[i][j] == 0) continue;

		int pv = max(j - 1, 0);

		add(dp[i + 1][pv], dp[i][j]);

		add(dp[i + 1][j+1], dp[i][j] * 2 % MOD);

	}



	ll x = mod_inv<ll>(mod_pow(2, m, MOD), MOD);

	ll ans = dp[n][m] * x % MOD;

	return (int)ans;

}



int solve2(int n, int m) {

	init_fast_fact();

	vector<ll> a = { 1, 1, 3 };

	for (int i = 3; i <= n; i++) {

		ll tmp = 3 * (i + 1) * a[i - 1] + 8 * (i - 2) * a[i - 2] - 24 * (i - 2) * a[i - 3];

		a.push_back(tmp % MOD * inverse[i + 1] % MOD);

		if (a[i] < 0) a[i] += MOD;

	}



	vector<ll> power_of_2;

	power_of_2.push_back(1);

	FOR(i, n) power_of_2.push_back(power_of_2.back() * 2 % MOD);



	ll ans = 0;

	FOR(s, n + 1) {

		const int rem = n - s;

		if (rem < m) continue;

		if ((rem - m) % 2 != 0) continue;

		const int B = (rem - m) / 2;

		const int A = rem - B;



		const ll a1 = B == 0 ? 1 : pseudo_catalan(A , B + 1, B);

		const ll a2 = power_of_2[B];

		const ll a3 = a[s];



		const ll s_ans = a1 % MOD * a2 % MOD * a3 % MOD;

		ans += s_ans;

	}



	return int(ans % MOD);

}



void test() {

	for (int n = 1; n < 300; n++) {

		for (int m = 1; m <= n; m++) {

			ll a1 = solve(n, m);

			ll a2 = solve2(n, m);

			if (a1 != a2) {

				cout << n << " " << m << endl;

				cout << "?";

			}

		}

	}

}



int main() {

	//test();

	//cout << "ok" << endl;



	int n; cin >> n;

	string s; cin >> s;

	int m = sz(s);

	int ans = solve2(n, m);

	writerLn(ans);

	solve2(n, m);



	return 0;

}