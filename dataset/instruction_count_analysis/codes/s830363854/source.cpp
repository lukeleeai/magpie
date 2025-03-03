#include <stdio.h>



int main (){

	

	int n;	// zero mengecek kalo perkaliannya dengan 0

	long long int a, max = 1e18, hasil = 1, flag = 0, zero = 0; 

	

	scanf("%d",&n);

	

	for(int i = 0; i < n; i++){

		scanf("%lld",&a);

		flag =(a > max) ? 1 : flag; // penanda kalo ada 0

		hasil *= a;

		a != 0 ? max /= a : zero = 1;

	}



	if(zero == 1){

		printf("0\n");

	}else if (flag == 1){

		printf("-1\n");

	}else{

		printf("%lld\n",hasil);

	}

return 0;

}
