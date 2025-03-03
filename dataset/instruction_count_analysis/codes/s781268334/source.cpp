#include<stdio.h>



int main(){

	int n;

	scanf("%d", &n);

	long long int total=1, batas=1e18;

	int zero=0, flag=0;

	for(int i=1; i<=n; i++){

		long long int angka;

		scanf("%lld", &angka);

		if(angka==0){

			zero=1;

			break;

		}

		else{

			flag=(batas<angka) ? flag=1 :flag=0;

			total*=angka;

			batas/=angka;

		}

	}

	if(zero==1){

		printf("0\n");

	}

	else{

		if(flag==1){

			printf("-1\n");

		}

		else printf("%lld\n", total);

	}

	return 0;

}