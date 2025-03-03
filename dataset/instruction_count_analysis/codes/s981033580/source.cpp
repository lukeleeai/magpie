#include <algorithm>

#include <cstdio>



const int N=20,M=7e4+5,mod=1e9+7;

int n,m,lim,fac[M],inv[M],a[N],f[N][M],digit[M],ans;



inline int combn(int n,int m){

	if(n<m) return 0;

	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;

}



int main(){

	scanf("%d%d",&n,&m); lim=1<<n; fac[0]=inv[0]=inv[1]=1;

	for(int i=1;i<=m;++i) scanf("%d",&a[i]);

	for(int i=1;i<=lim;++i) fac[i]=1ll*fac[i-1]*i%mod;

	for(int i=2;i<=lim;++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;

	for(int i=1;i<=lim;++i) inv[i]=1ll*inv[i-1]*inv[i]%mod;

	std::sort(a+1,a+1+m); f[m+1][0]=1;

	for(int i=m;i>=1;--i){

		for(int j=0;j<lim;++j){

			f[i][j]=(f[i][j]+f[i+1][j])%mod;

			for(int k=0;k<n;++k) if(!((j>>k)&1)){

				int tmp=1ll*combn(lim-j-a[i],(1<<k)-1)*fac[1<<k]%mod;

				f[i][j+(1<<k)]=(f[i][j+(1<<k)]+1ll*tmp*f[i+1][j])%mod;

			}

		}

	}

	for(int j=0;j<lim;++j){

		digit[j]=digit[j>>1]+(j&1);

		int tmp=1ll*fac[lim-1-j]*f[1][j]%mod;

		if(digit[j]&1) ans=(ans+mod-tmp)%mod;

		else ans=(ans+tmp)%mod;

	}

	printf("%d\n",1ll*ans*lim%mod);

	return 0;

}