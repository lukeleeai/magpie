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

    ll m = round(pow(4, n));

    ll ans = INF;

    REP(i, m){

        ll aa = 0, bb = 0, cc = 0, idx = 0, cnt[4] = {};

        for(ll j = i; j > 0; j /= 4){

            ll t = j % 4;

            if(t == 1){

                aa += l[idx];

                cnt[1]++;

            }

            else if(t == 2){

                bb += l[idx];

                cnt[2]++;

            }

            else if(t == 3){

                cc += l[idx];

                cnt[3]++;

            }

            idx++;

        }

        if(aa == 0 || bb == 0 || cc == 0) continue;

        ll sum = 0;

        sum += 10 * ((cnt[1] - 1) + (cnt[2] - 1) + (cnt[3] - 1));

        sum += abs(aa - a);

        sum += abs(bb - b);

        sum += abs(cc - c);

        ans = min(ans, sum);

    }

    cout << ans << endl;

}
