#include "stdc++.h"



#define REP(i,n) for(int i=0;i<(int)(n);i++)

#define ALL(x) (x).begin(),(x).end()



using namespace std;



using ll = long long;

using ld = long double;



template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }

template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }



template<int M>

class Modulo {

  using ll = long long;

  int n;

public:

  Modulo () : n(0) {;}

  Modulo (int m) : n(m) {

    if (n >= M) n %= M;

    else if (n < 0) n = (n % M + M) % M;

  }

  Modulo (ll m) {

    if (m >= M) m %= M;

    else if (m < 0) m = (m % M + M) % M;

    n = m;

  }

  explicit operator int() const { return n; }

  explicit operator ll() const { return n; }

  bool operator==(const Modulo &a) const { return n == a.n; }

  Modulo operator+=(const Modulo &a) { n += a.n; if (n >= M) n -= M; return *this; }

  Modulo operator-=(const Modulo &a) { n -= a.n; if (n < 0) n += M; return *this; }

  Modulo operator*=(const Modulo &a) { n = (ll(n) * a.n) % M; return *this; }

  Modulo operator+(const Modulo &a) const { Modulo res = *this; return res += a; }

  Modulo operator-(const Modulo &a) const { Modulo res = *this; return res -= a; }

  Modulo operator*(const Modulo &a) const { Modulo res = *this; return res *= a; }

};



const int mod = 1000000009;



using Mod = Modulo<mod>;

template <typename T> using Matrix = vector<vector<T>>;



template<typename T>

T dot(const vector<T> &a, const vector<T> &b) {

  return inner_product(begin(a), end(a), begin(b), T(0));

}



template<typename T>

Matrix<T> transpose(const Matrix<T> &A) {

  const int n = A[0].size(), m = A.size();

  Matrix<T> res(n, vector<T>(m, 0));

  for (int i = 0; i < n; ++i)

    for (int j = 0; j < m; ++j)

      res[i][j] = A[j][i];

  return res;

}



template<typename T>

Matrix<T> operator*(const Matrix<T> &a, Matrix<T> b) {

  b = transpose(b);

  const int n = a.size(), m = b.size();

  assert (a[0].size() == b[0].size());

  Matrix<T> res(n, vector<T>(m));

  for (int i = 0; i < n; ++i)

    for (int j = 0; j < m; ++j)

      res[i][j] = dot(a[i], b[j]);

  return res;

}



template<typename T>

Matrix<T> powmat(const Matrix<T> &a, ll n) {

  if (n == 0) {

    const int n = a.size();

    Matrix<T> res(n, vector<T>(n, 0));

    REP(i,n) res[i][i] = Mod(1);

    return res;

  }

  else {

    if (n % 2) return powmat(a, n - 1) * a;

    return powmat(a * a, n / 2);

  }

}



int main() {

  ll W, H, N;

  for (int cas = 1; cin >> W >> H >> N, W; ++cas) {

    Matrix<Mod> next(W, vector<Mod>(W, 0));

    REP(i,W) REP(j,W) {

      if (abs(i - j) <= 1) next[i][j] = 1;

    }

    vector<pair<ll,ll>> obstacles;

    REP(i,N) {

      ll x, y;

      cin >> x >> y;

      obstacles.emplace_back(y - 1, x - 1);

    }

    sort(ALL(obstacles));

    Matrix<Mod> vec(W, vector<Mod>(1, 0));

    vec[0][0] = 1;

    ll prev = 0;

    for (auto p: obstacles) {

      ll y, x;

      tie(y, x) = p;

      vec = powmat(next, y - prev) * vec;

      vec[x][0] = 0;

      prev = y;

    }

    vec = powmat(next, H - 1 - prev) * vec;

    printf("Case %d: %d\n", cas, int(vec[W-1][0]));

  }

  return 0;

}