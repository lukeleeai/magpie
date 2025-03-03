#include<stdio.h>

int main()

{

	int m,n,i,k,j;

	char a[105];

	scanf("%d%d",&m,&n);

	  for(i=1;i<=m;i++)

	    {

	    	scanf("%s",a);

	   	 if(i==1)

	      {

			for(j=1;j<=n+2;j++)

	    	  	printf("#");

	    	  	printf("\n");

	      }

			   for(j=0;j<n;j++)

			      {

			      	if(n==1)  {  printf("#%c#\n",a[0]); break;}

			      	if(j==0)  printf("#%c",a[0]);

			      	if(j==n-1) printf("%c#\n",a[j]);

			      	if((j!=0) && (j!=n-1)) printf("%c",a[j]);

				  }  

			if(i==m)	

				{

				 for(j=1;j<=n+2;j++)

	    	  	    printf("#");

					  printf("\n");

				}

		}

return 0;

 } 