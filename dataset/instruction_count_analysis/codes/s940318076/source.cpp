#include <iostream>

#include <cmath>

#include <functional>

#include <algorithm>

 

#define FOR(i, a, b) for (int i = (a); i < (b); i++)

#define REP(i, n) for (int i = 0; i < (n); i++)

#define ALL(a) (a).begin(), (a).end()

 

using namespace std;

 

int main() {

    int N, H, a[100000], b[100000];

    cin >> N >> H;

    REP(i, N) cin >> a[i] >> b[i];

 

    int a_max = *max_element(a, a + N);

    sort(b, b + N, greater<int>());

 

    int ans = 0, i = 0;

    while (H > 0) {

        if (b[i] > a_max) {

            H -= b[i];

            ans++;

        }

        else break;

        i++;

    }

    if (H <= 0) {

        cout << ans << endl;

        return 0;

    }

    ans += ceil((double)H / a_max);

    cout << ans << endl;

 

    return 0;

}