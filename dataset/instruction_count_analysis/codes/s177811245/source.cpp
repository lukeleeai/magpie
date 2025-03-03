#include<stdio.h>

int main()

{

	int i,n,s=0;

	scanf("%d",&n);

	int a;

	for(i=0;i<n;i++) { scanf("%d",&a); s+=a; }

	s-=n;

	printf("%d",s);

}