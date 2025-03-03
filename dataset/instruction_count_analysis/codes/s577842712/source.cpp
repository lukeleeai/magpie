#include "stdc++.h"

#define int long long

// using ii = pair<int, int>;

using namespace std;



int dx[] = {1, 0, -1, 0};

int dy[] = {0, 1, 0, -1};

vector<int> tbl[] = {

    {},

    {4, 2, 3, 5},

    {4, 6, 3, 1},

    {1, 2, 6, 5},

    {6, 2, 1, 5},

    {4, 1, 3, 6},

    {4, 5, 3, 2},

};



void solve() {

    int n; cin >> n;

    if (n == 0) exit(0);

    vector<int> t(n), f(n);

    for (int i = 0; i < n; i++) cin >> t[i] >> f[i];



    vector<vector<int>> num(100, vector<int>(100));

    vector<vector<int>> top(100, vector<int>(100));

    for (int i = 0; i < n; i++) {

        int x = 50, y = 50;

        int ct = t[i], cf = f[i];

        while (1) {

            // cout << x << " " << y << endl;

            int face = find(tbl[ct].begin(), tbl[ct].end(), cf) - tbl[ct].begin();

            bool no = true;

            for (int k = 6; k >= 4; k--) {

                int tmp = find(tbl[ct].begin(), tbl[ct].end(), k) - tbl[ct].begin();

                if (tmp >= 4) continue;

                int dif = (tmp - face + 4) % 4;

                int nx = x + dx[dif], ny = y + dy[dif];

                if (num[x][y] > num[nx][ny]) {

                    x = nx, y = ny;

                    if (dif == 0) cf = ct;

                    if (dif == 2) cf = 7 - ct;

                    ct = tbl[ct][(tmp + 2) % 4];

                    no = false;

                    break;

                }

            }

            if (no) break;

        }

        num[x][y]++;

        top[x][y] = ct;

    }



    vector<int> ans(7);

    for (int i = 0; i < 100; i++) {

        for (int j = 0; j < 100; j++) {

            ans[top[i][j]]++;

        }

    }

    for (int i = 1; i < 7; i++) {

        cout << ans[i] << (i == 6 ? "" : " ");

    }

    cout << endl;

}



signed main() {

    while (1) solve();

}
