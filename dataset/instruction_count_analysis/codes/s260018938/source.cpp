#include <cstdio>

#include <algorithm>

#include <cstring>

#include <set>

#include <map>

#include <iostream>

#include <cstring>

#include <cmath>

#include <queue>

#define ull unsigned long long

#define ll long long

#define INF 0x3f3f3f3f

using namespace std;

void close(){

       std::ios::sync_with_stdio(false);

       std::cin.tie(0);

}

const ll mod=1e9+7;

ll qpow(ll a,ll b){

	ll ret=1;

	while(b) {

		if (b&1) ret=(ret*a)%mod;

		a=(a*a)%mod;

		b>>=1;

	}

	return ret;

}

const int maxn=1e4+5;

const int N=1e6+5;

int n,a[maxn],num[N],lcm=1,ans=0;

int main(){

	cin>>n;

	for(int i=1;i<=n;i++) cin>>a[i];

	for(int i=1;i<=n;i++) {

		int x=a[i];

		for(int j=2;j*j<=x;j++){

			if(x%j==0){

				int cnt=0;

				while(x%j==0){

					x/=j,cnt++;

				}

				num[j]=max(num[j],cnt);

			}

		}

		if(x!=1) num[x]=max(num[x],1);

	}

	for(int i=2;i<N;i++) 

		if(num[i]){

			lcm=1ll*lcm*qpow(i,num[i])%mod;

		}

	for(int i=1;i<=n;i++){

		ans=(ans+1ll*lcm*qpow(a[i],mod-2)%mod)%mod;

	}

	cout<<ans<<endl;

}