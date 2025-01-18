#include"stdc++.h"

using namespace std;

typedef long long ll;

const int inf=0x3f3f3f3f;

const int N=2e5+5;

int a[N],dp[N],n,k;

int main(){

	cin>>n>>k;

	for(int i=1;i<=n;++i)

		cin>>a[i];

	dp[1]=0;

    dp[0]=0;

    for(int i=2;i<=n;++i)

    	dp[i]=inf;

    for(int i=2;i<=n;++i)

      for(int j=i-1;j>=max(1,i-k);j--)

            dp[i]=min(dp[i],dp[j]+abs(a[i]-a[j]));	

		cout<<dp[n];

	return 0;

} 