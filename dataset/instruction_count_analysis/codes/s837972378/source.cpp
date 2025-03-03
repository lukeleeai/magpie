#include<stdio.h>

int main()

{

	int N;scanf("%d",&N);

	int r=0,p=0,v=0;

	for(int i=0;i<N;i++)

	{

		p=v;

		scanf("%d",&v);

		if(p==v)r=r+1,v=0;

	}

	printf("%d",r);

	return 0;

}