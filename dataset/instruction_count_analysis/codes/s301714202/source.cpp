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

	sort(ALL(S), greater<int>());

	

	vector<vector<mint>> dp(N + 1, vector<mint>(X + 1));

	dp[0][X] = 1;

	REP(i, N) {

		REP(j, X + 1) {

			if (dp[i][j] == 0) continue;

			dp[i + 1][j] += dp[i][j] * (N - i - 1);

			dp[i + 1][j % S[i]] += dp[i][j];

		}

	}

	

	mint ans = 0;

	REP(i, X) ans += dp[N][i] * i;

	cout << ans << endl;

	return 0;

}
