#include "stdc++.h"

using namespace std;



#define pb push_back

#define pp pop_back

#define all(s) s.begin(), s.end()



const int inf = (int)1e9 + 7;



int d[55];

int ans, n;



void go (int in, vector < int > vec) {

    if (in == n + 1) {

        int dif = inf;

        sort(all(vec));

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j <= n; j++) {

                int q1 = vec[i];

                int q2 = vec[j];

                q2 -= q1;

                q1 = 0;

                dif = min(dif, min(q2, 24 - q2));

            }

        }

        ans = max(ans, dif);

        if (clock() > CLOCKS_PER_SEC * 1.5) {

            cout << ans;

            exit(0);

        }

        return ;

    }

    vec.pb(d[in]);

    go(in + 1, vec);

    vec.pp();



    vec.pb(24 - d[in]);

    go(in + 1, vec);

}



main() {

    scanf ("%d", &n);

    for (int i = 1; i <= n; i++) {

        scanf ("%d", d + i);

    }

    vector < int > vec;

    vec.pb(0);

    go(1, vec);

    cout << ans;

}
