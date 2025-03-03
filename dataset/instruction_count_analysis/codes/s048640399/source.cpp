#include<stdio.h>

#include<algorithm>

#include<string.h>

#include<queue>

using namespace std;

int main()

{

	int n;

	while(~scanf("%d",&n))

	{

		int z[200005]={0},y[200005]={0};

		int max=0;

		int s[20000];

 		int j=0;

 		int p=0;

		for(int i=0;i<n;i++)

		{

			scanf("%d",&z[i]);

			y[i]=z[i];

		}

		sort(z,z+n);

		for(int i=0;i<n;i++)

		{

			if(y[i]==z[n-1])

			printf("%d\n",z[n-2]);

			else

			printf("%d\n",z[n-1]);

		}

	}

}
