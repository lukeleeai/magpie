#include"stdc++.h"

using namespace std;

typedef long long ll;

ll cost[100002], n, k;

ll dp[100002];

ll jump(ll pos)

{

    if(dp[pos]!=-1)

    return dp[pos];

    if(pos == n)

    return 0;

    if(pos > n)

    return INT_MAX;

    ll ans = 0, prev = INT_MAX;

        for(ll i = 1; i<=k; i++){

            ans = (abs(cost[pos] - cost[pos+i]) +  jump(pos+i));

            prev = min(prev, ans);

        }   

    return dp[pos] = prev;

}







int main(){

    cin >> n >> k;

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i<=n; i++)

        cin >> cost[i];

    ll ans = jump(1);

    cout << ans << endl;

return 0;

}