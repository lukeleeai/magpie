#include<stdio.h>

#include<string.h>

int main(){

	int k;

	char s[105];

	scanf("%d",&k);

	getchar();

	scanf("%s",&s);

	if(strlen(s)>k){

		for(int i=0;i<k;i++){

			printf("%c",s[i]);

		}

		printf("...");

		printf("\n");

	}

	else{

		int l = strlen(s);

		for(int i=0;i<l;i++)

			printf("%c",s[i]);

		printf("\n");

	}

}