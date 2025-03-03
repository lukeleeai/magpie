#include <algorithm>

#include <iostream>

using namespace std;



typedef long long ll;

const int maxn = 1e5 + 5;



int main(int argc, const char* argv[]) {

    ll x, y, a, b, c, p[maxn], q[maxn], r[maxn * 3], ans = 0;

    cin >> x >> y >> a >> b >> c;

    for (int i = 0; i < a; i++) scanf("%lld", &p[i]);

    for (int i = 0; i < b; i++) scanf("%lld", &q[i]);

    for (int i = 0; i < c; i++) scanf("%lld", &r[i]);



    sort(p, p + a, greater<ll>());

    sort(q, q + b, greater<ll>());



    for (int i = 0; i < x; i++) r[c + i] = p[i];

    for (int i = 0; i < y; i++) r[c + x + i] = q[i];



    sort(r, r + c + x + y, greater<ll>());



    for (int i = 0; i < x + y; i++) ans += r[i];



    cout << ans << endl;

    return 0;

}