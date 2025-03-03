#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

//#define int long long

using namespace std;

const int maxn=5e5+1000;

typedef long long ll;

int n,m;

const int mod=998244353;

int fr[maxn],ans;

inline int ksm(int num,int t){

	int res=1;

	for(;t;t>>=1,num=1ll*num*num%mod){

		if(t&1)res=1ll*res*num%mod;

	}

	return res;

}

inline int c(int m,int n){

	return 1ll*fr[n]*ksm((1ll*fr[m]*fr[n-m])%mod,mod-2)%mod;	

}

int main(){

	ios::sync_with_stdio(0);

	cin>>n>>m;

	fr[0]=fr[1]=1;

	for(int i=2;i<maxn;i++)fr[i]=1ll*fr[i-1]*i%mod;	

	for(int i=0;i<=min(n,m);i++){

		ans=(ans+1ll*ksm(-1,i)*(1ll*c(i,n)*c(i,m)%mod*fr[i]%mod*ksm(m+1,n-i)%mod*ksm(n+1,m-i)%mod)%mod)%mod;	

	}

	ans=(ans%mod+mod)%mod;

	cout<<ans;

	return 0;

}//