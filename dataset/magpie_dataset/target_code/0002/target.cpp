#include"stdc++.h"

using namespace std;

#define ll long long

#define vi vector<int>

#define pb push_back

#define pii pair<int , int>

#define fast ios_base::sync_with_stdio(0)

#define mx 100005

#define inf 100000000000000000LL

ll arr[mx], dp[mx];

int main()

{

    int n,k;

    while(scanf("%d%d",&n, &k)){

        for(int i=1; i<=n; i++)

            scanf("%lld",&arr[i]);

        dp[n] = 0;

        for(int i = n-1; i>=1; i--){

            dp[i] = inf;

            for(int j=1; j<=k; j++){

                int nxt = i+j;

                if(nxt>n) break;

                dp[i] = min(dp[i], llabs(arr[i] - arr[nxt]) + dp[nxt]);

            }

        }

        printf("%lld\n", dp[1]);

        return 0;

    }

}


