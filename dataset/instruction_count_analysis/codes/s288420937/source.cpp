#include<cstdio>

#include<cstring>

int main(){

	int a,b,c,d,i,j;

	int n[6];

	c=0;d=0;

	for(i=0;i<3;i++)

	{

		scanf("%d",&n[i]);

		if(n[i]==5)

		c+=1;

		else if(n[i]==7)

		d+=1;

	}

	if(c==2&&d==1)

	printf("YES\n");

	else

	printf("NO\n");



}