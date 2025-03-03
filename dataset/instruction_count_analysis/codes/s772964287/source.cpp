#include <cstdio>

typedef long long ll;

inline int rd(){

    int x=0,p=1;

    char a=getchar();

    while((a<48||a>57)&&a!='-')a=getchar();

    if(a=='-')p=-p,a=getchar();

    while(a>47&&a<58)x=(x<<1)+(x<<3)+(a&15),a=getchar();

    return x*p;

}

const int N=3002;

const ll mod=1e9+7;

int n,q;

int a[N];

ll f[N][N],ans;

inline ll fpow(ll b,ll p=mod-2){

	ll ans=1,tmp=b;

	while(p){

		if(p&1)ans=ans*tmp%mod;

		tmp=tmp*tmp%mod;

		p>>=1;

	}

	return ans;

}

int main(){

	n=rd(),q=rd();

	for(int i=1;i<=n;i++)a[i]=rd();

	for(int i=1;i<=n;i++)

		for(int j=1;j<=n;j++)

			f[i][j]=a[i]<a[j];

	ll inv=fpow(2);

	for(int i=1,x,y;i<=q;i++){

		x=rd(),y=rd();

		f[x][y]=f[y][x]=(f[x][y]+f[y][x])%mod*inv%mod;

		for(int j=1;j<=n;j++)

			if(j!=x&&j!=y){

				f[x][j]=f[y][j]=(f[x][j]+f[y][j])%mod*inv%mod;

				f[j][x]=f[j][y]=(f[j][x]+f[j][y])%mod*inv%mod;

			}

	}

	for(int i=1;i<=n;i++)

		for(int j=1;j<i;j++)

			ans=(ans+f[i][j])%mod;

	printf("%lld\n",ans*fpow(2,q)%mod);

    return 0;

}