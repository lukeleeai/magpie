#include<cstdio>

#include<algorithm>

using namespace std;

typedef long long ll;

const int Mod=1e9+7;

const int Maxn=2*100000;

int H,W,A,B;

ll f[Maxn+10],inv[Maxn+10];

int N;

ll PowMod(ll a,int b) {

	ll ret=1;

	while(b) {

		if(b&1)ret=ret*a%Mod;

		a=a*a%Mod;

		b>>=1;

	}

	return ret;

}

void Init() {

	f[0]=1;

    for(int i=1;i<=N;i++)

        f[i]=f[i-1]*i%Mod;

    inv[0]=1;

    inv[N]=PowMod(f[N],Mod-2);

    for(int i=N-1;i>0;i--)

        inv[i]=inv[i+1]*(i+1)%Mod;

}

ll C(int a,int b) {

	if(a<0||b<0)return 1;

	return f[a]*inv[b]%Mod*inv[a-b]%Mod;

}

int main() {

	#ifdef LOACL

	freopen("in.txt","r",stdin);

	freopen("out.txt","w",stdout);

	#endif

	scanf("%d %d %d %d",&H,&W,&A,&B);

	N=H+W-2;

	Init();

	ll ans=C(H+W-2,H-1);

	for(ll i=1;i<=B;i++) {

		ans-=C(H-A+i-2,H-A-1)*C(A-1+W-i,A-1)%Mod;

		ans=(ans%Mod+Mod)%Mod;

	}

	printf("%lld",ans);

	return 0;

}