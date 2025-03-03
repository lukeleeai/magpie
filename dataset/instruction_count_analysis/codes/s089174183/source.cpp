#include<stdio.h>

int main(){

	int n,k,x,y,p;

	scanf("%d%d%d%d",&n,&k,&x,&y);

	if (n>k){

		p = x * k + y * (n - k);

		printf("%d\n",p);

		}

		else {

			p = x * n;

			printf("%d\n",p);

			}

	return 0;

	}