#include"stdc++.h"

using namespace std;

const int N = 1e5 + 1;

int n , a[N] , dp[N] , k;

int main(){

    scanf("%d%d", &n , &k);

    for(int i = 0 ; i < n ; i++){

        scanf("%d", &a[i]);

    }

    dp[0] = 0;

    //dp[1] = dp[0] + abs(a[0] - a[1]);

    for(int i = 1 ; i < n ; i++){

        dp[i] = 1e9 + 10;

        for(int j = 1; j <= k ; j++)

            if(i >= j)

                dp[i] = min(dp[i - j] + abs(a[i] - a[i - j]) , dp[i]);

    }

    cout<<dp[n - 1];

    return 0;

}