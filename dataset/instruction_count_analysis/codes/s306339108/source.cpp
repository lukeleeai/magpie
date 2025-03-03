#include <iostream>

using namespace std;

const int INF = 1e9;

int k;

int ary[100005];

void solve(int p, int q) {

    if (ary[p] <= q) return;

    ary[p] = q;

    solve(p * 10 % k, q);

    solve((p + 1) % k, q + 1);

}

int main(void) {

    cin >> k;

    for (int i = 0; i < k; ++i) ary[i] = 45;

    solve(1, 1);

    cout << ary[0] << endl;

    return 0;

}