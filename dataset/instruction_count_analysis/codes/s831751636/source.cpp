#include <cstdio>

#include <iostream>

#include <string>

#include <vector>

#include <sstream>

#include <map>

#include <set>

#include <queue>

#include <algorithm>

#include <cmath>

#include <cstring>

#include <typeinfo>

#include <numeric>

#include <functional>

#include <unordered_map>

#include <bitset>

#include <stack>

#include <assert.h>

#include <unordered_set>

#include <random>







using namespace std;

using ll = long long;

using ull = unsigned long long;



const ll INF = 1e18;

const ll MOD = 1e9 + 7;



#define REP(i, n) for(ll i = 0; i < n; i++)



































int main(){

    ll n, t;

    cin >> n >> t;

    vector<ll> a(n), b(n);

    REP(i, n){

        cin >> a[i] >> b[i];

    }

    

    vector<vector<ll>> dp1(n + 2, vector<ll>(6005));

    vector<vector<ll>> dp2(n + 2, vector<ll>(6005));

    REP(i, n){

        REP(j, t){

            dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);

            dp1[i + 1][j + a[i]] = max(dp1[i + 1][j + a[i]], dp1[i][j] + b[i]);

        }

    }

    for(ll i = n - 1; i >= 0; i--){

        REP(j, t){

            dp2[i + 1][j] = max(dp2[i + 1][j], dp2[i + 2][j]);

            dp2[i + 1][j + a[i]] = max(dp2[i + 1][j + a[i]], dp2[i + 2][j] + b[i]);

        }

    }

    ll ans = 0;

    for(ll i = 1; i <= n; i++){

        REP(j, t){

            ans = max(ans, dp1[i - 1][j] + dp2[i + 1][t - 1 - j] + b[i - 1]);

        }

    }

    cout << ans << endl;

}