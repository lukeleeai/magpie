#include "stdc++.h"

using namespace std;



int main()

{

    int N;

    string S;

    int dp[500005] = {};

    int pos = -1;

    cin >> N >> S;

    

    for(int i = 2; i < N; i++) {

        dp[i + 1] = dp[i];

        if(S.substr(i - 2, 3) == "101") {

            pos = i - 3;

            for(int j = i - 2; j >= 0 && S[j] != '0'; j--) {

                dp[i + 1] = max(dp[i + 1], dp[j] + i - j - 1);

            }

        }

        if(S[i] == '0') pos = -1;

        if(~pos) dp[i + 1] = max(dp[i + 1], dp[pos + 1] + i - pos - 2);

    }



    cout << dp[N] << endl;

    return (0);

}
