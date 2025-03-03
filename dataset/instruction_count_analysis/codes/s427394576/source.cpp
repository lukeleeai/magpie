#include<cstdio>

#define N 2002

#define p 924844033

inline int mod(int x){return x<p?x:x-p;}

int a[N],f[N][2],i,j,m,n,s,x;

int main()

{

	scanf("%d%d",&n,&m),f[0][0]=1;

	for(i=1;i<=m;i++)

	{

		for(j=0;j<=n;f[j++][0]=0)f[j][1]=mod(f[j][0]+f[j][1]);

		for(s=(n-i)/m+2>>1;s--;)

		for(j=n;j--;)

		{

			f[j+1][0]=mod(f[j+1][0]+f[j][0]);

			f[j+1][1]=mod(f[j+1][1]+mod(f[j][0]+f[j][1]));

			f[j][0]=mod(f[j][0]+f[j][1]);

			f[j][1]=0;

		}

		if(~((n-i)/m)&1)for(j=0;j<=n;j++)f[j][1]=0;

	}

	for(;i<=n&&i<=m<<1;i++)

	{

		for(j=0;j<=n;f[j++][1]=0)f[j][0]=mod(f[j][0]+f[j][1]);

		for(s=(n-i)/m+2>>1;s--;)

		for(j=n;j--;)

		{

			f[j+1][0]=mod(f[j+1][0]+f[j][0]);

			f[j+1][1]=mod(f[j+1][1]+mod(f[j][0]+f[j][1]));

			f[j][0]=mod(f[j][0]+f[j][1]);

			f[j][1]=0;

		}

		if(~((n-i)/m)&1)for(j=0;j<=n;j++)f[j][1]=0;

	}

	for(i=*a=1;i<=n;i++)a[i]=(long long)a[i-1]*i%p;

	for(i=0;i<=n;i++)x=i&1?(x+(long long)(p-a[n-i])*(f[i][0]+f[i][1]))%p:(x+(long long)a[n-i]*(f[i][0]+f[i][1]))%p;

	return 0&printf("%d\n",x);

}