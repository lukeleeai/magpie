#ifdef ConanYu

#include "local.hpp"

#else

#pragma GCC optimize("-O3")

#include "stdc++.h"

using namespace std;

typedef long long ll;

void Main();

#define debug(...) do { } while(0)

int main() {

  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

  Main();

}

#endif



const int MOD = 1e9 + 7;



namespace fft {

  const double pi = acos(-1.0);

  struct Complex {

    double r, i;

    Complex(double x = 0, double y = 0) : r(x), i(y) {}

    Complex operator+ (const Complex& b) const {

      return Complex(r + b.r, i + b.i);

    }

    Complex operator- (const Complex& b) const {

      return Complex(r - b.r, i - b.i);

    }

    Complex operator* (const Complex& b) const {

      return Complex(r * b.r - i * b.i, r * b.i + i * b.r);

    }

  };

  Complex conj(Complex a) { return Complex(a.r, -a.i); }



  int base = 1;

  vector<int> rev = { 0, 1 };

  vector<Complex> roots = { { 0, 0 }, { 1, 0 } };

  

  void ensure_base(int nbase) {

    if (nbase <= base) return;

    rev.resize(1 << nbase);

    for (int i = 0; i < (1 << nbase); i++) {

      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));

    }

    roots.resize(1 << nbase);

    while (base < nbase) {

      double angle = 2 * pi / (1 << (base + 1));

      for (int i = 1 << (base - 1); i < (1 << base); i++) {

        roots[i << 1] = roots[i];

        double angle_i = angle * (2 * i + 1 - (1 << base));

        roots[(i << 1) + 1] = Complex(cos(angle_i), sin(angle_i));

      }

      base++;

    }

  }

  void fft(vector<Complex> &a, int n = -1) {

    if (n == -1) {

      n = a.size();

    }

    assert((n & (n - 1)) == 0);

    int zeros = __builtin_ctz(n);

    ensure_base(zeros);

    int shift = base - zeros;

    for (int i = 0; i < n; i++) {

      if (i < (rev[i] >> shift)) {

        swap(a[i], a[rev[i] >> shift]);

      }

    }

    for (int k = 1; k < n; k <<= 1) {

      for (int i = 0; i < n; i += 2 * k) {

        for (int j = 0; j < k; j++) {

          Complex z = a[i + j + k] * roots[j + k];

          a[i + j + k] = a[i + j] - z;

          a[i + j] = a[i + j] + z;

        }

      }

    }

  }



  vector<Complex> fa, fb;

  template<typename T>

  vector<T> multiply(const vector<T> &a, const vector<T> &b) {

    int need = a.size() + b.size() - 1;

    int nbase = need > 1 ? 32 - __builtin_clz(need - 1) : 0;

    ensure_base(nbase);

    int sz = 1 << nbase;

    if (sz > (int) fa.size()) {

      fa.resize(sz);

    }

    for (int i = 0; i < sz; i++) {

      int x = (i < (int) a.size() ? a[i] : 0);

      int y = (i < (int) b.size() ? b[i] : 0);

      fa[i] = Complex(x, y);

    }

    fft(fa, sz);

    Complex r(0, -0.25 / sz);

    for (int i = 0; i <= (sz >> 1); i++) {

      int j = (sz - i) & (sz - 1);

      Complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;

      if (i != j) {

        fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;

      }

      fa[i] = z;

    }

    fft(fa, sz);

    vector<T> res(need);

    for (int i = 0; i < need; i++) {

      res[i] = fa[i].r + 0.5; // watch out that fa[i].r < 0

    }

    return res;

  }

  vector<int> multiply_mod(const vector<int> &a, const vector<int> &b, int m, int eq = 0) {

    int need = a.size() + b.size() - 1;

    int nbase = need > 1 ? 32 - __builtin_clz(need - 1) : 0;

    ensure_base(nbase);

    int sz = 1 << nbase;

    if (sz > (int) fa.size()) {

      fa.resize(sz);

    }

    for (int i = 0; i < (int) a.size(); i++) {

      int x = (a[i] % m + m) % m;

      fa[i] = Complex(x & ((1 << 15) - 1), x >> 15);

    }

    fill(fa.begin() + a.size(), fa.begin() + sz, Complex {0, 0});

    fft(fa, sz);

    if (sz > (int) fb.size()) {

      fb.resize(sz);

    }

    if (eq) {

      copy(fa.begin(), fa.begin() + sz, fb.begin());

    } else {

      for (int i = 0; i < (int) b.size(); i++) {

        int x = (b[i] % m + m) % m;

        fb[i] = Complex(x & ((1 << 15) - 1), x >> 15);

      }

      fill(fb.begin() + b.size(), fb.begin() + sz, Complex {0, 0});

      fft(fb, sz);

    }

    double ratio = 0.25 / sz;

    Complex r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);

    for (int i = 0; i <= (sz >> 1); i++) {

      int j = (sz - i) & (sz - 1);

      Complex a1 = (fa[i] + conj(fa[j]));

      Complex a2 = (fa[i] - conj(fa[j])) * r2;

      Complex b1 = (fb[i] + conj(fb[j])) * r3;

      Complex b2 = (fb[i] - conj(fb[j])) * r4;

      if (i != j) {

        Complex c1 = (fa[j] + conj(fa[i]));

        Complex c2 = (fa[j] - conj(fa[i])) * r2;

        Complex d1 = (fb[j] + conj(fb[i])) * r3;

        Complex d2 = (fb[j] - conj(fb[i])) * r4;

        fa[i] = c1 * d1 + c2 * d2 * r5;

        fb[i] = c1 * d2 + c2 * d1;

      }

      fa[j] = a1 * b1 + a2 * b2 * r5;

      fb[j] = a1 * b2 + a2 * b1;

    }

    fft(fa, sz);

    fft(fb, sz);

    vector<int> res(need);

    for (int i = 0; i < need; i++) {

      long long aa = fa[i].r + 0.5;

      long long bb = fb[i].r + 0.5;

      long long cc = fa[i].i + 0.5;

      res[i] = (aa + ((bb % m) << 15) + ((cc % m) << 30)) % m;

    }

    return res;

  }

  vector<int> square_mod(const vector<int> &a, int m) {

    return multiply_mod(a, a, m, 1);

  }

}



