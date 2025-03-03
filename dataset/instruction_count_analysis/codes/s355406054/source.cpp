#include<stdio.h>

int main()

{

	int i,n,t=0;

	scanf("%d",&n);

	int a;

	for(i=0;i<n;i++) { scanf("%d",&a); t+=a; }

	t-=n;

	printf("%d",t);

}