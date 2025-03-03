

#include <iostream>

#include <algorithm>

#include <utility>

#include <vector>

#include <numeric>

#include <tuple>

#include <type_traits>



template <class T, class U>

inline bool chmin(T& lhs, const U& rhs) {

  if (lhs > rhs) {

    lhs = rhs;

    return true;

  }

  return false;

}



template <class T, class U>

inline bool chmax(T& lhs, const U& rhs) {

  if (lhs < rhs) {

    lhs = rhs;

    return true;

  }

  return false;

}



// [l, r) from l to r

struct range {

  struct itr {

    int i;

    constexpr itr(int i_): i(i_) { }

    constexpr void operator ++ () { ++i; }

    constexpr int operator * () const { return i; }

    constexpr bool operator != (itr x) const { return i != x.i; }

  };

  const itr l, r;

  constexpr range(int l_, int r_): l(l_), r(std::max<int>(l_, r_)) { }

  constexpr itr begin() const { return l; }

  constexpr itr end() const { return r; }

};



// [l, r) from r to l

struct revrange {

  struct itr {

    int i;

    constexpr itr(int i_): i(i_) { }

    constexpr void operator ++ () { --i; }

    constexpr int operator * () const { return i; }

    constexpr bool operator != (itr x) const { return i != x.i; }

  };

  const itr r, l;

  constexpr revrange(int l_, int r_): l(l_ - 1), r(std::max<int>(l_, r_) - 1) { }

  constexpr itr begin() const { return r; }

  constexpr itr end() const { return l; }

};



template <class T>

inline T scan() {

  T res;

  std::cin >> res;

  return res;

}



template <class T>

class modulo_int {

public:

  static constexpr int mod = T::value;

  static_assert(mod > 0, "mod must be positive");

private:

  long long value;

  constexpr void normalize() {

    value %= mod;

    if (value < 0) value += mod;

  }

public:

  constexpr modulo_int(long long value_ = 0): value(value_) { normalize(); }

  constexpr modulo_int operator - () const { return modulo_int(mod - value); }

  constexpr modulo_int operator ~ () const { return power(mod - 2); }

  constexpr long long operator () () const { return value; }

  constexpr modulo_int operator + (const modulo_int& rhs) const { return modulo_int(*this) += rhs; }

  constexpr modulo_int& operator += (const modulo_int& rhs) {

    if ((value += rhs.value) >= mod) value -= mod;

    return (*this);

  }

  constexpr modulo_int operator - (const modulo_int& rhs) const { return modulo_int(*this) -= rhs; }

  constexpr modulo_int& operator -= (const modulo_int& rhs) {

    if ((value += mod - rhs.value) >= mod) value -= mod;

    return (*this);

  }

  constexpr modulo_int operator * (const modulo_int& rhs) const { return modulo_int(*this) *= rhs; }

  constexpr modulo_int& operator *= (const modulo_int& rhs) {

    (value *= rhs.value) %= mod;

    return (*this);

  }

  constexpr modulo_int operator / (const modulo_int& rhs) const { return modulo_int(*this) /= rhs; }

  constexpr modulo_int& operator /= (const modulo_int& rhs) {

    return (*this) *= ~rhs;

  }

  constexpr modulo_int power (unsigned long long pow) const {

    modulo_int result(1), mult(*this);

    while (pow > 0) {

      if (pow & 1) result *= mult;

      mult *= mult;

      pow >>= 1;

    }

    return result;

  }

  friend std::istream& operator >> (std::istream& stream, modulo_int& lhs) {

    stream >> lhs.value;

    lhs.normalize();

    return stream;

  }

  friend std::ostream& operator << (std::ostream& stream, const modulo_int& rhs) {

    return stream << rhs.value;

  }

};



using modint = modulo_int<std::integral_constant<int, 1000000007>>;



int main() {

  const int N = scan<int>();

  std::vector<int> A(N);

  for (auto &x: A) {

    std::cin >> x;

  }

  std::vector<modint> sum(N + 1);

  for (int i: range(1, N + 1)) {

    sum[i] += sum[i - 1] + ~modint(i);

  }

  modint ans;

  for (int i: range(0, N)) {

    ans += (sum[i + 1] + sum[N - i] - modint(1)) * modint(A[i]);

  }

  for (int i: range(1, N + 1)) {

    ans *= modint(i);

  }

  std::cout << ans << '\n';

  return 0;

}
