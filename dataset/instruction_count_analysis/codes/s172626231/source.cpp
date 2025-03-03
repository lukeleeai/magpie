#include<stdio.h>

#include<string.h>

char str[101][101];

char k[101];

int main()

{

	int i,j,m,n;

	scanf("%d %d",&m,&n);

	for(i=0 ; i<m ; i++)

	{

		scanf("%s",str[i]);

	}

	for(j=0 ; j<m ; j++)

		for(i=0 ; i<(m-1) ; i++)

		{

			if (strcmp(str[i],str[i+1])>0)

			{

				strcpy(k,str[i]);

				strcpy(str[i],str[i+1]);

				strcpy(str[i+1],k);

			}

		}

		for(i=0 ; i<m ; i++)

		{

        	printf("%s",str[i]);

		}

		return 0;

}