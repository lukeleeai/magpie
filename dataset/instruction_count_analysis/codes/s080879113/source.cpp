#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>

 

#define mod 1e9+7

#define ll long long int

#define epsilon 1e-7

 

ll min(ll x, ll y){

    if(x < y)return x;

    else return y;

}

 

int main(void){

    int n, ma, mb;

    scanf("%d %d %d", &n, &ma, &mb);

    int ab[n], c[n];

    for(int i = 0;i < n;i++){

        int a, b;

        scanf("%d %d %d", &a, &b, &c[i]);

        ab[i] = b * ma - a * mb;

    }

    int dp[n+1][8000];

    for(int i = 0;i <= n;i++){

        for(int j = 0;j < 8000;j++){

            dp[i][j] = mod;

        }

    }

    for(int i = 0;i < n;i++){

        for(int j = 0;j < 8000;j++){

            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);

            if(j==4000){

                dp[i+1][j+ab[i]]=min(dp[i+1][j+ab[i]],c[i]);

            }else if(dp[i][j]==mod){

                continue;

            }else{

                if(j+ab[i]>=0&&j+ab[i]<8000)dp[i+1][j+ab[i]] = min(dp[i+1][j+ab[i]],dp[i][j]+c[i]);

            }

        }

    }

    if(dp[n][4000] != mod)printf("%d\n", dp[n][4000]);

    else printf("-1\n");

    return 0;

}