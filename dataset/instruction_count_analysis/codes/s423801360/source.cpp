// https://atcoder.jp/contests/abc136/submissions/6750279

// #pragma GCC target("avx2")  // CPU 処理並列化

// #pragma GCC optimize("O3")  // CPU 処理並列化

// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす

#include<stdio.h>

#include<math.h>

#include<algorithm>

#include<queue>

#include<deque>

#include<stack>

#include<string>

#include<string.h>

#include<vector>

#include<set>

#include<map>

#include<bitset>

#include<stdlib.h>

#include<cassert>

#include<time.h>

#include<bitset>

#include<numeric>

using namespace std;

const long long mod=998244353;

const long long inf=mod*mod;

const long long d2=(mod+1)/2;

const double EPS=1e-10;

const double INF=1e+10;

const double PI=acos(-1.0);

const int C_SIZE = 3121000;

long long fact[C_SIZE];

long long finv[C_SIZE];

long long inv[C_SIZE];

long long Comb(int a,int b){

 	if(a<b||b<0)return 0;

 	return fact[a]*finv[b]%mod*finv[a-b]%mod;

}

void init_C(int n){

	fact[0]=finv[0]=inv[1]=1;

	for(int i=2;i<n;i++){

		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;

	}

	for(int i=1;i<n;i++){

		fact[i]=fact[i-1]*i%mod;

		finv[i]=finv[i-1]*inv[i]%mod;

	}

}

long long pw(long long a,long long b){

	if(a<0LL)return 0;

	if(b<0LL)return 0;

	long long ret=1;

	while(b){

		if(b%2)ret=ret*a%mod;

		a=a*a%mod;

		b/=2;

	}

	return ret;

}

int ABS(int a){return max(a,-a);}

long long ABS(long long a){return max(a,-a);}

double ABS(double a){return max(a,-a);}

int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }

// ここから編集しろ

long long gcd(long long a,long long b){

	while(a){b%=a;swap(a,b);}return b;

}

long long p[510];

int n;

int K;

long long tmp[510];

long long L[510];

long long R[510];

bool chk(long long a){

	for(int i=0;i<n;i++){

		tmp[i]=p[i]%a;

	}

	std::sort(tmp,tmp+n);

	long long ret=K+1;

	for(int i=0;i<n;i++){

		L[i+1]=L[i]+tmp[i];

		R[i+1]=R[i]+(a-tmp[n-1-i]);

	}

	for(int i=0;i<=n;i++){

		if(L[i]==R[n-i]){

			ret=L[i];break;

		}

	}

	if(ret<=K)return true;

	return false;

}

int main(){

	int a,b;scanf("%d%d",&a,&b);n=a;

	K=b;

	for(int i=0;i<a;i++)scanf("%lld",p+i);

	long long sum=0;

	for(int i=0;i<a;i++)sum+=p[i];

	long long ret=0;

	for(int i=1;i*i<=sum;i++){

		if(sum%i==0){

			if(i>ret&&chk(i))ret=i;

			if(sum/i>ret&&chk(sum/i))ret=sum/i;

		}

	}

	printf("%lld\n",ret);

}
