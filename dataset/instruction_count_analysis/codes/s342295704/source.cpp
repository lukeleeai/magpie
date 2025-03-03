#include "stdc++.h"



using namespace std;



const int inf = (int)1e9 + 7;



char c[2005][2005];

int b[2005][2005];

int he[2005][2005];



int get (int n, int a[]) {

    stack < int > left, right;

    int width[n + 1];

    for (int i = 0; i < n; i++) width[i] = 1;

    for (int i = 0; i < n; i++) {

        while (!left.empty() && a[i] <= a[left.top()]) left.pop();

        if (left.empty()) {

            width[i] += i;

        } else {

            width[i] += i - left.top() - 1;

        }

        left.push(i);

    }

    for (int i = n - 1; i >= 0; i--) {

        while (!right.empty() && a[i] <= a[right.top()]) right.pop();

        if (right.empty()) {

            width[i] += n - i - 1;

        } else {

            width[i] += right.top() - i - 1;

        }

        right.push(i);

    }

    int mx = -inf;

    for (int i = 0; i < n; i++) {

        mx = max(mx, (a[i] + 1) * min(n, (width[i] + 1)));

    }

    return mx;

}



main() {

    int h, w; scanf ("%d %d", &h, &w);

    bool p = 1;

    for (int i = 0; i < h; i++) {

        for (int j = 0; j < w; j++)

            cin >> c[i][j];

    }

    for (int i = 0; i < h - 1; i++) {

        for (int j = 0; j < w - 1; j++) {

            int res = (c[i][j] == '#') + (c[i + 1][j] == '#') + (c[i + 1][j + 1] == '#') + (c[i][j + 1] == '#');

            if ((res & 1) ^ 1) {

                b[i][j] = 1;

            } else p = 0;

        }

    }

    if (p) {

        cout << h * w;

        return 0;

    }

    int ans = max(h, w);

    for (int i = 0; i < h; i++) {

        for (int j = 0; j < w; j++) {

            if (b[i][j] == 1) {

                if (i == 0) {

                    he[i][j] = 1;

                } else he[i][j] = he[i - 1][j] + 1;

            }

//            cout << he[i][j] << ' ';

        }

//        puts("");

        ans = max(ans, get(w, he[i]));

//        cout << ans << endl;

    }



    cout << ans;

}
