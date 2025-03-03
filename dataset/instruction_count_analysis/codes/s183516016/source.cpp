#include<stdio.h>

using namespace std;

int main(void)

{

	int a,b;

	scanf("%d %d",&a,&b);

	printf("%s\n",(a*b)&1?"Odd":"Even");

	return 0;

}

/*

#include<stdio.h>

using namespace std;

int main(void)

{

	int left=1,right=100000000,mid,a,b;

	scanf("%d %d",&a,&b);

	while(left<=right)

	{

		mid=(left+right)/2;

		if(mid==a*b)

			break;

		else if(mid>a*b)

			right=mid;

		else

			left=mid;

	}

	printf("%s\n",mid&1?"Odd":"Even");

	return 0;

}

*/