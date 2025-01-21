#include <stdio.h>

#include <string.h>

int main(){

	int k;

	scanf("%d",&k);

	char s[100];

	scanf("%s",&s);

	int lol = strlen(s);

	s[k] = '\0';

	for(int i=0;s[i]!='\0';i++){

		printf("%c",s[i]);

	}

	if(k<lol){

		printf("...");

	}

return 0;

}