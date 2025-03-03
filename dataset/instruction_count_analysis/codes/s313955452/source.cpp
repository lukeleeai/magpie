#include       <set>

#include       <map>

#include     <queue>

#include     <cmath>

#include    <cstdio>

#include    <cctype>

#include    <vector>

#include   <cstring>

#include <algorithm>

using namespace std;



typedef long long ll;

const ll mod = 1e9+7;

const double eps = 1e-7;

const int maxn = 105;



ll fast_pow(ll a,ll b,ll mod){

    ll ans = 1;

    while(b){

        if(b&1)

            ans = ans*a%mod;

        a = a*a%mod;

        b>>=1;

    }

    return ans;

}



int w[maxn], v[maxn];

int dp[maxn*4][maxn];



int main(){

    int n, W, c;

    scanf("%d%d",&n,&W);

    for(int i=0;i<n;i++)

        scanf("%d%d",&w[i],&v[i]);

    for(int i=1;i<n;i++)

        w[i] -= w[0]-1;

    c = w[0]-1;

    w[0] = 1;

    for(int i=0;i<n;i++)

        for(int j=(i+1)*4;j>=w[i];j--)

            for(int k=1;k<=i+1;k++){

                dp[j][k] = max(dp[j][k],dp[j-w[i]][k-1]+v[i]);

    }

    int ans = 0;

    for(int j=n*4;j>=0;j--)

        for(int k=1;k<=n;k++){

            if(1ll*k*c+j<=W){

                ans = max(ans,dp[j][k]);

            }

    }

    printf("%d\n",ans);

    return 0;

}


