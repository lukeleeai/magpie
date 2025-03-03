#include<stdio.h>



int f(int angka){

	int v=100000000,panjang,total=0;

	

	for(int i=0; i<9; i++){

		total=total+(angka/v);

		angka=angka%v;

		v/=10;

		

	}

	

	

	return total;

}



int main(){

	int a;

	scanf("%d", &a);

	int b=f(a);

	printf("%s\n", a%b==0?"Yes":"No");

	return 0;

}