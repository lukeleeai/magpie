#include "stdc++.h"



using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;

const int maxn = 110000;

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout << setiosflags(ios::fixed) << setprecision(12);

    double pi = acos(-1);

    int n;

    cin >> n;

    double ans = 2 * pi * n;

    cout << ans << "\n";

    return 0;

}