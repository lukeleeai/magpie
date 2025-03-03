//#define NDEBUG



#pragma region cp_template



#include <algorithm>

#include <cstddef>

#include <cstdint>

#include <iostream>

#include <utility>

#include <vector>



namespace n91 {



using i32 = std::int32_t;

using i64 = std::int64_t;

using u32 = std::uint32_t;

using u64 = std::uint64_t;

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

  return a < b ? b - a : a - b;

}

template <class T> void chmin(T &a, const T &b) noexcept {

  if (b < a)

    a = b;

}

template <class T> void chmax(T &a, const T &b) noexcept {

  if (a < b)

    a = b;

}

template <class F> class rec_lambda {

  F f;



public:

  rec_lambda(F &&f) : f(std::move(f)) {}

  template <class... Args> auto operator()(Args &&... args) const {

    return f(*this, std::forward<Args>(args)...);

  }

};

template <class F> auto make_rec(F &&f) { return rec_lambda<F>(std::move(f)); }

template <class T> T scan() {

  T ret;

  std::cin >> ret;

  return ret;

}

constexpr char eoln = '\n';

template <class T> T ceildiv(const T &l, const T &r) {

  return l / r + (l % r != 0 ? 1 : 0);

}



} // namespace n91



#pragma endregion cp_template



#include <cstdint>



template <std::uint_fast64_t mod> class modint {

  using u64 = std::uint_fast64_t;



public:

  u64 v;



  constexpr modint(const u64 x = 0) noexcept : v(x % mod) {}

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

    while (exp != 0) {

      if (exp % 2 != 0)

        *this *= rhs;

      rhs *= rhs;

      exp /= 2;

    }

    return *this;

  }

};



#include <array>



namespace n91 {



void main_() {

  /*

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  //*/

  using mint = modint<998244353>;



  const usize a = scan<usize>();

  const usize b = scan<usize>();

  const usize c = scan<usize>();

  const usize d = scan<usize>();



  using node = std::array<std::array<mint, 3>, 3>;



  auto dp = md_vec(c + 2, d + 2, node());

  dp[a][b][0][0] = 1;



  for (const usize i : rep(a, c + 1)) {

    for (const usize j : rep(b, d + 1)) {

      const auto &cu = dp[i][j];

      {

        auto &nx = dp[i + 1][j];



        for (const usize k : rep(0, 3)) {

          for (const usize l : rep(0, 3)) {

            nx[std::min<usize>(2, k + 1)][1] += cu[k][l];

            nx[k][1] += cu[k][l] * (j - 1);

          }

        }

      }

      {

        auto &nx = dp[i][j + 1];



        if (i == a) {

          for (const usize k : rep(0, 3)) {

            for (const usize l : rep(0, 3)) {

              nx[1][std::min<usize>(2, l + 1)] += cu[k][l];

              nx[1][l] += cu[k][l] * (i - 1);

            }

          }

        } else {

          for (const usize k : rep(0, 3)) {

            for (const usize l : rep(1, 3)) {

              nx[1][std::min<usize>(2, l + 1)] += cu[k][l];

            }

            nx[1][0] += cu[k][0] * (i - 1);

            nx[1][2] += cu[k][2] * (i - 1);

          }

        }

      }

    }

  }



  mint ans = 0;



  for (const auto i : rep(0, 3)) {

    for (const auto j : rep(0, 3)) {

      ans += dp[c][d][i][j];

    }

  }



  std::cout << ans.v << eoln;

}



} // namespace n91



int main() {

  n91::main_();

  return 0;

}
