#include "stdc++.h"

#define REP(i,n,N) for(int i=n;i<N;i++)

#define p(S) cout<<(S)<<endl

using namespace std;

int dp[1001][1001];

int w[100010],c[100010];

int sumw[100010];

int main(){

	int n;

	cin>>n;

	REP(i,0,n) {

		cin>>c[i]>>w[i];

		if(i>0)	sumw[i]=sumw[i-1]+w[i];

		else sumw[i]=w[i];

	}

	REP(i,0,1001) REP(j,i,1001) dp[i][j]=j-i+1;

	REP(i,0,n-1)  if(c[i]>=w[i+1]||c[i+1]>=w[i]) dp[i][i+1]=1;





	for(int k=2;k<n;k++){

		for(int i=0;i+k<n;i++){

			if((dp[i+1][i+k]==1&&c[i]>=sumw[i+k]-sumw[i])||(dp[i][i+k-1]==1&&c[i+k]>=sumw[i+k-1]-(i?sumw[i-1]:0)))

				dp[i][i+k]=1;

			else dp[i][i+k]=min(dp[i+1][i+k],dp[i][i+k-1])+1;



			for(int j=i+1;j<i+k;j++)

				dp[i][i+k]=min(dp[i][i+k],dp[i][j]+dp[j+1][i+k]);

		}

	}

	p(dp[0][n-1]);

	return 0;

}