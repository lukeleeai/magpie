#include<cstdio>

#include<algorithm>

using namespace std;

int a,vis[66],n,k;

bool check(int x)

{

	while(x)

	{

		if(vis[x%10]) return 0;

		x/=10;

	}

	return 1;

}

int main()

{

	scanf("%d%d",&n,&k);

	for(int i=1;i<=k;i++)

	{

		scanf("%d",&a);

		vis[a]=1;

	}

	for(int i=n;;i++)

	{

		if(check(i))

		{

			printf("%d",i);

			break;

		}

	}

}