#include"stdc++.h"

#define ll long long

#define pr pair<ll,ll>

using namespace std;

int main() {

    ll s, bd = 1e9;

    cin >> s;

    if (s == 1e18)cout << 0 << ' ' << 0 << ' ' << 1000000000 << ' ' << 0 << ' ' << 0 << ' ' << 1000000000;

    else if (s <= bd)cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << 1 << ' ' << s << ' ' << 0;

    else {

        ll L = s / bd + 1, R = L * bd - s;

        cout << 0 << ' ' << 0 << ' ' << bd << ' ' << 1 << ' ' << R << ' ' << L;

    }

    return 0;

}
