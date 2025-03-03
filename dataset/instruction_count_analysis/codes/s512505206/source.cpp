#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

struct re

{

	int id;

	char name[105];

	int sc;

}a[105];

bool cmp(const re&a,const re&b)

{

	return(strcmp(a.name, b.name) < 0 || (strcmp(a.name, b.name) == 0 && a.sc > b.sc));

}

int main()

{

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)

	{

	

		scanf("%s",&a[i].name);

		scanf("%d", &a[i].sc);

		a[i].id = i + 1;

	}

	sort(a, a + n, cmp);

	for (int i = 0; i < n; i++)

		printf("%d\n", a[i].id);

	return 0;

}