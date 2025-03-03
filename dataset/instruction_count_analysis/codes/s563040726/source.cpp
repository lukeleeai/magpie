#include <algorithm>

#include <iostream>

#include <cstdio>

using namespace std;

#define debug(x) cerr << #x << "=" << x << endl;

typedef long long ll;

ll n, m, ans;

int main() {

    cin >> n >> m;

    if(m - 2*n >= 0) {

        ans += n;

        ans += (m-2*n)/4;

    } else {

        ans = m/2;

    }

    cout << ans;

    return 0;

}