#include <cstdio>

#include <algorithm>

using namespace std;

using ll = long long int;



const int S = 200010;

ll x[S], s[S], dp[S];

int main() {

    ll N, ans; scanf("%lld", &N);

    for(int i=0; i<N; i++) {

        scanf("%lld%lld", &x[i], &s[i]);

    }



    ans = dp[0] = s[0];

    for(int i=1; i<N; i++) {

        dp[i] = max(s[i], dp[i-1] + s[i] - (x[i] - x[i-1]));

        ans = max(ans, dp[i]);

    }

    printf("%lld\n", ans);

    return 0;

}