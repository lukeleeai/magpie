#include<stdio.h>

int main()

{

	char a,b;

	scanf("%c %c",&a,&b);

	if(a=='H' || a=='D' && b=='H' || b=='D')

	{

		if(a=='H' && b=='H')

		{

			printf("H\n");

		}

		else if(a=='H' && b=='D')

		{

			printf("D\n");

		}

		else if(a=='D' && b=='D')

		{

			printf("H\n");

		}

		else if(a=='D' && b=='H')

		{

			printf("D\n");

		}

	}

	return 0;

}