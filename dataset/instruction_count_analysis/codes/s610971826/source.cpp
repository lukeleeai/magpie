#include<cstdio>

int main()

{

	char a,b;

	scanf("%c %c",&a,&b);

	if(a=='H'){

		if(b=='H') printf("H\n");

		else printf("D\n");

	}

	if(a=='D'){

		if(b=='H') printf("D\n");

		else printf("H\n");

	}

	return 0;

}