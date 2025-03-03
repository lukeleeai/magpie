#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int cmp(const void*p,const void*q)

{

	return (*(int*)p-*(int*)q);

}

int a[300000],b[300000],c[300000],d[300000];

int main()

{

	int n,m,i,j,k,l,r,z;

	scanf("%d%d",&n,&m);

	for(k=j=i=0;i<m;i++)

	{

		scanf("%d%d",&a[i],&b[i]);

		if(a[i]==1)

			c[j++]=b[i];

		if(b[i]==n)

			d[k++]=a[i];

	}

	z=0;

	if(c[0]!=0&&d[0]!=0)

	{

	    qsort(c,j,sizeof(c[0]),cmp);

        qsort(d,k,sizeof(d[0]),cmp);

		for(z=i=0;i<j;i++)

		{

			l=0;r=k-1;

			while(l<=r)

			{

				int m=(l+r)/2;

				if(d[m]<c[i])

					l=m+1;

				else if(d[m]>c[i])

					r=m-1;

				else

				{

					z=1;

					break;

				}

			}

		}

	}

	if(z)

		printf("POSSIBLE\n");

	else

		printf("IMPOSSIBLE\n");

	return 0;

}
