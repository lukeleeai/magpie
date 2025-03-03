#include "stdc++.h"

using namespace std;

using ll=long long;

using vi = vector<int>;

using vvi = vector<vector<int>>;

using vl = vector<ll>;

using vvl = vector<vector<ll>>;

using pl = pair<ll,ll>;

using pi = pair<int,int>;

#define all(x) x.begin(),x.end()

#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)

#define _GLIBCXX_DEBUG

const ll MOD = 1000000007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//(a+b-1)/b

//priority_queue<ll, vector<ll>, greater<ll>> q;



template<int MOD> struct Fp {  

    long long val;

    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {

        if (val < 0) val += MOD;

    }

    constexpr int getmod() { return MOD; }

    constexpr Fp operator - () const noexcept {

        return val ? MOD - val : 0;

    }

    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }

    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }

    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }

    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }

    constexpr Fp& operator += (const Fp& r) noexcept {

        val += r.val;

        if (val >= MOD) val -= MOD;

        return *this;

    }

    constexpr Fp& operator -= (const Fp& r) noexcept {

        val -= r.val;

        if (val < 0) val += MOD;

        return *this;

    }

    constexpr Fp& operator *= (const Fp& r) noexcept {

        val = val * r.val % MOD;

        return *this;

    }

    constexpr Fp& operator /= (const Fp& r) noexcept {

        long long a = r.val, b = MOD, u = 1, v = 0;

        while (b) {

            long long t = a / b;

            a -= t * b; swap(a, b);

            u -= t * v; swap(u, v);

        }

        val = val * u % MOD;

        if (val < 0) val += MOD;

        return *this;

    }

    constexpr bool operator == (const Fp& r) const noexcept {

        return this->val == r.val;

    }

    constexpr bool operator != (const Fp& r) const noexcept {

        return this->val != r.val;

    }

    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {

        return os << x.val;

    }

    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {

        if (n == 0) return 1;

        auto t = modpow(a, n / 2);

        t = t * t;

        if (n & 1) t = t * a;

        return t;

    }

};

using mint = Fp<998244353>;



signed main(){

	//cout << fixed << setprecision(10);

    int n,k; cin >> n >> k;

	vi l(k) , r(k);

	rep(i,0,k) cin >> l[i] >> r[i];

	vector<mint> dp(n+1);

	vector<mint> dpsum(n+1);

	dp[1] = 1;

	dpsum[1] = 1;

	for(int i = 2; i <= n; i++){

		rep(j,0,k){

			int li = i - r[j];

			int ri = i - l[j];

			if(ri < 1)continue;

			chmax(li , 1);

			dp[i] += dpsum[ri] - dpsum[li-1];

		}

		dpsum[i] += dpsum[i-1] + dp[i];

	}

	cout << dp[n] << endl;



	return 0;

}