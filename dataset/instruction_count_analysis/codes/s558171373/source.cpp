#include<stdio.h>

int main(){

	int a[4];

	int m=0,n;

scanf("%d",&n);

a[3]=n%10;

a[2]=n/10%10;

a[1]=n/100%10;

a[0]=n/1000;

	for(int i=0;i<3;i++)

	if(a[i]==a[i+1])

	m++;

	if(m>0)

	printf("Bad\n");

	else

	printf("Good\n");

	return 0;

}