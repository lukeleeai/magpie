#include<stdio.h>

bool x=true;

char c;

int main()

{

	while((c=getchar())!=EOF)

	{

		if(x&1) putchar(c);

		x^=1;

	}

	putchar('\n');

	return 0;

}