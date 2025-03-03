#include "stdc++.h"

using namespace std;

const int N = 100010;

typedef long long LL;

int n, pri_cnt = 0;

LL a[N], p1[N], p2[N], pri[N];

void pre_pri() {

    for (int i = 2; i < N; i++) {

        if (pri[i]) continue;

        pri[++pri_cnt] = i;

        for (int j = i + i; j < N; j += i) pri[i] = 1;

    }

}

void cal(LL x, int id) {

    p1[id] = p2[id] = 1;

    for (int i = 1; pri[i] * pri[i] * pri[i] <= x; i++) {

        int t = 0;

        while (x % pri[i] == 0) x /= pri[i], t++;

        t %= 3;

        for (int j = 0; j < t; j++) p1[id] *= pri[i];

        t = (3 - t) % 3;

        for (int j = 0; j < t; j++) p2[id] *= pri[i];

    }

    if (x) {

        LL t = sqrt(x);

        if (t * t == x)

            p1[id] *= x, p2[id] *= t;

        else

            p1[id] *= x, p2[id] *= x * x;

    }

}

map<LL, int> mp;

int main() {

    pre_pri();

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        scanf("%lld", &a[i]);

        cal(a[i], i);

    }

    int ans = 0;

    for (int i = 1; i <= n; i++) mp[p1[i]]++;

    for (int i = 1; i <= n; i++) {

    	if (mp[p1[i]] == 0) continue;

        if (p1[i] == p2[i]) {

            ans++;

            mp[p1[i]] = 0;

            continue;

        }

        ans += max(mp[p1[i]], mp[p2[i]]);

        mp[p1[i]] = mp[p2[i]] = 0;

    }

    printf("%d\n", ans);

    return 0;

}