#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <vector>

#include <queue>

#include <map>

using namespace std;

#define LL long long



int n;

LL W, w[105], v[105];

LL judge;



//int dfs(int now, LL rest, LL value)

//{

//    if(value >= judge) return 1;

//    if(now > n) return 0;

//    int flag1 = 0, flag2 = 0;

//    flag1 = dfs(now + 1, rest, value);

//    if(rest - w[now] >= 0) flag2 = dfs(now + 1, rest - w[now], value + v[now]);

//    if(flag1 + flag2 > 0) return 1;

//    return 0;

//}

//

//int C(LL x)

//{

//    judge = x;

//    if(dfs(1, W, 0)) return 1;

//    else return 0;

//}

//

//int main()

//{

//    while(~scanf("%d %lld", &n, &W))

//    {

//        LL sum = 0;

//        for(int i = 1; i <= n; ++i)

//        {

//            scanf("%lld %lld", &w[i], &v[i]);

//            sum += v[i];

//        }

//        LL l = 0, r = sum, mid;

//        while(l < r)

//        {

//            mid = (l + r) / 2;

//            if(C(mid)) l = mid + 1;

//            else r = mid;

//        }

//        mid = (l + r) / 2;

//        if(!C(mid)) l--;

//        printf("%lld\n", l);

//    }

//}



map<LL, LL> dp[105];



LL dfs(int i, LL cost)

{

    if(cost > W) return -10000000;

    if(i > n) return 0;

    if(dp[i].count(cost)) return dp[i][cost];

    return dp[i][cost] = max(dfs(i + 1, cost + w[i]) + v[i], dfs(i + 1, cost));

}



int main()

{

    while(~scanf("%d %lld", &n, &W))

    {

        for(int i = 1; i <= n; ++i) dp[i].clear();

        for(int i = 1; i <= n; ++i)

            scanf("%lld %lld", &w[i], &v[i]);

        LL ans = dfs(1, 0);

        printf("%lld\n", ans);

    }

}
