#include<stdio.h>

int main(){

	int a,b=0,c=0,n,j,i;

	scanf("%d",&n);

	for(j=1;j<=n;j+=2)

	{for(i=1;i<=j;i++)

	{

		if(j%i==0)

		{b++;}

		

		

		

	}

	if(b==8)

	{c++;}

    b=0;

}

	



printf("%d\n",c);

return 0;

}

	



	
