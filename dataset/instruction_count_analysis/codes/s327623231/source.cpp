#include <stdio.h>

#include <math.h>

#include <string.h>

int _max(int x,int y){return x>y?x:y;}

int main(){

	int a,b;

	scanf("%d %d",&a,&b);

	if(a%b!=0)printf("%d\n",a);

	else printf("-1\n");

	return 0;

}