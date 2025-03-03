#include<stdio.h>

int main()

{

	int a,s[10]={},b;

	scanf("%d",&a);

	while(a!=0){

	for(int i=0;i<a;i++){

		scanf("%d",&b);

		s[b]++;

	}

	for(int i=0;i<10;i++){

		for(int j=0;j<s[i];j++){

			printf("*");

		}

		if(s[i]==0)

			printf("-");

		printf("\n");

	}

	for(int i=0;i<10;i++){

		s[i]=0;

	}

	scanf("%d",&a);

	}

	return 0;

}