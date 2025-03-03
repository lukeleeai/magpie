#include <iostream>

#include <vector>

#include <map>

#include <unordered_map>

#include <queue>

#include <set>

#include <algorithm>

#include <string>

#include <math.h>

#include <limits.h>

#include <stack>

#include <complex>

#include <stdlib.h>

#include <stdio.h>

#include <functional>

#include <cfloat>

#include <math.h>

#include <numeric>

#include <string.h>

#include <sys/time.h>

#include <random>





#define fs first

#define sc second



using namespace std;



typedef long long ll;

typedef unsigned int uint;

typedef pair<ll, ll> P;





// a と b の最大公約数を返す

ll gcd(ll a, ll b) {

    if (b == 0) return a;

    else return gcd(b, a % b);

}





ll lcm(ll a, ll b){

    return a / gcd(a, b) * b;

}







// 素数判定

bool is_prime(ll N) {

    if (N == 1) return false;

    for (ll i = 2; i * i <= N; ++i) {

        if (N % i == 0) return false;

    }

    return true;

}





// 約数列挙

vector<ll> enum_divisors(ll N) {

    vector<ll> res;

    for (ll i = 1; i * i <= N; ++i) {

        if (N % i == 0) {

            res.push_back(i);

            if (N/i != i) res.push_back(N/i);

        }

    }

    sort(res.begin(), res.end());

    return res;

}





// 素因数分解

vector<pair<ll, ll>> prime_factorize(ll N){

    vector<pair<ll, ll>> res;

    for(ll i = 2; i * i <= N; i++){

        if(N % i != 0)  continue;

        ll ex = 0;



        while(N % i == 0){

            ex++;

            N /= i;

        }



        res.push_back({i, ex});

    }



    if(N != 1)  res.push_back({N, 1});

    return res;

};





class modInt{

    ll value;

    static const ll mod = 1000000007;



public:

    modInt(ll x=0): value{x % mod}{}



    inline modInt& operator+=(modInt x){

        value = (value + x.value) % mod;

        return *this;

    }



    inline modInt& operator-=(modInt x){

        value = (value + mod - x.value) % mod;

        return *this;

    }



    inline modInt& operator*=(modInt x){

        value = (value * x.value) % mod;

        return *this;

    }





    inline modInt operator/=(modInt x){

        *this *= x.inv();

        return *this;

    }



    inline modInt pow(modInt x, int n){

        modInt res = modInt(1LL);

        while(n > 0){

            if(n & 1)   res *= x;

            x *= x;

            n >>= 1;

        }

        return res;

    }



    inline modInt inv(){

        modInt res = pow(value, mod-2);

        return res;

    }



    inline ll get(){

        return value;

    }

};



modInt operator+(modInt x, modInt y){

    return x += y;

}



modInt operator-(modInt x, modInt y){

    return x -= y;

}



modInt operator*(modInt x, modInt y){

    return x *= y;

}



modInt operator/(modInt x, modInt y){

    return x /= y;

}



ostream& operator<<(ostream& os, modInt x){

    return os << x.get();

}





class modIntCombinations{

    vector<modInt> factArray;



    void make_fact(ll x){

        for(auto i = factArray.size(); i <= x+1; i++){

            modInt y = factArray[i-1] * i;

            factArray.push_back(y);

        }

    }



public:

    modIntCombinations(){

        factArray.emplace_back(1);

    }



    modInt fact(ll x){

        if(factArray.size() < x+1){

            make_fact(x);

        }

        return factArray[x];

    }



    modInt comb(ll n, ll k){

        if(n < k){

            return modInt{0};

        }

        else{

            return fact(n) / fact(k) / fact(n - k);

        }

    }



    modInt perm(ll n, ll k){

        if(n < k){

            return modInt{0};

        }

        else{

            return fact(n) / fact(k);

        }

    }

};





int main(){

    ll n, m;    cin >> n >> m;

    vector<P> f = prime_factorize(m);



    modIntCombinations mic;

    modInt res = 1;

    for(int i = 0; i < f.size(); i++){

        res *= mic.comb(n-1+f[i].sc, f[i].sc);

    }



    cout << res << endl;







    return 0;

}