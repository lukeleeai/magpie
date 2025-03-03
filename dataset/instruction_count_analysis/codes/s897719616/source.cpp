#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

#define SF scanf

#define PF printf

#define MAXN 110

#define MOD 1000000007

#define eisiorti sort

using namespace std;

int a[MAXN];

int n;

int dp[MAXN/2][MAXN][MAXN];

int main(){

	SF("%d",&n);

	for(int i=1;i<=2*n-1;i++)

		SF("%d",&a[i]);

	eisiorti(a+1,a+2*n);

	dp[n][1][0]=1;

	for(int i=n;i>=2;i--){

		int al=(a[i-1]!=a[i]);

		int ar=(a[2*n-i+1]!=a[2*n-i]);

		for(int l=0;l<=2*n-1;l++)

			for(int r=0;r+l<=2*n-1;r++)

				if(dp[i][l][r]){

					for(int dl=1;dl<=l+al;dl++)

						(dp[i-1][l+al-dl+1][r+ar+(dl>1)]+=dp[i][l][r])%=MOD;	

					for(int dr=1;dr<=r+ar;dr++)

						(dp[i-1][l+al+1][r+ar-dr]+=dp[i][l][r])%=MOD;	

				}

	}

	int ans=0;

	for(int l=0;l<=2*n-1;l++)

		for(int r=0;r+l<=2*n-1;r++)

			(ans+=dp[1][l][r])%=MOD;

	PF("%d",ans);

}