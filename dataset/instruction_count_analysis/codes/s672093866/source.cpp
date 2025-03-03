#include"stdc++.h"

#define ll long long

#define N 100005

using namespace std;

int n,tot,a[N],b[N],c[N],e[N],d[N*3];

ll ans,v[N*3];

void add(int x,ll y){

	for (;x<=tot;x+=x&(-x)) v[x]+=y;

}

ll ask(int x){

	ll s=0;

	for (;x;x-=x&(-x)) s+=v[x];

	return s; 

}

int main(){

	scanf("%d",&n);

	for (int i=1;i<=n;i++)

		scanf("%d",&a[i]),d[++tot]=a[i];

	for (int i=1;i<=n;i++)

		scanf("%d",&b[i]),d[++tot]=b[i];

	for (int i=1;i<=n;i++)

		scanf("%d",&c[i]),d[++tot]=c[i];

	sort(d+1,d+tot+1);

	for (int i=1;i<=n;i++){

		a[i]=lower_bound(d+1,d+tot+1,a[i])-d;

		add(a[i],1);

	}

	for (int i=1;i<=n;i++){

		b[i]=lower_bound(d+1,d+tot+1,b[i])-d;

		e[i]=ask(b[i]-1);

	}

	memset(v,0,sizeof(v));

	for (int i=1;i<=n;i++)

		add(b[i],e[i]);

	for (int i=1;i<=n;i++){

		c[i]=lower_bound(d+1,d+tot+1,c[i])-d;

		ans+=ask(c[i]-1);

	}

	printf("%lld",ans);

}