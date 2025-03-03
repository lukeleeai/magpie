#include"stdc++.h"

#define N 1000005

#define p 998244353

#define int long long 

using namespace std;



inline void rd(int &x){

	x=0;char ch=0;int w=0;

	while(!isdigit(ch)) ch=getchar(),w|=ch=='-';

	while( isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();

	x=w?-x:x;

}



int n,m,ans;

int f[N],inv[N];



inline int POW(int a,int b=p-2,int ans=1){

	for(;b;b>>=1,a=a*a%p)

		if(b&1) ans=ans*a%p;

	return ans;

}



inline int C(int n,int m){

	return f[n]*inv[m]%p*inv[n-m]%p;

}

signed main(){

	cin>>n>>m;if(n<m) swap(n,m);

	for(int i=f[0]=inv[0]=1;i<=n+m;i++)

		f[i]=f[i-1]*i%p,inv[i]=POW(f[i]);

	for(int i=1;i<=m;i++)

		ans=(ans+C(i<<1,i)*C(n-i+m-i,n-i))%p;

	ans=ans*inv[2]%p*POW(C(n+m,n))%p;

	cout<<(ans+n)%p;

}