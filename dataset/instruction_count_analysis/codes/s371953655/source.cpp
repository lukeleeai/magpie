#include "stdc++.h"



using namespace std;



template <class T> bool minimize(T &x, const T &y) {

    if (x > y) x = y; else return false; return true;

}



typedef long long ll;



const int N = 2e5 + 10;



int n, m, A, B;

int a[N];

ll s[N], bit1[N], bit2[N], f[N];



void upbit1(int x, ll para) {

    for (; x <= n; x += x & -x)

        minimize(bit1[x], para);

}



ll getbit1(int x) {

    ll ret = (ll)(1e16);

    for (; x; x -= x & -x)

        minimize(ret, bit1[x]);

    return ret;

}



void upbit2(int x, ll para) {

    for (; x; x -= x & -x)

        minimize(bit2[x], para);

}



ll getbit2(int x) {

    ll ret = (ll)(1e16);

    for (; x <= n; x += x & -x)

        minimize(ret, bit2[x]);

    return ret;

}



int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> A >> B;

    for (int i = 1; i <= m; i++)

        cin >> a[i];

    /// init

    for (int i = 2; i <= m; i++) {

        s[i] = s[i - 1] + (ll)(abs(a[i] - a[i - 1]));

        /// A B

        f[i] = 1ll * abs(B - a[i]) + 1ll * abs(A - a[1]) + s[i - 1];

        /// B A

        f[i] = min(f[i], 1ll * abs(A - a[i]) + 1ll * abs(B - a[1]) + s[i - 1]);

    }

    memset(bit1, 60, sizeof(bit1));

    memset(bit2, 60, sizeof(bit2));

    /// dp

    for (int i = 2; i <= m; i++) {

        /// ai >= aj

        minimize(f[i], getbit1(a[i]) + (ll)(a[i]) + s[i - 1]);

        /// ai < aj

        minimize(f[i], getbit2(a[i] + 1) - (ll)(a[i]) + s[i - 1]);

        /// update

        upbit1(a[i - 1], f[i] - s[i] - (ll)(a[i - 1]));

        upbit2(a[i - 1], f[i] - s[i] + (ll)(a[i - 1]));

    }

    ll res = min(abs(a[1] - A), abs(a[1] - B)) + s[m];

    for (int i = 2; i <= m; i++)

        minimize(res, f[i] + s[m] - s[i]);

    cout << res;

}
