//In the name of God

#include"stdc++.h"

#define int long long



using namespace std;



int n , A , a[60] , dp[60][60][3000];



int32_t main(){

        ios_base::sync_with_stdio(false);

        cin.tie(0);

        cout.tie(0);

        cin >> n >> A;

        for(int i=1 ; i <= n ; i++)

                cin >> a[i];

        dp[0][0][0] = 1;

        for(int i=1 ; i <= n ; i++){

                dp[i][0][0] = 1;

                for(int j=1 ; j <= i ; j++)

                        for(int k=1 ; k < 2800 ; k++){

                                dp[i][j][k] = dp[i-1][j][k];

                                if(k >= a[i])

                                        dp[i][j][k] += dp[i-1][j-1][k - a[i]];

                        }

        }

        int res = 0;

        for(int i=1 ; i <= n ; i++)

                res += dp[n][i][i*A];

        cout << res;

} 