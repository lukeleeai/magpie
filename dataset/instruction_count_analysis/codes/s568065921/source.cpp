#include "stdc++.h"



using namespace std;



#define pb push_back

#define all(s) s.begin(), s.end()



const int N = (int)1e5 + 7;



int x[N];

int used[N];

int u[N];

int mx[N];

int ans;

vector < int > v[N];



main() {

    int n, m; scanf ("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {

        scanf ("%d", x + i);

        u[x[i]]++;

        int y = x[i] % m;

        used[y]++;

    }

    for (int i = 1; i < N; i++) {

        if (u[i] != 0) v[i % m].pb(u[i]);

    }

    for (int i = 0; i < m; i++) {

        sort(all(v[i]));

    }

    if (m % 2 == 0) {

        ans = used[m / 2] / 2;

        used[m / 2] %= 2;

    }

    ans += used[0] / 2;

    used[0] %= 2;

    int l = 1, r = m - 1;

    while (l < r) {

        int mn = min(used[l], used[r]);

        ans += mn;

        used[l] -= mn;

        used[r] -= mn;

        l++; r--;

    }

    for (int i = 0; i < m; i++) {

        for (int j = (int)v[i].size() - 1; j >= 0; j--) {

            if (used[i] - v[i][j] <= 0) {

                v[i][j] = used[i];

                ans += v[i][j] / 2;

                break;

            }

            ans += v[i][j] / 2;

            used[i] -= v[i][j] / 2 * 2;

        }

    }

    cout << ans;

}
