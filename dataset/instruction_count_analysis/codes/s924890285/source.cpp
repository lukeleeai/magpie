#include "bits/stdc++.h"



using namespace std;



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



    int n;

    while(cin>>n,n){

        vector<int> w(n);

        for(int i=0;i<n;i++) cin>>w[i];

        vector<vector<int> > dp(400,vector<int>(400,0));//dp[i][j]:=i~j??????????????????

        vector<vector<int> > res(400,vector<int>(400,0));

        for(int i=0;i<n-1;i++) if(abs(w[i]-w[i+1])<=1){

            dp[i][i+1]=1;

        }

        for(int i=4;i<=n;i+=2){

            for(int j=0;j+i<=n;j++){

                if(dp[j+1][j+i-2] && abs(w[j]-w[j+i-1])<=1){

                    dp[j][j+i-1]=1;

                    continue;

                }

                for(int k=2;k<i;k+=2){

                    if(dp[j][j+k-1] && dp[j+k][j+i-1]){

                        dp[j][j+i-1]=1;

                        break;

                    }

                }

            }        

        }

        for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(dp[i][j]){

            res[i][j]=j-i+1;

        }

        for(int k=0;k<n-1;k++){

            for(int i=0;i<=k;i++){

                for(int j=k+1;j<n;j++){

                    res[i][j]=max(res[i][j],res[i][k]+res[k+1][j]);

                }

            }

        }

        cout<<res[0][n-1]<<endl;

    }

}