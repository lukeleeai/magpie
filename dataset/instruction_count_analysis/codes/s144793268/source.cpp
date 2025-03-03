#include "stdc++.h"



#pragma comment(linker, "/stack:200000000")

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")



typedef long long ll;

typedef unsigned long long ull;

// typedef __int128_t lll;

#define fatnet ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



using namespace std;



const ll MOD1 = 1e9 + 7;

const ll MOD2 = 2000003983; // 3571 1e9 + 97

const ll MOD3 = 1e9 + 9;

const ll p1 = 1e6 + 3;

const ll p2 = 2017; // 131 37

const ll p3 = 37;

const ll INF = 5e18;



int main() {

    fatnet;



    ll l, r;

    cin >> l >> r;

    if ((r / 3 - (l - 1) / 3) && (r / 673 - (l - 1) / 673)) {

        cout << 0 << "\n";

        return 0;

    }

    ll ans = 2018;

    for (ll i = l; i < r; ++i)

        for (ll j = l + 1; j <= r; ++j)

            ans = min(ans, (i * j) % 2019);

    cout << ans << "\n";



    return 0;

}
