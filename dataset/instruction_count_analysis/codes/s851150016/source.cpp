#include<stdio.h>

#include<stdlib.h>

#include<string.h>

const int N=200005;

struct node

{

	char a;

	char b;

}stringss[N];

int inc1(const void *a, const void *b)

{

    struct node m = *(struct node *)a;

    struct node n = *(struct node *)b;

    return m.a-n.a;

}

int inc2(const void *a, const void *b)

{

    struct node m = *(struct node *)a;

    struct node n = *(struct node *)b;

    return m.b-n.b;

}

int main()

{

	char str1[N],str2[N];

	scanf("%s",str1);

	scanf("%s",str2);

	int len=strlen(str1);

	for(int i=0;i<len;i++)

	{

		stringss[i].a=str1[i];

		stringss[i].b=str2[i];

	}

	qsort(stringss,len,sizeof(struct node),inc1);

	for(int i=0;i<len;i++)

	{

		if(stringss[i].a==stringss[i+1].a&&stringss[i].b!=stringss[i+1].b)

		{

			printf("No\n");

			return 0;

		}

	}

	qsort(stringss,len,sizeof(struct node),inc2);

	for(int i=0;i<len;i++)

	{

		if(stringss[i].b==stringss[i+1].b&&stringss[i].a!=stringss[i+1].a)

		{

			printf("No\n");

			return 0;

		}

	}

	printf("Yes\n");

}