#include "stdc++.h"

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main() {

    int k, n;

    cin >> k >> n;

    if(k % 2 == 0) {

        rep(i, n) cout << k / (1 + !i) << "\n";

        return 0;

    }

    vector<int> v(n, k + 1 >> 1);

    int j = n;

    rep(i, n - i - 1) if(--v[--j]) while(++j < n) v[j] = k;

    rep(i, j) cout << v[i] << "\n";

}