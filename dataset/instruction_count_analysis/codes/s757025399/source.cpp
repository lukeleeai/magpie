#include "stdc++.h"



using namespace std;



int main()

{

#ifdef LOCAL

    freopen("input.txt", "r", stdin);

#endif // LOCAL

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int n;

    cin >> n;

    int x;

    cin >> x;

    vector <int> l(n + 1);

    vector <int> d(n + 2);

    for (int i = 1; i <= n; i++) cin >> l[i];

    d[1] = 0;

    for (int i = 2; i <= n + 1; i++) {

        d[i] = d[i - 1] + l[i - 1];

    }

    int ans = 0;

    for (int i = 1; i <= n + 1; i++) {

        if (d[i] <= x) {

            ans++;

//            return 0;

        }

    }

    cout << ans;

    return 0;

}
