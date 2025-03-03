#include<stdio.h>

int main(){

	int a,b;

	scanf("%d %d",&a,&b);

	if (a<=13&&a>=2&&b<=13&&b>=2&&a>b){printf("Alice\n");}

	if (a<=13&&a>=2&&b<=13&&b>=2&&b>a){printf("Bob\n");}

	if (a<=13&&a>=2&&b==1){printf("Bob\n");}

	if (b<=13&&b>=2&&a==1){printf("Alice\n");}

	if (a<=13&&a>=2&&b<=13&&b>=2&&a==b){printf("Draw\n");}

	if (a==1&&b==1){printf("Draw\n");}

	return 0;

	}