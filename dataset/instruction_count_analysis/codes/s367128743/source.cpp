#include <cstdio>  

#include <cstring>  

#include <cmath>  

using namespace std;  

const int maxn=1e2+10;   

int n;  

int a[maxn][maxn];  

int dp[maxn][maxn];  

  

int max(int a,int b)  

{  

    return a>b?a:b;  

 }   

  

void solve()  

{  

    dp[1][1]=a[1][1];  

    for(int i=1;i<=2;i++)  

    {  

        for(int j=1;j<=n;j++)  

        {  

            if(i==1)  

                dp[i][j]=dp[i][j-1]+a[i][j];  

            else  

                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];   

        }  

    }  

}   

int main()  

{  

    while(~scanf("%d",&n))  

    {  

      

    memset(a,0,sizeof(a));  

    memset(dp,0,sizeof(dp));  

    for(int i=1;i<=2;i++)  

    {  

        for(int j=1;j<=n;j++)  

        {  

            scanf("%d",&a[i][j]);  

        }  

    }  

    solve();  

    printf("%d\n",dp[2][n]);  

}  

    return 0;  

} 