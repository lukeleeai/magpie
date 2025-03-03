#include<cstdio>

using namespace std;

int n,k;

int main(){

	scanf("%d",&k);

	if (k==1){

		puts("1\n1");

		return 0;

	}

	n=(k+3)/4*2; printf("%d\n",n);

	for (int i=0;i<n;i++){

		for (int j=0;j<n;j++)

			if (i&1) printf("%d ",(i+j)%n+n<k?(i+j)%n+n+1:(i+j)%n+1);

			else printf("%d ",(i+j)%n+1);

		putchar('\n');

	}

	return 0;

}