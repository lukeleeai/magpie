#include<stdio.h>

int a[100003];

int main()

{

	long long b,c,d;

	scanf("%lld",&b);

	for(int i=1;i<=b;i++)

	{

	scanf("%lld",&a[i]);

	} 

	c=a[1];

	if(c==2) printf("1");

	else {

	for(int i=1;;i++)

	{

	d=a[c];

	if(d==2) 

	{

	printf("%d",i+1);

	break;

   }

	c=d;

	if(i==b-1){

     

	printf("-1");

	break;

	}       

}

}

	return 0;

}