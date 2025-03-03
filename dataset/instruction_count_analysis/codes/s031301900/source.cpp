#include<cstdio>

#include<algorithm>

#include<bitset>

#define rep(i,l,r) for (int i=(l); i<=(r); i++)

using namespace std;



const int mod=998244353,N=305;

int mi[N],n,m,k,ans,a[N][N];

bitset<N>b[N],x;



int main(){

	mi[0]=1; rep(i,1,300) mi[i]=2ll*mi[i-1]%mod;

	scanf("%d%d",&n,&m);

	rep(i,1,n){

		x.reset(); int l=-1;

		rep(j,0,m-1) scanf("%d",a[i]+j),x.set(j,a[i][j]);

		rep(j,0,m-1) if (x[j]){

			if (b[j].any()) x^=b[j]; else{ b[j]=x; l=j; break; }

		}

		if (l==-1) k++;

	}

	ans=(1ll*mi[m]*mi[k]+1ll*mi[m-1]*(mi[n]+mod-mi[k]))%mod;

	printf("%lld\n",(1ll*mi[n]*mi[m]+mod-ans)%mod);

	return 0;

}