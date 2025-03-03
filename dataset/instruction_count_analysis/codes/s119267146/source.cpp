#include"stdc++.h"

#define int long long

using namespace std;

int a, b, c, x, y, ans = 1e18 + 13;

int32_t main () {

    cin >> a >> b >> c >> x >> y;

    for (int i = 0; i <= 300000; i++) {

	int resx = max(0ll, x - i / 2), resy = max(0ll, y - i / 2);

	ans = min(ans, i * c + resx * a + resy * b);

    }

    cout << ans << endl;

}
