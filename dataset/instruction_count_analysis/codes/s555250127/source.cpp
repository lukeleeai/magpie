#include<stdio.h>

const int M = 1e5+5;



int arr[M] = {0};



int main(){

	int n,i,j;

	int num1 = 0;

	int num2 = 0;

	int ans = 0;

	scanf("%d",&n);

	for(i = 0; i < n; i++){

		scanf("%d",&j);

		if(arr[j] == 0){

			arr[j] = 1;

			num1++;

		}

		else{

			num2++;

		}

	}

	if(num2 % 2 == 0) ans = num1;

	else ans = num1 -1;

	printf("%d",ans);

}