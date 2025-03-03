#include "stdc++.h"



using namespace std;

typedef long long LL;



const int MAXN = 123456;

LL presum[MAXN];

vector<LL> line[MAXN];

map<LL, int> mp;



LL cal(LL cur, LL mod) {

   if (cur >= mod)

      return (cur - mod) % mod;

   else

      return (mod - cur) % mod;

}



int main() {

    int N, M;

    scanf("%d %d", &N, &M);

    int idx = 0;

    for (int i = 1; i <= N; i++) {

        int tmp;

        scanf("%d", &tmp);

        presum[i] = presum[i - 1] + tmp;

        presum[i] %= M;

        if (!mp.count(presum[i])) mp[presum[i]] = idx++;

        line[mp[presum[i]]].push_back(i);

    }

    LL ans = 0;

    for (int i = 1; i <= N; i++) {

        LL tmp = cal(-presum[i - 1], M);

        // printf("i = %d tmp = %lld\n", i, tmp);

        if (mp.count(tmp)) {

           LL cur = mp[tmp];

           auto low = lower_bound(line[cur].begin(), line[cur].end(), i);

           ans += LL(line[cur].end() - low);

           // printf("ans = %lld\n", ans);

        }

    }

    printf("%lld\n", ans);

    return 0;

}
