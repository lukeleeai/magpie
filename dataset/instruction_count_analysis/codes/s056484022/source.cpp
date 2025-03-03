#include<cstdio>

int a[2001][2001],sum1[2001][2001],sum2[2001][2001],sum[2001][2001],n,m,q;

char c[2005];

int main()

{

	scanf("%d%d%d",&n,&m,&q);

	for(int i=1;i<=n;++i){

		scanf("%s",c);

		for(int j=0;j<m;++j)a[i][j+1]=c[j]-48,sum[i][j+1]=sum[i-1][j+1]+sum[i][j]-sum[i-1][j]+a[i][j+1];

	}

	for(int i=1;i<n;++i)for(int j=1;j<=m;++j)sum1[i][j]=sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1]+(a[i][j]&a[i+1][j]);

	for(int i=1;i<=n;++i)for(int j=1;j<m;++j)sum2[i][j]=sum2[i-1][j]+sum2[i][j-1]-sum2[i-1][j-1]+(a[i][j]&a[i][j+1]);

	while(q--){

		int x,y,z,w,b,c,d;

		scanf("%d%d%d%d",&x,&y,&z,&w);

		b=sum[z][w]-sum[z][y-1]-sum[x-1][w]+sum[x-1][y-1];

		c=sum2[z][w-1]-sum2[z][y-1]-sum2[x-1][w-1]+sum2[x-1][y-1];

		d=sum1[z-1][w]-sum1[z-1][y-1]-sum1[x-1][w]+sum1[x-1][y-1];

		printf("%d\n",b-c-d);

	}

	return 0;

}