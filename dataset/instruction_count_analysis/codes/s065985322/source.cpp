#include <stdio.h>



int main() {

	int a,b;

	scanf("%d %d", &a, &b);

	char s[255];

	scanf("%s", s);

	int angka = 0;

	for(int i = 0; s[i] != '\0'; i++){

		if(s[a] != '-'){

			puts("No");

			return 0;

		}

		if(s[i] >= '0' && s[i] <= '9'){

			angka++;

		}

	}

	if(angka == a+b){

		puts("Yes");

	}else{

		puts("No");

	}

	return 0;

}
