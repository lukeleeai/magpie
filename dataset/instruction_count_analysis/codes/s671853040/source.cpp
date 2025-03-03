#include<stdio.h>

int main(){

	int n,k,q,i,j;

	scanf("%d %d %d",&n,&k,&q);

	int a[n],b[q];

	for(i=0;i<n;i++){

		a[i]=k;

	}

	for(i=0;i<q;i++){

		scanf("%d",&b[i]);

	}

	for(i=0;i<q;i++){

		a[b[i]-1]=a[b[i]-1]+1;

	}

	for(j=0;j<n;j++){

		a[j]=a[j]-q;

		if(a[j]>0)

		printf("Yes\n");

		else

		printf("No\n");

	}

	return 0;

} 