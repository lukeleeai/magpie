#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)

#define rep1(i,n) for(int i=1;i<=int(n);++i)

#define all(a) a.begin(),a.end()

#define lb(s,x) lower_bound(all(s),x)-s.begin()

#define debug(x) cerr<<#x<<": "<<x<<endl

#define INF 1e9

typedef long long ll;



#define updmin(dp,x) (dp=(dp == 0 ? x : min(dp,x)))



int main(void){

    int n;

    while(cin>>n, n){

        vector<int> p(n);

        rep(i,n) cin>>p[i];

        // vector<map<int,int>> dp(n+1); // dp[get][coin] = pay

        vector<vector<int>> dp(n+1, vector<int>(500*n,INF));

        dp[0][0] = 0;

        int coin_max = 0;

        rep(i,n){

            for(int k = i; k >= 0; k--){

                // for(auto itr = dp[k].rbegin(); itr != dp[k].rend(); ++itr){

                for(int coin = 500*n-1; coin>=0; coin--){

                    if(dp[k][coin] == INF) continue;

                    // int coin = itr->first;

                    // coin_max = max(coin_max, coin);

                    int pay = dp[k][coin];

                    // int pay = itr->second;

                    int mod = p[i]%500;

                    if(p[i]%1000 == 0){

                        if(coin>=500) updmin(dp[k+1][coin-500], pay+p[i]);

                    }else if(p[i]%1000 == 500){

                        updmin(dp[k+1][coin], pay+p[i]);

                    }else if(p[i]%1000 <= 500){

                        // if(mod+500<=coin){

                        //     updmin(dp[k+1][coin-500-mod], pay+p[i]);

                        // }else{

                            updmin(dp[k+1][coin+500-mod], pay+p[i]);

                        // }

                    }else if(mod <= coin){

                        updmin(dp[k+1][coin-mod], pay+p[i]);

                    }else{

                        updmin(dp[k][coin+500-mod], pay+p[i]);

                    }

                }

            }

        }

        for(int i = n; i>=0; i--){

            // if(dp[i].size()){

                int res = INF;

                for(auto itr : dp[i]){

                    // res = min(res,itr.second);

                    res = min(res,itr);



                }

                if(res != INF){

                cout<<i<<" "<<res<<endl;

                break;

            }

            // }

        }

        // debug(coin_max);

    }

    return 0;

}


