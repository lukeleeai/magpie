#include<stdio.h>

int a,b,c;

int main()

{

	scanf("%d%d%d",&a,&b,&c);

	printf("%d %d %d\n",a,b,3*c-a-b);

	printf("%d %d %d\n",(c<<2)-(a<<1)-b,c,(a<<1)+b-(c<<1));

	printf("%d %d %d\n",a+b-c,(c<<1)-b,(c<<1)-a);

	return 0 ;

}