#include "stdc++.h"

using namespace std;



#define for_(i,a,b) for(int i=a;i<b;++i)

#define ALL(a) a.begin(),a.end()

#define INIT(a,b) memset(a,b,sizeof(a))

using lint = long long int;



string T;

int dp[200005][2];

int prv[200005][2];



int main() {

    cin >> T;

    int N = T.size();



    INIT(dp, -1);

    dp[0][0] = 0;



    for_(i,0,N) for_(j,0,2) {

        if (dp[i][j] == -1) continue;

        if (T[i] == 'P' or T[i] == '?') {

            if (dp[i + 1][1] < dp[i][j]) {

                dp[i + 1][1] = dp[i][j];

                prv[i + 1][1] = j;

            }

        }

        if (T[i] == 'D' or T[i] == '?') {

            if (j == 1) {

                if (dp[i + 1][0] < dp[i][j] + 2) {

                    dp[i + 1][0] = dp[i][j] + 2;

                    prv[i + 1][0] = j;

                }

            }

            else {

                if (dp[i + 1][0] < dp[i][j] + 1) {

                    dp[i + 1][0] = dp[i][j] + 1;

                    prv[i + 1][0] = j;

                }

            }

        }

    }



    int k = (dp[N][0] < dp[N][1] ? 1 : 0);

    int i = N;

    string ans = "";

    while (i) {

        if (k == 1) ans += 'P';

        else ans += 'D';

        k = prv[i][k];

        --i;

    }

    reverse(ALL(ans));

    cout << ans << endl;

}