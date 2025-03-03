//#define NDEBUG

#include <algorithm>

#include <cstddef>

#include <cstdint>

#include <iostream>

#include <utility>

#include <vector>



namespace n91 {



using i8 = std::int_fast8_t;

using i32 = std::int_fast32_t;

using i64 = std::int_fast64_t;

using u8 = std::uint_fast8_t;

using u32 = std::uint_fast32_t;

using u64 = std::uint_fast64_t;

using isize = std::ptrdiff_t;

using usize = std::size_t;



struct rep {

  struct itr {

    usize i;

    constexpr itr(const usize i) noexcept : i(i) {}

    void operator++() noexcept { ++i; }

    constexpr usize operator*() const noexcept { return i; }

    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }

  };

  const itr f, l;

  constexpr rep(const usize f, const usize l) noexcept

      : f(std::min(f, l)), l(l) {}

  constexpr auto begin() const noexcept { return f; }

  constexpr auto end() const noexcept { return l; }

};

struct revrep {

  struct itr {

    usize i;

    constexpr itr(const usize i) noexcept : i(i) {}

    void operator++() noexcept { --i; }

    constexpr usize operator*() const noexcept { return i; }

    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }

  };

  const itr f, l;

  constexpr revrep(const usize f, const usize l) noexcept

      : f(l - 1), l(std::min(f, l) - 1) {}

  constexpr auto begin() const noexcept { return f; }

  constexpr auto end() const noexcept { return l; }

};

template <class T> auto md_vec(const usize n, const T &value) {

  return std::vector<T>(n, value);

}

template <class... Args> auto md_vec(const usize n, Args... args) {

  return std::vector<decltype(md_vec(args...))>(n, md_vec(args...));

}

template <class T> constexpr T difference(const T &a, const T &b) noexcept {

  if (a < b) {

    return b - a;

  } else {

    return a - b;

  }

}

template <class T> void chmin(T &a, const T &b) noexcept {

  if (b < a) {

    a = b;

  }

}

template <class T> void chmax(T &a, const T &b) noexcept {

  if (a < b) {

    a = b;

  }

}

template <class F> class fix_point : private F {

public:

  explicit constexpr fix_point(F &&f) : F(std::forward<F>(f)) {}



  template <class... Args>

  constexpr decltype(auto) operator()(Args &&... args) const {

    return F::operator()(*this, std::forward<Args>(args)...);

  }

};

template <class F> constexpr decltype(auto) make_fix(F &&f) {

  return fix_point<F>(std::forward<F>(f));

}

template <class T> T scan() {

  T ret;

  std::cin >> ret;

  return ret;

}



} // namespace n91

#include <cstdint>



namespace n91 {



template <std::uint_fast64_t Modulus> class modint {

  using u64 = std::uint_fast64_t;



public:

  using value_type = u64;



  static constexpr u64 mod = Modulus;



private:

  static_assert(mod < static_cast<u64>(1) << 32,

                "Modulus must be less than 2**32");



  u64 v;



  constexpr modint &negate() noexcept {

    if (v != 0)

      v = mod - v;

    return *this;

  }



public:

  constexpr modint(const u64 x = 0) noexcept : v(x % mod) {}

  constexpr u64 &value() noexcept { return v; }

  constexpr const u64 &value() const noexcept { return v; }

  constexpr modint operator+() const noexcept { return modint(*this); }

  constexpr modint operator-() const noexcept { return modint(*this).negate(); }

  constexpr modint operator+(const modint rhs) const noexcept {

    return modint(*this) += rhs;

  }

  constexpr modint operator-(const modint rhs) const noexcept {

    return modint(*this) -= rhs;

  }

  constexpr modint operator*(const modint rhs) const noexcept {

    return modint(*this) *= rhs;

  }

  constexpr modint operator/(const modint rhs) const noexcept {

    return modint(*this) /= rhs;

  }

  constexpr modint &operator+=(const modint rhs) noexcept {

    v += rhs.v;

    if (v >= mod)

      v -= mod;

    return *this;

  }

  constexpr modint &operator-=(const modint rhs) noexcept {

    if (v < rhs.v)

      v += mod;

    v -= rhs.v;

    return *this;

  }

  constexpr modint &operator*=(const modint rhs) noexcept {

    v = v * rhs.v % mod;

    return *this;

  }

  constexpr modint &operator/=(modint rhs) noexcept {

    u64 exp = mod - 2;

    while (exp) {

      if (exp % 2 != 0)

        *this *= rhs;

      rhs *= rhs;

      exp /= 2;

    }

    return *this;

  }

  constexpr bool operator==(const modint rhs) const noexcept {

    return v == rhs.v;

  }

  constexpr bool operator!=(const modint rhs) const noexcept {

    return v != rhs.v;

  }

};

template <std::uint_fast64_t Modulus>

constexpr typename modint<Modulus>::u64 modint<Modulus>::mod;



} // namespace n91

