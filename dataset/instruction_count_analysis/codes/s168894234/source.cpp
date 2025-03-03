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





using namespace std;

using ll = long long;

using ull = unsigned long long;



const ll INF = 1e16;

const ll MOD = 1e9 + 7;



#define REP(i, n) for(ll i = 0; i < n; i++)











int main() {

    ll n, a, b, c;

    cin >> n >> a >> b >> c;

    vector<ll> l(n);

    REP(i, n){

        cin >> l[i];

    }

    ll m = round(pow(2, n * 3));

    ll ans = INF;

    REP(i, m){

        bool use[3][8] = {}, ok = true, flag[8] = {};

        for(ll j = n * 3 - 1; j >= 0; j--){

            if(i & (1 << j)){

                if(flag[j % n]){

                    ok = false;

                    break;

                }

                use[j / n][j % n] = true;

                flag[j % n] = true;

            }

        }

        if(!ok) continue;

        REP(j, 3){

            bool f = false;

            REP(k, n){

                if(use[j][k]) f = true;

            }

            if(!f) ok = false;

        }

        if(!ok) continue;

        ll sum = 0;

        REP(j, 3){

            ll d = 0, cnt = 0;

            REP(k, n){

                if(use[j][k]){

                    d += l[k];

                    cnt++;

                }

            }

            sum += 10 * (cnt - 1);

            if(j == 0) sum += abs(a - d);

            else if(j == 1) sum += abs(b - d);

            else sum += abs(c - d);

        }

        ans = min(ans, sum);

    }

    cout << ans << endl;

}
