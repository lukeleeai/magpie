#include<stdio.h>

int n,a[100005];

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++){

		scanf("%d",&a[i]);

	}

	int w=1,j=a[1];

		do{

		if(j==2)

		break;

		else{

			j=a[j];

			w++;

		}

	}while(w<=n);

	if(w>n)

	printf("-1");

	else

	printf("%d",w);

	return 0;	

}