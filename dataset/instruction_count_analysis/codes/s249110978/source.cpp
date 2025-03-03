#include<stdio.h>



int main()

{

	char a[6]={'A','B','C','D','E','F'};

	char  b,c;int b1=0,c1=0;

	b=getchar();

	char d=getchar();

	c=getchar();

	for(int i=0;i<6;i++)

	{

		if(a[i]==b)

			b1=i+10;

		if(a[i]==c)

			c1=i+10;	

	}

	if(b1<c1)

	{

		printf("<\n");

	}

	if(b1>c1)

	{

		printf(">\n");

	}

		if(b1==c1)

	{

		printf("=\n");

	}

	

	return 0;

 } 