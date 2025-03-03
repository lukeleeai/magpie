#include "stdc++.h"

using namespace std;



int MAX = 3000;

vector<vector<string>> dp(2,vector<string>(MAX+1,""));

string s,t;



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    cin >> s >> t;

    int u = s.size(), v = t.size();



    for(int i = 0;i < u;i++){

        for(int j = 0;j < v;j++){

            if(s[i]==t[j])

                dp[1][j+1] = dp[0][j] + s[i];

            else{

                if(dp[1][j].size() >= dp[0][j+1].size())

                    dp[1][j+1] = dp[1][j];

                else

                    dp[1][j+1] = dp[0][j+1];

            }

        }

        dp[0] = dp[1];

    }

    cout << dp[0][v] << "\n";

}