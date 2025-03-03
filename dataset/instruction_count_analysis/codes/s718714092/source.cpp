#include"stdc++.h"



using namespace std;



const int mod=1e9+7;

long long dp[2002];



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);cout.tie(NULL);

    int i,j,n;

    cin >> n;

    dp[0]=1;

    for(i=1;i<=n;i++)

    {

        for(j=3;j<=i;j++)

        {

            dp[i]+=dp[i-j];

            dp[i]%=mod;

        }

    }

    cout << dp[n];

    return 0;

}
