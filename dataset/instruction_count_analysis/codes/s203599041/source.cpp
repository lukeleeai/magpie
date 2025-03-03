#include "stdc++.h"

using namespace std;

#pragma warning (disable:4996)

#ifndef constexpr

#define constexpr const

#endif // !constexpr



using ll = long long;

using LL = ll;

using ull = unsigned long long;

using uLL = ull;

using pii = pair<int, int>;

#define clean_0(A) memset((A),0,sizeof(A))

#define clean_1(A) memset((A),-1,sizeof(A))

constexpr int INF = 0x7F7F7F7F;

#define clean_INF(A) memset((A),INF,sizeof(A))

#define For(i,a,b) for(int (i)=(a);(i)<=b;++(i))



constexpr double eps = 1e-9;



constexpr ll mod1 = 197;

constexpr ll mod2 = 19260817;

constexpr ll mod3 = ll(1e8) + 7;

constexpr ll mod4 = ll(1e9) + 7;;

constexpr ll mod5 = 998244353;

constexpr ll mod = mod4;

constexpr int maxn = int(1e5) + 1;

constexpr int MAXN = maxn;

//#define Enable_IO

//#define Enable_MATH



#ifdef Enable_IO

namespace io

{

#define in(a) (a=read())

#define out(a) write(a)

#define outn(a) (out(a),putchar('\n'))

#define I_int  int

	inline I_int read() {

		I_int x = 0, f = 1; char c = getchar();

		while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }

		while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }

		return x * f;

	}

	template<typename T>

	bool scan_d(T& ret)

	{

#define p(x) ((x)>='0'&&(x)<='9')

		int c; int sgn;

		if (c = getchar(), c == EOF)return false;

		while (c != '-' && !p(c))c = getchar();

		sgn = (c == '-') ? -1 : 1;

		ret = (c == '-') ? 0 : c - '0';

		while (c = getchar(), p(c))ret = ret * 10 + c - '0';

		ret *= sgn;

		return true;

#undef p

	}

	char F[200];

	template<typename T>

	inline void write(T x) {

		if (x == 0) { putchar('0'); return; }

		auto tmp = x > 0 ? x : -x;

		if (x < 0) putchar('-');

		int sum = 0;

		while (tmp > 0) {

			F[sum++] = tmp % 10 + '0';

			tmp /= 10;

		}

		while (sum > 0) putchar(F[--sum]);

	}

	void read(char* s, int Arr[], size_t n)

	{

		for (size_t i = 0; i < n; ++i)Arr[i] = strtoll(s, &s, 10);

	}

#undef I_int

}

using namespace io;

#endif // Enable_IO



#ifdef Enable_MATH

template<typename T> constexpr T ModUp(const T& x, ll Mod = mod) { return (x % Mod + Mod) % Mod; }

template<typename T>

constexpr T exgcd(T a, T b, T& x, T& y)

{

	if (a == 0 && b == 0)return -1;

	if (b == 0) { x = 1, y = 0; return a; }

	T d = exgcd(b, a % b, y, x);

	y -= a / b * x;

	return d;

}

template<typename T>

constexpr T inv1(T a, T Mod = mod)

{

	T x = -1, y = -1;

	return exgcd(a, Mod, x, y) == 1 ? (x % Mod + Mod) % Mod : -1;

}

template<typename T>

constexpr T _gcd(T a, T b)

{

	return b ? _gcd(b, a % b) : a;

}

template<typename T>

constexpr T combinator(T n, T m, T Mod = mod - 1)

{

	m = min(m, n - m);

	T ret = 1;

	for (T i = 1; i <= m; ++i)

	{

		ret = ret * (n - m + i) / i % Mod;

	}

	return ret;

}

template<typename T>

constexpr T poww(T a, T b, T Mod = mod)

{

	T ret = 1;

	a %= Mod;

	b %= Mod - 1;

	if (b < 0)b += Mod - 1;

	while (b)

	{

		if (b & 1)ret = ret * a % Mod;

		a = a * a % Mod;

		b >>= 1;

	}

	return ret;

}

constexpr ll inv2(ll a, ll Mod = mod)

{

	return poww(a, Mod - 2, Mod);

}

struct Combinator1

{

	static constexpr int Mod = ::mod;

	static constexpr int Maxn = 1;//::maxn;

	int dp[Maxn][Maxn];//this is C(n,m)%(mod-1)

	constexpr Combinator1() :dp()

	{

		for (int i = 0; i < Maxn; ++i)

		{

			for (int k = 0; k <= i; ++k)

			{

				if (k == 0) dp[i][k] = 1;

				else if (i == k) dp[i][k] = 1;

				else dp[i][k] = (dp[i - 1][k] + dp[i - 1][k - 1]) % (Mod - 1);

			}

		}

	}

};

struct Combinator2

{

	static constexpr int Mod = ::mod;

	static constexpr int Maxn = ::maxn;

	ll Fact[Maxn], Inv_Fact[Maxn];

	constexpr Combinator2(const int n = Maxn - 1) :Fact(), Inv_Fact()

	{

		Fact[0] = 1;

		for (int i = 1; i <= n; ++i)

			Fact[i] = Fact[i - 1] * i % Mod;

		Inv_Fact[0] = 1;

		Inv_Fact[n] = inv2(Fact[n], Mod);

		for (int i = n; i > 1; --i)

			Inv_Fact[i - 1] = Inv_Fact[i] * i % Mod;

	}

	constexpr ll Comb(int a, int b)const

	{

		if (a < 0 || b < 0)return 1;

		return Fact[a] * Inv_Fact[b] % Mod * Inv_Fact[a - b] % Mod;

	}

};

#endif // Enable_MATH

int cnt[2][maxn];

int main()

{

	int n;

	ios::sync_with_stdio(false);

	while (cin >> n)

	{

		clean_0(cnt);

		int x;

		for (int i = 0; i < n; ++i)

		{

			cin >> x;

			++cnt[i & 1][x];

		}

		int ans = 0;

		int max_0 = max_element(cnt[0], cnt[0] + maxn) - cnt[0];

		int max_1 = max_element(cnt[1], cnt[1] + maxn) - cnt[1];

		if (max_1 != max_0)

		{

			ans = n - cnt[0][max_0] - cnt[1][max_1];

		}

		else

		{

			int m0 = cnt[0][max_0];

			int m1 = cnt[1][max_1];

			cnt[0][max_0] = cnt[1][max_1] = 0;

			max_0 = max_element(cnt[0], cnt[0] + maxn) - cnt[0];

			max_1 = max_element(cnt[1], cnt[1] + maxn) - cnt[1];

			ans = n - max(cnt[0][max_0] + m1, m0 + cnt[1][max_1]);

		}

		cout << ans << endl;

	}

}