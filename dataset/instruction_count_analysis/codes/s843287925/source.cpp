#include<stdio.h>

int main(){

	char o[51],s[51];

	scanf("%s%s",o,s);

	int i,j,so=1,ss=1;

	while(o[so] != '\0'){so++;}

	while(s[ss] != '\0'){ss++;}

	if(so == ss){

		for(i = 0;i < so;i++){

			printf("%c",o[i]);

			printf("%c",s[i]);

		}

	}

	else if(so - ss == 1){

		for(j = 0;j < ss;j++){

			printf("%c",o[j]);

			printf("%c",s[j]);

		}

		printf("%c",o[so-1]);

	}

	printf("\n");

	return 0;

}