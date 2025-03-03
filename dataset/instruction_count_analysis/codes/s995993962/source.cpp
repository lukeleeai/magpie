#include<stdio.h>

#include<stdlib.h>

#include<string.h>

typedef long long ll;

char str[100005];

int main(void)

{

	int p = 0, r = 0;

	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; i++)

		str[i] == 'p' ? p++ : r++;

	int max = len / 2;

	max = max > p ? max - p : 0;

	printf("%d\n", max);

	return 0;

}