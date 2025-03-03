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



typedef long long ll;

typedef uint64_t ull;

typedef pair<int, int> P;

constexpr double EPS = 1e-9;

constexpr int INF = 1001001001;

constexpr int mod = 1000000007;

// constexpr int mod = 998244353;



#define chmax(x, y) x = max(x, y)

#define chmin(x, y) x = min(x, y)



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



    int n, k;

    cin >> n >> k;

    map<int, int> mp;

    for(int i = 0; i < n; ++i){

        int a;

        cin >> a;

        ++mp[a];

    }

    vector<P> a;

    for(auto it : mp){

        a.emplace_back(it.first, it.second);

    }

    int sz = a.size();

    vector<int> S(sz + 1);

    S[0] = 0;

    for(int i = 0; i < sz; ++i){

        S[i + 1] = S[i] + a[i].second;

    }

    Combination<modint> c(n + 5);



    modint ans = 0;

    for(int i = 0; i < sz; ++i){

        const int& val = a[i].first;

        const int& bound = a[i].second;

        // cerr << "leftS:" << S[i] << ",rightS:" << S[sz] - S[i + 1] << '\n';

        for(int j = 1; j <= min(k, bound); ++j){

            // cerr << "val:" << val << ",bound:" << bound << ' ';

            modint x = c.get_combination(bound, j);

            x *= c.get_combination(S[i], k - j);

            x *= val;

            ans += x;

            // cerr << x << ' ';



            x = c.get_combination(bound, j);

            x *= c.get_combination(S[sz] - S[i + 1], k - j);

            x *= val;

            ans -= x;

            // cerr << x << '\n';

        }

    }

    cout << ans << endl;

}