#include "stdc++.h"

using namespace std;

int n,m,b[100010],d[100010],c[100010];

int main(){

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++){

		int x;

		scanf("%d",&x);

		b[x%m]++;

		c[x]++;

		if(c[x]%2==0)d[x%m]++;

	}

	int ans=0;

	for(int x=0;x<m;x++){

		int y=m-x;

		if(y==x||y==m)ans+=b[x]/2;

		else{

			ans+=min(b[x],b[y]);

			if(b[x]<b[y])ans+=min((b[y]-b[x])/2,d[y]);

			else ans+=min((b[x]-b[y])/2,d[x]);

		}



		//printf("%d %d %d %d %d %d %d\n",x,y,b[x],b[y],d[x],d[y],ans);

		b[x]=b[y]=0;

		d[x]=d[y]=0;

	}

	printf("%d\n",ans);

	return 0;

}
