#include<stdio.h>

int main(void)

{

	int a, b, t, c, ji;

	scanf("%d%d", &a, &b);

	if(a > b)

	{

		t = a;

		a = b;

		b = t;

	}

	for(int i = a; i <= b; i++)

	{

		c = i;

		ji = a*b*c;

		if(ji%2 == 1)

		break;

	}

	if(ji%2 == 0)

	printf("No");

	else

	printf("Yes");

	return 0;

 } 