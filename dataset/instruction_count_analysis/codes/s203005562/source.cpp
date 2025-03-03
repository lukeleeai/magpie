#include"stdc++.h"

using namespace std;



int main(){

    int n;

    while(scanf("%d",&n),n){

        int dp[2][1010]={{0}};

        int ma=0;

        for(int i=0;i<n;i++){

            char str[1010];

            scanf("%s",str);

            for(int j=0;j<n;j++){

                if(str[j]=='*')dp[(i+1)&1][j+1]=0;

                else{

                    dp[(i+1)&1][j+1]=min(dp[i&1][j],min(dp[(i+1)&1][j],dp[i&1][j+1]))+1;

                }

                ma=max(ma,dp[(i+1)&1][j+1]);

            }

        }



        printf("%d\n",ma);

    }



    return 0;

}