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

const ll mod = 1e+9 + 7;



#define chadd(x, y) x = (x + y) % mod



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



    Combination(int sz = 2 * 1e+5) : sz(sz) {

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



ll dp[3005][2];



int main(){

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int h, w, n;

    cin >> h >> w >> n;

    vector<P> rc(n);

    for(int i = 0; i < n; ++i){

        int r, c;

        cin >> r >> c;

        --r, --c;

        rc[i] = P(r, c);

    }

    rc.push_back(P(0, 0));      // スタート地点

    rc.push_back(P(h-1, w-1));  // ゴール地点

    sort(rc.begin(), rc.end());

    Combination c;

    

    dp[0][1] = 1;

    // 包徐原理により dp テーブルを埋めていく

    // rc の要素数は n+2 個あり、最初の要素を除いた要素について走査

    // r の昇順に要素を見ていく

    for(int i = 1; i <= n+1; ++i){

        for(int j = 0; j < 2; ++j){

            for(int k = 0; k < i; ++k){     // (r_i, c_i) に到達し得る (r, c) について走査

                // 遷移不能ならば continue

                // r について昇順で並んでいるので、 c を比べて判定

                if(rc[i].second < rc[k].second) continue;



                int N = rc[i].first + rc[i].second - rc[k].first - rc[k].second;

                int K = rc[i].first - rc[k].first;

                // (r_k, c_k) から (r_i, c_i) に到達する経路数

                // j は (0, 1) → (1, 0) と遷移

                ll add = dp[k][j ^ 1] * c.get_combination(N, K) % mod;

                chadd(dp[i][j], add);

            }

        }

    }



    ll res = (dp[n+1][0] - dp[n+1][1]) % mod;

    if(res < 0) res += mod;

    cout << res << endl;

}