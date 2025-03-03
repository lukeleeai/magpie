#include<stdio.h>

int main() {

	int i,n;

	scanf("%d",&n);

	int a;

	int b[n];

	for( i=0;i<n;i++) {

		b[i]=0;

	}

	for( i=0;i<n-1;i++){

		scanf("%d",&a);

		b[a-1]=b[a-1]+1;

	}

	for( i=0;i<n;i++) {

		printf("%d\n",b[i]);

	}

}
