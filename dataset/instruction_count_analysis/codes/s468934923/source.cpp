#include"stdc++.h"

using namespace std;

int n,cnt[100003],cntt[16],ans;

int dp[65536];

int main(){

	cin>>n;

	for(int i=1;i<n;i++){int x,y,a;cin>>x>>y>>a;cnt[x]^=a;cnt[y]^=a;}

	for(int i=0;i<n;i++)cntt[cnt[i]]++;

	for(int i=1;i<16;i++)ans+=cntt[i]/2,cntt[i]%=2;

	int tmp=0;for(int i=1;i<16;i++)tmp=tmp+cntt[i]*(1<<i);

	memset(dp,31,sizeof(dp));

	dp[tmp]=0; 

	for(int i=tmp;i>0;i-=2)

		if(dp[i]<20000000)

			for(int j=1;j<16;j++)

				for(int k=j+1;k<16;k++)

					if((i|(1<<j))==i&&(i|(1<<k))==i)

						for(int l=1;l<=j;l++)

							if(((j|k)|l)==(j|k))

								dp[(((i-(1<<j)-(1<<k))^(1<<(j^l)))^(1<<(k^l)))/2*2]=min(dp[i]+1+bool((i&(1<<(j^l)))!=0)+

								bool((i&(1<<(k^l)))!=0),dp[(((i-(1<<j)-(1<<k))^(1<<(j^l)))^(1<<(k^l)))/2*2]);

	cout<<ans+dp[0];

}