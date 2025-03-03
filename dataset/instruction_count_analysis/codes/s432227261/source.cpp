#include <cstdio>

int main()

{

	

	int a = 0,b = 0;

	char c;

	scanf ("%d %c %d",&a,&c,&b);

	switch (c){

		case '+':printf ("%d",a + b);break;

		case '-':printf ("%d",a - b);

		}

	return 0;

	}