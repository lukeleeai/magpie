#include <iostream>

#include <vector>

#include <algorithm>

#include <cmath>

#include <queue>

#include <string>

#include <map>

#include <set>

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

using namespace std;



#define chmax(x, y) x = max(x, y)

#define chmin(x, y) x = min(x, y)



typedef long long ll;

typedef pair<int, int> P;

typedef pair<int, double> Pid;

typedef pair<double, int> Pdi;

const double PI = 3.1415926535897932;   // acos(-1)

const double EPS = 1e-15;

const int INF = 1001001001;

const int mod = 1e+9 + 7;



ll mod_pow(ll x, int n){

    if(n == 0)      return 1;



    ll res = 1;

    while(n > 0){

        if(n & 1)   res = res * x % mod;

        x = x * x % mod;

        n >>= 1;

    }

    return res;

}



struct Combination{

    int sz;

    vector<ll> fact;

    vector<ll> ifact;



    Combination(int sz = 1e+5) : sz(sz) {

        fact = vector<ll>(sz + 1);

        ifact = vector<ll>(sz + 1);



        fact[0] = 1;

        for(ll i = 1; i <= sz; ++i){

            fact[i] = fact[i - 1] * i % mod;

        }



        ifact[sz] = mod_pow(fact[sz], mod - 2);

        for(ll i = sz; i > 0; --i){

            ifact[i - 1] = ifact[i] * i % mod;

        }

    }



    ll get_combination(int n, int r){

        if(n < 0 || r < 0 || n < r)     return 0;



        return fact[n] * ifact[r] % mod * ifact[n - r] % mod;

    }

};



int main(){

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int n, k;

    cin >> n >> k;

    vector<ll> a(n);

    set<ll> s;

    for(int i = 0; i < n; ++i){

        cin >> a[i];

        s.insert(a[i]);

    }

    sort(a.begin(), a.end());

    Combination c;

    

    ll res = 0;

    for(int i = 0; i < n; ++i){

        ll tmp = a[i] * c.get_combination(i, k - 1) % mod;

        res = (res + tmp) % mod;

        tmp = a[i] * c.get_combination(n - i - 1, k - 1) % mod;

        res = (res - tmp) % mod;

        while(res < 0)  res += mod;

    }

    // for(auto it : s){

    //     int max_pos = upper_bound(a.begin(), a.end(), it) - a.begin();

    //     int min_pos = lower_bound(a.begin(), a.end(), it) - a.begin();

    //     int cnt = max_pos - min_pos;

    //     --max_pos;



    //     ll tmp = it * c.get_combination(max_pos, k - 1) % mod * cnt % mod;

    //     res = (res + tmp) % mod;

        

    //     tmp = it * c.get_combination(n - min_pos - 1, k - 1) % mod * cnt % mod;;

    //     res = (res - tmp) % mod;

    //     while(res < 0)  res += mod;

    // }

    cout << res << endl;

}