typedef pair<ll, ll> pll;

pll exgcd(const long long x, const long long y) {

  if (!y) return {1, 0};

  pll cur = exgcd(y, x % y);

  return {cur.second, cur.first - (x / y) * cur.second};

}



namespace poly {

  int MOD = 1e9 + 7;

  

  // 多项式求逆 O(nlog(n))

  vector<int> inv(const vector<int> &a) {

    if(a.size() == 1) {

      const int inv = exgcd(a[0], MOD).first;

      return vector<int>(1, inv < 0 ? inv + MOD : inv);

    }

    const int na = a.size(), nb = (na + 1) >> 1;

    vector<int> b(a.begin(), a.begin() + nb);

    b = inv(b);

    vector<int> c = fft::multiply_mod(b, b, MOD);

    c.resize(na);

    c = fft::multiply_mod(a, c, MOD);

    b.resize(na), c.resize(na);

    for(int i = 0; i < na; i++) {

      c[i] = (((2ll * b[i] - c[i]) % MOD) + MOD) % MOD;

    }

    return c;

  }

  

  // A = B * C + D (mod x^n) (n = A.size())

  // always use with the next function mod

  // make sure A.size() >= B.size() or else it will return an empty vector

  // O(nlog(n))

  vector<int> divide(const vector<int> &a, const vector<int> &b) {

    const int n = a.size(), m = b.size();

    if(n < m) return {};

    vector<int> A(a), B(b);

    reverse(A.begin(), A.end()), reverse(B.begin(), B.end());

    A.resize(n - m + 1), B.resize(n - m + 1);

    B = inv(B);

    vector<int> C = fft::multiply_mod(A, B, MOD);

    C.resize(n - m + 1), reverse(C.begin(), C.end());

    return C;

  }

  

  // O(nlog(n))

