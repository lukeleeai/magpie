#include"stdc++.h"

using namespace std;

typedef long long ll;

ll dp[100009];

int arr[100009];

ll sum = 0;

int k;

long long Frog1(int n){

 

    if(n==0) return 0;

 

    else if(dp[n]!=-1) return dp[n];

    else {

            ll sum = INT_MAX;

            for(int i=n-1,j=1;i>=0 && j<=k;i--,j++ ){

 

                ll x;

                if(dp[i]!=-1) x = dp[i];

                else x = Frog1(i);

 

                x = abs(arr[i] - arr[n]) + x;

                sum = min(sum,x);

                //cout << n  << " " << i  << " " << j << endl;

            }

            dp[n] = sum;

            return sum;

    }

}

 

 

int main()

{

    int n;

    memset(dp,-1,sizeof(dp));

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> arr[i];

    cout << Frog1(n-1) << endl;

}