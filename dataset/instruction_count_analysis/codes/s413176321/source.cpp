#include "stdc++.h"

using namespace std;

#define int long long

const int N = 2e5 + 7;



int n, a[N], b[N];

void out() {

    cout << "Yes\n";

    for (int i = 0; i < n; ++i)

        cout << b[i] << " ";

    exit(0);

}



signed main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)

        cin >> a[i];

    for (int i = 0; i < n; ++i)

        cin >> b[i];

    reverse(b, b + n);

    int bad = -1;

    for (int i = 0; i < n; ++i) {

        if (a[i] == b[i])

            bad = b[i];

    }

    vector<int> arr;

    for (int i = 0; i < n; ++i) {

        if (a[i] != bad && b[i] != bad)

            arr.push_back(i);

    }

    int pos = 0;

    for (int i = 0; i < n; ++i) {

        if (a[i] == b[i]) {

            if (pos == arr.size()) {

                cout << "No\n";

                return 0;

            }

            swap(b[arr[pos++]], b[i]);

        }

    }

    out();

    return 0;

}
