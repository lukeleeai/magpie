#pragma GCC optimize ("O3")

#include "stdc++.h"

#define ll long long

#define ld long double

#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

const int N = 2e5 + 5, M = 2 * N + 5;





int main(){

    IO;

    ll n;

    cin >> n;

    ll mn = LLONG_MAX;

    for(ll i = 1 ; i * i <= n ; ++i)

        if(n % i == 0)

            mn = min(mn, (i + n / i - 2));

    cout << mn << endl;

}