#include<cstdio>

#include<cstdlib>

#define min(a,b) (a<b?a:b)

const int clz=998244353;

#define mod clz

long long matm(long long val,long long k){

	long long ret=1;

	while(k){

		if(k&1) ret=ret*val%mod;

		k>>=1; val=val*val%mod;

	}

	return ret;

}

int n,k;

long long pw[100005],pu[100005],inv[100005];

inline long long C(int n,int m){if(m<0||m>n) return 0;return (pu[n]*inv[m]%mod)*inv[n-m]%mod;}

long long getans(int val){

	if(val&1){

		long long ans=0;

		int gro=min(k-val/2,val/2);

		int p=k-gro*2;

		//if(p==0) exit(0);

		for(int i=(p==0)?1:0;i<=gro;i++) {ans+=(C(n+p-1,i+p-1)*pw[i]%mod)*C(gro,i)%mod; ans%=mod;}

		return ans;

	}

	else{

		long long ans=0;

		int gro=min(k-val/2+1,val/2);

		int p=k-gro*2+1;

		//if(p==0) exit(0);

		for(int i=(p==0)?1:0;i<gro;i++) {ans+=(C(n+p-1,i+p-1)*pw[i]%mod)*C(gro-1,i)%mod; ans%=mod;}

		for(int i=(p==0)?1:0;i<gro;i++) {ans+=(C(n+p-2,i+p-1)*pw[i]%mod)*C(gro-1,i)%mod; ans%=mod;}

		return ans;

	}

}

int main(){

	pu[0]=pw[0]=1;

	for(int i=1;i<=100000;i++) pu[i]=pu[i-1]*i%mod;

	for(int i=1;i<=100000;i++) pw[i]=pw[i-1]*2%mod;

	inv[100000]=matm(pu[100000],mod-2);

	for(int i=99999;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;

	scanf("%d%d",&k,&n);

	for(int i=2;i<=2*k;i++) printf("%lld\n",getans(i));

	return 0;

}