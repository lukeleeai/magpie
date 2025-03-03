#include<cstdio>

#include<cstring>

#include<algorithm>

#define ll long long

using namespace std;

const int N=2010,M=4000010;

const ll mod=1e9+7;

ll dp[N][N],d1[M],d2[M];

int n,k,max1;

inline ll f(ll y,ll x){

	ll t=y,s=1;if(x%2)s=y;x>>=1;

	while(x){t=(t*t)%mod;if(x%2)s=(s*t)%mod;x>>=1;}

	return s;

}

inline ll c(int m,int n){

	//printf("c%d %d %lld\n",m,n,((d1[n]*d2[m])%mod*d2[n-m])%mod);

	return ((d1[n]*d2[m])%mod*d2[n-m])%mod;

}

int main(){

	scanf("%d%d",&n,&k);max1=n*k;

	if(k==1){printf("1");return 0;}

	d1[0]=1;d2[0]=1;

	for(int i=1;i<=max1;i++)d1[i]=(d1[i-1]*i)%mod;

	d2[max1]=f(d1[max1],mod-2);//printf("%lld ",d2[max1]);

	for(int i=max1-1;i>=1;i--)d2[i]=(d2[i+1]*(i+1))%mod;

	dp[1][0]=1;dp[1][1]=(c(k-2,max1-2)*n)%mod;//printf("1 1 %lld\n",dp[1][1]);

	for(int i=2;i<=n;i++){

		dp[i][0]=1;

		for(int j=1;j<=i;j++){

			dp[i][j]=(dp[i-1][j]+((dp[i][j-1]*c(k-2,max1-i-1-(j-1)*(k-1)))%mod*(n-j+1))%mod)%mod;

			//printf("%d %d %lld\n",i,j,dp[i][j]);

		}

	}

	printf("%lld",dp[n][n]);

	return 0;

} 