#include <iostream>

#include "stdc++.h"

#define mod 1000000007



using namespace std;

char str[100005];

int len,dp[100005][13];



int main()

{

    scanf("%s",str);len = strlen(str);

    reverse(str,str+len);

    int base = 1;

    int ori = 0;

    for(int i=0;i<len;++i)

    {

        if(str[i]!='?'){

            ori+=(str[i]-'0')*base;

            ori%=13;

        }

        base*=10;base%=13;

    }

    dp[0][ori] = 1;



    if(str[0]=='?'){

        for(int i=0;i<10;++i)

        {

            for(int j=0;j<13;++j)

            {

                dp[1][(j+i)%13]+=dp[0][j];

                dp[1][(j+i)%13]%=mod;

            }

        }

        for(int j=0;j<13;++j){

            dp[0][j] = dp[1][j];

            dp[1][j] =0;

        }

    }



    base = 1;



    for(int t=1;t<len;++t)

    {

        base*=10;base%=13;

        if(str[t]!='?'){

            for(int j=0;j<13;++j)

                dp[t][j] = dp[t-1][j];

            continue;

        }

        for(int i=0;i<10;++i)

        {

            for(int j=0;j<13;++j)

            {

                dp[t][(j+i*base)%13]+=dp[t-1][j];

                dp[t][(j+i*base)%13]%=mod;

            }

        }

    }

    printf("%d\n",dp[len-1][5]);

    return 0;

}
