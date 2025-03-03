#include <cstdio>

const int MAXN=2E5+10;

typedef long long LL;

LL mod;

LL powi(LL a,LL b) {

	LL ans=1;

	while(b) {

		if(b&1)ans=ans*a%mod;

		a=a*a%mod;

		b>>=1;

	}return ans;

}

LL inv(LL x) {

	return powi(x,mod-2);

}

LL tong[MAXN],a[MAXN];

int main() {

	LL n;scanf("%lld%lld",&n,&mod);

	for(int i=1;i<=n;++i) {

		scanf("%1lld",&a[i]);

	}

	if(mod==2 || mod==5) {

		LL ans=0;

		for(int i=1;i<=n;++i) {

			if(a[i]%mod==0) {

				ans+=i;

			}

		}printf("%lld\n",ans);

	}else {

		LL hx=0,pi=1,inv10=inv(10),ans=0;

		tong[hx]++;

		for(int i=1;i<=n;++i) {

			hx=(hx*10+a[i])%mod;

			pi=pi*inv10%mod;

			ans+=tong[hx*pi%mod];

			tong[hx*pi%mod]++;

		}printf("%lld\n",ans);

	}

	return 0;

} 