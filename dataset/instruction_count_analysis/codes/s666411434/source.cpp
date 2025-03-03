#pragma GCC optimize("Ofast")

#define _USE_MATH_DEFINES

#include "bits/stdc++.h"



using namespace std;



using u8 = uint8_t;

using u16 = uint16_t;

using u32 = uint32_t;

using u64 = uint64_t;

using i8 = int8_t;

using i32 = int32_t;

using i64 = int64_t;



constexpr char newl = '\n';

constexpr double eps = 1e-10;



#define FOR(i,a,b) for (int i = (a); i < (b); i++)

#define F0R(i,b) FOR(i,0,b)

#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)

#define RF0(i,b) RFO(i,0,b)

//#define fi first

//#define se second

#define debug(x) cout << #x << ": " << x << '\n';

#define rng(a) a.begin(),a.end()

#define rrng(a) a.rbegin(),a.rend()



template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }

template<class T> void Print(vector<T> v) {

  F0R(i, v.size()) {

    cout << v[i] << ' ';

  }

  cout << newl;

}



#if 1



constexpr int MOD = 1e9 + 7; // 1e9 + 7



struct Factorial {



  int modpow(int a, u64 n) noexcept {

    if (n == 0) return 1;

    auto t = modpow(a, n / 2);

    t = (int)((i64)t * t % mod);

    if (n & 1) t = (int)((i64)t * a % mod);

    return t;

  }



  Factorial(int count, int mod) : mod(mod) {



    f.reserve(count + 1);

    fi.reserve(count + 1);



    f.push_back(1);

    fi.push_back(1);

    FOR(i, 1, count + 1) {

      f.push_back((int)(((i64)f[i - 1] * i) % mod));

      fi.push_back(modpow(f[i], mod - 2));

      //cout << i << " " << f[i] << " " << fi[i] << newl;

    }

    f[0] = 0;

  }



  int Ncr(int n, int r) {

    //debug(f[n]);

    //debug(fi[r]);

    //debug(fi[n - r]);

    return (int)((i64)f[n] * fi[r] % mod * fi[n - r] % mod);

  }



  // 自分では何が起きているか分かっていないmod除算

  // - mod が素数じゃないと動かない模様

  // - 4 / 2 を mod100 で計算したら 4 になった

  int Div(int l, int r) noexcept {

    long long a = r, b = mod, u = 1, v = 0;

    while (b) {

      long long t = a / b;

      a -= t * b; swap(a, b);

      u -= t * v; swap(u, v);

    }

    l = l * u % mod;

    if (l < 0) l += mod;

    return l;

  }

  // こちらも mod が素数じゃないと動かない様子

  // - 4 / 2 を mod100 で計算したら 76 になった

  /*

  int Div(int l, int r) noexcept {

    return l * modpow(r, mod - 2) % mod;

  }

  */



  int mod;



  // 階乗

  vector<int> f;



  // 階乗の逆元

  vector<int> fi;

};

template<int MOD> struct Modint {

  long long val;

  constexpr Modint(long long v = 0) noexcept : val(v% MOD) {

    if (val < 0) val += MOD;

  }

  constexpr int getmod() { return MOD; }

  constexpr Modint operator - () const noexcept {

    return val ? MOD - val : 0;

  }

  constexpr Modint operator + (const Modint& r) const noexcept { return Modint(*this) += r; }

  constexpr Modint operator - (const Modint& r) const noexcept { return Modint(*this) -= r; }

  constexpr Modint operator * (const Modint& r) const noexcept { return Modint(*this) *= r; }

  constexpr Modint operator / (const Modint& r) const noexcept { return Modint(*this) /= r; }

  constexpr Modint& operator += (const Modint& r) noexcept {

    val += r.val;

    if (val >= MOD) val -= MOD;

    return *this;

  }

  constexpr Modint& operator -= (const Modint& r) noexcept {

    val -= r.val;

    if (val < 0) val += MOD;

    return *this;

  }

  constexpr Modint& operator *= (const Modint& r) noexcept {

    val = val * r.val % MOD;

    return *this;

  }

  constexpr Modint& operator /= (const Modint& r) noexcept {

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

  constexpr bool operator == (const Modint& r) const noexcept {

    return this->val == r.val;

  }

  constexpr bool operator != (const Modint& r) const noexcept {

    return this->val != r.val;

  }

  friend constexpr ostream& operator << (ostream& os, const Modint<MOD>& x) noexcept {

    return os << x.val;

  }

  friend constexpr Modint<MOD> modpow(const Modint<MOD>& a, long long n) noexcept {

    if (n == 0) return 1;

    auto t = modpow(a, n / 2);

    t = t * t;

    if (n & 1) t = t * a;

    return t;

  }



  friend constexpr Modint<MOD> Ncr(Modint<MOD> a, int n) {

    Modint<MOD> p = 1, q = 1;



    while (n > 0) {

      p *= a;

      a -= 1;

      q *= n--;

    }



    return p / q;

  }

};

template<int MOD>

using mint = Modint<MOD>;





// INSERT ABOVE HERE

signed main() {

  cin.tie(0);

  ios_base::sync_with_stdio(false);



  // f(r,c) = r+cCr = (r+c)! / r! / c!



  // abc+ade = a(bc+de)



  // 分子

  //  (r+c)!  (r+c+1)! (r+c+2)!

  //

  // (r+c+1)! (r+c+2)!

  //

  // (r+c+2)!



  // 分母

  //   r!c!     r!(c+1)!    r!(c+2)!

  //

  // (r+1)!c! (r+1)!(c+1)!

  //

  // (r+2)!c!



  // r1 = 0, c1 = 0 なら計算できるか？

  // r1 = 0, c1 = 0 での r2, c2 に対する解を g(r2, c2)とする



  // 0C0 1C0 2C0

  // 1C1 2C1 3C1

  // 2C2 3C2 4C2



  // f(r,c)

  // 1 1  1  1

  // 1 2  3  4

  // 1 3  6 10

  // 1 4 10 20

  //

  // g(r,c)

  // 1  2  3  4

  // 2  5  9 14

  // 3  9 19 34

  // 4 14 34 69



  //           r  c

  // g(r,c) = Σ Σ (a+b)Ca

  //          a=0 b=0



  // 分子

  // 0! 1! 2!

  // 1! 2! 3!

  // 2! 3! 4!



  // 分母

  // 0!0! 0!1! 0!2!

  //

  // 1!0! 1!1!

  //

  // 2!0!



  // 解説を読む

  //

  //           c

  // f(r,c) = Σ f(r-1,a)

  //          a=0

  // これを用いると、g(r,c)の計算がO(N^2)からO(N)になる







  int r1, c1, r2, c2;

  cin >> r1 >> c1 >> r2 >> c2;



  Factorial fc(r2 + c2 + 1, MOD);



  auto g = [&fc](int r, int c)->mint<MOD> {

    mint<MOD> rs = 0;

    F0R(i, r + 1) {

      rs += fc.Ncr(i + 1 + c, c);

    }

    return rs;

  };



  mint<MOD> result = g(r2, c2) - g(r2, c1 - 1) - g(r1 - 1, c2) + g(r1 - 1, c1 - 1);

  cout << result.val;

}

#endif
