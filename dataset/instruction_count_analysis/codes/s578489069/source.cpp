#include "stdc++.h"

#define LL long long

using namespace std;

int n,a,b,c,d;

const int N=1003;

const int mod=1e9+7;

int f[N],dp[N],C[N][N],power[N],F[N][N];



int mu(int x,int m)

{

    if (m==1) return x;

    int c=mu(x,m/2);

    c=(LL)c*c%mod;

    if (m%2==0) return c;

    return (LL)c*x%mod;

}

int main()

{

   

    ios_base::sync_with_stdio(0);

    cin.tie(0);cout.tie(0);

    cin>>n>>a>>b>>c>>d;

    dp[0]=1;

    for (int i=0;i<=n;i++) C[i][i]=C[i][0]=1;

    for (int i=2;i<=n;i++)

    for (int j=1;j<i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;

    power[0]=1;

    for (int i=1;i<=n;i++) power[i]=((LL)power[i-1]*i)%mod;

    power[n]=mu(power[n],mod-2);

    for (int i=n-1;i>=0;i--) power[i]=(LL)power[i+1]*(i+1)%mod;

    for (int i=1;i<=n;i++) F[0][i]=1;

    for (int i=1;i<=n;i++)

    for (int j=i;j<=n;j+=i)

         F[j][i]=(LL)F[j-i][i]*C[j][i]%mod;

    for (int i=1;i<=n;i++)

    for (int j=i;j<=n;j+=i)

    {

        F[j][i]=(LL)F[j][i]*power[j/i]%mod;

        //cout<<j<<" "<<i<<" "<<F[j][i]<<"\n";

    }

    dp[0]=1;

    for (int i=a;i<=b;i++)

    {

        for (int h=0;h<=n;h++) f[h]=dp[h];

        for (int j=c;j<=d;j++)

        {

            int k=i*j;

            for (int h=k;h<=n;h++)

            {

                dp[h]=(dp[h]+((LL)f[h-k]*F[k][i]%mod)*C[n-h+k][k]%mod)%mod;

                //cout<<i<<" "<<j<<" "<<h<<" "<<dp[h]<<" "<<f[h-k]<<"\n";

            }

        }

    }

    cout<<dp[n];

    return 0;

}
