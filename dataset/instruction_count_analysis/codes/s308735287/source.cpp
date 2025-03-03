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

using namespace std;



using ll = long long;

using ull = uint64_t;

using P = pair<int, int>;

constexpr double EPS = 1e-9;

constexpr int INF = 1001001001;

constexpr int mod = 1000000007;

// constexpr int mod = 998244353;



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



template<typename T>

struct Combination{

    int sz;

    vector<T> fact_;

    vector<T> ifact_;

    vector<T> inv_;

    

    Combination(int n = 1e+6) : sz(n) {

        fact_.resize(sz + 1);

        ifact_.resize(sz + 1);

        inv_.resize(sz + 1);



        fact_[0] = ifact_[sz] = inv_[0] = 1;

        for(int i = 1; i <= sz; ++i)    fact_[i] = fact_[i - 1] * i;

        ifact_[sz] /= fact_[sz];

        for(int i = sz; i > 0; --i)     ifact_[i - 1] = ifact_[i] * i;

        for(int i = 1; i <= sz; ++i)    inv_[i] = ifact_[i] * fact_[i - 1];

    }



    inline T fact(int k) const  {return fact_[k];}

    inline T ifact(int k) const {return ifact_[k];}

    inline T inv(int k) const   {return inv_[k];}



    T get_permutation(int n, int k){

        if(n < 0 || k < 0 || n < k)     return 0;

        return fact(n) * ifact(n - k);

    }



    T get_combination(int n, int k){

        if(n < 0 || k < 0 || n < k)     return 0;

        return fact(n) * ifact(k) * ifact(n - k);

    }

};



int main(){

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int H, W, N;

    cin >> H >> W >> N;

    vector<P> ps(N);

    for(int i = 0; i < N; ++i)  cin >> ps[i].first >> ps[i].second;

    ps.emplace_back(1, 1);

    ps.emplace_back(H, W);

    sort(ps.begin(), ps.end());

    Combination<modint> c(H + W);



    vector<vector<modint>> dp(N + 2, vector<modint>(2));

    dp[0][1] = 1;

    for(int i = 0; i <= N; ++i){

        int sx = ps[i].first, sy = ps[i].second;

        for(int j = i + 1; j <= N + 1; ++j){

            int tx = ps[j].first, ty = ps[j].second;

            if(ty < sy) continue;

            modint X = c.get_combination(tx + ty - sx - sy, tx - sx);

            for(int k = 0; k < 2; ++k){

                if(dp[i][k] == 0)   continue;

                int nk = k ^ 1;

                dp[j][nk] += X * dp[i][k];

            }

        }

    }



    cout << dp[N + 1][0] - dp[N + 1][1] << endl;

}