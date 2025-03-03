#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <algorithm>

#define inf 0x3f3f3f3f

#define inf64 0x3f3f3f3f3f3f3f3f

using namespace std;

typedef long long ll;

const int maxn = 2e3+10;

int dp[maxn][maxn],a[maxn][maxn];



int main(){

    int n,m,ans=0;

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);

    }

    for(int i=1;i<=n;i++){

        for(int j=m;j>=1;j--){

            if(a[i][j]) dp[i][j]=0;

            else dp[i][j]=min(min(dp[i-1][j],dp[i][j+1]),dp[i-1][j+1])+1;

            ans=max(ans,dp[i][j]);

//            printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);

        }

    }

    printf("%d\n",ans*ans);

    return 0;

}


