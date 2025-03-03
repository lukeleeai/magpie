#include <stdio.h>



int main ()

{

	int N;

	double t,c;

	scanf("%d",&N);

	

    if(N%2==0)

	{

		t=N/2;

		c=(double)t/N;

		printf("%0.10lf\n",c);

	}

	else if(N%2!=0)

	{

		t=(N+1)/2;

		c=(double)t/N;

		printf("%0.10lf\n",c);

	}

	return 0;

}