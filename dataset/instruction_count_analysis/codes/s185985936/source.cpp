#include "stdc++.h"



using namespace std;



int main(){



    int n, m;



    cin >> n >> m;



    int c[m];

    int dp[50001];



    for(int i = 0; i <= n; ++i){

        dp[i] = 1 << 24;

    }



    dp[0] = 0;



    for(int i = 0; i < m; ++i){

        cin >> c[i];

    }



    for(int i = 0; i < m; ++i){

        for(int j = c[i]; j <= n; j++){

            dp[j] = min(dp[j], dp[j - c[i]] + 1);

        }

    }



    cout << dp[n] << endl;



}