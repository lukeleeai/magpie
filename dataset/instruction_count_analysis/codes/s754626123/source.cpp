#include<cstdio>

#include<cstring>

char ren[1000000];

int main()

{

	int n,k;

	scanf("%d %d",&n,&k);

	int xf=0;

	int j2=0;

	scanf("%s",&ren); 

	for(int i=1;i<n;i++)

	{

		if(ren[i]==ren[i-1])

		xf++;

	}

//	printf("xf%d\n",xf);

	if(xf+2*k>n-1)

	xf=n-1;

	else

	xf=xf+2*k;

	

	printf("%d",xf);

}