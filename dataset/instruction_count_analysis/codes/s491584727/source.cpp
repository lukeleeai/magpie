#include<stdio.h>

int main(){

	int a;

	scanf("%d", &a);

	char b[10001];

	scanf("%s", b);

	for(int i=0; b[i]!='\0'; i++){

		b[i]+=a;

		if(b[i]>'Z'){

			b[i]-=26;

		}

		printf("%c", b[i]);

	}

	return 0;

}