#include"stdc++.h"

using namespace std;

int n,m,c[1000005],d,f[1000005],a[1000005],q;

int main(){

	scanf("%d%d",&n,&m); d=m;

	for (int i=1;i<=n;i++){

		scanf("%d",&a[i]);

		if (abs(d-a[i])<d) d=abs(d-a[i]);

		c[i]=d;

	}

	f[n+1]=1;

	for (int i=n;i>=1;i--){

		f[i]=f[i+1];

		if (abs(f[i]-a[i])<f[i]) f[i]=f[i]+a[i];

	}

	c[0]=m;

	scanf("%d",&q);

	for (int i=1;i<=q;i++){

		int x;

		scanf("%d",&x);

		if (c[x-1]>=f[x+1]) printf("YES\n");

		else printf("NO\n");

	}

	return 0;

}