#include<cstdio>

#include<algorithm>

#include<iostream>

#include<cstring>

using namespace std;

int n,m;

struct qq

{

int  p,c;

}s[15];

int f[1000005];

int sum=0;

int main()

{

	scanf("%d%d",&n,&m);m/=100;



	memset(f,63,sizeof(f));	f[0]=0;

	for (int u=1;u<=n;u++)		

	{

		scanf("%d%d",&s[u].p,&s[u].c);

		s[u].c/=100;

		sum=sum+s[u].p*u+s[u].c;

	}

	for (int u=1;u<=n;u++)

		for (int i=sum;i>=0;i--)

		{

			if (i>=u*s[u].p+s[u].c)	f[i]=min(f[i],f[i-u*s[u].p-s[u].c]+s[u].p);

			for (int j=1;j<s[u].p;j++)	

			{

			//	if (i==2) printf("YES%d %d\n",j,i-u*j);

				if (i>=u*j) 	f[i]=min(f[i],f[i-u*j]+j);

			}

		//	printf("%d %d %d\n",i,f[i],u*s[u].p+s[u].c);

		}

	int ans=f[m];

	for (int u=m+1;u<=sum;u++) ans=min(ans,f[u]);

	printf("%d\n",ans);

	return 0;

}