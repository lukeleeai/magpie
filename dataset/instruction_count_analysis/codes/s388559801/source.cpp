#include<stdio.h>

#include<string.h>

int main()

{

	int n;

	scanf("%d",&n);

	int a,b;

	int ans=0;

	while(n--)

	{

		scanf("%d %d",&a,&b);

		if(a!=b)

		{

			ans+=(b-a+1);

		}

		else

		{

			ans+=1;

		}

	 } 

	 printf("%d\n",ans);

	 return 0;

 } 