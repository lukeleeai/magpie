#include"stdc++.h"

#define ll long long

#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

double PI=acos(-1);

int n,k,arr[105];

ll dp[105][100005];

int const mod=1e9 +7;



int main(){

    IO

    cin>>n>>k;

    for(int i=0;i<105;i++) dp[i][0]=1;

    for(int i=1;i<n+1;i++) cin>>arr[i];

    sort(arr,arr+n+1);

    for(int i=1;i<=n;i++){

        for(int j=1;j<=100000;j++){

            if(arr[i]>=j) dp[i][j]=dp[i][j-1]+dp[i-1][j];

            else dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-arr[i]-1];

            dp[i][j]=(dp[i][j]+mod)%mod;

        }

    }

    cout<<dp[n][k]<<'\n';





    return 0;

}
