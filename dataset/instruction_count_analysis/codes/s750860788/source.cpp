

#include <iostream>

#include <cstdint>

#include <array>



template <uint32_t Modulus>

class modular {

public:

  using value_type = uint32_t;

  using max_type = uint64_t;



  static constexpr value_type mod = Modulus;

  static constexpr value_type mod_min = 1;

  static constexpr value_type mod_max = 2147483647;

  static_assert(mod >= mod_min, "invalid mod :: too small");

  static_assert(mod <= mod_max, "invalid mod :: too big");



  template <class T>

  static constexpr value_type normalize(T value_) {

    if (value_ < 0) {

      value_ = -value_;

      value_ %= mod;

      if (value_ == 0) return 0;

      return mod - value_;

    }

    return value_ % mod;

  }



private:

  value_type value;



public:

  constexpr modular(): value(0) { }

  template <class T>

  explicit constexpr modular(T value_): value(normalize(value_)) { }

  template <class T>

  explicit constexpr operator T() { return static_cast<T>(value); }



  constexpr modular operator - () const { return modular(mod - value); }

  constexpr modular operator ~ () const { return inverse(); }





  constexpr modular inverse() const { return power(mod - 2); }

  constexpr modular power(max_type exp) const {

    modular res(1), mult(*this);

    while (exp > 0) {

      if (exp & 1) res *= mult;

      mult *= mult;

      exp >>= 1;

    }

    return res;

  }



  constexpr modular operator + (const modular &rhs) const { return modular(*this) += rhs; }

  constexpr modular& operator += (const modular &rhs) { 

    if ((value += rhs.value) >= mod) value -= mod; 

    return *this; 

  }



  constexpr modular operator - (const modular &rhs) const { return modular(*this) -= rhs; }

  constexpr modular& operator -= (const modular &rhs) { 

    if ((value += mod - rhs.value) >= mod) value -= mod; 

    return *this; 

  }



  constexpr modular operator * (const modular &rhs) const { return modular(*this) *= rhs; }

  constexpr modular& operator *= (const modular &rhs) { 

    value = (max_type) value * rhs.value % mod;

    return *this;

  }



  constexpr modular operator / (const modular &rhs) const { return modular(*this) /= rhs; }

  constexpr modular& operator /= (const modular &rhs) const { return (*this) *= rhs.inverse(); }



  constexpr bool zero() const { return value == 0; }

  constexpr bool operator == (const modular &rhs) const { return value == rhs.value; }

  constexpr bool operator != (const modular &rhs) const { return value != rhs.value; }

  friend std::ostream& operator << (std::ostream &stream, const modular &rhs) {

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



  constexpr factorials() {

    fact.front() = value_type(1);

    for (std::size_t i = 1; i <= size; ++i) {

      fact[i] = fact[i - 1] * value_type(i);

    }

    fact_inv.back() = ~fact.back();

    for (std::size_t i = size; i > 0; --i) {

      fact_inv[i - 1] = fact_inv[i] * value_type(i);

    }

  }



  constexpr value_type operator () (std::size_t n, std::size_t r) const {

    return fact[n] * fact_inv[n - r] * fact_inv[r];

  }



};



using modint = modular<998244353>;

factorials<modint, 200000> fact;



int main() {

  int N, M, K;

  std::cin >> N >> M >> K;

  modint ans;

  for (int i = 0; i <= K; ++i) {

    int B = N - i;

    ans += fact(N - 1, B - 1) * modint(M) * modint(M - 1).power(B - 1);

  }

  std::cout << ans << '\n';

  return 0;

}
