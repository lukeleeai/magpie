#include<stdio.h>

int main(){

	char a[8],c;

	scanf("%s",a);

	for(int i=0;i<3;i++)

	for(int j=0;j<3-i;j++)

	if(a[j]<a[j+1])

	{

	c=a[j];

	a[j]=a[j+1];

	a[j+1]=c;

    }

if(a[0]==a[1]&&a[2]==a[3]&&a[0]!=a[2]&&a[0]!=a[3])

	printf("Yes\n");

	else

	printf("No\n");

	return 0;

}
