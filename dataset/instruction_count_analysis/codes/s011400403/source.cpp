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

    vector <long long> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector <long long> ans(n);

    ans[0] = 0;

    for (int i = n - 1; i >= 0; i--) {

        if (i & 1) ans[0] -= a[i];

        else ans[0] += a[i];

    }

    for (int i = 0; i < n - 1; i++) {

        ans[i + 1] = 2 * a[i] - ans[i];

    }

    for (int i = 0; i < n; i++) {

        cout << ans[i] << " ";

    }

    return 0;

}