#include<stdio.h>

#include<string.h>

#include<ctype.h>



int main(){

	int a, b, c;

	int k;

	scanf("%d %d %d", &a, &b, &c);

	scanf("%d", &k);

	if(a>b && a>c) printf("%d\n", (a<<k)+b+c);

	else if(b>a && b>c) printf("%d\n", a+(b<<k)+c);

	else printf("%d\n", a+b+(c<<k));

	return 0;

}