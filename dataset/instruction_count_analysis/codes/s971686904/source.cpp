#include"stdc++.h"

using namespace std;

const int N=510;

typedef long long ll;

int dp[N],mod,jc[N],n,L[N],R[N],ans,id[N];

int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin>>n>>mod;

	jc[0]=1;

	for(int i=1;i<=2*n;++i)jc[i]=(ll)jc[i-1]*i%mod;

	for(int i=0;i<2*n;++i){

		for(L[i]=0;i*i+L[i]*L[i]<n*n;++L[i]);

		for(R[i]=2*n-1;i*i+R[i]*R[i]>2*n*2*n;--R[i]);

		id[i]=i;

	}

	for(int i=n;i<2*n;++i)L[i]=R[i]+1;

	for(int i=0;i<2*n;++i)

		for(int j=i+1;j<2*n;++j)

			if(L[i]>L[j]||(L[i]==L[j]&&R[i]>R[j])){swap(L[i],L[j]);swap(R[i],R[j]);swap(id[i],id[j]);}

	for(int i=n;i<=2*n;++i){

		memset(dp,0,sizeof dp);dp[0]=1;

		int cnt=0,lim1=0;

		for(int j=0;j<2*n;++j)if(id[j]>=n){

			++cnt;lim1=min(lim1+1,i);

			for(int k=lim1;k>=cnt;--k)

				dp[k]=dp[k-1]?(ll)dp[k-1]*(L[j]-k+1)%mod:0;

			dp[cnt-1]=0;

		}else{

			lim1=min(lim1+1,i);

			for(int k=lim1;k>cnt;--k)dp[k]=((ll)dp[k]*(R[j]-(i+j-k)+1)+(ll)dp[k-1]*(L[j]-k+1))%mod;

			dp[cnt]=(ll)dp[cnt]*(R[j]-(i+j-cnt)+1)%mod;

		}

		if((i-n)&1)ans=(ans-dp[i]+mod)%mod;

		else ans=(ans+dp[i])%mod;

	}

	cout<<ans<<'\n';

	return 0;

}