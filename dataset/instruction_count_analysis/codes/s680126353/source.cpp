#include<stdio.h>

int main()

{

	int N,M;

	scanf("%d %d", &N,&M);

	int P=1,K=1,O=0,L=0;

	for(int i = 1;i<N;i++)

	{

		O = O + P;

		P++;

	}

	for(int j = 1;j<M;j++)

	{

		L = L + K;

		K++;

	}

	

	printf("%d",O+L);

	return 0;

}