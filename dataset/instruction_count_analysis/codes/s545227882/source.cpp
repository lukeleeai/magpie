#include "stdc++.h"



using namespace std;

int ans=-1, d,mod =1e9+7, dp[10004][3][101];

string x;



int solve (int i , int t, int cnt){

if (i == x.size()-1) {

    if (cnt) return 0;

    return 1;

}



if (dp[i][t][cnt]!=-1) return dp[i][t][cnt];

int v =0;



for (int j=0; j<10; j++){

    if (t==0 && j == x[i+1]-48) v = (v+solve(i+1, 0, (cnt+j)%d))%mod;

    else if (t==0 && j > x[i+1]-48) break;

    else v = (v+solve(i+1, 1, (cnt+j)%d))%mod;

}



return dp[i][t][cnt]=v;

}



int main()

{

memset(dp , -1, sizeof dp);

    cin >> x >> d;

    int first = x[0]-48;



    for ( int i=0; i<first; i++)  ans=  (ans+solve(0, 1, i%d))%mod;

    ans=  (ans+solve(0, 0, first%d))%mod;



    cout << ans%mod;

    return 0;

}
