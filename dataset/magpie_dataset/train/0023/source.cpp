#include<iostream>

#include<vector>

#include<algorithm>

#include<string>

using namespace std;

int dp[1001][1001];

int latte(int i,int j,int k){

    return dp[i+k][j+k]-dp[i+k][j-1]-dp[i-1][j+k]+dp[i-1][j-1];

}

int main(){

    int n;

    while(cin>>n,n){

        fill(dp[0],dp[0]+1001*1001,0);

        for(int i=0;i<n;i++){

            string str;

            cin>>str;

            for(int j=0;j<n;j++){

                dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j];

                if(str[j]=='*')dp[i+1][j+1]++;

            }

        }

        int Max=0;

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){

                if(latte(i,j,0))continue;

                int lb=0,ub=min(n-i,n-j)+1;

                while(ub-lb>1){

                    int k=(ub+lb)/2;

                    //if(i+k>n||j+k>n)ub=k;

                    if(latte(i,j,k))ub=k;

                    else lb=k;

                }

                Max=max(Max,lb+1);

            }

        }

        cout<<Max<<endl;

    }

}