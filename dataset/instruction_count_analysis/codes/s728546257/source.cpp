#include"stdc++.h"

using namespace std;

typedef long long ll;

ll f ( ll x ) {

    if ( x == 0 ) return 0;

    else return x % 10 + f ( x / 10 );

}

int main() {

    std::ios::sync_with_stdio ( false );

    int k;

    cin >> k;

    int num = 0;

    ll ans = 1;

    ll p = 1;

    while ( num < k ) {

        cout << ans << endl;

        ll ans1 = ans + p;

        ll ans2 = ans + p * 10;

        if ( ans1 * f ( ans2 ) <= ans2 * f ( ans1 ) ) {

            ans = ans1;

        } else {

            ans = ans2;

            p *= 10;

        }

        num++;

    }

    return 0;

}
