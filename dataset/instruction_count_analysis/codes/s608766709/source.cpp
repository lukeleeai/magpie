#include<stdio.h>

#include<string.h>



int main(void) {

	int j = 0;

	char s[200001], t[200001];

	scanf("%s%s",&s, &t);



	for (int i = 0; i <= strlen(s); i++)

		if (s[i] != t[i])

			j++;

	printf("%d", j);

	return 0;

}
