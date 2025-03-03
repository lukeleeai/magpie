#include<stdio.h>

int a[10010]={0},b[10010]={0},c[100][100]={0};

int main()

{

	int i,j,H,W,N,f=1,t=0;

	scanf("%d%d",&H,&W);

	scanf("%d",&N);

	for(i=0;i<N;i++)

	{

		scanf("%d",&a[i]);

	}

	int sum=0;

	for(j=0;j<N;j++)

	{

	for(i=0;i<a[j];i++)

	{

		b[sum+i]=j+1; 

	}

	sum+=a[j];

	}

	

   	for(i=0,j=0,t=0;t<H*W;t++)

   	{	

	    c[i][j]=b[t];

	    i+=f;

   		if(i==H)

   		{ 

   			f=-1;

   			j++;

   			i=H-1;

		}

		if(i==-1)

		{

   			f=1;

   			j++;

   			i=0;

		}

	}

	

   	for(i=0;i<H;i++)

   	{

   		for(j=0;j<W;j++)

   	{

		printf("%d ",c[i][j]); 

		if(j==W-1)printf("\n"); 

	}

	}

	return 0;

}	