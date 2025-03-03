#include "stdc++.h"

 

using namespace std;



int a[100100], t[100100], mx[100100];

int n;

 

int main() {

    ios::sync_with_stdio(0); cin.tie(0);

 

    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> a[i];

        t[i] = a[i];

    }

    for (int i = 0; i < n; i++) {

        if (i > 0) mx[i] = max(mx[i - 1], a[i - 1]);

    }

    sort(t, t + n);

    int cur = 0;

    for (int i = 0; i < n; i++) {

        if (mx[i] >= a[i]) cout << "0\n";

        else {

            long long sm = 0;

            while (cur < n && t[cur] <= a[i]) {

                sm += t[cur] - mx[i];

                cur++;

            }

            sm += 1ll * (n - cur) * (a[i] - mx[i]);

            cout << sm << '\n';

        }

    }

}