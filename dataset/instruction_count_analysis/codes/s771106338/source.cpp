#include"stdc++.h"

using namespace std;



#define M 1000000007

string s[1001];

int dp[1001][1001];





int main(){



        int n, m; cin >> n >> m;

        for(int i = 1; i <= n; i++){

                cin >> s[i];

                s[i] = '#' + s[i];

        }



        memset(dp, 0, sizeof dp);

        dp[1][1] = 1;

        for(int i = 1; i <= n; i++){

                for(int j = 1; j <= m; j++){

                        if(s[i][j] == '.'){

                                dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % M;

                        }

                }

        }



        cout << dp[n][m] << endl;







        return 0;

}
