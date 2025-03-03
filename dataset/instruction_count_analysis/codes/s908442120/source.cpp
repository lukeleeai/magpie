#include <cstdio>

#include <iostream>

#include <string>

#include <vector>

#include <sstream>

#include <map>

#include <set>

#include <queue>

#include <algorithm>

#include <cmath>

#include <cstring>

#include <typeinfo>

#include <numeric>

#include <functional>

#include <unordered_map>

#include <bitset>

#include <stack>

#include <assert.h>

#include <unordered_set>

#include <random>

// #include <atcoder/all>





using namespace std;

// using namespace atcoder;

using ll = long long;

using ull = unsigned long long;



const ll INF = 1e18;

const ll MOD = 1e9 + 7;





#define REP(i, n) for(ll i = 0; i < n; i++)

















































template<int MOD_>

class ModInt {

private:

public:

    long long val;

    constexpr ModInt(long long v = 0) noexcept : val(v % MOD_) {

        if (val < 0) val += MOD_;

    }

    constexpr int getmod() { return MOD_; }

    constexpr ModInt operator - () const noexcept {

        return val ? MOD_ - val : 0;

    }

    constexpr ModInt operator + (const ModInt& r) const noexcept { return ModInt(*this) += r; }

    constexpr ModInt operator - (const ModInt& r) const noexcept { return ModInt(*this) -= r; }

    constexpr ModInt operator * (const ModInt& r) const noexcept { return ModInt(*this) *= r; }

    constexpr ModInt operator / (const ModInt& r) const noexcept { return ModInt(*this) /= r; }

    constexpr ModInt operator % (const ModInt& r) const noexcept { return ModInt(*this) %= r; }

    constexpr ModInt operator ^ (const ModInt& r) const noexcept { return ModInt(*this) ^= r; }

    constexpr ModInt operator & (const ModInt& r) const noexcept { return ModInt(*this) &= r; }

    constexpr ModInt operator | (const ModInt& r) const noexcept { return ModInt(*this) |= r; }

    constexpr ModInt& operator += (const ModInt& r) noexcept {

        val += r.val;

        if (val >= MOD_) val -= MOD_;

        return *this;

    }

    constexpr ModInt& operator -= (const ModInt& r) noexcept {

        val -= r.val;

        if (val < 0) val += MOD_;

        return *this;

    }

    constexpr ModInt& operator *= (const ModInt& r) noexcept {

        val = val * r.val % MOD_;

        return *this;

    }

    constexpr ModInt& operator /= (const ModInt& r) noexcept {

        long long a = r.val, b = MOD_, u = 1, v = 0;

        while (b) {

            long long t = a / b;

            a -= t * b; swap(a, b);

            u -= t * v; swap(u, v);

        }

        val = val * u % MOD_;

        if (val < 0) val += MOD_;

        return *this;

    }

    constexpr ModInt& operator %= (const ModInt& r) noexcept {

        assert(r != 0);

        val = val % r.val;

        return *this;

    }

    constexpr ModInt& operator ^= (const ModInt& r) noexcept {

        val = (val ^ r.val) % MOD_;

        return *this;

    }

    constexpr ModInt& operator &= (const ModInt& r) noexcept {

        val = val & r.val;

        return *this;

    }

    constexpr ModInt& operator |= (const ModInt& r) noexcept {

        val = (val | r.val) % MOD_;

        return *this;

    }

    constexpr bool operator == (const ModInt& r) const noexcept {

        return this->val == r.val;

    }

    constexpr bool operator != (const ModInt& r) const noexcept {

        return this->val != r.val;

    }

    constexpr bool operator < (const ModInt& r) const noexcept {

        return this->val < r.val;

    }

    constexpr bool operator > (const ModInt& r) const noexcept {

        return this->val > r.val;

    }

    constexpr bool operator <= (const ModInt& r) const noexcept {

        return this->val <= r.val;

    }

    constexpr bool operator >= (const ModInt& r) const noexcept {

        return this->val >= r.val;

    }

    constexpr bool operator && (const ModInt& r) const noexcept {

        return this->val && r.val;

    }

    constexpr bool operator || (const ModInt& r) const noexcept {

        return this->val || r.val;

    }

    constexpr ModInt& operator ++ () noexcept {

        val = (val + 1) % MOD_;

        return *this;

    }

    constexpr ModInt operator ++ (int n) noexcept {

        ModInt<MOD_> t = *this;

        val = (val + 1) % MOD_;

        return t;

    }

    constexpr ModInt& operator -- () noexcept {

        val = (val - 1 + MOD_) % MOD_;

        return *this;

    }

    constexpr ModInt operator -- (int n) noexcept {

        ModInt<MOD_> t = *this;

        val = (val - 1 + MOD_) % MOD_;

        return t;

    }

    constexpr ModInt operator ! () noexcept {

        return val? 1 : 0;

    }

    friend constexpr ostream& operator << (ostream &os, const ModInt<MOD_>& x) noexcept {

        return os << x.val;

    }

    friend constexpr istream& operator >> (istream &is, ModInt<MOD_>& x) noexcept {

        return is >> x.val;

    }

    friend constexpr ModInt<MOD_> modpow(const ModInt<MOD_> &a, long long n) noexcept {

        if (n == 0) return 1;

        auto t = modpow(a, n / 2);

        t = t * t;

        if (n & 1) t = t * a;

        return t;

    }

};



int main(){

    ll s;

    cin >> s;

    vector<ModInt<MOD>> dp(s + 1, 0);

    dp[0] = 1;

    for(ll i = 3; i <= s; i++){

        for(ll j = 0; j <= i - 3; j++){

            dp[i] += dp[j];

        }

    }

    cout << dp[s] << endl;

}