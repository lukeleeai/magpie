

#include <iostream>

#include <algorithm>

#include <utility>

#include <vector>

#include <numeric>



template <class T, class U>

inline bool chmin(T &lhs, const U &rhs) {

  if (lhs > rhs) {

    lhs = rhs;

    return true;

  }

  return false;

}



template <class T, class U>

inline bool chmax(T &lhs, const U &rhs) {

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

  constexpr range(int l_, int r_): l(l_), r(std::max(l_, r_)) { }

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

  const itr l, r;

  constexpr revrange(int l_, int r_): l(l_ - 1), r(std::max(l_, r_) - 1) { }

  constexpr itr begin() const { return r; }

  constexpr itr end() const { return l; }

};



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

  constexpr modulo_int operator + (const modulo_int &rhs) const { return modulo_int(*this) += rhs; }

  constexpr modulo_int &operator += (const modulo_int &rhs) {

    if ((value += rhs.value) >= mod) value -= mod;

    return (*this);

  }

  constexpr modulo_int operator - (const modulo_int &rhs) const { return modulo_int(*this) -= rhs; }

  constexpr modulo_int &operator -= (const modulo_int &rhs) {

    if ((value += mod - rhs.value) >= mod) value -= mod;

    return (*this);

  }

  constexpr modulo_int operator * (const modulo_int &rhs) const { return modulo_int(*this) *= rhs; }

  constexpr modulo_int &operator *= (const modulo_int &rhs) {

    (value *= rhs.value) %= mod;

    return (*this);

  }

  constexpr modulo_int operator / (const modulo_int &rhs) const { return modulo_int(*this) /= rhs; }

  constexpr modulo_int &operator /= (const modulo_int &rhs) {

    return (*this) *= ~rhs;

  }

  constexpr bool operator == (const modulo_int &rhs) const {

    return value == rhs();

  }

  constexpr bool operator != (const modulo_int &rhs) const {

    return value != rhs();

  }

  constexpr modulo_int power (uint64_t exp) const {

    modulo_int result(1), mult(*this);

    while (exp > 0) {

      if (exp & 1) result *= mult;

      mult *= mult;

      exp >>= 1;

    }

    return result;

  }

  friend std::istream &operator >> (std::istream &stream, modulo_int &lhs) {

    stream >> lhs.value;

    lhs.normalize();

    return stream;

  }

  friend std::ostream &operator << (std::ostream &stream, const modulo_int &rhs) {

    return stream << rhs.value;

  }

};





template <class T, std::size_t N>

class factorials {

public:

  using value_type = T;

  static constexpr std::size_t size = N;



public:

  std::array<value_type, size + 1> fact{};

  std::array<value_type, size + 1> fact_inv{};



  factorials() {

    fact.front() = value_type(1);

    for (std::size_t i = 1; i <= size; ++i) {

      fact[i] = fact[i - 1] * value_type(i);

    }

    fact_inv.back() = ~fact.back();

    for (std::size_t i = size; i > 0; --i) {

      fact_inv[i - 1] = fact_inv[i] * value_type(i);

    }

  }



  value_type operator () (std::size_t n, std::size_t r) const {

    return fact[n] * fact_inv[n - r] * fact_inv[r];

  }



};



using modint = modulo_int<std::integral_constant<int, 998244353>>;

factorials<modint, 200000> fact;



int main() {

  int N, M, K;

  std::cin >> N >> M >> K;

  modint ans;

  for (int i: range(0, K + 1)) {

    int B = N - i;

    ans += fact(N - 1, B - 1) * modint(M) * modint(M - 1).power(B - 1);

  }

  std::cout << ans << '\n';

  return 0;

}
