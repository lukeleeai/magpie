#include"stdc++.h"

using namespace std;

int n,k,a[110],dp[101][100010];

long long qz[200000];

int main(){

	scanf("%d%d",&n,&k);

	for(int i=1;i<=n;i++)

	  scanf("%d",&a[i]);

	dp[0][k]=1;

	for(int i=1;i<=n;i++){

		memset(qz,0,sizeof(qz));

		for(int j=k;j>=0;j--)

		  qz[j]=qz[j+1]+dp[i-1][j];

		for(int j=k;j>=0;j--){

			dp[i][j]=(qz[j]-qz[j+a[i]+1])%(1000000007);

		}

	}

	printf("%d",dp[n][0]);

}