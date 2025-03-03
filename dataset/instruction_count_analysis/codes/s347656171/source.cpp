#include <cstdio>

int a,b,c,d,i,j,k;

char t;

int main(){

	scanf("%d %c %d",&a,&t,&b);

	if (t=='-'){

		printf("%d\n",a-b);

	}	

	if (t=='+'){

		printf("%d\n",a+b);

	}

}