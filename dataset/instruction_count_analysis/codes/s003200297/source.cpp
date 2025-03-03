#include<iostream>

#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<queue>

#include<stack>

#include<vector>

#include<map>

#define int long long 

using namespace std;

const int maxn = 1e6+10;



int read(){

	int x=0,f=1;

	char c=getchar();

	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}

	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}

	return x*f;

}



int k,m,n;

int a[maxn];

int dp[maxn][2],sum[maxn][2],max_[maxn];

signed main(){

	n=read();

	for(register int i=1;i<=n;i++)a[i]=read();

	for(register int i=1;i<=n;i++){

		sum[i][0]=sum[i-1][0];

		sum[i][1]=sum[i-1][1];

		if(i%2==0)sum[i][0]+=a[i];

		else sum[i][1]+=a[i];

	}

	if(n%2==0){

		int sum1=0,sum2=0;

		for(register int i=1;i<=n;i++){

			if(i%2==1)sum1+=a[i];

			else sum2+=a[i];

		}

		int ans=max(sum1,sum2);

		for(register int i=1;i<=n;i+=2){

			ans=max(ans,sum[i][1]+sum[n][0]-sum[i+1][0]);

		}

		printf("%lld\n",ans);

		return 0;

	}



	int ans=-1e16;

	for(register int i=1;i<n;i++){

		int summ=0,x=(i-1)%2;

		summ+=sum[i-1][x];

		summ+=sum[n][x^1]-sum[i+1][x^1];

		ans=max(ans,summ);

	}

	int summ=sum[n][(n-1)%2];

	ans=max(ans,summ); 

	for(register int i=1;i<n;i+=2){

		max_[i]=summ+sum[i+1][1]-sum[i+1][0];

	//	cout<<i<<" "<<max_[i]<<" "<<sum[i+1][1]<<endl;

		if(i>2)max_[i]=max(max_[i],max_[i-2]);

	}

	int maxx=0;

	for(register int i=n-1;i>1;i-=2){

		maxx=max(maxx,(sum[n][1]-sum[i-1][1])-(sum[n][0]-sum[i-1][0]));

		//cout<<i<<" "<<maxx<<" "<<max_[i+1]<<" "<<(sum[n][1]-sum[i-1][1])<<" "<<(sum[n][0]+sum[i-1][0])<<endl;

		ans=max(ans,max_[i-1]+maxx);

	}

	printf("%lld\n",ans);

	return 0;

}