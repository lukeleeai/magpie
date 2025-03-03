#define _USE_MATH_DEFIMES

#include <algorithm>

#include <array>

#include <bitset>

#include <cassert>

#include <cctype>

#include <climits>

#include <clocale>

#include <cmath>

#include <complex>

#include <cstdio>

#include <cstdlib>

#include <ctime>

#include <deque>

#include <fstream>

#include <functional>

#include <iomanip>

#include <iostream>

#include <iterator>

#include <list>

#include <map>

#include <numeric>

#include <queue>

#include <random>

#include <regex>

#include <set>

#include <sstream>

#include <stack>

#include <string>

#include <tuple>

#include <unordered_map>

#include <unordered_set>

#include <utility>

#include <vector>



const int MOD = 1'000'000'007;

const int INF = 1'000'000'000; //1e9

const int NIL = -1;

const long long LINF = 1'000'000'000'000'000'000; // 1e18

const long double EPS = 1E-10;



template<class T, class S> inline bool chmax(T &a, const S &b){

    if(a < b){

        a = b; return true;

    }

    return false;

}

template<class T, class S> inline bool chmin(T &a, const S &b){

    if(b < a){

        a = b; return true;

    }

    return false;

}













template<unsigned long long m> class comb_perm{

private:

    int n;

    std::vector<long long> fact, fact_inv;

public:

    comb_perm(): n(0), fact(1), fact_inv(1){

        fact[0] = fact_inv[0] = 1;

    }

    comb_perm(int N): n(N), fact(N+1), fact_inv(N+1){

        fact[0] = fact[1] = fact_inv[0] = fact_inv[1] = 1;

        for(int i(2); i <= n; ++i) fact[i] = fact[i - 1] * i % m;

        for(int i(2); i <= n; ++i) fact_inv[i] = inv(fact[i]);

    }

 

    void resize(int N){

        fact.resize(N+1);

        fact_inv.resize(N+1);

        if(!n && N){

            fact[1] = fact_inv[1] = 1;

        }

        for(int i(std::max(2, n+1)); i <= N; ++i) fact[i] = fact[i - 1] * i % m;

        for(int i(std::max(2, n+1)); i <= N; ++i) fact_inv[i] = inv(fact[i], m);

        n = N;

    }

 

    long long power(long long a, unsigned long long b){

        long long ret(1);

        while(b){

            if(b & 1) ret = (ret * a) % m;

            a = (a * a) % m;

            b /= 2;

            if(ret < 0) ret += m;

            if(a < 0) a += m;

        }

        return ret;

    }

 

    long long inv(long long a){ // GCD(a, m) = 1

        return power(a, m-2);

    }

 

    long long permutation(int n, int r){

        if(n < r) return 0;

        if(n < 0 || r < 0) return 0;

        long long ret(fact[n]);

        ret = ret * fact_inv[n - r] % m;

        return ret;

    }

 

    long long combination(int n, int r){

        if(n < r) return 0;

        if(n < 0 || r < 0) return 0;

        long long ret(permutation(n, r));

        return ret * fact_inv[r] % m;

    }

 

    long long factorial(int a){

        return fact[a];

    }

 

    long long inv_factorial(int a){

        return fact_inv[a];

    }

};



int main(){

    int N; std::cin >> N;

    comb_perm<MOD> cp;

    long long ans(cp.power(10, N) - cp.power(9, N));

    ans *= 2;

    ans %= MOD;

    if(ans < 0) ans += MOD;

    ans -= cp.power(10, N) - cp.power(8, N);

    ans %= MOD;

    if(ans < 0) ans += MOD;

    std::cout << ans << std::endl;

    return 0;

}