  vector<int> mod(const vector<int> &a, const vector<int> &b, const vector<int> &c) {

    const int n = a.size(), m = b.size();

    if(n < m) return a;

    vector<int> e = fft::multiply_mod(b, c, MOD);

    e.resize(m - 1);

    for(int i = 0; i < m - 1; i++) {

      e[i] = a[i] - e[i];

      if(e[i] < 0) {

        e[i] += MOD;

      }

    }

    return e;

  }



  // 多项式对数函数 O(nlog(n))

  vector<int> ln(const vector<int> &a) {

    const int n = a.size();

    vector<int> ap(a);

    for(int i = 0; i < n - 1; i++) {

      ap[i] = 1ll * ap[i + 1] * (i + 1) % MOD;

    }

    ap.resize(n - 1);

    vector<int> b = fft::multiply_mod(inv(a), ap, MOD);

    b.resize(n);

    vector<int> INV(n);

    INV[1] = 1;

    for(int i = 2; i < n; i++) {

      INV[i] = 1ll * INV[MOD % i] * (MOD - MOD / i) % MOD;

    }

    for(int i = n - 1; i > 0; i--) {

      b[i] = 1ll * b[i - 1] * INV[i] % MOD;

    }

    b[0] = 0;

    return b;

  }



  vector<int> _exp(const vector<int> &a, const int &n) {

    if(n == 1) return vector<int> (1, 1);

    int t = (n + 1) >> 1;

    vector<int> b = _exp(a, t);

    b.resize(n);

    vector<int> tmp = ln(b);

    for(int i = 0; i < n; i++) {

      tmp[i] = a[i] - tmp[i];

      if(tmp[i] < 0) tmp[i] += MOD;

    }

    tmp[0] = (tmp[0] == MOD - 1 ? 0 : tmp[0] + 1);

    vector<int> ret = fft::multiply_mod(b, tmp, MOD);

    ret.resize(n);

    return ret;

  }



  // 多项式指数函数 O(nlog^2(n))

  vector<int> exp(const vector<int> &a) {

    assert(a.size() != 0);

    return _exp(a, int(a.size()));

  }



  // 构造一个多项式 \prod_{i=left}^{right} (x-vec_i)

  vector<int> buildPoly(const vector<int> &vec, const int left, const int right) {

    if(left == right) {

      vector<int> ret;

      ret.push_back(MOD - vec[left]);

      ret.push_back(1);

      return ret;

    }

    const int mid = (left + right) >> 1;

    return fft::multiply_mod(buildPoly(vec, left, mid), buildPoly(vec, mid + 1, right), MOD);

  }



  void multipointCalc(const vector<int> &poly, const vector<int> &vec, const int left, const int right, vector<int> &ret) {

    const int n = poly.size(), mid = (left + right) >> 1;

    if(n == 1) {

      for(int i = left; i <= right; i++) {

        ret[i] = poly[0];

      }

      return;

    }

    const vector<int> b0 = buildPoly(vec, left, mid);

    multipointCalc(mod(poly, b0, divide(poly, b0)), vec, left, mid, ret);

    if(left != right) {

      const vector<int> b1 = buildPoly(vec, mid + 1, right);

      multipointCalc(mod(poly, b1, divide(poly, b1)), vec, mid + 1, right, ret);

    }

  }



  // 多点求值 O(nlog^2(n))

  vector<int> multipointCalc(const vector<int> &poly, const vector<int> &vec) {

    const int n = vec.size();

    vector<int> ret(n);

    multipointCalc(poly, vec, 0, n - 1, ret);

    return ret;

  }



  // 多值乘法逆元 O(n)

  vector<int> multiInv(const vector<int> &vec) {

    const int n = vec.size();

    vector<int> a(n + 1), ret(n); a[0] = 1;

    for(int i = 1; i <= n; i++) {

      a[i] = 1ll * a[i - 1] * vec[i - 1] % MOD;

    }

    int cur = (exgcd(a[n], MOD).first + MOD) % MOD;

    for(int i = n - 1; i >= 0; i--) {

      ret[i] = 1ll * cur * a[i] % MOD;

      cur = 1ll * cur * vec[i] % MOD;

    }

    return ret;

  }



