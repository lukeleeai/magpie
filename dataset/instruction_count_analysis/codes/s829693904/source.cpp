#include "stdc++.h"

using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;

const LL mod = 1e9 + 7;

const int N = 300005;



int a[N], b[N];

vector<int> c, d;

int main() {

    int n, m, g;

    scanf("%d%d%d", &n, &m, &g);

    set<pair<int, int> > se;

    for (int i = 0; i < g; i++) {

        int x, y;

        scanf("%d%d", &x, &y);

        se.insert({x, y});

        a[x]++;

        b[y]++;

    }

    int mx1 = 0, mx2 = 0;

    for (int i = 1; i <= n; i++) mx1 = max(mx1, a[i]);

    for (int i = 1; i <= m; i++) mx2 = max(mx2, b[i]);

    for (int i = 1; i <= n; i++)

        if (mx1 == a[i]) c.push_back(i);

    for (int i = 1; i <= m; i++)

        if (mx2 == b[i]) d.push_back(i);

    for (auto x : c) {

        for (auto y : d) {

            if (se.count({x, y}) == 0) {

                printf("%d\n", mx1 + mx2);

                return 0;

            }

        }

    }

    printf("%d\n", mx1 + mx2 - 1);

    return 0;

}
