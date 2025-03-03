#include<cstdio>

#include<iostream>

#include<cmath>

#include<algorithm>

#include<cstring>

#include<vector>

#define cri const int

#define ll long long

#define int ll

using namespace std;

vector<int>to[52];

int is[52];

ll w[52],v[52],dp[125010];

void dfs(cri x){

	w[x]=1;

	for(int y:to[x]) dfs(y),w[x]+=w[y],v[x]+=v[y];

}

inline int as(cri x,cri y){ return w[x]*v[y]>w[y]*v[x]; }

signed main(){

	int n,X,d,sum=0;

	cin>>n>>X>>d>>v[1];is[1]=1;

	for(int i=2,x;i<=n;i++){

		cin>>v[i]>>x;is[i]=i;

		to[x].push_back(i);

	}

	dfs(1);

	sort(is+1,is+n+1,as);

	memset(dp,0x3f,sizeof dp);dp[0]=0;

	cri mn=min(d,n);

	for(int i=1;i<=n;i++){

		int lst=mn;

		for(int j=1;j<=lst;j<<=1){

			sum+=j*w[i];

			for(int k=sum;k>=j*w[i];k--) dp[k]=min(dp[k],dp[k-j*w[i]]+j*v[i]);

			lst-=j;

		}

		if(lst){

			cri j=lst;

			sum+=j*w[i];

			for(int k=sum;k>=j*w[i];k--) dp[k]=min(dp[k],dp[k-j*w[i]]+j*v[i]);

		}

	}//cout<<1<<endl;

	ll ans=0;

	for(int s=0;s<=sum;s++) if(dp[s]<=X){

		int lst=X-dp[s];ll tmp=s;

		for(int i=1;i<=n;i++){

			cri x=is[i],num=x==1?lst/v[x]:min((ll)d-mn,lst/v[x]);

			tmp+=num*w[x];lst-=num*v[x];

		}

		//cout<<tmp<<endl;

		ans=max(ans,tmp);

	}

	cout<<ans<<endl;

}