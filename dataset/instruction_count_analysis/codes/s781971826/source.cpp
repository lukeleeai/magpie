#include"stdc++.h"

using namespace std;

#define nn 502

#define int long long

int n,mod;int dp[nn][nn];

int li[nn],ri[nn];

int id[nn];

#define pii pair<int,int>

#define mp make_pair

pii make(int x){

	if(li[x]) return mp(li[x]-1,ri[x]);

	else return mp(ri[x],li[x]); 

}

int cmp(int x,int y){

	return make(x)<make(y);

}

void add(int &x,int y){

	x=(x+y)%mod;

}



int solve(int diss){

	memset(dp,0,sizeof dp);dp[0][0]=1;int cnt=0,tnc=0;;

	for(int i=0;i<n;i++){

		int x=id[i];

		if(li[x]){

			for(int j=0;j<=diss;j++){

				add(dp[i+1][j],dp[i][j]*max(0ll,ri[x]+1-n/2-tnc-(diss-j)));

				add(dp[i+1][j+1],dp[i][j]*max(0ll,li[x]-j-cnt));

			}

			tnc++;

		}

		else{

			for(int j=0;j<=diss;j++) add(dp[i+1][j],dp[i][j]*max(0ll,ri[x]-j-cnt+1));

			++cnt;

		}

	}

//	cout<<dp[n][diss]<<" ";

	return dp[n][diss];

}

signed main(){

	scanf("%lld%lld",&n,&mod);n=n*2;

	for(int i=0;i<n;i++){

		li[i]=-1,ri[i]=n,id[i]=i;

		for(int j=0;j<n;j++) if(i*i+j*j<n*n/4) li[i]=j;li[i]++;

		for(int j=n-1;j>=0;j--) if(i*i+j*j>n*n) ri[i]=j;ri[i]--;

	//s	cout<<li[i]<<" "<<ri[i]<<"\n";

	}

	

	sort(id,id+n,cmp);

	

	int flg=1,ans=0;

	for(int diss=0;diss<=n/2;diss++,flg=-flg)

		ans=(ans+flg*solve(diss))%mod;

	ans+=mod;ans%=mod;

	printf("%lld\n",ans);

	return 0;

}