#include "stdc++.h"



using namespace std;

using int64 = long long;



constexpr int DEBUG = 0;



constexpr int64 P = 1000000007;



struct FiniteField {

 private:

  int64 x;

 public:

  FiniteField(int64 raw_x) : x(raw_x) {

    if (x >= P || x < 0) { 

      x %= P;

      if (x < 0) x += P;

    }

  }

  FiniteField() : x(0) {}

  int64 Value() const { return x; }

  inline FiniteField operator+(FiniteField o) const {

    FiniteField r(*this); r += o; return r;

  }

  inline FiniteField operator-(FiniteField o) const {

    FiniteField r(*this); r -= o; return r;

  }

  inline FiniteField operator* (FiniteField o) const {

    FiniteField r(*this); r *= o; return r;

  }

  inline FiniteField operator/ (FiniteField o) const {

    FiniteField r(*this); r /= o; return r;

  }

  inline void operator+= (FiniteField o) { x = (x + o.x) % P; }

  inline void operator-= (FiniteField o) { x = (x + P - o.x) % P; }

  inline void operator*= (FiniteField o) { x = (x * o.x) % P; }

  void operator/=(FiniteField o) {

    int64 p = P - 2; while (p) { if (p % 2) { *this *= o; } o *= o; p /= 2; }

  }

};

ostream& operator<<(ostream& s, const FiniteField& x) { s << x.Value(); return s; }



FiniteField Combination(int a, int b) {

  FiniteField r = 1;

  for (int k = 0; k < b; k++) {

    r *= (a - k);

    r /= (1 + k);

  }

  return r;

}



FiniteField F(int n) {

  FiniteField r = 0;

  for (int x = 0; n - 5 - 2 * x >= 0; x++) {

    r += Combination(x + 4, 4) * Combination(n - 2 * x + 5, 10);

  }

  return r;

}



FiniteField LagrangeInterpolation(const vector<pair<int, FiniteField>>& ps, int x) {

  FiniteField r = 0;

  for (int i = 0; i < ps.size(); i++) {

    const auto [x_i, y_i] = ps[i];

    FiniteField t = 1;

    for (int k = 0; k < ps.size(); k++) {

      if (k == i) continue;

      const auto [x_k, y_k] = ps[k];

      t *= x - x_k;

      t /= x_i - x_k;

    }

    r += t * y_i;

  }

  return r;

}



FiniteField Solve() {

  int n;

  cin >> n;

  if (n <= 4) return 0;



  if (n % 2 == 1) {

    vector<pair<int, FiniteField>> ps;

    for (int x = 5; x < 5 + 2 * 16; x += 2) {

      ps.push_back({x, F(x)});

    }



    FiniteField r = LagrangeInterpolation(ps, n);

    return r;

  } else {

    vector<pair<int, FiniteField>> ps;

    for (int x = 6; x < 6 + 2 * 16; x += 2) {

      ps.push_back({x, F(x)});

    }



    FiniteField r = LagrangeInterpolation(ps, n);

    return r;

  }

}



int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);



  int num_cases;

  cin >> num_cases;

  for (int case_id = 0; case_id < num_cases; case_id++) {

    cout << Solve() << endl;

  }

}