#include <utility>

#include <vector>



namespace n91 {



template <class T> std::vector<T> factorize(T n) noexcept {

  std::vector<T> ret;

  for (T p = static_cast<T>(2); p * p <= n; ++p) {

    while (n % p == static_cast<T>(0)) {

      n /= p;

      ret.push_back(p);

    }

  }

  if (n != static_cast<T>(1)) {

    ret.push_back(std::move(n));

  }

  ret.shrink_to_fit();

  return std::move(ret);

}



} // namespace n91

#include <utility>

#include <vector>



namespace n91 {



template <class T>

std::vector<std::pair<T, std::size_t>>

run_length_encoding(const std::vector<T> &a) {

  if (a.empty()) {

    return std::vector<std::pair<T, std::size_t>>();

  }

  std::vector<std::pair<T, std::size_t>> ret;

  ret.reserve(a.size());

  ret.emplace_back(a.front(), static_cast<std::size_t>(0));

  for (const T &e : a) {

    if (e != ret.back().first) {

      ret.emplace_back(e, static_cast<std::size_t>(0));

    }

    ++ret.back().second;

  }

  ret.shrink_to_fit();

  return std::move(ret);

}



} // namespace n91

#include <cstddef>

#include <cstdint>



constexpr std::size_t popcount32(std::uint_fast32_t c) noexcept {

#ifdef _GNUC_

  return __builtin_popcount(c);

#else

  c -= c >> 1 & 0x55555555;

  c = (c & 0x33333333) + (c >> 2 & 0x33333333);

  c = (c + (c >> 4)) & 0x0F0F0F0F;

  return c * 0x01010101 >> 24 & 0x3F;

#endif

}

#include <algorithm>

#include <iostream>

#include <set>

#include <string>

#include <utility>

#include <vector>



namespace n91 {



void main_() {

  /*

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  //*/

  const usize n = scan<usize>();

  auto g = md_vec(n, 0, usize());

  for (const usize i : rep(0, n - 1)) {

    const usize a = scan<usize>() - 1;

    const usize b = scan<usize>() - 1;

    g[a].push_back(b);

    g[b].push_back(a);

  }

  const usize m = scan<usize>();

  struct cons {

    usize u, v;

  };

  std::vector<cons> cs(m);

  for (auto &e : cs) {

    e.u = scan<usize>() - 1;

    e.v = scan<usize>() - 1;

  }

  const auto merge = [](auto &l, auto &r) {

    if (l.size() < r.size()) {

      std::swap(l, r);

    }

    for (const auto e : r) {

      if (l.count(e))

        l.erase(e);

      else

        l.insert(e);

    }

    r.clear();

  };

  u64 ans = 0;

  for (const usize s : rep(0, 1 << m)) {

    u64 res = 1;

    std::vector<std::set<usize>> ls(n);

    for (const usize i : rep(0, m)) {

      if (s >> i & 1) {

        ls[cs[i].u].insert(i);

        ls[cs[i].v].insert(i);

      }

    }

    make_fix([&](const auto &dfs, const usize v, const usize p) -> void {

      for (const auto e : g[v]) {

        if (e != p) {

          dfs(e, v);

          if (ls[e].empty()) {

            res *= 2;

          }

          merge(ls[v], ls[e]);

        }

      }

    })(0, n);

    if (popcount32(s) % 2 == 1)

      res = -res;

    ans += res;

  }

  std::cout << ans << std::endl;

}



} // namespace n91



int main() {

  n91::main_();

  return 0;

}
