#include "stdc++.h"

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n) FOR(i,0,n)

#define ALL(v) begin(v),end(v)

#define fi first

#define se second

template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }

template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;

using pii = pair<int, int>;

constexpr ll INF = 1ll<<30;

constexpr ll longINF = 1ll<<60;

constexpr ll MOD = 1000000007;

constexpr bool debug = 0;

//---------------------------------//



template<int M>

struct ModInt {

public:

	using value_type = long long;

	

	ModInt(value_type val = 0) : val(val < 0 ? (M - (-val % M)) % M : val % M) {}

	

	explicit operator bool() const noexcept { return val; }

	bool operator ==(const ModInt & rhs) const noexcept { return val == rhs.val; }

	bool operator !=(const ModInt & rhs) const noexcept { return !(*this == rhs); }

	ModInt operator +() const noexcept { return ModInt(*this); }

	ModInt operator -() const noexcept { return ModInt(0) -= *this; }

	ModInt operator +(const ModInt & rhs) const noexcept { return ModInt(*this) += rhs; }

	ModInt operator -(const ModInt & rhs) const noexcept { return ModInt(*this) -= rhs; }

	ModInt operator *(const ModInt & rhs) const noexcept { return ModInt(*this) *= rhs; }

	ModInt operator /(const ModInt & rhs) const noexcept { return ModInt(*this) /= rhs; }

	

	ModInt & operator +=(const ModInt & rhs) noexcept {

		val += rhs.val;

		if (val >= M) val -= M;

		return *this;

	}

	ModInt & operator -=(const ModInt & rhs) noexcept {

		if (val < rhs.val) val += M;

		val -= rhs.val;

		return *this;

	}

	ModInt & operator *=(const ModInt & rhs) noexcept {

		val = val * rhs.val % M;

		return *this;

	}

	ModInt & operator /=(const ModInt & rhs) noexcept {

		*this *= rhs.inverse();

		return *this;

	}

	

	ModInt pow(value_type n) const {

		ModInt res = 1, x = val;

		if (n < 0) { x = x.inverse(); n = -n; }

		while (n) { if (n & 1) res *= x; x *= x; n >>= 1; }

		return res;

	}

	

	ModInt inverse() const {

		long long a = val, a1 = 1, a2 = 0, b = M, b1 = 0, b2 = 1;

		while (b > 0) {

			value_type q = a / b, r = a % b;

			value_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;

			a = b; b = r;

			a1 = b1; b1 = nb1;

			a2 = b2; b2 = nb2;

		}

		assert(a == 1);

		return a1;

	}

	

	const value_type & get() const noexcept { return val; }

	static decltype(M) get_mod() noexcept { return M; }

	

	friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val; }

	friend std::istream & operator >>(std::istream & is, ModInt & rhs) {

		value_type x;

		is >> x;

		rhs = ModInt(x);

		return is;

	}

private:

	value_type val;

};

using mint = ModInt<MOD>;



int main() {

	int N, X;

	cin >> N >> X;

	vector<int> S(N);

	REP(i, N) scanf("%d", &S[i]);

	sort(ALL(S));

	

	constexpr int MAX_S = 100000;

	

	vector<int> rsum(MAX_S + 2); // i 以上の要素数

	REP(i, N) ++rsum[S[i]];

	for (int i = MAX_S + 1; i > 0; --i) rsum[i - 1] += rsum[i];

	

	vector<vector<mint>> dp(X + 1, vector<mint>(N + 1)); // 現在の数, 使った個数

	dp[X][0] = 1;

	mint ans = 0;

	for (int i = X; i > 0; --i) {

		REP(j, N) {

			if (dp[i][j] == 0) continue;

			int can = rsum[i + 1] - j;

			if (can > 0) dp[i][j + 1] += dp[i][j] * can;

			

			REP(k, N) {

				if (S[k] > i) break;

				dp[i % S[k]][j + 1] += dp[i][j];

			}

		}

		ans += dp[i][N] * i;

	}

	cout << ans << endl;

	return 0;

}
