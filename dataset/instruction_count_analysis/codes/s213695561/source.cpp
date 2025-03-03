#include<cstdio>

#include<algorithm>

using namespace std;

int main(){

    int n,w[300],dp[300][300];

    scanf("%d",&n);

    while(n){

        for(int i=0;i<n;i++){

            scanf("%d",&w[i]);

        }

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                dp[i][j]=0;

            }

        }

        for(int k=1;k<n;k++){

            for(int i=0;i+k<n;i++){

                if(dp[i+1][i+k-1]==k-1&&max(w[i],w[i+k])-min(w[i],w[i+k])<=1){

                    dp[i][i+k]=k+1;

                }

                else{

                    for(int j=i;j<i+k;j++){

                        dp[i][i+k]=max(dp[i][i+k],dp[i][j]+dp[j+1][i+k]);

                    }

                }

            }

        }

        printf("%d\n",dp[0][n-1]);

        scanf("%d",&n);

    }

}
