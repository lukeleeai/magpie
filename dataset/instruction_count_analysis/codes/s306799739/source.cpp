#include "stdc++.h"

using namespace std;

typedef long long ll;

ll dp[41][41][41];

int G[41][41];

int main(){

	int n;

	scanf("%d",&n);

	n *= 2;

	for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){

            char x;

            scanf(" %c",&x);

            G[i][j] = x-'0';

        }

	}

	for (int i = 1; i < n; i++) dp[i][i][i] = 1;

	for (int l = 1; l < n; l++){

        for (int s = 1; s+l < n; s++){

            int u = s+l;

            for (int t = s+1; t < u; t++){

                for (int p1 = s; p1 < t; p1++){

                    for (int p2 = t+1; p2 <= u; p2++){

                        for (int r1 = s; r1 <= p1; r1++){

                            for (int r2 = p2; r2 <= u; r2++){

                                if (G[r1][r2] == 0) continue;

                                dp[s][t][u] += dp[s][r1][p1]*dp[p1+1][t][p2-1]*dp[p2][r2][u];

                            }

                        }

                    }

                }

            }

        }

	}

	ll ans = 0;

	for (int i = 1; i <= n-1; i++){

        if (G[0][i]){

            ans += dp[1][i][n-1];

            //printf("if take 0-%d, %lld\n",i,dp(1,i,2*n-1));

        }

	}

	printf("%lld",ans);

}
