#include<stdio.h>

#include<string.h>

#include<iostream>

using namespace std;

int main()

{

	char o[110], e[110];

	int i, j;

	int lo, le;

	scanf("%s", &o);

	scanf("%s", &e);

	lo = strlen(o);

	le = strlen(e);

	if(lo == le)

	{

		for(i = 0; i <= lo - 1; i++)

		{

			if(i != lo - 1)

			printf("%c%c", o[i], e[i]);

			else if(i == lo - 1)

				printf("%c%c\n", o[i], e[i]);

		}

	}

	else if(lo > le)

	{

		for(i = 0; i <= lo - 2; i++)

				printf("%c%c", o[i], e[i]);

				printf("%c\n", o[lo - 1]);

	}

		



}