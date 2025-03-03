#include "stdc++.h"



using namespace std;

typedef long long LL;



const int MAXN = 123456;

map<LL, int> mp;



int main() {

    int N, M;

    scanf("%d %d", &N, &M);

    LL ans = 0, presum = 0;

    mp[0] = 1;

    for (int i = 1; i <= N; i++) {

        int tmp;

        scanf("%d", &tmp);

        presum = (presum + tmp) % M;

        ans += mp[presum];

        mp[presum]++;

    }

    printf("%lld\n", ans);

    return 0;

}
