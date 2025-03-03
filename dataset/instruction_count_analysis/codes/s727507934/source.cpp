#include <stdio.h>

#include <string.h>

int main(){

	char s[400],t[400];

	scanf("%s",s);

	getchar();

	scanf("%s",t);

	getchar();

	int len = strlen(s);

	t[len] = '\0';

	if (strcmp (s,t) == 0){

		printf("Yes\n");

	}

	else{

		printf("No\n");

	}

	return 0;

}