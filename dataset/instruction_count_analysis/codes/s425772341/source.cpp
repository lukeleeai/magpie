#include "stdc++.h"



using namespace std;

const int MAXN = 2e5 + 5;



vector<int> e[MAXN];



int main(int argc, char* argv[]) {

    int n;

    scanf("%d", &n);

    long long ans = 1LL * n * (n + 1) * (n + 2) / 6;

    for (int i = 1; i < n; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        if (u > v) swap(u, v);

        ans -= 1LL * u * (n - v + 1);

    }

    printf("%lld\n", ans);

    return 0;

}
