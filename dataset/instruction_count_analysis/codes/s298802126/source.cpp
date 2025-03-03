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



ostream& operator<<(ostream& s, const FiniteField& x) {

  s << x.Value();

  return s;

}



// Vector

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {

  int len = v.size();

  s << "[";

	for (int i = 0; i < len; i++) {

    if (i > 0) s << ", ";

		s << v[i];

  }

  s << "]";

  return s;

}



// Find the n-th term of a sequence defined by a generative function P(x) / Q(x).

// Q(x) is a polynomial of degree k which satisfies Q(0) = 1.

// P(X) is a polynomial of degree at most k - 1.

// The method name follows SymPy.

FiniteField RationalAlgorithm(const vector<FiniteField>& p, const vector<FiniteField>& q, int64 n) {

  if (n == 0) {

    if (p.empty()) return 0;

    return p[0];

  }



  static auto multiply_fn = [](const vector<FiniteField>& p1, const vector<FiniteField>& p2) {

    if (p1.empty() || p2.empty()) return vector<FiniteField>();

    int d1 = p1.size() - 1;

    int d2 = p2.size() - 1;

    vector<FiniteField> r(d1 + d2 + 1);

    for (int i = 0; i <= d1; i++) {

      for (int j = 0; j <= d2; j++) {

        r[i + j] += p1[i] * p2[j];

      }

    }

    return r;

  };



  // Returns P(-x) for a given P(x).

  static auto minus_x_fn = [](const vector<FiniteField>& p) {

    vector<FiniteField> r = p;

    for (int i = 1; i < r.size(); i += 2) {

      r[i] *= -1;

    }

    return r;

  };



  static auto take_even_fn = [](const vector<FiniteField>& p) {

    vector<FiniteField> r;

    for (int i = 0; i < p.size(); i += 2) {

      r.push_back(p[i]);

    }

    return r;

  };



  static auto take_odd_fn = [](const vector<FiniteField>& p) {

    vector<FiniteField> r;

    for (int i = 1; i < p.size(); i += 2) {

      r.push_back(p[i]);

    }

    return r;

  };



  if (n % 2 == 0) {

    return RationalAlgorithm(

        take_even_fn(multiply_fn(p, minus_x_fn(q))),

        take_even_fn(multiply_fn(q, minus_x_fn(q))),

        n / 2);

  } else {

    return RationalAlgorithm(

        take_odd_fn(multiply_fn(p, minus_x_fn(q))),

        take_even_fn(multiply_fn(q, minus_x_fn(q))),

        (n - 1) / 2);

  } 

}



int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);



  static auto multiply_fn = [](const vector<FiniteField>& p1, const vector<FiniteField>& p2) {

    if (p1.empty() || p2.empty()) return vector<FiniteField>();

    int d1 = p1.size() - 1;

    int d2 = p2.size() - 1;

    vector<FiniteField> r(d1 + d2 + 1);

    for (int i = 0; i <= d1; i++) {

      for (int j = 0; j <= d2; j++) {

        r[i + j] += p1[i] * p2[j];

      }

    }

    return r;

  };



  vector<FiniteField> f({0, 1});

  vector<FiniteField> g({1, -2, 0, 2, -1});



  vector<FiniteField> p({1});

  vector<FiniteField> q({1});

  for (int i = 0; i < 5; i++) {

    p = multiply_fn(p, f);

    q = multiply_fn(q, g);

  }

  q = multiply_fn(q, {1, -1});



  int t;

  cin >> t;

  for (int i = 0; i < t; i++) {

    int n;

    cin >> n;

    cout << RationalAlgorithm(p, q, n) << endl;

  }

}