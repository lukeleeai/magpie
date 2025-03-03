#include<cstdio>

using namespace std;

int n,k,m;

int main(){

	scanf("%d",&n); k=0;

	while ((1<<(k+1))-1<=n) k++;

	m=(1<<k);

	if (m==n||n==1){

		puts("No");

		return 0;

	}

	puts("Yes");

	for (int i=1;i<m-1;i++){

		printf("%d %d\n",i,i+1);

		printf("%d %d\n",n+i,n+i+1);

	}

	printf("%d %d\n",m-1,n+1);

	if (n!=m-1){

		printf("1 %d\n",m+n);

		printf("%d %d\n",m,m+n+1);

	}

	for (int i=m+1;i<=n;i++){

		printf("%d %d\n",i+n-1,i);

		printf("%d %d\n",i-m,i+n);

	}

	return 0;

}
