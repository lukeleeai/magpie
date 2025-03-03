#include <cstdint>

#include <iostream>



template <std::uint32_t mod>

class modint

{

    using i64 = std::int64_t;

    using u32 = std::uint32_t;

    using u64 = std::int64_t;



    static_assert(mod < (u32(1) << 31), "mod must be less than 2**31");



public:

    u32 v;



    constexpr modint(const i64 x = 0) noexcept

        : v(x < 0 ? mod - 1 - -(x + 1) % mod : x % mod) {}

    constexpr modint operator+(const modint rhs) const noexcept

    {

        return modint(*this) += rhs;

    }

    constexpr modint operator-(const modint rhs) const noexcept

    {

        return modint(*this) -= rhs;

    }

    constexpr modint operator*(const modint rhs) const noexcept

    {

        return modint(*this) *= rhs;

    }

    constexpr modint operator/(const modint rhs) const noexcept

    {

        return modint(*this) /= rhs;

    }

    constexpr modint &operator+=(const modint rhs) noexcept

    {

        v += rhs.v;

        if (v >= mod)

            v -= mod;

        return *this;

    }

    constexpr modint &operator-=(const modint rhs) noexcept

    {

        if (v < rhs.v)

            v += mod;

        v -= rhs.v;

        return *this;

    }

    constexpr modint &operator*=(const modint rhs) noexcept

    {

        v = u64(v) * rhs.v % mod;

        return *this;

    }

    constexpr modint &operator/=(const modint rhs) noexcept

    {

        *this *= rhs.pow(mod - 2);

    }

    constexpr modint pow(u32 exp) noexcept

    {

        modint self(*this), ret(1);

        while (exp != 0)

        {

            if (exp % 2 != 0)

                ret *= self;

            self *= self;

            exp /= 2;

        }

        return ret;

    }

};



template <std::uint32_t mod>

std::istream &operator>>(std::istream &is, modint<mod> &rhs)

{

    std::int64_t v;

    is >> v;

    rhs = modint<mod>(v);

    return is;

}



template <std::uint32_t mod>

std::ostream &operator<<(std::ostream &os, const modint<mod> &rhs)

{

    os << rhs.v;

    return os;

}



#include <vector>



int main()

{

    using mint = modint<998244353>;

    using std::vector;



    int a, b, c, d;

    std::cin >> a >> b >> c >> d;



    vector<vector<mint>> dp(c + 1, vector<mint>(d + 1));



    for (int i = a; i <= c; ++i)

    {

        for (int j = b; j <= d; ++j)

        {

            if (i == a && j == b)

            {

                dp[i][j] = 1;

                continue;

            }

            dp[i][j] = dp[i - 1][j] * j + dp[i][j - 1] * i -

                       dp[i - 1][j - 1] * (i - 1) * (j - 1);

        }

    }



    std::cout << dp[c][d] << std::endl;

}
