#include"stdc++.h"

using namespace std;

const int N=510;

typedef long long ll;

int dp[N/2][N],mod,jc[N],n,L[N],R[N],ans,id[N];

int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin>>n>>mod;

	jc[0]=1;

	for(int i=1;i<=2*n;++i)jc[i]=(ll)jc[i-1]*i%mod;

	for(int i=0;i<2*n;++i){

		for(L[i]=0;i*i+L[i]*L[i]<n*n;++L[i]);

		for(R[i]=1;i*i+(2*n-R[i])*(2*n-R[i])>2*n*2*n;++R[i]);--R[i];

		id[i]=i;

	}

	for(int i=n;i<2*n;++i)L[i]=2*n-R[i];

	for(int i=0;i<2*n;++i)

		for(int j=i+1;j<2*n;++j)

			if(L[i]<L[j]||(L[i]==L[j]&&R[i]>R[j])){swap(L[i],L[j]);swap(R[i],R[j]);swap(id[i],id[j]);}

	for(int i=n;i<=2*n;++i){

		memset(dp,0,sizeof dp);dp[0][0]=1;

		int cnt=0,lim1=0,lim2=0;

		for(int j=0;j<2*n;++j)if(id[j]>=n){

			++cnt;lim1=min(lim1+1,i);

			for(int l=lim2;l>=0;--l){

				for(int k=lim1;k>=cnt;--k)

					dp[l][k]=dp[l][k-1]?(ll)dp[l][k-1]*(L[j]-(i-k))%mod:0;

				dp[l][cnt-1]=0;

			}

		}else{

			lim1=min(lim1+1,i);lim2=min(lim2+1,2*n-i);

			for(int l=lim2;l>=0;--l)for(int k=lim1;k>=cnt;--k)

				{

					if(dp[l][k-1])dp[l][k]=(dp[l][k]+(ll)dp[l][k-1]*(L[j]-(i-k)))%mod;

					if(l&&dp[l-1][k])dp[l][k]=(dp[l][k]+(ll)dp[l-1][k]*(R[j]-l+1))%mod;

				}

		}

		for(int j=0;j<=2*n-i;++j){

			int ret=(ll)dp[j][i]*jc[2*n-i-j]%mod;

			if((i-n+j)&1)ans=(ans-ret+mod)%mod;

			else ans=(ans+ret)%mod;

		}

	}

	cout<<ans<<'\n';

	return 0;

}