#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 510

#define MAXM 250010

int a[MAXM],f[MAXN],x[MAXN],n,ls=1;

bool cmp(int a,int b)

{

	return x[a]<x[b];

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

	{

		scanf("%d",&x[i]);

		a[x[i]]=i;

		f[i]=i;

	}

	sort(f+1,f+1+n,cmp);

	for(int i=1;i<=n;i++)

	{

		int k=f[i];

		for(int j=1;j<k;j++)

		{

			while(a[ls]) ls++;

			if(ls>x[k])

			{

				printf("No\n");

				return 0;

			}

			a[ls]=k;

		}

	}

	for(int i=1;i<=n;i++)

	{

		int k=f[i];

		for(int j=1;j<=n-k;j++)

		{

			while(a[ls]) ls++;

			if(ls<x[k]||ls>n*n)

			{

				printf("No\n");

				return 0;

			}

			a[ls]=k;

		}

	}

	printf("Yes\n");

	for(int i=1;i<=n*n;i++)

		printf("%d ",a[i]);

}