#include<cstdio>



char c1,c2,c;

int l=0;



int main()

{

	

	while((c=getchar())!=-1)

	{

		l++;

		if(c1==c)

		{

			printf("%d %d",l-1,l);

			return 0;

		}

		if(c2==c)

		{

			printf("%d %d",l-2,l);

			return 0;

		}

		c2=c1; c1=c;

	}

	puts("-1 -1");

	return 0;

}