#include<cstdio>

int n,m,a[200010],c[200010],x,y,ans=0,b[200010];

int main(){

	scanf("%d%d",&n,&m);

	ans=n;

	for(int i=1;i<=n;i++){

		scanf("%d",&a[i]),c[a[i]]++;

		if(a[i]-c[a[i]]>=0) b[a[i]-c[a[i]]]++;

		if(a[i]-c[a[i]]>=0&&b[a[i]-c[a[i]]]==1)ans--;

	}

	for(int i=1;i<=m;i++){

		scanf("%d%d",&x,&y);

		if(a[x]-c[a[x]]>=0) b[a[x]-c[a[x]]]--;

		if(a[x]-c[a[x]]>=0&&b[a[x]-c[a[x]]]==0)ans++;

		c[a[x]]--;

		a[x]=y;

		c[a[x]]++;

		if(a[x]-c[a[x]]>=0) b[a[x]-c[a[x]]]++;

		if(a[x]-c[a[x]]>=0&&b[a[x]-c[a[x]]]==1)ans--;

		printf("%d\n",ans); 

	}

	return 0;

}