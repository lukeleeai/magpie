#include "stdc++.h"

using namespace std;

#define INF 0x3f3f3f3f

#define maxn 200005

#define ll long long



void DBG() {

    cerr << "]\n";

}

template <class H, class... T> void DBG(H h, T... t) {

    cerr << h;

    if (sizeof...(t)) {

        cerr << ", ";

    }

    DBG(t...);

}

#define _DEBUG

#ifdef _DEBUG

#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

#else

#define dbg(...) 0

#endif



int tt, n, k;

int a[maxn];



int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);



    cin >> n;

    for (int i = 1; i <= n; i++) {

        cin >> a[i];

    }

    sort(a + 1, a + n + 1);

    ll ans = 0;

    for (int i = 1; i < n; i++) {

        ans += a[n - i / 2];

    }



    cout << ans;

    return 0;

}