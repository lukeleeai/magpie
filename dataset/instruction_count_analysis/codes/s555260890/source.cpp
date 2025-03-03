#include <stdio.h>

#define sz 200009

typedef long long ll;

int ar[sz],br[sz];

int i,j,n,r,max=0;

int main()

{

	

	scanf("%d",&n);

	for (i=1; i<=n; i++)

	{

		scanf("%d",&r);

		if (r>max) max=r;

		br[i]=r;

		ar[r]++;

	}

	for (i=1; i<=n; i++)

	{

		for (j=max; ; j-- )

		{

			if (ar[j]>0)

			{

				if (j==br[i]){

			if (br[i]==max && ar[max]==1) continue;}

	         printf("%d\n",j);

	         break;

			}

		}

	}

	return 0;

}