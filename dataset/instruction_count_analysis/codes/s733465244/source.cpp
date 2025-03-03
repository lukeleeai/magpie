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

constexpr ll MOD = 998244353;

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

	int A, B, C, D;

	cin >> A >> B >> C >> D;

	

	vector<vector<vector<mint>>> dp(C + 1, vector<vector<mint>>(D + 1, vector<mint>(4)));

	dp[A][B][0] = 1;

	

	FOR(i, A, C + 1) FOR(j, B, D + 1) {

		REP(k, 4) { // 1:u, 2:r

			if (dp[i][j][k] == 0) continue;

			

			if (k == 3) {

				mint cur = 0;

				REP(l, 4) cur += dp[i - 1][j - 1][l];

				dp[i][j][k] -= cur * (i - 1) * (j - 1);

			}

			

			if (i < C) {

				dp[i + 1][j][k | 1] += dp[i][j][k] * (j - 1);

				if (k >> 2 & 1) dp[i + 1][j][(k | 1) & (3 ^ 2)] += dp[i][j][k];

				else dp[i + 1][j][k | 1] += dp[i][j][k];

			}

			if (j < D) {

				dp[i][j + 1][k | 2] += dp[i][j][k] * (i - 1);

				if (k >> 1 & 1) dp[i][j + 1][(k | 2) & (3 ^ 1)] += dp[i][j][k];

				else dp[i][j + 1][k | 2] += dp[i][j][k];

			}

		}

	}

	mint ans = 0;

	REP(k, 4) ans += dp[C][D][k];

	cout << ans << endl;

	return 0;

}