  // 快速插值 {{x0, y0}, {x1, y1}, {x2, y2}, ...} O(nlog^3(n))

  vector<int> interpolate(const vector<pair<int, int>> &p) {

    const int n = p.size(), n0 = (n + 1) >> 1, n1 = n - n0;

    if(n == 1) {

      return {p[0].second};

    }

    vector<pair<int, int>> p0(p.begin() + n1, p.end());

    vector<int> f0 = interpolate(p0);

    vector<int> x(n);

    for(int i = 0; i < n; i++) {

      x[i] = p[i].first;

    }

    vector<int> g0 = buildPoly(x, n1, n - 1);

    x.resize(n1);

    vector<int> fx = multipointCalc(f0, x), gx = multipointCalc(g0, x);

    gx = multiInv(gx);

    p0.resize(n1);

    for(int i = 0; i < n1; i++) {

      p0[i].first = p[0].first;

      p0[i].second = (p[i].second - fx[i] + MOD) % MOD;

      p0[i].second = 1ll * p0[i].second * gx[i] % MOD;

    }

    fx = interpolate(p0);

    fx = fft::multiply_mod(fx, g0, MOD);

    fx.resize(n), f0.resize(n);

    for(int i = 0; i < n; i++) {

      fx[i] = (fx[i] + f0[i]) % MOD;

    }

    return fx;

  }

}



const int MAT[5][5] = {

  {0, 0, 0, 0, 0},

  {0, 0, 1, 4, 10},

  {0, 1, 8, 25, 56},

  {0, 4, 25, 72, 154},

  {0, 10, 56, 154, 320}

};



const int N = 2e5 + 10;

int t1[N], t2[N];



int fpow(int a, int b) {

  int ans = 1;

  for(; b > 0; b >>= 1, a = 1ll * a * a % MOD) {

    if(b & 1) {

      ans = 1ll * ans * a % MOD;

    }

  }

  return ans;

}



int fac(int n) {

  if(n <= 1) return 1;

  const int C = sqrt(n);

  vector<int> v(C);

  for(int i = 0; i < C; i++) {

    v[i] = MOD - (i + 1);

  }

  v = poly::buildPoly(v, 0, C - 1);

  vector<int> p(C);

  for(int i = 0; i < C; i++) {

    p[i] = C * i;

  }

  int ans = 1;

  p = poly::multipointCalc(v, p);

  for(int i = 0; i < C; i++) {

    ans = 1ll * ans * p[i] % MOD;

  }

  for(int i = C * C + 1; i <= n; i++) {

    ans = 1ll * ans * i % MOD;

  }

  return ans;

}



int C(int n, int m) {

  return 1ll * fac(n) * fpow(fac(n - m), MOD - 2) % MOD * fpow(fac(m), MOD - 2) % MOD;

}



int lucas(ll n, ll m) {

  if(n < MOD && m < MOD) {

    return C(n, m);

  }

  return C(n % MOD, m % MOD) * lucas(n / MOD, m / MOD) % MOD;

}



void Main() {

  int n, m; ll k; cin >> n >> m >> k;

  for(int i = 1; i <= 4; i++) {

    for(int j = 1; j <= 4; j++) {

      t1[j] = MAT[i][j];

    }

    for(int j = 5; j <= n; j++) {

      t1[j] = (((4ll * t1[j - 1] - 6ll * t1[j - 2] + 4ll * t1[j - 3] - 1ll * t1[j - 4]) % MOD) + MOD) % MOD;

    }

    t2[i] = t1[n];

  }

  for(int i = 5; i <= m; i++) {

    t2[i] = (((4ll * t2[i - 1] - 6ll * t2[i - 2] + 4ll * t2[i - 3] - 1ll * t2[i - 4]) % MOD) + MOD) % MOD;

  }

  int res = 1ll * t2[m] * lucas(1ll * n * m - 2, k - 2) % MOD;

  cout << res << "\n";

}
