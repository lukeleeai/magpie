#include<iostream>

#include<cstdio>

using namespace std;



#define mod 998244353

int n,x[205],y[205];



int qpow(int x,int y){

	int ans=1;

	while(y){

		if(y&1)ans=1LL*ans*x%mod;

		y>>=1,x=1LL*x*x%mod;

	}

	return ans;

}



bool check(int i,int j,int k){

	int a=1LL*(y[j]-y[i])*(x[k]-x[j])%mod;

	int b=1LL*(y[k]-y[j])*(x[j]-x[i])%mod;

	return a==b;

}



int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		scanf("%d%d",x+i,y+i);

	int ans=((qpow(2,n)-(1LL*n*(n-1)>>1)%mod-n-1)%mod+mod)%mod;

	for(int i=1;i<=n;i++){

		for(int j=i+1;j<=n;j++){

			int sum=0;

			for(int k=j+1;k<=n;k++){

				if(k==i||k==j)continue;

				if(check(i,j,k))sum++;

			}

			ans=(ans-qpow(2,sum)+1+mod)%mod;

		}

	}

	printf("%d",ans);

	

} 