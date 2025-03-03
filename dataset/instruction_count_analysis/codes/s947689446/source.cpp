#include "stdc++.h"



using namespace std;



typedef long long ll;



const int N=200050;

const ll MOD=1e9+7;

int n;

int a[N],p[N];

ll f[N];



int main(){

	scanf("%d",&n);

	for (int i=1;i<=n;++i) scanf("%d",&a[i]);

	f[0]=0;f[1]=1;

	memset(p,0,sizeof(p));p[a[1]]=1;

	for (int i=2;i<=n;++i){

		f[i]=f[i-1];

		if (a[i]!=a[i-1])

			f[i]=(f[i]+f[p[a[i]]])%MOD;

		p[a[i]]=i;

	}

	printf("%lld\n",f[n]);

}