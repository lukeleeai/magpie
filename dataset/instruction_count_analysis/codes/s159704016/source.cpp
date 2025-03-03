#include <iostream>

#include <vector>

#include <algorithm>

#include <cmath>

#include <queue>

#include <string>

#include <map>

#include <set>

#include <stack>

#include <tuple>

#include <deque>

#include <numeric>

#include <bitset>

#include <iomanip>

#include <cassert>

#include <chrono>

#include <random>

#include <limits>

#include <iterator>

#include <functional>

#include <sstream>

#include <complex>

#include <cstring>

using namespace std;



using ll = long long;

using P = pair<int, int>;

constexpr int INF = 1001001001;

// constexpr int mod = 1000000007;

constexpr int mod = 998244353;



template<class T>

inline bool chmax(T& x, T y){

    if(x < y){

        x = y;

        return true;

    }

    return false;

}

template<class T>

inline bool chmin(T& x, T y){

    if(x > y){

        x = y;

        return true;

    }

    return false;

}



template<int mod>

struct ModInt{

    int x;



    ModInt() : x(0) {}

    

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    

    ModInt &operator+=(const ModInt &p){

        if((x += p.x) >= mod)   x -= mod;

        return *this;

    }

    

    ModInt &operator-=(const ModInt &p){

        if((x += mod - p.x) >= mod) x -= mod;

        return *this;

    }



    ModInt &operator*=(const ModInt &p){

        x = (int)(1LL * x * p.x % mod);

        return *this;

    }



    ModInt &operator/=(const ModInt &p){

        *this *= p.inverse();

        return *this;

    }

    

    ModInt operator-() const {return ModInt(-x);}



    ModInt operator+(const ModInt &p) const {return ModInt(*this) += p;}



    ModInt operator-(const ModInt &p) const {return ModInt(*this) -= p;}



    ModInt operator*(const ModInt &p) const {return ModInt(*this) *= p;}



    ModInt operator/(const ModInt &p) const {return ModInt(*this) /= p;}



    bool operator==(const ModInt &p) const {return x == p.x;}



    bool operator!=(const ModInt &p) const {return x != p.x;}



    ModInt inverse() const{

        int a = x, b = mod, u = 1, v = 0, t;

        while(b > 0){

            t = a / b;

            swap(a -= t * b, b);

            swap(u -= t * v, v);

        }

        return ModInt(u);

    }



    ModInt pow(int64_t n) const{

        ModInt ret(1), mul(x);

        while(n > 0){

            if(n & 1)   ret *= mul;

            mul *= mul;

            n >>= 1;

        }

        return ret;

    }



    friend ostream &operator<<(ostream &os, const ModInt &p){

        return os << p.x;

    }



    friend istream &operator>>(istream &is, ModInt &a){

        int64_t t;

        is >> t;

        a = ModInt<mod>(t);

        return (is);

    }



    static int get_mod() {return mod;}

};



using modint = ModInt<mod>;



modint dp[2][90005], dp2[2][90005];



int main(){

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int N;

    cin >> N;

    vector<int> a(N);

    for(int i = 0; i < N; ++i)  cin >> a[i];

    int S = 0;

    dp[0][0] = dp2[0][0] = 1;

    for(int i = 0; i < N; ++i){

        for(int j = 0; j <= S; ++j) dp[1][j] = 0;

        int nxt_S = S;

        for(int j = 0; j <= S; ++j){

            if(dp[0][j] == 0)   continue;

            dp[1][j] += dp[0][j] * 2;

            dp[1][j + a[i]] += dp[0][j];

            chmax(nxt_S, j + a[i]);

        }

        swap(dp[0], dp[1]);

        S = nxt_S;

    }

    modint X = 0, Y = 0;

    for(int i = S / 2 + (S & 1); i <= S; ++i)   X += dp[0][i];

    if(~S & 1){

        S = 0;

        for(int i = 0; i < N; ++i){

            for(int j = 0; j <= S; ++j) dp2[1][j] = 0;

            int nxt_S = S;

            for(int j = 0; j <= S; ++j){

                if(dp2[0][j] == 0)  continue;

                dp2[1][j] += dp2[0][j];

                dp2[1][j + a[i]] += dp2[0][j];

                chmax(nxt_S, j + a[i]);

            }

            swap(dp2[0], dp2[1]);

            S = nxt_S;

        }

        Y = dp2[0][S / 2];

    }

    modint ans = modint(3).pow(N) - X * 3 + Y * 3;

    cout << ans << endl;

}