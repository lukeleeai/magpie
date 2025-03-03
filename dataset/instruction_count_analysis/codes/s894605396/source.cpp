#include <stdio.h>



int main() {

	int pos,a,b;

	scanf("%d %d %d", &pos, &a, &b);

	int disa, disb;

	if(pos > a){

		disa = pos - a;

	}else{

		disa = a - pos;

	}

	if(pos > b){

		disb = pos - b;

	}else{

		disb = b - pos;

	}

	if(disa > disb){

		puts("B");

	}else{

		puts("A");

	}

	

	

	return 0;

}
